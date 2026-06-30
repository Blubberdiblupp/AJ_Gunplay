/**
 * AJWeaponStatsManager.c - hardcoded tier-based attachment stats.
 *
 * Lower Recoil/Sway is better. Higher ADS/Precision is better.
 */

class AJWeaponStatsManager
{
	protected float m_BaseRecoil;
	protected float m_BaseSway;
	protected float m_BaseAimSpeed;
	protected float m_BasePrecision;
	
	protected float m_CurrentRecoil;
	protected float m_CurrentSway;
	protected float m_CurrentAimSpeed;
	protected float m_CurrentPrecision;
	
	protected float m_HipFireSpreadModifier;
	
	protected ref TStringArray m_ButtstockSlots;
	protected ref TStringArray m_PistolGripSlots;
	protected ref TStringArray m_ForegripSlots;
	protected ref TStringArray m_HandguardSlots;
	protected ref TStringArray m_BipodSlots;
	protected ref TStringArray m_OpticSlots;
	protected ref TStringArray m_HeavyScopes;
	protected ref TStringArray m_LightScopes;
	protected ref TStringArray m_SniperScopes;
	protected ref TStringArray m_LaserSlots;
	protected ref TStringArray m_FlashlightSlots;
	protected ref TStringArray m_BayonetSlots;
	protected ref TStringArray m_MuzzleSlots;
	protected ref TStringArray m_WrapSlots;
	protected ref TStringArray m_MagazineSlots;
	protected ref TStringArray m_AttachmentEffectLines;
	
	void AJWeaponStatsManager()
	{
		m_ButtstockSlots = new TStringArray;
		m_PistolGripSlots = new TStringArray;
		m_ForegripSlots = new TStringArray;
		m_HandguardSlots = new TStringArray;
		m_BipodSlots = new TStringArray;
		m_OpticSlots = new TStringArray;
		m_HeavyScopes = new TStringArray;
		m_LightScopes = new TStringArray;
		m_SniperScopes = new TStringArray;
		m_LaserSlots = new TStringArray;
		m_FlashlightSlots = new TStringArray;
		m_BayonetSlots = new TStringArray;
		m_MuzzleSlots = new TStringArray;
		m_WrapSlots = new TStringArray;
		m_MagazineSlots = new TStringArray;
		m_AttachmentEffectLines = new TStringArray;
		
		InitAttachmentLists();
	}
	
