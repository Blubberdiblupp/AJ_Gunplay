modded class Weapon_Base
{
	protected ref AJWeaponStatsManager m_AJStatsManager;
	protected bool m_AJStatsDirty = true;
	
	protected bool m_AJWasInIronsights;
	protected int m_AJLastZeroing;
	protected float m_AJLastZoomLevel;
	
	void Weapon_Base()
	{
		m_AJStatsManager = new AJWeaponStatsManager();
		m_AJWasInIronsights = false;
		m_AJLastZeroing = 0;
		m_AJLastZoomLevel = 0;
	}
	
	void ~Weapon_Base()
	{
		if (m_AJStatsManager)
		{
			delete m_AJStatsManager;
		}
	}
	
	override void EEItemAttached(EntityAI item, string slot_name)
	{
		if (item)
		{
			m_AJStatsDirty = true;
		}
		
		super.EEItemAttached(item, slot_name);
		
		if (!item) return;
		
		string itemType = item.GetType();
		
		AJNetworkOptimizer optimizer = AJNetworkOptimizer.GetInstance();
		
		if (!optimizer.ShouldTriggerStatRecalc(itemType, slot_name))
		{
			if (GetGame().IsServer())
			{
				AJGunplayConfig debugConfigAttached = AJGunplayConfig.GetInstance();
				if (debugConfigAttached.DebugMode)
				{
					Print("[AJ Gunplay] Cosmetic attachment ignored: " + itemType + " (slot: " + slot_name + ")");
				}
			}
			return;
		}
		
		if (GetGame().IsServer())
		{
			AJGunplayConfig attachConfig = AJGunplayConfig.GetInstance();
			if (attachConfig.DebugMode)
			{
				Print("[AJ Gunplay] Stat-affecting item attached: " + itemType + " to slot: " + slot_name);
			}
			
			AJRecalculateStats();
		}
	}
	
	override void EEItemDetached(EntityAI item, string slot_name)
	{
		if (item)
		{
			m_AJStatsDirty = true;
		}
		
		super.EEItemDetached(item, slot_name);
		
		if (!item) return;
		
		string itemType = item.GetType();
		
		AJNetworkOptimizer optimizer = AJNetworkOptimizer.GetInstance();
		
		if (!optimizer.ShouldTriggerStatRecalc(itemType, slot_name))
		{
			if (GetGame().IsServer())
			{
				AJGunplayConfig debugConfigDetached = AJGunplayConfig.GetInstance();
				if (debugConfigDetached.DebugMode)
				{
					Print("[AJ Gunplay] Cosmetic detachment ignored: " + itemType + " (slot: " + slot_name + ")");
				}
			}
			return;
		}
		
		if (GetGame().IsServer())
		{
			AJGunplayConfig detachConfig = AJGunplayConfig.GetInstance();
			if (detachConfig.DebugMode)
			{
				Print("[AJ Gunplay] Stat-affecting item detached: " + itemType + " from slot: " + slot_name);
			}
			
			AJRecalculateStats();
		}
	}
	
	void AJRecalculateStats()
	{
		if (!m_AJStatsManager)
		{
			m_AJStatsManager = new AJWeaponStatsManager();
		}
		
		m_AJStatsManager.CalculateStats(this);
		m_AJStatsDirty = false;
		
		AJGunplayConfig config = AJGunplayConfig.GetInstance();
		
		if (config.DebugMode && m_AJStatsManager)
		{
			Print(m_AJStatsManager.GetStatsString());
		}
	}
	
	override RecoilBase SpawnRecoilObject()
	{
		if (AJShouldApplyGunplay() && m_AJStatsDirty)
		{
			AJRecalculateStats();
		}
		
		return super.SpawnRecoilObject();
	}
	
	float GetAJWeaponRecoilModifier()
	{
		if (!AJShouldApplyGunplay())
		{
			return 1.0;
		}
		
		if (m_AJStatsDirty)
		{
			AJRecalculateStats();
		}
		
		if (m_AJStatsManager)
		{
			return m_AJStatsManager.GetCurrentRecoil();
		}
		
		return 1.0;
	}
	
	float GetAJDispersion()
	{
		if (!AJShouldApplyGunplay())
		{
			return 0.0;
		}
		
		if (m_AJStatsDirty)
		{
			AJRecalculateStats();
		}
		
		if (m_AJStatsManager)
		{
			return m_AJStatsManager.GetCurrentSway() / m_AJStatsManager.GetCurrentPrecision();
		}
		
		return 0.0;
	}
	
	float GetAJOpticsDisableLookOverride()
	{
		if (!AJShouldApplyGunplay())
		{
			return 1.0;
		}
		
		if (m_AJStatsDirty)
		{
			AJRecalculateStats();
		}
		
		if (m_AJStatsManager)
		{
			return m_AJStatsManager.GetCurrentAimSpeed();
		}
		
		return 1.0;
	}
	
	int GetAJOpticEnterDelay()
	{
		float aimSpeed = GetAJOpticsDisableLookOverride();
		if (aimSpeed <= 0.05)
		{
			aimSpeed = 1.0;
		}
		
		float delay = 700.0 / aimSpeed;
		if (delay < 150.0)
		{
			delay = 150.0;
		}
		
		if (delay > 1400.0)
		{
			delay = 1400.0;
		}
		
		return Math.Round(delay);
	}
	
	float GetAJHipFireSpreadModifier()
	{
		if (!AJShouldApplyGunplay())
		{
			return 1.0;
		}
		
		if (m_AJStatsDirty)
		{
			AJRecalculateStats();
		}
		
		if (m_AJStatsManager)
		{
			return m_AJStatsManager.GetAJHipFireSpreadModifier();
		}
		
		return 1.0;
	}
	
	bool AJShouldApplyGunplay()
	{
		if (!GetGame().ConfigIsExisting("CfgPatches SNAFU_Gunplay"))
		{
			return true;
		}
		
		return AJHasWeaponPackContent();
	}
	
	bool AJHasWeaponPackContent()
	{
		if (GetType().Contains("AJW_"))
		{
			return true;
		}
		
		if (!GetInventory())
		{
			return false;
		}
		
		for (int i = 0; i < GetInventory().AttachmentCount(); i++)
		{
			EntityAI attachment = GetInventory().GetAttachmentFromIndex(i);
			if (attachment && attachment.GetType().Contains("AJW_"))
			{
				return true;
			}
		}
		
		return false;
	}
	
	bool AJHasGripAttached()
	{
		if (FindAttachmentBySlotName("AJar15afg")) return true;
		if (FindAttachmentBySlotName("FGRIP")) return true;
		if (FindAttachmentBySlotName("weaponGripCQR")) return true;
		if (FindAttachmentBySlotName("weaponGripKAAR")) return true;
		if (FindAttachmentBySlotName("AJM249Grip")) return true;
		
		return false;
	}
	
	bool AJHasScopeAttached()
	{
		if (FindAttachmentBySlotName("weaponOptics")) return true;
		if (FindAttachmentBySlotName("weaponOpticsHunting")) return true;
		if (FindAttachmentBySlotName("weaponOpticsSniper")) return true;
		
		return false;
	}
	
	bool AJIsHeavyScopeAttached()
	{
		return false;
	}
	
	string GetAJGunplayStatsDisplay()
	{
		if (m_AJStatsDirty)
		{
			AJRecalculateStats();
		}
		
		if (m_AJStatsManager)
		{
			return m_AJStatsManager.GetStatsString();
		}
		
		return "";
	}
	
}
