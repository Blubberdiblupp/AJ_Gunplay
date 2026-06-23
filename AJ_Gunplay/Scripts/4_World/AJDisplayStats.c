class AJDisplayStats
{
	static AJDisplayData GetDisplay(EntityAI item, string itemType = "", array<string> attachmentTypes = null)
	{
		if (!AJShouldShowDisplay(item, itemType, attachmentTypes))
		{
			return null;
		}
		
		AJDisplayData armorDisplay = AJArmorStats.GetArmorDisplay(item);
		if (armorDisplay)
		{
			return armorDisplay;
		}
		
		if (itemType != "")
		{
			armorDisplay = AJArmorStats.GetArmorDisplayByType(itemType);
			if (armorDisplay)
			{
				return armorDisplay;
			}
		}
		
		AJTierEffect effect = GetEffect(item, itemType, attachmentTypes);
		if (!effect)
		{
			return null;
		}
		
		return GetWeaponDisplay(effect);
	}
	
	static AJTierEffect GetEffect(EntityAI item, string itemType = "", array<string> attachmentTypes = null)
	{
		Weapon_Base weapon = Weapon_Base.Cast(item);
		if (weapon)
		{
			AJWeaponStatsManager manager = new AJWeaponStatsManager();
			manager.CalculateStats(weapon);
			return new AJTierEffect("Weapon", "Total", manager.GetCurrentRecoil(), manager.GetCurrentSway(), manager.GetCurrentAimSpeed(), manager.GetCurrentPrecision(), manager.GetAJHipFireSpreadModifier());
		}
		
		AJTierEffect attachmentEffect = AJAttachmentStats.GetEffect(item);
		if (attachmentEffect)
		{
			return attachmentEffect;
		}
		
		return GetEffectByType(itemType, attachmentTypes);
	}
	
	static AJTierEffect GetEffectByType(string itemType, array<string> attachmentTypes = null)
	{
		if (itemType == "")
		{
			return null;
		}
		
		if (IsWeaponType(itemType))
		{
			return GetWeaponEffectByType(itemType, attachmentTypes);
		}
		
		return AJAttachmentStats.GetEffectByType(itemType);
	}
	
	protected static bool IsWeaponType(string itemType)
	{
		if (itemType == "")
		{
			return false;
		}
		
		return GetGame().ConfigIsExisting("CfgWeapons " + itemType);
	}
	
	protected static AJTierEffect GetWeaponEffectByType(string itemType, array<string> attachmentTypes = null)
	{
		AJGunplayConfig config = AJGunplayConfig.GetInstance();
		if (!config)
		{
			return null;
		}
		
		AJWeaponStatsManager manager = new AJWeaponStatsManager();
		float baseRecoil = manager.GetBaseRecoilByType(itemType);
		float baseSway = manager.GetBaseSwayByType(itemType);
		float baseAimSpeed = manager.GetBaseAimSpeedByType(itemType);
		float basePrecision = manager.GetBasePrecisionByType(itemType);
		
		AJTierEffect effect = new AJTierEffect("Weapon", "Total", baseRecoil * config.GlobalRecoilMultiplier, baseSway * config.GlobalSwayMultiplier, baseAimSpeed * config.GlobalAimSpeedMultiplier, basePrecision, 1.0);
		ApplyAttachmentTypes(effect, attachmentTypes);
		
		return effect;
	}
	
	protected static AJDisplayData GetWeaponDisplay(AJTierEffect effect)
	{
		AJDisplayData data = new AJDisplayData();
		data.TierLabel = effect.GetLabel();
		data.Line1Label = "Recoil:";
		data.Line1Value = AJAttachmentStats.FormatDelta(effect.Recoil);
		data.Line1Color = AJAttachmentStats.GetDeltaColor(effect.Recoil, false);
		data.Line2Label = "Sway:";
		data.Line2Value = AJAttachmentStats.FormatDelta(effect.Sway);
		data.Line2Color = AJAttachmentStats.GetDeltaColor(effect.Sway, false);
		data.Line3Label = "ADS:";
		data.Line3Value = AJAttachmentStats.FormatDelta(effect.ADS);
		data.Line3Color = AJAttachmentStats.GetDeltaColor(effect.ADS, true);
		data.Line4Label = "Precision:";
		data.Line4Value = AJAttachmentStats.FormatDelta(effect.Precision);
		data.Line4Color = AJAttachmentStats.GetDeltaColor(effect.Precision, true);
		data.Line5Label = "Hipfire:";
		data.Line5Value = AJAttachmentStats.FormatDelta(effect.HipFire);
		data.Line5Color = AJAttachmentStats.GetDeltaColor(effect.HipFire, false);
		data.ShowLine5 = true;
		
		return data;
	}
	
	protected static void ApplyAttachmentTypes(AJTierEffect weaponEffect, array<string> attachmentTypes)
	{
		if (!weaponEffect || !attachmentTypes)
		{
			return;
		}
		
		foreach (string attachmentType : attachmentTypes)
		{
			AJTierEffect attachmentEffect = AJAttachmentStats.GetEffectByType(attachmentType);
			if (!attachmentEffect)
			{
				continue;
			}
			
			weaponEffect.Recoil *= attachmentEffect.Recoil;
			weaponEffect.Sway *= attachmentEffect.Sway;
			weaponEffect.ADS *= attachmentEffect.ADS;
			weaponEffect.Precision *= attachmentEffect.Precision;
			weaponEffect.HipFire *= attachmentEffect.HipFire;
		}
	}
	
	protected static bool AJShouldShowDisplay(EntityAI item, string itemType = "", array<string> attachmentTypes = null)
	{
		if (!GetGame().ConfigIsExisting("CfgPatches SNAFU_Gunplay"))
		{
			return true;
		}
		
		if (item && item.GetType().Contains("AJW_"))
		{
			return true;
		}
		
		Weapon_Base weapon = Weapon_Base.Cast(item);
		if (weapon && weapon.AJShouldApplyGunplay())
		{
			return true;
		}
		
		if (itemType.Contains("AJW_"))
		{
			return true;
		}
		
		if (attachmentTypes)
		{
			foreach (string attachmentType : attachmentTypes)
			{
				if (attachmentType.Contains("AJW_"))
				{
					return true;
				}
			}
		}
		
		return false;
	}
}