	void InitAttachmentLists()
	{
		m_ButtstockSlots.Insert("weaponButtstock");
		m_ButtstockSlots.Insert("weaponButtstockAK");
		m_ButtstockSlots.Insert("weaponButtstockM4");
		m_ButtstockSlots.Insert("weaponButtstockCQR");
		m_ButtstockSlots.Insert("weaponButtstockADAR");
		m_ButtstockSlots.Insert("weaponButtstockFal");
		m_ButtstockSlots.Insert("weaponButtstockG36");
		m_ButtstockSlots.Insert("weaponMP5Buttstock");
		m_ButtstockSlots.Insert("weaponPKButtstock");
		m_ButtstockSlots.Insert("weaponScarButtstock");
		m_ButtstockSlots.Insert("weaponSpas12Buttstock");
		m_ButtstockSlots.Insert("weaponVectorButtstock");
		m_ButtstockSlots.Insert("weaponump45buttstock");
		m_ButtstockSlots.Insert("weaponevobuttstock");
		m_ButtstockSlots.Insert("weaponStock");
		m_ButtstockSlots.Insert("HuntingButtstock");
		m_ButtstockSlots.Insert("MP5_PlasticButtstock");
		m_ButtstockSlots.Insert("MP5_PaddedButtstock");
		m_ButtstockSlots.Insert("MossbergStock");
		m_ButtstockSlots.Insert("weaponTubeStockAdapterAK");
		m_ButtstockSlots.Insert("weaponTubeStockAdapterASVAL");
		m_ButtstockSlots.Insert("weaponTubeStockAdapterScar");
		m_ButtstockSlots.Insert("weaponTubeStockAdapterSVD");
		m_ButtstockSlots.Insert("weaponTubeStockAdapterVector");
		m_ButtstockSlots.Insert("AJM249Stock");
		m_ButtstockSlots.Insert("AJM200Stock");
		m_ButtstockSlots.Insert("AJWSR3Stock");
		m_ButtstockSlots.Insert("Slot_AJW_74M_Stock");
		m_ButtstockSlots.Insert("Slot_AJW_MCX_Stock");
		m_ButtstockSlots.Insert("AJW_EVO3_Stock");
		m_ButtstockSlots.Insert("AJW_R700Stock_Magpul");
		m_ButtstockSlots.Insert("AJW_SV98_OV_Stock");
		m_ButtstockSlots.Insert("AJW_svd_stockadapt");
		
		m_PistolGripSlots.Insert("weaponPistolGrip");
		m_PistolGripSlots.Insert("weaponGrip");
		m_PistolGripSlots.Insert("weaponGripAK");
		m_PistolGripSlots.Insert("weaponAKPistolGrip");
		m_PistolGripSlots.Insert("weaponM4PistolGrip");
		m_PistolGripSlots.Insert("weaponFALPistolGrip");
		m_PistolGripSlots.Insert("weaponevopistolgrip");
		m_PistolGripSlots.Insert("AJMPXGRIP");
		m_PistolGripSlots.Insert("Slot_AJW_AK_PG");
		m_PistolGripSlots.Insert("Slot_AJW_M4_PG");
		
		m_ForegripSlots.Insert("AJar15afg");
		m_ForegripSlots.Insert("FGRIP");
		m_ForegripSlots.Insert("weaponForegrip");
		m_ForegripSlots.Insert("weaponGripCQR");
		m_ForegripSlots.Insert("weaponGripKAAR");
		m_ForegripSlots.Insert("AJM249Grip");
		m_ForegripSlots.Insert("AJSR3Grip");
		m_ForegripSlots.Insert("weaponrgripAJ");
		m_ForegripSlots.Insert("Slot_AJW_M4_FG");
		
		m_HandguardSlots.Insert("weaponHandguard");
		m_HandguardSlots.Insert("weaponHandguardM4");
		m_HandguardSlots.Insert("WeaponHandguardAK");
		m_HandguardSlots.Insert("weaponHandguardASVAL");
		m_HandguardSlots.Insert("weaponHandguardFAL");
		m_HandguardSlots.Insert("weaponHandguardHK");
		m_HandguardSlots.Insert("weaponHandguardHKG28");
		m_HandguardSlots.Insert("weaponHandguardM16");
		m_HandguardSlots.Insert("WeaponHandguardM4");
		m_HandguardSlots.Insert("weaponHandguardPK");
		m_HandguardSlots.Insert("weaponForearmMP5");
		m_HandguardSlots.Insert("weaponForearmMP5k");
		m_HandguardSlots.Insert("MossbergForearm");
		m_HandguardSlots.Insert("MP153Forearm");
		m_HandguardSlots.Insert("AJWeaponHandguardAK");
		m_HandguardSlots.Insert("HandguardRIS");
		m_HandguardSlots.Insert("M4_OEBHandGuard");
		m_HandguardSlots.Insert("M4_MOLLEHandGuard");
		m_HandguardSlots.Insert("weaponHGAdarNA");
		m_HandguardSlots.Insert("weaponHGAJ10");
		m_HandguardSlots.Insert("weaponHGAJ10NA");
		m_HandguardSlots.Insert("weaponHGAJ14");
		m_HandguardSlots.Insert("weaponHGAJ14NA");
		m_HandguardSlots.Insert("weaponHGAJ16");
		m_HandguardSlots.Insert("weaponHGAJ16NA");
		m_HandguardSlots.Insert("AJM249HG");
		m_HandguardSlots.Insert("AJM60Handguard");
		m_HandguardSlots.Insert("AJSR3HG");
		m_HandguardSlots.Insert("Expansion_M1AScopeRail");
		m_HandguardSlots.Insert("Expansion_MP5ScopeRail");
		m_HandguardSlots.Insert("Slot_AJW_AK_HG");
		m_HandguardSlots.Insert("Slot_AJW_AK74U_HG");
		m_HandguardSlots.Insert("Slot_AJW_AR10_HG");
		m_HandguardSlots.Insert("Slot_AJW_HK_HG");
		m_HandguardSlots.Insert("Slot_AJW_M4_HG");
		m_HandguardSlots.Insert("Slot_AJW_MCX_HG");
		m_HandguardSlots.Insert("Slot_AJW_SA58_HG");
		m_HandguardSlots.Insert("Slot_AJW_SCAR_HG");
		m_HandguardSlots.Insert("Slot_AJW_AK_Dustcover");
		m_HandguardSlots.Insert("Slot_AJW_74U_DC");
		m_HandguardSlots.Insert("Slot_AJW_Vityaz_DC");
		m_HandguardSlots.Insert("AJW_EVO3_BarrelAssembly");
		m_HandguardSlots.Insert("AJW_svd_chassismk1");
		
		m_BipodSlots.Insert("AJweaponBipod");
		m_BipodSlots.Insert("weaponBipod");
		m_BipodSlots.Insert("AJM249Bipod");
		m_BipodSlots.Insert("AJM200Bipod");
		m_BipodSlots.Insert("AJvsskBipod");
		m_BipodSlots.Insert("sr25bipod");
		m_BipodSlots.Insert("PKPBIPOD");
		m_BipodSlots.Insert("Slot_AJW_Bipod");
		
		m_OpticSlots.Insert("weaponOptics");
		m_OpticSlots.Insert("weaponOpticsAK");
		m_OpticSlots.Insert("weaponOpticsHunting");
		m_OpticSlots.Insert("weaponOpticsSniper");
		m_OpticSlots.Insert("weaponOpticsMosin");
		m_OpticSlots.Insert("weaponOpticsCrossbow");
		m_OpticSlots.Insert("pistolOptics");
		m_OpticSlots.Insert("AJSIGHT");
		m_OpticSlots.Insert("weaponOpticMount");
		m_OpticSlots.Insert("weaponOpticMountAK");
		m_OpticSlots.Insert("weaponOpticMountM16");
		m_OpticSlots.Insert("weaponFALOpticMount");
		m_OpticSlots.Insert("weaponMP5OpticMount");
		m_OpticSlots.Insert("weaponPKOpticMount");
		m_OpticSlots.Insert("weaponSKSOpticMount");
		m_OpticSlots.Insert("MossbergOpticMount");
		m_OpticSlots.Insert("AJM60ScopeMount");
		m_OpticSlots.Insert("GCGN_M84_Optic");
		m_OpticSlots.Insert("ExpansionSniperOptics");
		m_OpticSlots.Insert("ExpansionKar98Optics");
		m_OpticSlots.Insert("AJW_weaponMagnifier");
		m_OpticSlots.Insert("AJW_K98_Optic_Slot");
		
		m_HeavyScopes.Insert("AJ_Tango6T");
		m_HeavyScopes.Insert("AJ_Leupold_MK8");
		m_HeavyScopes.Insert("AJ_Kahles");
		m_HeavyScopes.Insert("AJ_Walther");
		m_HeavyScopes.Insert("ACOGOptic");
		m_HeavyScopes.Insert("ACOGOptic_6x");
		m_HeavyScopes.Insert("PSO1Optic");
		m_HeavyScopes.Insert("PSO11Optic");
		m_HeavyScopes.Insert("PSO6Optic");
		m_HeavyScopes.Insert("GrozaOptic");
		m_HeavyScopes.Insert("PUScopeOptic");
		m_HeavyScopes.Insert("MK4Optic_ColorBase");
		m_HeavyScopes.Insert("MK4Optic_Tan");
		m_HeavyScopes.Insert("MK4Optic_Green");
		m_HeavyScopes.Insert("MK4Optic_Black");
		m_HeavyScopes.Insert("KazuarOptic");
		m_HeavyScopes.Insert("StarlightOptic");
		m_HeavyScopes.Insert("GCGN_M84_Optic");
		m_HeavyScopes.Insert("AJ_M14Optic");
		m_HeavyScopes.Insert("ExpansionHAMROptic");
		
		m_LightScopes.Insert("AJ_RDS");
		m_LightScopes.Insert("AJ_EOTech_EXPS3");
		m_LightScopes.Insert("AJ_Aimpoint_M5");
		m_LightScopes.Insert("AJ_Docter");
		m_LightScopes.Insert("AJ_Elcan");
		m_LightScopes.Insert("M4_CarryHandleOptic");
		m_LightScopes.Insert("BUISOptic");
		m_LightScopes.Insert("M68Optic");
		m_LightScopes.Insert("M4_T3NRDSOptic");
		m_LightScopes.Insert("FNP45_MRDSOptic");
		m_LightScopes.Insert("ReflexOptic");
		m_LightScopes.Insert("KobraOptic");
		m_LightScopes.Insert("PistolOptic");
		m_LightScopes.Insert("SportingOptic");
		m_LightScopes.Insert("KashtanOptic");
		m_LightScopes.Insert("ExpansionDeltapointOptic");
		m_LightScopes.Insert("ExpansionEXPS3HoloOptic");
		m_LightScopes.Insert("ExpansionReflexMRSOptic");
		
		m_SniperScopes.Insert("HuntingOptic");
		m_SniperScopes.Insert("LongrangeOptic");
		m_SniperScopes.Insert("AJ_Hunting");
		m_SniperScopes.Insert("AJ_Nightforce");
		m_SniperScopes.Insert("AJ_AKNightforce");
		m_SniperScopes.Insert("AJ_HNightforce");
		m_SniperScopes.Insert("AJ_MNightforce");
		m_SniperScopes.Insert("AJ_AKHuntingOptic");
		m_SniperScopes.Insert("AJ_HHuntingOptic");
		m_SniperScopes.Insert("AJ_HuntingOptic");
		m_SniperScopes.Insert("AJ_MHuntingOptic");
		m_SniperScopes.Insert("Expansion_PMII25Optic");
		m_SniperScopes.Insert("ExpansionKar98ScopeOptic");
		
		m_LaserSlots.Insert("weaponLaserPointer");
		m_LaserSlots.Insert("weaponLaser");
		m_LaserSlots.Insert("PistolLaserPointer");
		m_LaserSlots.Insert("AJPEQLASER");
		m_LaserSlots.Insert("Slot_AJW_Laser");
		
		m_FlashlightSlots.Insert("weaponFlashlight");
		m_FlashlightSlots.Insert("weaponFlashlightRail");
		m_FlashlightSlots.Insert("TLRLight");
		m_FlashlightSlots.Insert("UniversalLight");
		m_FlashlightSlots.Insert("weaponLightLeft");
		m_FlashlightSlots.Insert("weaponLightRight");
		m_FlashlightSlots.Insert("weaponLightTop");
		m_FlashlightSlots.Insert("pistolFlashlight");
		m_FlashlightSlots.Insert("helmetFlashlight");
		
		m_BayonetSlots.Insert("weaponBayonet");
		m_BayonetSlots.Insert("weaponBayonetAK");
		m_BayonetSlots.Insert("weaponBayonetSKS");
		m_BayonetSlots.Insert("expansionWeaponBayonetKar");
		m_BayonetSlots.Insert("Bayonet");
		m_BayonetSlots.Insert("M9A1Bayonet");
		m_BayonetSlots.Insert("GCGN_M1Garand_Bayonet");
		m_BayonetSlots.Insert("AJ_SKS_Bayonet");
		m_BayonetSlots.Insert("Slot_AJW_M1897Bayonet");
		
		m_MuzzleSlots.Insert("weaponMuzzleM4");
		m_MuzzleSlots.Insert("weaponMuzzleAK");
		m_MuzzleSlots.Insert("weaponMuzzleSKS");
		m_MuzzleSlots.Insert("weaponMuzzleFAL");
		m_MuzzleSlots.Insert("weaponMuzzle277");
		m_MuzzleSlots.Insert("weaponMuzzle308");
		m_MuzzleSlots.Insert("weaponMuzzle338");
		m_MuzzleSlots.Insert("weaponmuzzle338");
		m_MuzzleSlots.Insert("weaponMuzzle408");
		m_MuzzleSlots.Insert("weaponmuzzle408");
		m_MuzzleSlots.Insert("weaponMuzzle86");
		m_MuzzleSlots.Insert("weaponMuzzleShotgun");
		m_MuzzleSlots.Insert("weaponMuzzleMosin");
		m_MuzzleSlots.Insert("weaponMuzzleMP5");
		m_MuzzleSlots.Insert("pistolMuzzle");
		m_MuzzleSlots.Insert("suppressorImpro");
		m_MuzzleSlots.Insert("Slot_AJW_50Cal_Muzzle");
		m_MuzzleSlots.Insert("Slot_AJW_Muzzle12GA");
		m_MuzzleSlots.Insert("Slot_XM7_Suppressor");
		m_MuzzleSlots.Insert("AJW_HKG28_Suppressor");
		m_MuzzleSlots.Insert("weaponMuzzelAJ");
		m_MuzzleSlots.Insert("GCGN_M1Garand_Muzzle");
		m_MuzzleSlots.Insert("AJShotgunchoke");
		m_MuzzleSlots.Insert("AJ50bmg");
		m_MuzzleSlots.Insert("sr25Muzzle");
		m_MuzzleSlots.Insert("22LRSuppressor");
		m_MuzzleSlots.Insert("ASH12Suppressor");
		m_MuzzleSlots.Insert("HoneyBadgerSuppressor");
		m_MuzzleSlots.Insert("MP7A2Suppressor");
		m_MuzzleSlots.Insert("QDLSuppressor");
		m_MuzzleSlots.Insert("AJ338_Suppressor");
		m_MuzzleSlots.Insert("Suppressor9A91");
		m_MuzzleSlots.Insert("AJ300acsupp");
		m_MuzzleSlots.Insert("SR3S");
		
		m_WrapSlots.Insert("weaponWrap");
		
		m_MagazineSlots.Insert("weaponMagazine");
		m_MagazineSlots.Insert("magazine");
	}
	
