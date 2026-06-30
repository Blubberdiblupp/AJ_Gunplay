class AJTierEffect
{
	string Category;
	string Tier;
	float Recoil;
	float Sway;
	float ADS;
	float Precision;
	float HipFire;
	
	void AJTierEffect(string category = "Neutral", string tier = "Neutral", float recoil = 1.0, float sway = 1.0, float ads = 1.0, float precision = 1.0, float hipFire = 1.0)
	{
		Category = category;
		Tier = tier;
		Recoil = recoil;
		Sway = sway;
		ADS = ads;
		Precision = precision;
		HipFire = hipFire;
	}
	
	string GetLabel()
	{
		return Category + " " + Tier;
	}
}

class AJGunplayConfig
{
	static ref AJGunplayConfig m_Instance;
	
	float GlobalRecoilMultiplier;
	float GlobalSwayMultiplier;
	float GlobalAimSpeedMultiplier;
	float GlobalHipFireMultiplier;
	float GlobalPrecisionMultiplier;
	bool EnableHipFireNerf;
	bool EnableWeaponGeometryDamage;
	float GripRecoilReduction;
	float GripSwayReduction;
	float HeavyScopeAimSpeedPenalty;
	float LightScopeAimSpeedPenalty;
	float HipFireAccuracyDegradation;
	bool DebugMode;
	
	int HighCapMagazineThreshold;
	
	float Modifier_Buttstock_Recoil;
	float Modifier_Buttstock_Sway;
	float Modifier_PistolGrip_Recoil;
	float Modifier_PistolGrip_ADS;
	float Modifier_Foregrip_Recoil;
	float Modifier_Foregrip_ADS;
	float Modifier_Handguard_Sway;
	float Modifier_Handguard_Precision;
	float Modifier_Bipod_Sway;
	float Modifier_Bipod_ADS;
	float Modifier_Laser_HipFire;
	float Modifier_Flashlight_Sway;
	float Modifier_Flashlight_ADS;
	float Modifier_Bayonet_Sway;
	float Modifier_Bayonet_ADS;
	float Modifier_HighCapMag_ADS;
	float Modifier_HighCapMag_Sway;
	
	ref map<string, string> AttachmentTiers;
	ref map<string, ref AJTierEffect> AttachmentTierEffects;
	
	static AJGunplayConfig GetInstance()
	{
		if (!m_Instance)
		{
			m_Instance = new AJGunplayConfig();
			m_Instance.Init();
		}
		return m_Instance;
	}
	
	void Init()
	{
		AttachmentTiers = new map<string, string>;
		AttachmentTierEffects = new map<string, ref AJTierEffect>;
		
		ApplyDefaultValues();
		Print("[AJ Gunplay] Hardcoded gunplay config loaded");
	}
	
	void ApplyDefaultValues()
	{
		GlobalRecoilMultiplier = 1.08;
		GlobalSwayMultiplier = 1.08;
		GlobalAimSpeedMultiplier = 0.95;
		GlobalHipFireMultiplier = 1.0;
		GlobalPrecisionMultiplier = 1.0;
		EnableHipFireNerf = true;
		EnableWeaponGeometryDamage = true;
		GripRecoilReduction = 0.30;
		GripSwayReduction = 0.30;
		HeavyScopeAimSpeedPenalty = 0.3;
		LightScopeAimSpeedPenalty = 0.1;
		HipFireAccuracyDegradation = 0.65;
		DebugMode = false;
		
		HighCapMagazineThreshold = 30;
		
		Modifier_Buttstock_Recoil = 0.10;
		Modifier_Buttstock_Sway = 0.55;
		Modifier_PistolGrip_Recoil = 0.55;
		Modifier_PistolGrip_ADS = 1.10;
		Modifier_Foregrip_Recoil = 0.40;
		Modifier_Foregrip_ADS = 1.10;
		Modifier_Handguard_Sway = 0.70;
		Modifier_Handguard_Precision = 1.20;
		Modifier_Bipod_Sway = 0.40;
		Modifier_Bipod_ADS = 0.85;
		Modifier_Laser_HipFire = 0.50;
		Modifier_Flashlight_Sway = 1.03;
		Modifier_Flashlight_ADS = 0.96;
		Modifier_Bayonet_Sway = 1.06;
		Modifier_Bayonet_ADS = 0.94;
		Modifier_HighCapMag_ADS = 0.98;
		Modifier_HighCapMag_Sway = 1.03;
		
		InitDefaultTierEffects();
		InitDefaultAttachmentTiers();
		ApplyAdminConfig(AJGetAdminConfig());
	}
	
	void InitDefaultTierEffects()
	{
		AttachmentTierEffects.Clear();
		
		SetTierEffect("Foregrip_T1", "Foregrip", "T1", 0.70, 0.925, 1.03, 1.05, 0.90);
		SetTierEffect("Foregrip_T2", "Foregrip", "T2", 0.40, 0.85, 1.06, 1.10, 0.80);
		SetTierEffect("Foregrip_T3", "Foregrip", "T3", 0.10, 0.775, 1.08, 1.15, 0.70);
		
		SetTierEffect("PistolGrip_T1", "Pistol Grip", "T1", 0.70, 1.00, 1.05, 1.00, 0.90);
		SetTierEffect("PistolGrip_T2", "Pistol Grip", "T2", 0.40, 0.97, 1.10, 1.02, 0.80);
		SetTierEffect("PistolGrip_T3", "Pistol Grip", "T3", 0.10, 0.94, 1.15, 1.04, 0.70);
		
		SetTierEffect("Stock_T1", "Stock", "T1", 0.70, 0.85, 1.00, 1.05, 1.00);
		SetTierEffect("Stock_T2", "Stock", "T2", 0.40, 0.70, 0.99, 1.10, 1.00);
		SetTierEffect("Stock_T3", "Stock", "T3", 0.10, 0.55, 0.98, 1.15, 1.00);
		
		SetTierEffect("Handguard_T1", "Handguard", "T1", 1.00, 0.85, 1.02, 1.10, 0.90);
		SetTierEffect("Handguard_T2", "Handguard", "T2", 0.94, 0.70, 1.04, 1.20, 0.80);
		SetTierEffect("Handguard_T3", "Handguard", "T3", 0.88, 0.55, 1.06, 1.30, 0.70);
		
		SetTierEffect("Bipod_Special", "Bipod", "Special", 0.70, 0.43, 0.86, 1.16, 1.00);
		SetTierEffect("LightOptic_T1", "Optic", "T1", 1.00, 0.985, 1.05, 1.10, 1.00);
		SetTierEffect("HeavyOptic_T2", "Optic", "T2", 1.00, 0.97, 0.95, 1.20, 1.00);
		SetTierEffect("SniperOptic_T3", "Optic", "T3", 1.00, 0.955, 0.85, 1.30, 1.00);
		SetTierEffect("Laser_Tactical", "Laser", "Tactical", 1.00, 1.00, 1.00, 1.00, 0.55);
		SetTierEffect("Flashlight_Utility", "Flashlight", "Utility", 1.00, 1.04, 0.96, 1.00, 1.00);
		SetTierEffect("Bayonet_Heavy", "Bayonet", "Heavy", 1.00, 1.08, 0.92, 1.00, 1.00);
		SetTierEffect("Muzzle_T1", "Muzzle", "T1", 0.85, 0.925, 1.00, 1.05, 0.95);
		SetTierEffect("Muzzle_T2", "Muzzle", "T2", 0.70, 0.85, 0.99, 1.10, 0.90);
		SetTierEffect("Muzzle_T3", "Muzzle", "T3", 0.55, 0.775, 0.98, 1.15, 0.85);
		SetTierEffect("Suppressor_T1", "Suppressor", "T1", 0.85, 1.00, 0.98, 1.05, 0.95);
		SetTierEffect("Suppressor_T2", "Suppressor", "T2", 0.70, 1.01, 0.96, 1.10, 0.90);
		SetTierEffect("Suppressor_T3", "Suppressor", "T3", 0.55, 1.02, 0.94, 1.15, 0.85);
		SetTierEffect("WeaponWrap_Utility", "Wrap", "Utility", 1.00, 0.925, 0.97, 1.03, 1.00);
		SetTierEffect("StandardMag_Neutral", "Magazine", "Standard", 1.00, 1.00, 1.00, 1.00, 1.00);
		SetTierEffect("HighCap_Heavy", "Magazine", "HighCap", 1.02, 1.03, 0.98, 1.00, 1.00);
		SetTierEffect("Neutral", "Neutral", "Neutral", 1.00, 1.00, 1.00, 1.00, 1.00);
	}
	