	void CalculateStats(Weapon_Base weapon)
	{
		AJGunplayConfig config = AJGunplayConfig.GetInstance();
		
		m_BaseRecoil = GetBaseRecoil(weapon);
		m_BaseSway = GetBaseSway(weapon);
		m_BaseAimSpeed = GetBaseAimSpeed(weapon);
		m_BasePrecision = GetBasePrecision(weapon);
		
		m_CurrentRecoil = m_BaseRecoil * config.GlobalRecoilMultiplier;
		m_CurrentSway = m_BaseSway * config.GlobalSwayMultiplier;
		m_CurrentAimSpeed = m_BaseAimSpeed * config.GlobalAimSpeedMultiplier;
		m_CurrentPrecision = m_BasePrecision * config.GlobalPrecisionMultiplier;
		
		m_HipFireSpreadModifier = config.GlobalHipFireMultiplier;
		m_AttachmentEffectLines.Clear();
		
		ApplyAttachmentModifiers(weapon, config);
	}
	
	float GetBaseRecoil(Weapon_Base weapon)
	{
		if (!weapon) return 1.0;
		return GetBaseRecoilByType(weapon.GetType());
	}
	
	float GetBaseSway(Weapon_Base weapon)
	{
		if (!weapon) return 1.0;
		return GetBaseSwayByType(weapon.GetType());
	}
	
	float GetBaseAimSpeed(Weapon_Base weapon)
	{
		if (!weapon) return 1.0;
		return GetBaseAimSpeedByType(weapon.GetType());
	}
	
	float GetBasePrecision(Weapon_Base weapon)
	{
		if (!weapon) return 1.0;
		return GetBasePrecisionByType(weapon.GetType());
	}
	
	float GetBaseRecoilByType(string weaponType)
	{
		float configRecoil = GetAverageConfigFloatArray("CfgWeapons " + weaponType + " recoilModifier", 1.0);
		float weight = GetWeaponWeightKg(weaponType);
		float weightReduction = ClampFloat((weight - 3.0) * 0.025, -0.06, 0.12);
		
		return ClampFloat(configRecoil * (1.0 - weightReduction), 0.65, 1.85);
	}
	
	float GetBaseSwayByType(string weaponType)
	{
		float configSway = GetAverageConfigFloatArray("CfgWeapons " + weaponType + " swayModifier", 1.0);
		float weight = GetWeaponWeightKg(weaponType);
		float length = GetWeaponLengthMeters(weaponType);
		float weightPenalty = ClampFloat((weight - 3.0) * 0.025, -0.05, 0.16);
		float lengthPenalty = ClampFloat((length - 0.7) * 0.18, -0.06, 0.14);
		
		return ClampFloat(configSway * (1.0 + weightPenalty + lengthPenalty), 0.70, 1.95);
	}
	