	void InitDefaultAttachmentTiers()
	{
		AttachmentTiers.Clear();
		
		SetAttachmentTier("FGRIP", "Foregrip_T1");
		SetAttachmentTier("AJar15afg", "Foregrip_T2");
		SetAttachmentTier("weaponGripCQR", "Foregrip_T2");
		SetAttachmentTier("weaponGripKAAR", "Foregrip_T3");
		SetAttachmentTier("AJ_M249Grip", "Foregrip_T2");
		SetAttachmentTier("AJSR3Grip", "Foregrip_T2");
		SetAttachmentTier("weaponrgripAJ", "Foregrip_T2");
		
		SetAttachmentTier("weaponGrip", "PistolGrip_T1");
		SetAttachmentTier("weaponGripAK", "PistolGrip_T2");
		SetAttachmentTier("weaponPistolGrip", "PistolGrip_T2");
		SetAttachmentTier("AJMPXGRIP", "PistolGrip_T2");
		
		SetAttachmentTier("AJ_M249Stock", "Stock_T2");
		SetAttachmentTier("AJ_M200Stock", "Stock_T3");
		SetAttachmentTier("AJ_AK_AR_Stock", "Stock_T2");
		SetAttachmentTier("AJ_AK19_Stock", "Stock_T2");
		SetAttachmentTier("M4_OEBttstck", "Stock_T1");
		SetAttachmentTier("M4_MPBttstck", "Stock_T2");
		SetAttachmentTier("M4_CQBBttstck", "Stock_T3");
		SetAttachmentTier("AK_WoodBttstck", "Stock_T1");
		SetAttachmentTier("AK74_WoodBttstck", "Stock_T1");
		SetAttachmentTier("AK_PlasticBttstck", "Stock_T2");
		SetAttachmentTier("AK_FoldingBttstck", "Stock_T2");
		SetAttachmentTier("AKS74U_Bttstck", "Stock_T2");
		SetAttachmentTier("MP5k_StockBttstck", "Stock_T2");
		SetAttachmentTier("Red9Bttstck", "Stock_T1");
		SetAttachmentTier("Fal_OeBttstck", "Stock_T2");
		SetAttachmentTier("Fal_FoldingBttstck", "Stock_T3");
		SetAttachmentTier("Saiga_Bttstck", "Stock_T2");
		SetAttachmentTier("PP19_Bttstck", "Stock_T2");
		SetAttachmentTier("AJWSR3Stock", "Stock_T2");
		
		SetAttachmentTier("AJ_M249HG", "Handguard_T2");
		SetAttachmentTier("AJM60Handguard", "Handguard_T2");
		SetAttachmentTier("AJSR3HG", "Handguard_T2");
		SetAttachmentTier("HandguardRIS", "Handguard_T2");
		SetAttachmentTier("M4_OEBHandGuard", "Handguard_T1");
		SetAttachmentTier("M4_MOLLEHandGuard", "Handguard_T2");
		SetAttachmentTier("M4_PlasticHndgrd", "Handguard_T1");
		SetAttachmentTier("M4_RISHndgrd", "Handguard_T2");
		SetAttachmentTier("M4_MPHndgrd", "Handguard_T2");
		SetAttachmentTier("AK_WoodHndgrd", "Handguard_T1");
		SetAttachmentTier("AK74_Hndgrd", "Handguard_T1");
		SetAttachmentTier("AK_PlasticHndgrd", "Handguard_T2");
		SetAttachmentTier("AK_RailHndgrd", "Handguard_T3");
		SetAttachmentTier("MP5_PlasticHndgrd", "Handguard_T1");
		SetAttachmentTier("MP5_RailHndgrd", "Handguard_T2");
		SetAttachmentTier("M249_Hndgrd", "Handguard_T1");
		SetAttachmentTier("M249_RisHndgrd", "Handguard_T2");
		SetAttachmentTier("weaponHGAJ10", "Handguard_T2");
		SetAttachmentTier("weaponHGAJ10NA", "Handguard_T2");
		SetAttachmentTier("weaponHGAJ14", "Handguard_T2");
		SetAttachmentTier("weaponHGAJ14NA", "Handguard_T2");
		SetAttachmentTier("weaponHGAJ16", "Handguard_T3");
		SetAttachmentTier("weaponHGAJ16NA", "Handguard_T3");
		
		SetAttachmentTier("AJweaponBipod", "Bipod_Special");
		SetAttachmentTier("AJ_M249Bipod", "Bipod_Special");
		SetAttachmentTier("AJ_M200B_BK", "Bipod_Special");
		SetAttachmentTier("AJ_M200Bipod_Base", "Bipod_Special");
		SetAttachmentTier("AJvsskBipod", "Bipod_Special");
		SetAttachmentTier("sr25bipod", "Bipod_Special");
		SetAttachmentTier("PKPBIPOD", "Bipod_Special");
		
		SetAttachmentTier("AJ_RDS", "LightOptic_T1");
		SetAttachmentTier("AJ_EOTech_EXPS3", "LightOptic_T1");
		SetAttachmentTier("AJ_Aimpoint_M5", "LightOptic_T1");
		SetAttachmentTier("AJ_Docter", "LightOptic_T1");
		SetAttachmentTier("AJ_Elcan", "LightOptic_T1");
		SetAttachmentTier("AJ_Hunting", "SniperOptic_T3");
		SetAttachmentTier("AJM60ScopeMount", "LightOptic_T1");
		SetAttachmentTier("AJ_Nightforce", "SniperOptic_T3");
		SetAttachmentTier("AJ_AKNightforce", "SniperOptic_T3");
		SetAttachmentTier("AJ_HNightforce", "SniperOptic_T3");
		SetAttachmentTier("AJ_MNightforce", "SniperOptic_T3");
		SetAttachmentTier("AJ_Tango6T", "HeavyOptic_T2");
		SetAttachmentTier("AJ_Tango6T_Black", "HeavyOptic_T2");
		SetAttachmentTier("AJ_Tango6T_Tan", "HeavyOptic_T2");
		SetAttachmentTier("AJ_Tango6T_Wood", "HeavyOptic_T2");
		SetAttachmentTier("AJ_Tango6T_Snow", "HeavyOptic_T2");
		SetAttachmentTier("AJ_AKTango6T_Black", "HeavyOptic_T2");
		SetAttachmentTier("AJ_AKTango6T_Tan", "HeavyOptic_T2");
		SetAttachmentTier("AJ_AKTango6T_Wood", "HeavyOptic_T2");
		SetAttachmentTier("AJ_AKTango6T_Snow", "HeavyOptic_T2");
		SetAttachmentTier("AJ_MTango6T_Black", "HeavyOptic_T2");
		SetAttachmentTier("AJ_MTango6T_Tan", "HeavyOptic_T2");
		SetAttachmentTier("AJ_MTango6T_Wood", "HeavyOptic_T2");
		SetAttachmentTier("AJ_MTango6T_Snow", "HeavyOptic_T2");
		SetAttachmentTier("AJ_Leupold_MK8", "HeavyOptic_T2");
		SetAttachmentTier("AJ_Leupold_Mark8", "HeavyOptic_T2");
		SetAttachmentTier("AJ_AKLeupold_Mark8", "HeavyOptic_T2");
		SetAttachmentTier("AJ_HLeupold_Mark8", "HeavyOptic_T2");
		SetAttachmentTier("AJ_MLeupold_Mark8", "HeavyOptic_T2");
		SetAttachmentTier("AJ_Kahles", "HeavyOptic_T2");
		SetAttachmentTier("AJ_AKKahles", "HeavyOptic_T2");
		SetAttachmentTier("AJ_HKahles", "HeavyOptic_T2");
		SetAttachmentTier("AJ_MKahles", "HeavyOptic_T2");
		SetAttachmentTier("AJ_Walther", "HeavyOptic_T2");
		SetAttachmentTier("AJ_AKWalther", "HeavyOptic_T2");
		SetAttachmentTier("AJ_HWalther", "HeavyOptic_T2");
		SetAttachmentTier("AJ_MWalther", "HeavyOptic_T2");
		SetAttachmentTier("GCGN_M84_Optic", "HeavyOptic_T2");
		SetAttachmentTier("AJ_AKHuntingOptic", "SniperOptic_T3");
		SetAttachmentTier("AJ_HHuntingOptic", "SniperOptic_T3");
		SetAttachmentTier("AJ_HuntingOptic", "SniperOptic_T3");
		SetAttachmentTier("AJ_M14Optic", "HeavyOptic_T2");
		SetAttachmentTier("AJ_MHuntingOptic", "SniperOptic_T3");
		SetAttachmentTier("M4_CarryHandleOptic", "LightOptic_T1");
		SetAttachmentTier("BUISOptic", "LightOptic_T1");
		SetAttachmentTier("M68Optic", "LightOptic_T1");
		SetAttachmentTier("M4_T3NRDSOptic", "LightOptic_T1");
		SetAttachmentTier("FNP45_MRDSOptic", "LightOptic_T1");
		SetAttachmentTier("ReflexOptic", "LightOptic_T1");
		SetAttachmentTier("KobraOptic", "LightOptic_T1");
		SetAttachmentTier("PistolOptic", "LightOptic_T1");
		SetAttachmentTier("SportingOptic", "LightOptic_T1");
		SetAttachmentTier("ACOGOptic", "HeavyOptic_T2");
		SetAttachmentTier("ACOGOptic_6x", "HeavyOptic_T2");
		SetAttachmentTier("PSO1Optic", "HeavyOptic_T2");
		SetAttachmentTier("PSO11Optic", "HeavyOptic_T2");
		SetAttachmentTier("PSO6Optic", "HeavyOptic_T2");
		SetAttachmentTier("GrozaOptic", "HeavyOptic_T2");
		SetAttachmentTier("KashtanOptic", "LightOptic_T1");
		SetAttachmentTier("PUScopeOptic", "HeavyOptic_T2");
		SetAttachmentTier("LongrangeOptic", "SniperOptic_T3");
		SetAttachmentTier("HuntingOptic", "SniperOptic_T3");
		SetAttachmentTier("MK4Optic_ColorBase", "HeavyOptic_T2");
		SetAttachmentTier("MK4Optic_Tan", "HeavyOptic_T2");
		SetAttachmentTier("MK4Optic_Green", "HeavyOptic_T2");
		SetAttachmentTier("MK4Optic_Black", "HeavyOptic_T2");
		SetAttachmentTier("KazuarOptic", "HeavyOptic_T2");
		SetAttachmentTier("StarlightOptic", "HeavyOptic_T2");
		SetAttachmentTier("ExpansionDeltapointOptic", "LightOptic_T1");
		SetAttachmentTier("ExpansionEXPS3HoloOptic", "LightOptic_T1");
		SetAttachmentTier("ExpansionHAMROptic", "HeavyOptic_T2");
		SetAttachmentTier("ExpansionKar98ScopeOptic", "SniperOptic_T3");
		SetAttachmentTier("Expansion_PMII25Optic", "SniperOptic_T3");
		SetAttachmentTier("ExpansionReflexMRSOptic", "LightOptic_T1");
		SetAttachmentTier("Expansion_M1A_RailAtt", "Handguard_T1");
		SetAttachmentTier("Expansion_MP5_RailAtt", "Handguard_T1");
		SetAttachmentTier("AJW_Optic_MicroT2_Black", "LightOptic_T1");
		SetAttachmentTier("AJW_Optic_MicroT2_FDE", "LightOptic_T1");
		SetAttachmentTier("AJW_Optic_MicroT2_Unity_Black", "LightOptic_T1");
		SetAttachmentTier("AJW_Optic_MicroT2_Unity_FDE", "LightOptic_T1");
		SetAttachmentTier("AJW_Optic_HydraT2_Black", "LightOptic_T1");
		SetAttachmentTier("AJW_Optic_HydraT2_FDE", "LightOptic_T1");
		SetAttachmentTier("AJW_Optic_HydraXps_Black", "LightOptic_T1");
		SetAttachmentTier("AJW_Optic_HydraXps_FDE", "LightOptic_T1");
		SetAttachmentTier("AJW_Optic_EOTech_EXPS3_Black", "LightOptic_T1");
		SetAttachmentTier("AJW_Optic_EOTech_EXPS3_FDE", "LightOptic_T1");
		SetAttachmentTier("AJW_Optic_EOTech_EXPS3_TwoTone", "LightOptic_T1");
		SetAttachmentTier("AJW_Optic_EOTech_EXPS3_Black_Wojack", "LightOptic_T1");
		SetAttachmentTier("AJW_Optic_SRO_Black", "LightOptic_T1");
		SetAttachmentTier("AJW_Optic_StrikeFire_Black", "LightOptic_T1");
		SetAttachmentTier("AJW_Optic_StrikeFire_FDE", "LightOptic_T1");
		SetAttachmentTier("AJW_Optic_OKP7", "LightOptic_T1");
		SetAttachmentTier("AJW_BD_Car15_Optic", "LightOptic_T1");
		SetAttachmentTier("AJW_Magnifier_G33", "LightOptic_T1");
		SetAttachmentTier("AJW_Magnifier_G43", "LightOptic_T1");
		SetAttachmentTier("AJW_Magnifier_Aimpoint3x_UnityTall", "LightOptic_T1");
		SetAttachmentTier("AJW_Optic_ACOG_Chevron", "HeavyOptic_T2");
		SetAttachmentTier("AJW_Optic_ACOG_Horseshoe", "HeavyOptic_T2");
		SetAttachmentTier("AJW_Optic_ACOG_ACSS", "HeavyOptic_T2");
		SetAttachmentTier("AJW_Optic_Accupower", "HeavyOptic_T2");
		SetAttachmentTier("AJW_Optic_EoTechVudu", "HeavyOptic_T2");
		SetAttachmentTier("AJW_Optic_Vortex", "HeavyOptic_T2");
		SetAttachmentTier("AJW_Optic_ELCAN_Black", "HeavyOptic_T2");
		SetAttachmentTier("AJW_Optic_ELCAN_FDE", "HeavyOptic_T2");
		SetAttachmentTier("AJW_Optic_HAMR", "HeavyOptic_T2");
		SetAttachmentTier("AJW_Optic_LeupoldHoloDEVO", "HeavyOptic_T2");
		SetAttachmentTier("AJW_Optic_Leupold_M3A", "SniperOptic_T3");
		SetAttachmentTier("AJW_Optic_K98", "SniperOptic_T3");
		
		SetAttachmentTier("AJW_NGAL_Green", "Laser_Tactical");
		SetAttachmentTier("AJW_NGAL_Red", "Laser_Tactical");
		SetAttachmentTier("AJW_DBAL_Tan_Green", "Laser_Tactical");
		SetAttachmentTier("AJW_DBAL_Tan_Red", "Laser_Tactical");
		SetAttachmentTier("AJW_DBAL_Black_Green", "Laser_Tactical");
		SetAttachmentTier("AJW_DBAL_Black_Red", "Laser_Tactical");
		SetAttachmentTier("AJW_PEQ15_Tan_Green", "Laser_Tactical");
		SetAttachmentTier("AJW_PEQ15_Tan_Red", "Laser_Tactical");
		SetAttachmentTier("AJW_PEQ15_Black_Green", "Laser_Tactical");
		SetAttachmentTier("AJW_PEQ15_Black_Red", "Laser_Tactical");
		SetAttachmentTier("AJW_MAWL_Tan_Green", "Laser_Tactical");
		SetAttachmentTier("AJW_MAWL_Tan_Red", "Laser_Tactical");
		SetAttachmentTier("AJW_MAWL_Black_Green", "Laser_Tactical");
		SetAttachmentTier("AJW_MAWL_Black_Red", "Laser_Tactical");
		
		SetAttachmentTier("AJW_MOE_FG_Black", "Foregrip_T1");
		SetAttachmentTier("AJW_MOE_FG_FDE", "Foregrip_T1");
		SetAttachmentTier("AJW_AFG_FG_Black", "Foregrip_T2");
		SetAttachmentTier("AJW_AFG_FG_FDE", "Foregrip_T2");
		SetAttachmentTier("AJW_AFG2_FG_Black", "Foregrip_T2");
		SetAttachmentTier("AJW_AFG2_FG_FDE", "Foregrip_T2");
		SetAttachmentTier("AJW_Cobra_FG_Black", "Foregrip_T3");
		SetAttachmentTier("AJW_CQR_FG_Black", "Foregrip_T3");
		SetAttachmentTier("AJW_HK_FG_Black", "Foregrip_T3");
		SetAttachmentTier("AJW_HK_FG_FDE", "Foregrip_T3");
		SetAttachmentTier("AJW_Stark_FG_Black", "Foregrip_T3");
		
		SetAttachmentTier("AJW_AK_PG_MOE_Black", "PistolGrip_T1");
		SetAttachmentTier("AJW_AK_PG_MOE_Grey", "PistolGrip_T1");
		SetAttachmentTier("AJW_AK_PG_MOE_FDE", "PistolGrip_T1");
		SetAttachmentTier("AJW_AK_PG_MOE_OD", "PistolGrip_T1");
		SetAttachmentTier("AJW_AK_PG_AK12_Black", "PistolGrip_T2");
		SetAttachmentTier("AJW_AK_PG_AK12_Camo", "PistolGrip_T2");
		SetAttachmentTier("AJW_AK_PG_AK12_FDE", "PistolGrip_T2");
		SetAttachmentTier("AJW_AK_PG_MG47_Black", "PistolGrip_T2");
		SetAttachmentTier("AJW_AK_PG_MG47_FDE", "PistolGrip_T2");
		SetAttachmentTier("AJW_AK_PG_MG47_Red", "PistolGrip_T2");
		SetAttachmentTier("AJW_AK_PG_MG47_Brass", "PistolGrip_T2");
		SetAttachmentTier("AJW_AK_PG_MG47_Anared", "PistolGrip_T2");
		SetAttachmentTier("AJW_AK_PG_RK3_Black", "PistolGrip_T3");
		SetAttachmentTier("AJW_AK_PG_RK3_FDE", "PistolGrip_T3");
		SetAttachmentTier("AJW_AK_PG_Scorpius_Grey", "PistolGrip_T3");
		SetAttachmentTier("AJW_AK_PG_SI_Black", "PistolGrip_T3");
		SetAttachmentTier("AJW_AK_PG_SI_FDE", "PistolGrip_T3");
		SetAttachmentTier("AJW_AK_PG_TD_Black", "PistolGrip_T1");
		SetAttachmentTier("AJW_AK_PG_TD_FDE", "PistolGrip_T1");
		SetAttachmentTier("AJW_M4_Skele_PGrip", "PistolGrip_T3");
		SetAttachmentTier("AJW_M4_PG_BCM_Black", "PistolGrip_T2");
		SetAttachmentTier("AJW_M4_PG_BCM_FDE", "PistolGrip_T2");
		SetAttachmentTier("AJW_M4_PG_DD_Black", "PistolGrip_T2");
		SetAttachmentTier("AJW_M4_PG_DD_FDE", "PistolGrip_T2");
		SetAttachmentTier("AJW_M4_PG_F1_Black", "PistolGrip_T3");
		SetAttachmentTier("AJW_M4_PG_F1_Yellow", "PistolGrip_T3");
		SetAttachmentTier("AJW_M4_PG_F1_Cyan", "PistolGrip_T3");
		SetAttachmentTier("AJW_M4_PG_F1_OD", "PistolGrip_T3");
		SetAttachmentTier("AJW_M4_PG_F1_Pink", "PistolGrip_T3");
		SetAttachmentTier("AJW_M4_PG_F1_Red", "PistolGrip_T3");
		SetAttachmentTier("AJW_M4_PG_Hogue_Black", "PistolGrip_T1");
		SetAttachmentTier("AJW_M4_PG_Hogue_FDE", "PistolGrip_T1");
		SetAttachmentTier("AJW_M4_PG_MOE_Black", "PistolGrip_T1");
		SetAttachmentTier("AJW_M4_PG_MOE_FDE", "PistolGrip_T1");
		SetAttachmentTier("AJW_M4_PG_HKERGO", "PistolGrip_T2");
		SetAttachmentTier("AJW_M4_PG_HK_Black", "PistolGrip_T2");
		SetAttachmentTier("AJW_M4_PG_HK_FDE", "PistolGrip_T2");
		SetAttachmentTier("AJW_M4_PG_MOEK2_Black", "PistolGrip_T2");
		SetAttachmentTier("AJW_M4_PG_MOEK2_FDE", "PistolGrip_T2");
		SetAttachmentTier("AJW_M4_PG_TD_Black", "PistolGrip_T1");
		SetAttachmentTier("AJW_M4_PG_TD_FDE", "PistolGrip_T1");
		SetAttachmentTier("AJW_M4_PG_TD_Red", "PistolGrip_T1");
		
		SetAttachmentTier("AJW_M4_CH_Aero", "Handguard_T1");
		SetAttachmentTier("AJW_M4_CH_Aero_Black", "Handguard_T1");
		SetAttachmentTier("AJW_M4_CH_Aero_ANred", "Handguard_T1");
		SetAttachmentTier("AJW_M4_CH_Aero_Gold", "Handguard_T1");
		SetAttachmentTier("AJW_Vityaz_DC_SN_Black", "Handguard_T1");
		SetAttachmentTier("AJW_Vityaz_DC_SN_FDE", "Handguard_T1");
		SetAttachmentTier("AJW_AK_DC_B33_Black", "Handguard_T1");
		SetAttachmentTier("AJW_AK_DC_B33_FDE", "Handguard_T1");
		SetAttachmentTier("AJW_74U_PDC_DC", "Handguard_T1");
		SetAttachmentTier("AJW_HK_HG_STD_Quad_Grey", "Handguard_T2");
		SetAttachmentTier("AJW_HK_HG_STD_Quad_Black", "Handguard_T2");
		SetAttachmentTier("AJW_HK_HG_STD_Quad_FDE", "Handguard_T2");
		SetAttachmentTier("AJW_HK_Geissele_HG10_Black", "Handguard_T2");
		SetAttachmentTier("AJW_HK_Geissele_HG10_Grey", "Handguard_T2");
		SetAttachmentTier("AJW_HK_Geissele_HG10_FDE", "Handguard_T2");
		SetAttachmentTier("AJW_HK_Geissele_HG10_Rose", "Handguard_T2");
		SetAttachmentTier("AJW_HK_Geissele_HG14_Grey", "Handguard_T3");
		SetAttachmentTier("AJW_HK_Geissele_HG14_FDE", "Handguard_T3");
		SetAttachmentTier("AJW_HK_Geissele_HG14_Rose", "Handguard_T3");
		SetAttachmentTier("AJW_HK_Geissele_HG14_Black", "Handguard_T3");
		SetAttachmentTier("AJW_M4_RISHndgrd", "Handguard_T2");
		SetAttachmentTier("AJW_M4_BlockII_Hndgrd", "Handguard_T3");
		SetAttachmentTier("AJW_M4_BlockII_HG_Black", "Handguard_T3");
		SetAttachmentTier("AJW_M4_BlockII_HG_FDE", "Handguard_T3");
		SetAttachmentTier("AJW_M4_BlockII_10_HG_Black", "Handguard_T2");
		SetAttachmentTier("AJW_M4_BlockII_10_HG_FDE", "Handguard_T2");
		SetAttachmentTier("AJW_M4_URX4_Hndgrd", "Handguard_T3");
		SetAttachmentTier("AJW_M4_URX4_HG_Black", "Handguard_T3");
		SetAttachmentTier("AJW_M4_URX4_HG_FDE", "Handguard_T3");
		SetAttachmentTier("AJW_M4_URX4_10_HG_Black", "Handguard_T2");
		SetAttachmentTier("AJW_M4_URX4_10_HG_FDE", "Handguard_T2");
		SetAttachmentTier("AJW_M4_LVOA_HG_Black", "Handguard_T3");
		SetAttachmentTier("AJW_M4_LVOA_HG_FDE", "Handguard_T3");
		SetAttachmentTier("AJW_M4_URGI_10_HG_Black", "Handguard_T2");
		SetAttachmentTier("AJW_M4_URGI_10_HG_FDE", "Handguard_T2");
		SetAttachmentTier("AJW_M4_Honey_Hndgrd", "Handguard_T2");
		SetAttachmentTier("AJW_M4_Honey_HG_Black", "Handguard_T2");
		SetAttachmentTier("AJW_M4_Honey_HG_FDE", "Handguard_T2");
		SetAttachmentTier("AJW_M4_Honey_HG_Badger", "Handguard_T2");
		SetAttachmentTier("AJW_MCX_STD_HG_Black", "Handguard_T2");
		SetAttachmentTier("AJW_MCX_STD_HG_FDE", "Handguard_T2");
		SetAttachmentTier("AJW_MCX_STD_HG_Grey", "Handguard_T2");
		SetAttachmentTier("AJW_MCX_LVAW_HG_Black", "Handguard_T3");
		SetAttachmentTier("AJW_MCX_LVAW_HG_FDE", "Handguard_T3");
		SetAttachmentTier("AJW_MCX_LT_HG_Black", "Handguard_T3");
		SetAttachmentTier("AJW_MCX_LT_HG_FDE", "Handguard_T3");
		SetAttachmentTier("AJW_MCX_LT_HG_OD", "Handguard_T3");
		SetAttachmentTier("AJW_MCX_LCH_HG_Black", "Handguard_T3");
		SetAttachmentTier("AJW_MCX_KM_HG_Black", "Handguard_T3");
		SetAttachmentTier("AJW_MCX_KM_HG_FDE", "Handguard_T3");
		SetAttachmentTier("AJW_MCX_KM_HG_OD", "Handguard_T3");
		SetAttachmentTier("AJW_MCX_KM_HG_AnaRed", "Handguard_T3");
		SetAttachmentTier("AJW_SCAR_MREX_HG_FDE", "Handguard_T3");
		SetAttachmentTier("AJW_SCAR_MREX_HG_Black", "Handguard_T3");
		SetAttachmentTier("AJW_SCAR_CASV_HG_FDE", "Handguard_T2");
		SetAttachmentTier("AJW_SCAR_CASV_HG_Black", "Handguard_T2");
		SetAttachmentTier("AJW_SCAR_PMM_HG_FDE", "Handguard_T3");
		SetAttachmentTier("AJW_SCAR_PMM_HG_Black", "Handguard_T3");
		SetAttachmentTier("AJW_AK_B30_HG_Black", "Handguard_T3");
		SetAttachmentTier("AJW_AK_B30_HG_FDE", "Handguard_T3");
		SetAttachmentTier("AJW_AK_Hexagon_HG_Black", "Handguard_T2");
		SetAttachmentTier("AJW_AK_Hexagon_HG_FDE", "Handguard_T2");
		SetAttachmentTier("AJW_AK_Hexagon_HG_Red", "Handguard_T2");
		SetAttachmentTier("AJW_AK_MagpulL_HG_Black", "Handguard_T2");
		SetAttachmentTier("AJW_AK_MagpulL_HG_FDE", "Handguard_T2");
		SetAttachmentTier("AJW_AK_CMRD_HG_Black", "Handguard_T3");
		SetAttachmentTier("AJW_AK_CMRD_HG_FDE", "Handguard_T3");
		SetAttachmentTier("AJW_AK_AK100_HG", "Handguard_T1");
		SetAttachmentTier("AJW_AK_B10_HG_Plastic", "Handguard_T1");
		SetAttachmentTier("AJW_AK_B19_HG_Black", "Handguard_T2");
		SetAttachmentTier("AJW_AK_B19_HG_FDE", "Handguard_T2");
		SetAttachmentTier("AJW_AK_MagpulS_HG_Black", "Handguard_T2");
		SetAttachmentTier("AJW_AK_MagpulS_HG_FDE", "Handguard_T2");
		SetAttachmentTier("AJW_AK_Shark_HG_Wood", "Handguard_T1");
		SetAttachmentTier("AJW_AK_SLR_HG_Black", "Handguard_T3");
		SetAttachmentTier("AJW_AK_Sport1_HG_Black", "Handguard_T3");
		SetAttachmentTier("AJW_AK_Sport1_HG_FDE", "Handguard_T3");
		SetAttachmentTier("AJW_AK_Troy_HG_Black", "Handguard_T2");
		SetAttachmentTier("AJW_AK_Troy_HG_FDE", "Handguard_T2");
		SetAttachmentTier("AJW_AK74U_HG_STD", "Handguard_T1");
		SetAttachmentTier("AJW_AK74U_HG_B11", "Handguard_T2");
		SetAttachmentTier("AJW_AK74U_HG_Goliaf_Black", "Handguard_T3");
		SetAttachmentTier("AJW_AK74U_HG_Goliaf_Copper", "Handguard_T3");
		SetAttachmentTier("AJW_AR10_URX_HG_Black", "Handguard_T3");
		SetAttachmentTier("AJW_AR10_URX_HG_FDE", "Handguard_T3");
		SetAttachmentTier("AJW_AR10_CCMG_HG_Black", "Handguard_T3");
		SetAttachmentTier("AJW_AR10_CCMG_HG_FDE", "Handguard_T3");
		SetAttachmentTier("AJW_AR10_SWS_N6_HG", "Handguard_T3");
		SetAttachmentTier("AJW_AR10_SWS_N6_10_HG", "Handguard_T2");
		SetAttachmentTier("AJW_SA58_STD_HG_Grey", "Handguard_T1");
		SetAttachmentTier("AJW_SA58_CASV_HG_Grey", "Handguard_T2");
		
		SetAttachmentTier("AJW_Bipod_Harris", "Bipod_Special");
		SetAttachmentTier("AJW_Surefire_Gunlight_Black", "Flashlight_Utility");
		SetAttachmentTier("AJW_Surefire_Gunlight_FDE", "Flashlight_Utility");
		SetAttachmentTier("AJW_Surefire_M600v_Gunlight_Black", "Flashlight_Utility");
		SetAttachmentTier("AJW_Surefire_M600v_Gunlight_FDE", "Flashlight_Utility");
		SetAttachmentTier("AJW_HKMk23SOCOM_LAM", "Laser_Tactical");
		SetAttachmentTier("AJW_M1897_Bayonet", "Bayonet_Heavy");
		
		SetAttachmentTier("AJW_12GA_MuzzleBreak", "Muzzle_T1");
		SetAttachmentTier("AJW_M4_MD_Noveske_Black", "Muzzle_T2");
		SetAttachmentTier("AJW_M4_MD_Noveske_FDE", "Muzzle_T2");
		SetAttachmentTier("AJW_AK74M_Comp", "Muzzle_T2");
		SetAttachmentTier("AJW_50cal_MD_M82_Black", "Muzzle_T3");
		SetAttachmentTier("AJW_50cal_MD_AK50_Black", "Muzzle_T3");
		SetAttachmentTier("AJW_SurefireRC2_Tan_Suppressor", "Suppressor_T2");
		SetAttachmentTier("AJW_SurefireRC2_Black_Suppressor", "Suppressor_T2");
		SetAttachmentTier("AJW_SurefireFA762K_Tan_Suppressor", "Suppressor_T2");
		SetAttachmentTier("AJW_SurefireFA762K_Black_Suppressor", "Suppressor_T2");
		SetAttachmentTier("AJW_HKG28_BTQD_Suppressor_Tan", "Suppressor_T3");
		SetAttachmentTier("AJW_HKG28_BTQD_Suppressor_Black", "Suppressor_T3");
		SetAttachmentTier("AJW_AACSDN_Suppressor_FDE", "Suppressor_T2");
		SetAttachmentTier("AJW_AACSDN_Suppressor_Black", "Suppressor_T2");
		SetAttachmentTier("AJW_Rotor43_Suppressor_Black", "Suppressor_T2");
		SetAttachmentTier("AJW_Rotor43_Suppressor_Rattle", "Suppressor_T2");
		SetAttachmentTier("AJW_Osprey_Suppressor_Black", "Suppressor_T2");
		SetAttachmentTier("AJW_Osprey_Suppressor_FDE", "Suppressor_T2");
		SetAttachmentTier("AJW_HKMk23SOCOM_Suppressor", "Suppressor_T2");
		SetAttachmentTier("AJW_QDSSNT4_Suppressor_Black", "Suppressor_T3");
		SetAttachmentTier("AJW_QDSSNT4_Suppressor_FDE", "Suppressor_T3");
		SetAttachmentTier("AJW_Gemtech_Suppressor_Black", "Suppressor_T2");
		SetAttachmentTier("AJW_Gemtech_Suppressor_FDE", "Suppressor_T2");
		SetAttachmentTier("AJW_DTK4_Suppressor_Black", "Suppressor_T2");
		SetAttachmentTier("AJW_DTK4_Suppressor_MC", "Suppressor_T2");
		SetAttachmentTier("AJW_DTKP_Suppressor_Black", "Suppressor_T2");
		SetAttachmentTier("AJW_DTKP_Suppressor_FDE", "Suppressor_T2");
		SetAttachmentTier("AJW_Hexagon_Suppressor_Black", "Suppressor_T2");
		SetAttachmentTier("AJW_PBS1_Suppressor", "Suppressor_T2");
		SetAttachmentTier("AJW_PBS4_Suppressor", "Suppressor_T2");
		SetAttachmentTier("AJW_50cal_Suppressor_Black", "Suppressor_T3");
		SetAttachmentTier("AJW_50cal_Suppressor_Tan", "Suppressor_T3");
		SetAttachmentTier("AJW_50cal_Suppressor_Wrapped_Black", "Suppressor_T3");
		SetAttachmentTier("AJW_50cal_Suppressor_Wrapped_RG", "Suppressor_T3");
		SetAttachmentTier("AJW_50cal_Suppressor_Wrapped_MC", "Suppressor_T3");
		SetAttachmentTier("AJW_50cal_Suppressor_Wrapped_Tan", "Suppressor_T3");
		SetAttachmentTier("AJW_50cal_Suppressor_Wrapped_TANMC", "Suppressor_T3");
		SetAttachmentTier("AJW_50cal_Suppressor_Long_Black", "Suppressor_T3");
		SetAttachmentTier("AJW_50cal_Suppressor_Long_Tan", "Suppressor_T3");
		SetAttachmentTier("AJW_50cal_Suppressor_QDL_Black", "Suppressor_T3");
		SetAttachmentTier("AJW_50cal_Suppressor_QDL_FDE", "Suppressor_T3");
		SetAttachmentTier("AJW_SLX_Suppressor_FDE", "Suppressor_T3");
		SetAttachmentTier("AJW_SLX_S_Suppressor_FDE", "Suppressor_T3");
		
		SetAttachmentTier("AJW_BS_Magpul_MOE_FDE", "Stock_T1");
		SetAttachmentTier("AJW_BS_Magpul_MOE_OD", "Stock_T1");
		SetAttachmentTier("AJW_BS_Magpul_MOE_Green", "Stock_T1");
		SetAttachmentTier("AJW_BS_Magpul_MOE_Grey", "Stock_T1");
		SetAttachmentTier("AJW_BS_Magpul_MOE_Black", "Stock_T1");
		SetAttachmentTier("AJW_BS_SOPMOD_Black", "Stock_T2");
		SetAttachmentTier("AJW_BS_SOPMOD_FDE", "Stock_T2");
		SetAttachmentTier("AJW_BS_PRS2_FDE", "Stock_T3");
		SetAttachmentTier("AJW_BS_PRS2_Black", "Stock_T3");
		SetAttachmentTier("AJW_BS_PRS3_FDE", "Stock_T3");
		SetAttachmentTier("AJW_BS_PRS3_Black", "Stock_T3");
		SetAttachmentTier("AJW_BS_PRS3_OD", "Stock_T3");
		SetAttachmentTier("AJW_BS_PRS_Lite_FDE", "Stock_T3");
		SetAttachmentTier("AJW_BS_PRS_Lite_Black", "Stock_T3");
		SetAttachmentTier("AJW_BS_PRS_Lite_OD", "Stock_T3");
		SetAttachmentTier("AJW_BS_HKG28_FDE", "Stock_T3");
		SetAttachmentTier("AJW_BS_HKG28_Black", "Stock_T3");
		SetAttachmentTier("AJW_MCX_Stock_Buffer", "Stock_T1");
		SetAttachmentTier("AJW_BS_MCX_Buffer_Black", "Stock_T2");
		SetAttachmentTier("AJW_BS_MCX_Buffer_AnaRed", "Stock_T2");
		SetAttachmentTier("AJW_MCX_Stock_STD", "Stock_T2");
		SetAttachmentTier("AJW_BS_MCX_Collapsible_Open", "Stock_T2");
		SetAttachmentTier("AJW_BS_MCX_Collapsible_Closed", "Stock_T2");
		SetAttachmentTier("AJW_BS_MCX_Skele", "Stock_T3");
		SetAttachmentTier("AJW_BS_MCX_MiniSkele", "Stock_T3");
		SetAttachmentTier("AJW_BS_MCX_Visor", "Stock_T2");
		SetAttachmentTier("AJW_BS_AK12_Black", "Stock_T2");
		SetAttachmentTier("AJW_BS_B5_Black", "Stock_T2");
		SetAttachmentTier("AJW_BS_B5_FDE", "Stock_T2");
		SetAttachmentTier("AJW_BS_Viper_Black", "Stock_T2");
		SetAttachmentTier("AJW_BS_Viper_FDE", "Stock_T2");
		SetAttachmentTier("AJW_BS_BCM_Black", "Stock_T2");
		SetAttachmentTier("AJW_BS_BCM_FDE", "Stock_T2");
		SetAttachmentTier("AJW_BS_CMMG_Black", "Stock_T2");
		SetAttachmentTier("AJW_BS_DD_Black", "Stock_T2");
		SetAttachmentTier("AJW_BS_DD_FDE", "Stock_T2");
		SetAttachmentTier("AJW_BS_DS150_Black", "Stock_T2");
		SetAttachmentTier("AJW_BS_DS150_FDE", "Stock_T2");
		SetAttachmentTier("AJW_BS_FAB_GLC_Black", "Stock_T2");
		SetAttachmentTier("AJW_BS_AK74M_Plastic", "Stock_T1");
		SetAttachmentTier("AJW_BS_AK74M_PT1_Black", "Stock_T2");
		SetAttachmentTier("AJW_BS_AK74M_PT3_Black", "Stock_T3");
		SetAttachmentTier("AJW_BS_SA58_BRS_Black", "Stock_T2");
		SetAttachmentTier("AJW_BS_SA58_Folding", "Stock_T2");
		SetAttachmentTier("AJW_BS_HoneyBadger_FDE", "Stock_T3");
		SetAttachmentTier("AJW_BS_HoneyBadger_Black", "Stock_T3");
		SetAttachmentTier("AJW_BS_HoneyBadger_Badger", "Stock_T3");
		SetAttachmentTier("AJW_EVO3_Stock_Standard_Grey", "Stock_T1");
		SetAttachmentTier("AJW_EVO3_Stock_Standard_Black", "Stock_T1");
		SetAttachmentTier("AJW_EVO3_Stock_Standard_FDE", "Stock_T1");
		SetAttachmentTier("AJW_EVO3_Stock_Mini", "Stock_T2");
		SetAttachmentTier("AJW_EVO3_Stock_BufferTube", "Stock_T2");
		SetAttachmentTier("AJW_BD_Car15_Bttstck", "Stock_T1");
		
		SetAttachmentTier("AJW_CZEVO3_Barrel_Long", "Handguard_T2");
		SetAttachmentTier("AJW_CZEVO3_Barrel_Micro", "Handguard_T1");
		SetAttachmentTier("AJW_SV98_OV_Chassis_FDE", "Stock_T3");
		SetAttachmentTier("AJW_SV98_Suppressor_Black", "Suppressor_T3");
		SetAttachmentTier("AJW_SVD_SAGChassis_Black", "Handguard_T3");
		SetAttachmentTier("AJW_SVD_SAGChassis_Rattle", "Handguard_T3");
		SetAttachmentTier("AJW_SVD_StockAdapt_Black", "Stock_T2");
		SetAttachmentTier("AJW_R700_MagpulChassis_Black", "Stock_T3");
		SetAttachmentTier("AJW_R700_MagpulChassis_OD", "Stock_T3");
		SetAttachmentTier("AJW_R700_MagpulChassis_FDE", "Stock_T3");
		SetAttachmentTier("AJW_MCX_Barrel_556", "Muzzle_T1");
		SetAttachmentTier("AJW_MCX_Barrel_300", "Muzzle_T1");
		SetAttachmentTier("AJW_M4_Trigger_Castellan_Black", "Neutral");
		SetAttachmentTier("AJW_M4_Trigger_Castellan_Blue", "Neutral");
		SetAttachmentTier("AJW_M4_Trigger_Castellan_BajaB", "Neutral");
		SetAttachmentTier("AJW_M4_Trigger_Castellan_Orange", "Neutral");
		SetAttachmentTier("AJW_M4_Trigger_Castellan_Pink", "Neutral");
		SetAttachmentTier("AJW_M4_Trigger_Castellan_Purple", "Neutral");
		SetAttachmentTier("AJW_M4_Trigger_Castellan_Red", "Neutral");
		
		SetAttachmentTier("weaponLaserPointer", "Laser_Tactical");
		SetAttachmentTier("weaponLaser", "Laser_Tactical");
		SetAttachmentTier("PistolLaserPointer", "Laser_Tactical");
		SetAttachmentTier("AJPEQLASER", "Laser_Tactical");
		SetAttachmentTier("Expansion_ANPEQ15_Base", "Laser_Tactical");
		SetAttachmentTier("Expansion_ANPEQ15_Red", "Laser_Tactical");
		SetAttachmentTier("Expansion_ANPEQ15_Green", "Laser_Tactical");
		SetAttachmentTier("Expansion_ANPEQ15_GreenNV", "Laser_Tactical");
		SetAttachmentTier("Expansion_ANPEQ15_IR", "Laser_Tactical");
		
		SetAttachmentTier("weaponFlashlight", "Flashlight_Utility");
		SetAttachmentTier("weaponFlashlightRail", "Flashlight_Utility");
		SetAttachmentTier("TLRLight", "Flashlight_Utility");
		SetAttachmentTier("UniversalLight", "Flashlight_Utility");
		
		SetAttachmentTier("weaponBayonet", "Bayonet_Heavy");
		SetAttachmentTier("Bayonet", "Bayonet_Heavy");
		SetAttachmentTier("M9A1Bayonet", "Bayonet_Heavy");
		SetAttachmentTier("AK_Bayonet", "Bayonet_Heavy");
		SetAttachmentTier("M9A1_Bayonet", "Bayonet_Heavy");
		SetAttachmentTier("Mosin_Bayonet", "Bayonet_Heavy");
		SetAttachmentTier("SKS_Bayonet", "Bayonet_Heavy");
		SetAttachmentTier("AJ_SKS_Bayonet", "Bayonet_Heavy");
		SetAttachmentTier("GCGN_M1Garand_Bayonet", "Bayonet_Heavy");
		SetAttachmentTier("Expansion_Kar98_Bayonet", "Bayonet_Heavy");
		
		SetAttachmentTier("Mosin_Compensator", "Muzzle_T1");
		SetAttachmentTier("MP5_Compensator", "Muzzle_T1");
		SetAttachmentTier("Aug_Barrel", "Muzzle_T1");
		SetAttachmentTier("Groza_Barrel_Short", "Muzzle_T1");
		SetAttachmentTier("GCGN_M1Garand_Muzzle", "Muzzle_T1");
		SetAttachmentTier("AJShotgunchoke", "Muzzle_T1");
		SetAttachmentTier("Groza_Barrel_Grip", "Muzzle_T2");
		SetAttachmentTier("sr25Muzzle", "Muzzle_T2");
		SetAttachmentTier("AJ50bmg", "Muzzle_T3");
		
		SetAttachmentTier("ImprovisedSuppressor", "Suppressor_T1");
		SetAttachmentTier("MakarovPBSuppressor", "Suppressor_T1");
		SetAttachmentTier("ItemSuppressor", "Suppressor_T1");
		SetAttachmentTier("22LRSuppressor", "Suppressor_T1");
		SetAttachmentTier("M4_Suppressor", "Suppressor_T2");
		SetAttachmentTier("AK_Suppressor", "Suppressor_T2");
		SetAttachmentTier("PistolSuppressor", "Suppressor_T2");
		SetAttachmentTier("Groza_Barrel_Suppressor", "Suppressor_T2");
		SetAttachmentTier("ASH12Suppressor", "Suppressor_T2");
		SetAttachmentTier("MP7A2Suppressor", "Suppressor_T2");
		SetAttachmentTier("Suppressor9A91", "Suppressor_T2");
		SetAttachmentTier("AJ_Normalized_Suppressor_Base", "Suppressor_T2");
		SetAttachmentTier("AJ_Normalized_Suppressor_Black", "Suppressor_T2");
		SetAttachmentTier("AJ_Normalized_Suppressor_Green", "Suppressor_T2");
		SetAttachmentTier("AJ_Standardized_Suppressor_Base", "Suppressor_T2");
		SetAttachmentTier("AJ_Standardized_Suppressor_Black", "Suppressor_T2");
		SetAttachmentTier("AJ_Standardized_Suppressor_Green", "Suppressor_T2");
		SetAttachmentTier("AJ_MPX_Suppressor_Base", "Suppressor_T2");
		SetAttachmentTier("AJ_MPX_Suppressor_Black", "Suppressor_T2");
		SetAttachmentTier("AJ_Agram_Suppressor_Base", "Suppressor_T2");
		SetAttachmentTier("AJ_Agram_Suppressor_Black", "Suppressor_T2");
		SetAttachmentTier("AJ_SPMOD", "Suppressor_T2");
		SetAttachmentTier("AJSR3_SuppBase", "Suppressor_T2");
		SetAttachmentTier("AJ_SR3Vikhr_Supp", "Suppressor_T2");
		SetAttachmentTier("SR3_Vikhr_Supp", "Suppressor_T2");
		SetAttachmentTier("AJAR15_SPR_SIL_Base", "Suppressor_T2");
		SetAttachmentTier("AJAR15_SPR_SIL", "Suppressor_T2");
		SetAttachmentTier("HoneyBadgerSuppressor", "Suppressor_T3");
		SetAttachmentTier("QDLSuppressor", "Suppressor_T3");
		SetAttachmentTier("AJ338_Suppressor", "Suppressor_T3");
		SetAttachmentTier("AJ300acsupp", "Suppressor_T3");
		SetAttachmentTier("AJ_SR25_Supp_Base", "Suppressor_T3");
		SetAttachmentTier("AJ_SR25_Supp", "Suppressor_T3");
		SetAttachmentTier("AJKivaari_338_Supp_Base", "Suppressor_T3");
		SetAttachmentTier("AJKivaari_338_Supp", "Suppressor_T3");
		SetAttachmentTier("AJ_ScarH_SIL_Base", "Suppressor_T3");
		SetAttachmentTier("AJ_ScarH_SIL_Tan", "Suppressor_T3");
		SetAttachmentTier("AJ_ScarH_SIL_Black", "Suppressor_T3");
		SetAttachmentTier("AJGevar_Suppressor_Black", "Suppressor_T3");
		SetAttachmentTier("AJGevar_Suppressor_Tan", "Suppressor_T3");
		SetAttachmentTier("AJGevar_Suppressor_Green", "Suppressor_T3");
		SetAttachmentTier("AJ_LNormalized_Suppressor_Base", "Suppressor_T3");
		SetAttachmentTier("AJ_LNormalized_Suppressor_Black", "Suppressor_T3");
		SetAttachmentTier("AJ_LNormalized_Suppressor_Green", "Suppressor_T3");
		SetAttachmentTier("AJ_LStandardized_Suppressor_Base", "Suppressor_T3");
		SetAttachmentTier("AJ_LStandardized_Suppressor_Black", "Suppressor_T3");
		SetAttachmentTier("AJ_LStandardized_Suppressor_Green", "Suppressor_T3");
		SetAttachmentTier("AJ_50bmg_Suppressor_Base", "Suppressor_T3");
		SetAttachmentTier("AJ_50bmg_Suppressor_B", "Suppressor_T3");
		SetAttachmentTier("AJ_50bmg_Suppressor_M", "Suppressor_T3");
		SetAttachmentTier("AJ_50bmg_Suppressor_S", "Suppressor_T3");
		SetAttachmentTier("AJ_50bmg_Suppressor_U", "Suppressor_T3");
		SetAttachmentTier("AJ_50bmg_Suppressor_W", "Suppressor_T3");
		SetAttachmentTier("AJ_408_Suppressor_T", "Suppressor_T3");
		SetAttachmentTier("AJAR15_SPR_SQSIL_Base", "Suppressor_T3");
		SetAttachmentTier("AJAR15_SPR_SQSIL", "Suppressor_T3");
		
		SetAttachmentTier("GhillieAtt_ColorBase", "WeaponWrap_Utility");
		SetAttachmentTier("Groza_LowerReceiver", "Handguard_T2");
		SetAttachmentTier("GrozaGL_LowerReceiver", "Handguard_T2");
		
		SetAttachmentTier("Mag_Expansion_M9_15Rnd", "StandardMag_Neutral");
		SetAttachmentTier("Mag_Expansion_G36_30Rnd", "StandardMag_Neutral");
		SetAttachmentTier("Mag_Expansion_M14_10Rnd", "StandardMag_Neutral");
		SetAttachmentTier("Mag_Expansion_M14_20Rnd", "StandardMag_Neutral");
		SetAttachmentTier("Mag_Expansion_MPX_50Rnd", "HighCap_Heavy");
		SetAttachmentTier("Mag_Expansion_MP7_40Rnd", "HighCap_Heavy");
		SetAttachmentTier("Mag_Expansion_Kedr_20Rnd", "StandardMag_Neutral");
		SetAttachmentTier("Mag_Expansion_Vityaz_30Rnd", "StandardMag_Neutral");
		SetAttachmentTier("Mag_Expansion_AWM_5rnd", "StandardMag_Neutral");
		SetAttachmentTier("Mag_Expansion_Taser", "StandardMag_Neutral");
	}
	