	float GetBaseAimSpeedByType(string weaponType)
	{
		float configAimSpeed = GetAverageConfigFloatArray("CfgWeapons " + weaponType + " aimSpeedModifier", 0.35);
		float weight = GetWeaponWeightKg(weaponType);
		float length = GetWeaponLengthMeters(weaponType);
		float normalizedAimSpeed = 0.35 / ClampFloat(configAimSpeed, 0.12, 1.20);
		float weightPenalty = ClampFloat((weight - 3.0) * 0.018, -0.05, 0.14);
		float lengthPenalty = ClampFloat((length - 0.7) * 0.14, -0.05, 0.12);
		
		return ClampFloat(normalizedAimSpeed * (1.0 - weightPenalty - lengthPenalty), 0.65, 1.35);
	}
	
	float GetBasePrecisionByType(string weaponType)
	{
		float length = GetWeaponLengthMeters(weaponType);
		float weight = GetWeaponWeightKg(weaponType);
		float lengthBonus = ClampFloat((length - 0.55) * 0.20, -0.08, 0.18);
		float weightBonus = ClampFloat((weight - 3.0) * 0.010, -0.04, 0.08);
		
		return ClampFloat(1.0 + lengthBonus + weightBonus, 0.85, 1.25);
	}
	
	protected float GetWeaponWeightKg(string weaponType)
	{
		float weight = GetGame().ConfigGetFloat("CfgWeapons " + weaponType + " weight");
		if (weight <= 0.0)
		{
			return 3.0;
		}
		
		return weight / 1000.0;
	}
	