	void SetAttachmentTier(string className, string tierKey)
	{
		if (!AttachmentTiers) AttachmentTiers = new map<string, string>;
		AttachmentTiers.Set(className, tierKey);
	}
	
	void SetTierEffect(string key, string category, string tier, float recoil, float sway, float ads, float precision, float hipFire)
	{
		if (!AttachmentTierEffects) AttachmentTierEffects = new map<string, ref AJTierEffect>;
		AttachmentTierEffects.Set(key, new AJTierEffect(category, tier, recoil, sway, ads, precision, hipFire));
	}
	
	string GetAttachmentTier(string className, string fallbackTier = "Neutral")
	{
		if (AttachmentTiers && AttachmentTiers.Contains(className))
		{
			return AttachmentTiers.Get(className);
		}
		
		return fallbackTier;
	}
	
	AJTierEffect GetTierEffect(string tierKey)
	{
		if (AttachmentTierEffects && AttachmentTierEffects.Contains(tierKey))
		{
			return AttachmentTierEffects.Get(tierKey);
		}
		
		if (AttachmentTierEffects && AttachmentTierEffects.Contains("Neutral"))
		{
			return AttachmentTierEffects.Get("Neutral");
		}
		
		return new AJTierEffect();
	}
	
	void ResetToDefaults()
	{
		ApplyDefaultValues();
		Print("[AJ Gunplay] Config reset to defaults plus admin JSON");
	}
	
	void ApplyAdminConfig(AJGunplayAdminConfig adminConfig)
	{
		if (!adminConfig)
		{
			return;
		}
		
		adminConfig.EnsureDefaults();
		GlobalRecoilMultiplier = adminConfig.GlobalRecoilMultiplier;
		GlobalSwayMultiplier = adminConfig.GlobalSwayMultiplier;
		GlobalAimSpeedMultiplier = adminConfig.GlobalAimSpeedMultiplier;
		GlobalHipFireMultiplier = adminConfig.GlobalHipFireMultiplier;
		GlobalPrecisionMultiplier = adminConfig.GlobalPrecisionMultiplier;
		EnableHipFireNerf = adminConfig.EnableHipFireNerf;
		EnableWeaponGeometryDamage = adminConfig.EnableWeaponGeometryDamage;
		DebugMode = adminConfig.DebugMode;
		HighCapMagazineThreshold = adminConfig.HighCapMagazineThreshold;
		
		array<ref AJAttachmentStatOverride> customStatOverrides = new array<ref AJAttachmentStatOverride>;
		foreach (AJAttachmentStatOverride statOverride : adminConfig.AttachmentStatOverrides)
		{
			if (statOverride && !IsDefaultAttachmentStatOverride(statOverride))
			{
				customStatOverrides.Insert(statOverride);
			}
		}
		
		foreach (AJAttachmentTierOverride tierAssignment : adminConfig.AttachmentTierOverrides)
		{
			if (tierAssignment && tierAssignment.ClassName != "" && tierAssignment.TierKey != "")
			{
				SetAttachmentTier(tierAssignment.ClassName, tierAssignment.TierKey);
			}
		}
		
		foreach (AJTierMultiplierOverride tierOverride : adminConfig.TierMultiplierOverrides)
		{
			ApplyTierMultiplierOverride(tierOverride);
		}
		
		foreach (AJAttachmentStatOverride customStatOverride : customStatOverrides)
		{
			ApplyAttachmentStatOverride(customStatOverride);
		}
	}
	