	protected float GetWeaponLengthMeters(string weaponType)
	{
		float length = GetGame().ConfigGetFloat("CfgWeapons " + weaponType + " WeaponLength");
		if (length <= 0.0)
		{
			return 0.7;
		}
		
		return length;
	}
	
	protected float GetAverageConfigFloatArray(string path, float fallback)
	{
		if (!GetGame().ConfigIsExisting(path))
		{
			return fallback;
		}
		
		TFloatArray values = new TFloatArray;
		GetGame().ConfigGetFloatArray(path, values);
		if (values.Count() == 0)
		{
			return fallback;
		}
		
		float total = 0.0;
		foreach (float value : values)
		{
			total += value;
		}
		
		return total / values.Count();
	}
	
	protected float ClampFloat(float value, float minValue, float maxValue)
	{
		if (value < minValue)
		{
			return minValue;
		}
		
		if (value > maxValue)
		{
			return maxValue;
		}
		
		return value;
	}
	
	void ApplyAttachmentModifiers(Weapon_Base weapon, AJGunplayConfig config)
	{
		if (!weapon) return;
		
		ApplyTieredAttachmentModifier(weapon, config, m_ButtstockSlots, "Stock", "Stock_T1");
		ApplyTieredAttachmentModifier(weapon, config, m_PistolGripSlots, "Pistol Grip", "PistolGrip_T1");
		ApplyTieredAttachmentModifier(weapon, config, m_ForegripSlots, "Foregrip", "Foregrip_T1");
		ApplyTieredAttachmentModifier(weapon, config, m_HandguardSlots, "Handguard", "Handguard_T1");
		ApplyTieredAttachmentModifier(weapon, config, m_BipodSlots, "Bipod", "Bipod_Special");
		ApplyOpticModifiers(weapon, config);
		ApplyMuzzleModifiers(weapon, config);
		ApplyTieredAttachmentModifier(weapon, config, m_WrapSlots, "Wrap", "WeaponWrap_Utility");
		ApplyTieredAttachmentModifier(weapon, config, m_LaserSlots, "Laser", "Laser_Tactical");
		ApplyTieredAttachmentModifier(weapon, config, m_FlashlightSlots, "Flashlight", "Flashlight_Utility");
		ApplyTieredAttachmentModifier(weapon, config, m_BayonetSlots, "Bayonet", "Bayonet_Heavy");
		ApplyMagazineModifiers(weapon, config);
	}
	