	bool IsDefaultAttachmentStatOverride(AJAttachmentStatOverride statOverride)
	{
		if (!statOverride || statOverride.ClassName == "")
		{
			return false;
		}
		
		if (!AttachmentTiers || !AttachmentTiers.Contains(statOverride.ClassName))
		{
			return false;
		}
		
		string tierKey = AttachmentTiers.Get(statOverride.ClassName);
		if (!AttachmentTierEffects || !AttachmentTierEffects.Contains(tierKey))
		{
			return false;
		}
		
		AJTierEffect effect = AttachmentTierEffects.Get(tierKey);
		if (!effect)
		{
			return false;
		}
		
		return statOverride.Category == effect.Category && statOverride.Tier == effect.Tier && FloatClose(statOverride.Recoil, effect.Recoil) && FloatClose(statOverride.Sway, effect.Sway) && FloatClose(statOverride.ADS, effect.ADS) && FloatClose(statOverride.Precision, effect.Precision) && FloatClose(statOverride.HipFire, effect.HipFire);
	}
	
	bool FloatClose(float a, float b)
	{
		float diff = a - b;
		if (diff < 0.0)
		{
			diff = -diff;
		}
		
		return diff < 0.0001;
	}
	
	void ApplyTierMultiplierOverride(AJTierMultiplierOverride tierOverride)
	{
		if (!tierOverride || tierOverride.TierKey == "")
		{
			return;
		}
		
		if (!AttachmentTierEffects || !AttachmentTierEffects.Contains(tierOverride.TierKey))
		{
			return;
		}
		
		AJTierEffect effect = AttachmentTierEffects.Get(tierOverride.TierKey);
		if (!effect)
		{
			return;
		}
		
		effect.Recoil *= tierOverride.Recoil;
		effect.Sway *= tierOverride.Sway;
		effect.ADS *= tierOverride.ADS;
		effect.Precision *= tierOverride.Precision;
		effect.HipFire *= tierOverride.HipFire;
	}
	
	void ApplyAttachmentStatOverride(AJAttachmentStatOverride statOverride)
	{
		if (!statOverride || statOverride.ClassName == "")
		{
			return;
		}
		
		string tierKey = "Admin_" + statOverride.ClassName;
		SetTierEffect(tierKey, statOverride.Category, statOverride.Tier, statOverride.Recoil, statOverride.Sway, statOverride.ADS, statOverride.Precision, statOverride.HipFire);
		SetAttachmentTier(statOverride.ClassName, tierKey);
	}
}