	void ApplyTieredAttachmentModifier(Weapon_Base weapon, AJGunplayConfig config, TStringArray slots, string category, string fallbackTier)
	{
		foreach (string slot : slots)
		{
			EntityAI attachment = weapon.FindAttachmentBySlotName(slot);
			if (!attachment) continue;
			
			string attachmentType = attachment.GetType();
			string tierKey = config.GetAttachmentTier(attachmentType, fallbackTier);
			AJTierEffect effect = config.GetTierEffect(tierKey);
			
			ApplyTierEffect(effect);
			AddAttachmentEffectLine(effect.Category, attachmentType, tierKey, effect);
			
			if (config.DebugMode)
			{
				Print("[AJ Gunplay] " + category + " " + attachmentType + " -> " + tierKey);
			}
			
			break;
		}
	}
	
	void ApplyMuzzleModifiers(Weapon_Base weapon, AJGunplayConfig config)
	{
		foreach (string slot : m_MuzzleSlots)
		{
			EntityAI attachment = weapon.FindAttachmentBySlotName(slot);
			if (!attachment) continue;
			
			string attachmentType = attachment.GetType();
			string fallbackTier = GetMuzzleFallbackTier(slot, attachmentType);
			string tierKey = config.GetAttachmentTier(attachmentType, fallbackTier);
			AJTierEffect effect = config.GetTierEffect(tierKey);
			
			ApplyTierEffect(effect);
			AddAttachmentEffectLine(effect.Category, attachmentType, tierKey, effect);
			
			if (config.DebugMode)
			{
				Print("[AJ Gunplay] Muzzle " + attachmentType + " -> " + tierKey);
			}
			
			break;
		}
	}
	
	string GetMuzzleFallbackTier(string slot, string attachmentType)
	{
		if (slot == "pistolMuzzle" || slot == "suppressorImpro")
		{
			return "Suppressor_T1";
		}
		
		if (attachmentType.Contains("Suppressor") || attachmentType.Contains("Silencer"))
		{
			return "Suppressor_T1";
		}
		
		return "Muzzle_T1";
	}
	
	void ApplyTierEffect(AJTierEffect effect)
	{
		if (!effect) return;
		
		m_CurrentRecoil *= effect.Recoil;
		m_CurrentSway *= effect.Sway;
		m_CurrentAimSpeed *= effect.ADS;
		m_CurrentPrecision *= effect.Precision;
		m_HipFireSpreadModifier *= effect.HipFire;
	}
	
	void ApplyOpticModifiers(Weapon_Base weapon, AJGunplayConfig config)
	{
		foreach (string slot : m_OpticSlots)
		{
			EntityAI optic = weapon.FindAttachmentBySlotName(slot);
			if (!optic) continue;
			
			string opticType = optic.GetType();
			string fallbackTier = "LightOptic_T1";
			if (IsSniperScope(opticType))
				fallbackTier = "SniperOptic_T3";
			else if (IsHeavyScope(opticType))
				fallbackTier = "HeavyOptic_T2";
			string tierKey = config.GetAttachmentTier(opticType, fallbackTier);
			AJTierEffect effect = config.GetTierEffect(tierKey);
			
			ApplyTierEffect(effect);
			AddAttachmentEffectLine("Optic", opticType, tierKey, effect);
			break;
		}
	}
	
	bool IsHeavyScope(string opticType)
	{
		foreach (string heavyScope : m_HeavyScopes)
		{
			if (opticType == heavyScope) return true;
		}
		
		return false;
	}
	
	bool IsSniperScope(string opticType)
	{
		foreach (string sniperScope : m_SniperScopes)
		{
			if (opticType == sniperScope) return true;
		}
		
		return false;
	}
	
	void ApplyMagazineModifiers(Weapon_Base weapon, AJGunplayConfig config)
	{
		foreach (string slot : m_MagazineSlots)
		{
			EntityAI mag = weapon.FindAttachmentBySlotName(slot);
			if (!mag) continue;
			
			int maxAmmo = GetMagazineMaxAmmo(mag);
			string tierKey = config.GetAttachmentTier(mag.GetType(), "StandardMag_Neutral");
			if (maxAmmo > config.HighCapMagazineThreshold)
			{
				tierKey = config.GetAttachmentTier(mag.GetType(), "HighCap_Heavy");
			}
			
			AJTierEffect effect = config.GetTierEffect(tierKey);
			ApplyTierEffect(effect);
			AddAttachmentEffectLine("Magazine", mag.GetType() + " " + maxAmmo + "rnd", tierKey, effect);
			
			break;
		}
	}
	
	int GetMagazineMaxAmmo(EntityAI mag)
	{
		if (!mag) return 0;
		
		int configCount = GetGame().ConfigGetInt("CfgMagazines " + mag.GetType() + " count");
		if (configCount > 0) return configCount;
		
		return 0;
	}
	
	void AddAttachmentEffectLine(string category, string attachmentType, string tierKey, AJTierEffect effect)
	{
		if (!effect) return;
		
		string line = category + ": " + effect.Tier + " (" + attachmentType + ")";
		string effects = "";
		
		effects += FormatEffect("Recoil", effect.Recoil, false);
		effects += FormatEffect("Sway", effect.Sway, false);
		effects += FormatEffect("ADS", effect.ADS, true);
		effects += FormatEffect("Precision", effect.Precision, true);
		effects += FormatEffect("HipFire", effect.HipFire, false);
		
		if (effects != "")
		{
			line += " " + effects;
			m_AttachmentEffectLines.Insert(line);
		}
	}
	
	string FormatEffect(string label, float multiplier, bool higherIsBetter)
	{
		if (Math.AbsFloat(multiplier - 1.0) < 0.001) return "";
		
		float delta = (multiplier - 1.0) * 100.0;
		int rounded = Math.Round(delta);
		
		if (rounded > 0)
		{
			return label + " +" + rounded + "% ";
		}
		
		return label + " " + rounded + "% ";
	}
	
	float GetCurrentRecoil() { return m_CurrentRecoil; }
	float GetCurrentSway() { return m_CurrentSway; }
	float GetCurrentAimSpeed() { return m_CurrentAimSpeed; }
	float GetCurrentPrecision() { return m_CurrentPrecision; }
	float GetAJHipFireSpreadModifier() { return m_HipFireSpreadModifier; }
	float GetBaseRecoil() { return m_BaseRecoil; }
	float GetBaseSway() { return m_BaseSway; }
	float GetBaseAimSpeed() { return m_BaseAimSpeed; }
	float GetBasePrecision() { return m_BasePrecision; }
	TStringArray GetAttachmentEffectLines() { return m_AttachmentEffectLines; }
	
	string GetStatsString()
	{
		string stats = "\n=== AJ Gunplay Stats (Tiered Hardcoded) ===\n";
		stats += "Recoil: " + Math.Round(m_CurrentRecoil * 100) / 100 + " (Base: " + Math.Round(m_BaseRecoil * 100) / 100 + ")\n";
		stats += "Sway: " + Math.Round(m_CurrentSway * 1000) / 1000 + " (Base: " + Math.Round(m_BaseSway * 1000) / 1000 + ")\n";
		stats += "Aim Speed: " + Math.Round(m_CurrentAimSpeed * 100) + "% (Base: " + Math.Round(m_BaseAimSpeed * 100) + "%)\n";
		stats += "Precision: " + Math.Round(m_CurrentPrecision * 100) + "% (Base: " + Math.Round(m_BasePrecision * 100) + "%)\n";
		stats += "Hip-Fire Spread: " + Math.Round(m_HipFireSpreadModifier * 100) + "%\n";
		
		foreach (string line : m_AttachmentEffectLines)
		{
			stats += "- " + line + "\n";
		}
		
		stats += "==========================================\n";
		return stats;
	}
}
