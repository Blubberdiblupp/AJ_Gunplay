class AJGunplayAdminDefaults
{
	static void FillMissingDefaults(AJGunplayAdminConfig config)
	{
		if (!config)
		{
			return;
		}

		if (!config.AttachmentTierOverrides)
		{
			config.AttachmentTierOverrides = new array<ref AJAttachmentTierOverride>;
		}

		if (!config.TierMultiplierOverrides)
		{
			config.TierMultiplierOverrides = new array<ref AJTierMultiplierOverride>;
		}

		if (!config.AttachmentStatOverrides)
		{
			config.AttachmentStatOverrides = new array<ref AJAttachmentStatOverride>;
		}

		FillDefaultTierMultipliers(config);
		FillDefaultAttachmentTiers(config);
		FillDefaultAttachmentStats(config);
	}

	static void FillDefaultTierMultipliers(AJGunplayAdminConfig config)
	{
		AddDefaultTierMultiplier(config, "Foregrip_T1");
		AddDefaultTierMultiplier(config, "Foregrip_T2");
		AddDefaultTierMultiplier(config, "Foregrip_T3");
		AddDefaultTierMultiplier(config, "PistolGrip_T1");
		AddDefaultTierMultiplier(config, "PistolGrip_T2");
		AddDefaultTierMultiplier(config, "PistolGrip_T3");
		AddDefaultTierMultiplier(config, "Stock_T1");
		AddDefaultTierMultiplier(config, "Stock_T2");
		AddDefaultTierMultiplier(config, "Stock_T3");
		AddDefaultTierMultiplier(config, "Handguard_T1");
		AddDefaultTierMultiplier(config, "Handguard_T2");
		AddDefaultTierMultiplier(config, "Handguard_T3");
		AddDefaultTierMultiplier(config, "Bipod_Special");
		AddDefaultTierMultiplier(config, "LightOptic_T1");
		AddDefaultTierMultiplier(config, "HeavyOptic_T2");
		AddDefaultTierMultiplier(config, "SniperOptic_T3");
		AddDefaultTierMultiplier(config, "Laser_Tactical");
		AddDefaultTierMultiplier(config, "Flashlight_Utility");
		AddDefaultTierMultiplier(config, "Bayonet_Heavy");
		AddDefaultTierMultiplier(config, "Muzzle_T1");
		AddDefaultTierMultiplier(config, "Muzzle_T2");
		AddDefaultTierMultiplier(config, "Muzzle_T3");
		AddDefaultTierMultiplier(config, "Suppressor_T1");
		AddDefaultTierMultiplier(config, "Suppressor_T2");
		AddDefaultTierMultiplier(config, "Suppressor_T3");
		AddDefaultTierMultiplier(config, "WeaponWrap_Utility");
		AddDefaultTierMultiplier(config, "StandardMag_Neutral");
		AddDefaultTierMultiplier(config, "HighCap_Heavy");
		AddDefaultTierMultiplier(config, "Neutral");
	}

	static void FillDefaultAttachmentTiers(AJGunplayAdminConfig config)
	{
		AddDefaultAttachmentTier(config, "FGRIP", "Foregrip_T1");
		AddDefaultAttachmentTier(config, "AJar15afg", "Foregrip_T2");
		AddDefaultAttachmentTier(config, "weaponGripCQR", "Foregrip_T2");
		AddDefaultAttachmentTier(config, "weaponGripKAAR", "Foregrip_T3");
		AddDefaultAttachmentTier(config, "AJ_M249Grip", "Foregrip_T2");
		AddDefaultAttachmentTier(config, "AJSR3Grip", "Foregrip_T2");
		AddDefaultAttachmentTier(config, "weaponrgripAJ", "Foregrip_T2");
		AddDefaultAttachmentTier(config, "weaponGrip", "PistolGrip_T1");
		AddDefaultAttachmentTier(config, "weaponGripAK", "PistolGrip_T2");
		AddDefaultAttachmentTier(config, "weaponPistolGrip", "PistolGrip_T2");
		AddDefaultAttachmentTier(config, "AJMPXGRIP", "PistolGrip_T2");
		AddDefaultAttachmentTier(config, "AJ_M249Stock", "Stock_T2");
		AddDefaultAttachmentTier(config, "AJ_M200Stock", "Stock_T3");
		AddDefaultAttachmentTier(config, "AJ_AK_AR_Stock", "Stock_T2");
		AddDefaultAttachmentTier(config, "AJ_AK19_Stock", "Stock_T2");
		AddDefaultAttachmentTier(config, "M4_OEBttstck", "Stock_T1");
		AddDefaultAttachmentTier(config, "M4_MPBttstck", "Stock_T2");
		AddDefaultAttachmentTier(config, "M4_CQBBttstck", "Stock_T3");
		AddDefaultAttachmentTier(config, "AK_WoodBttstck", "Stock_T1");
		AddDefaultAttachmentTier(config, "AK74_WoodBttstck", "Stock_T1");
		AddDefaultAttachmentTier(config, "AK_PlasticBttstck", "Stock_T2");
		AddDefaultAttachmentTier(config, "AK_FoldingBttstck", "Stock_T2");
		AddDefaultAttachmentTier(config, "AKS74U_Bttstck", "Stock_T2");
		AddDefaultAttachmentTier(config, "MP5k_StockBttstck", "Stock_T2");
		AddDefaultAttachmentTier(config, "Red9Bttstck", "Stock_T1");
		AddDefaultAttachmentTier(config, "Fal_OeBttstck", "Stock_T2");
		AddDefaultAttachmentTier(config, "Fal_FoldingBttstck", "Stock_T3");
		AddDefaultAttachmentTier(config, "Saiga_Bttstck", "Stock_T2");
		AddDefaultAttachmentTier(config, "PP19_Bttstck", "Stock_T2");
		AddDefaultAttachmentTier(config, "AJWSR3Stock", "Stock_T2");
		AddDefaultAttachmentTier(config, "AJ_M249HG", "Handguard_T2");
		AddDefaultAttachmentTier(config, "AJM60Handguard", "Handguard_T2");
		AddDefaultAttachmentTier(config, "AJSR3HG", "Handguard_T2");
		AddDefaultAttachmentTier(config, "HandguardRIS", "Handguard_T2");
		AddDefaultAttachmentTier(config, "M4_OEBHandGuard", "Handguard_T1");
		AddDefaultAttachmentTier(config, "M4_MOLLEHandGuard", "Handguard_T2");
		AddDefaultAttachmentTier(config, "M4_PlasticHndgrd", "Handguard_T1");
		AddDefaultAttachmentTier(config, "M4_RISHndgrd", "Handguard_T2");
		AddDefaultAttachmentTier(config, "M4_MPHndgrd", "Handguard_T2");
		AddDefaultAttachmentTier(config, "AK_WoodHndgrd", "Handguard_T1");
		AddDefaultAttachmentTier(config, "AK74_Hndgrd", "Handguard_T1");
		AddDefaultAttachmentTier(config, "AK_PlasticHndgrd", "Handguard_T2");
		AddDefaultAttachmentTier(config, "AK_RailHndgrd", "Handguard_T3");
		AddDefaultAttachmentTier(config, "MP5_PlasticHndgrd", "Handguard_T1");
		AddDefaultAttachmentTier(config, "MP5_RailHndgrd", "Handguard_T2");
		AddDefaultAttachmentTier(config, "M249_Hndgrd", "Handguard_T1");
		AddDefaultAttachmentTier(config, "M249_RisHndgrd", "Handguard_T2");
		AddDefaultAttachmentTier(config, "weaponHGAJ10", "Handguard_T2");
		AddDefaultAttachmentTier(config, "weaponHGAJ10NA", "Handguard_T2");
		AddDefaultAttachmentTier(config, "weaponHGAJ14", "Handguard_T2");
		AddDefaultAttachmentTier(config, "weaponHGAJ14NA", "Handguard_T2");
		AddDefaultAttachmentTier(config, "weaponHGAJ16", "Handguard_T3");
		AddDefaultAttachmentTier(config, "weaponHGAJ16NA", "Handguard_T3");
		AddDefaultAttachmentTier(config, "AJweaponBipod", "Bipod_Special");
		AddDefaultAttachmentTier(config, "AJ_M249Bipod", "Bipod_Special");
		AddDefaultAttachmentTier(config, "AJ_M200B_BK", "Bipod_Special");
		AddDefaultAttachmentTier(config, "AJ_M200Bipod_Base", "Bipod_Special");
		AddDefaultAttachmentTier(config, "AJvsskBipod", "Bipod_Special");
		AddDefaultAttachmentTier(config, "sr25bipod", "Bipod_Special");
		AddDefaultAttachmentTier(config, "PKPBIPOD", "Bipod_Special");
		AddDefaultAttachmentTier(config, "AJ_RDS", "LightOptic_T1");
		AddDefaultAttachmentTier(config, "AJ_EOTech_EXPS3", "LightOptic_T1");
		AddDefaultAttachmentTier(config, "AJ_Aimpoint_M5", "LightOptic_T1");
		AddDefaultAttachmentTier(config, "AJ_Docter", "LightOptic_T1");
		AddDefaultAttachmentTier(config, "AJ_Elcan", "LightOptic_T1");
		AddDefaultAttachmentTier(config, "AJ_Hunting", "SniperOptic_T3");
		AddDefaultAttachmentTier(config, "AJM60ScopeMount", "LightOptic_T1");
		AddDefaultAttachmentTier(config, "AJ_Nightforce", "SniperOptic_T3");
		AddDefaultAttachmentTier(config, "AJ_AKNightforce", "SniperOptic_T3");
		AddDefaultAttachmentTier(config, "AJ_HNightforce", "SniperOptic_T3");
		AddDefaultAttachmentTier(config, "AJ_MNightforce", "SniperOptic_T3");
		AddDefaultAttachmentTier(config, "AJ_Tango6T", "HeavyOptic_T2");
		AddDefaultAttachmentTier(config, "AJ_Tango6T_Black", "HeavyOptic_T2");
		AddDefaultAttachmentTier(config, "AJ_Tango6T_Tan", "HeavyOptic_T2");
		AddDefaultAttachmentTier(config, "AJ_Tango6T_Wood", "HeavyOptic_T2");
		AddDefaultAttachmentTier(config, "AJ_Tango6T_Snow", "HeavyOptic_T2");
		AddDefaultAttachmentTier(config, "AJ_AKTango6T_Black", "HeavyOptic_T2");
		AddDefaultAttachmentTier(config, "AJ_AKTango6T_Tan", "HeavyOptic_T2");
		AddDefaultAttachmentTier(config, "AJ_AKTango6T_Wood", "HeavyOptic_T2");
		AddDefaultAttachmentTier(config, "AJ_AKTango6T_Snow", "HeavyOptic_T2");
		AddDefaultAttachmentTier(config, "AJ_MTango6T_Black", "HeavyOptic_T2");
		AddDefaultAttachmentTier(config, "AJ_MTango6T_Tan", "HeavyOptic_T2");
		AddDefaultAttachmentTier(config, "AJ_MTango6T_Wood", "HeavyOptic_T2");
		AddDefaultAttachmentTier(config, "AJ_MTango6T_Snow", "HeavyOptic_T2");
		AddDefaultAttachmentTier(config, "AJ_Leupold_MK8", "HeavyOptic_T2");
		AddDefaultAttachmentTier(config, "AJ_Leupold_Mark8", "HeavyOptic_T2");
		AddDefaultAttachmentTier(config, "AJ_AKLeupold_Mark8", "HeavyOptic_T2");
		AddDefaultAttachmentTier(config, "AJ_HLeupold_Mark8", "HeavyOptic_T2");
		AddDefaultAttachmentTier(config, "AJ_MLeupold_Mark8", "HeavyOptic_T2");
		AddDefaultAttachmentTier(config, "AJ_Kahles", "HeavyOptic_T2");
		AddDefaultAttachmentTier(config, "AJ_AKKahles", "HeavyOptic_T2");
		AddDefaultAttachmentTier(config, "AJ_HKahles", "HeavyOptic_T2");
		AddDefaultAttachmentTier(config, "AJ_MKahles", "HeavyOptic_T2");
		AddDefaultAttachmentTier(config, "AJ_Walther", "HeavyOptic_T2");
		AddDefaultAttachmentTier(config, "AJ_AKWalther", "HeavyOptic_T2");
		AddDefaultAttachmentTier(config, "AJ_HWalther", "HeavyOptic_T2");
		AddDefaultAttachmentTier(config, "AJ_MWalther", "HeavyOptic_T2");
		AddDefaultAttachmentTier(config, "GCGN_M84_Optic", "HeavyOptic_T2");
		AddDefaultAttachmentTier(config, "AJ_AKHuntingOptic", "SniperOptic_T3");
		AddDefaultAttachmentTier(config, "AJ_HHuntingOptic", "SniperOptic_T3");
		AddDefaultAttachmentTier(config, "AJ_HuntingOptic", "SniperOptic_T3");
		AddDefaultAttachmentTier(config, "AJ_M14Optic", "HeavyOptic_T2");
		AddDefaultAttachmentTier(config, "AJ_MHuntingOptic", "SniperOptic_T3");
		AddDefaultAttachmentTier(config, "M4_CarryHandleOptic", "LightOptic_T1");
		AddDefaultAttachmentTier(config, "BUISOptic", "LightOptic_T1");
		AddDefaultAttachmentTier(config, "M68Optic", "LightOptic_T1");
		AddDefaultAttachmentTier(config, "M4_T3NRDSOptic", "LightOptic_T1");
		AddDefaultAttachmentTier(config, "FNP45_MRDSOptic", "LightOptic_T1");
		AddDefaultAttachmentTier(config, "ReflexOptic", "LightOptic_T1");
		AddDefaultAttachmentTier(config, "KobraOptic", "LightOptic_T1");
		AddDefaultAttachmentTier(config, "PistolOptic", "LightOptic_T1");
		AddDefaultAttachmentTier(config, "SportingOptic", "LightOptic_T1");
		AddDefaultAttachmentTier(config, "ACOGOptic", "HeavyOptic_T2");
		AddDefaultAttachmentTier(config, "ACOGOptic_6x", "HeavyOptic_T2");
		AddDefaultAttachmentTier(config, "PSO1Optic", "HeavyOptic_T2");
		AddDefaultAttachmentTier(config, "PSO11Optic", "HeavyOptic_T2");
		AddDefaultAttachmentTier(config, "PSO6Optic", "HeavyOptic_T2");
		AddDefaultAttachmentTier(config, "GrozaOptic", "HeavyOptic_T2");
		AddDefaultAttachmentTier(config, "KashtanOptic", "LightOptic_T1");
		AddDefaultAttachmentTier(config, "PUScopeOptic", "HeavyOptic_T2");
		AddDefaultAttachmentTier(config, "LongrangeOptic", "SniperOptic_T3");
		AddDefaultAttachmentTier(config, "HuntingOptic", "SniperOptic_T3");
		AddDefaultAttachmentTier(config, "MK4Optic_ColorBase", "HeavyOptic_T2");
		AddDefaultAttachmentTier(config, "MK4Optic_Tan", "HeavyOptic_T2");
		AddDefaultAttachmentTier(config, "MK4Optic_Green", "HeavyOptic_T2");
		AddDefaultAttachmentTier(config, "MK4Optic_Black", "HeavyOptic_T2");
		AddDefaultAttachmentTier(config, "KazuarOptic", "HeavyOptic_T2");
		AddDefaultAttachmentTier(config, "StarlightOptic", "HeavyOptic_T2");
		AddDefaultAttachmentTier(config, "ExpansionDeltapointOptic", "LightOptic_T1");
		AddDefaultAttachmentTier(config, "ExpansionEXPS3HoloOptic", "LightOptic_T1");
		AddDefaultAttachmentTier(config, "ExpansionHAMROptic", "HeavyOptic_T2");
		AddDefaultAttachmentTier(config, "ExpansionKar98ScopeOptic", "SniperOptic_T3");
		AddDefaultAttachmentTier(config, "Expansion_PMII25Optic", "SniperOptic_T3");
		AddDefaultAttachmentTier(config, "ExpansionReflexMRSOptic", "LightOptic_T1");
		AddDefaultAttachmentTier(config, "Expansion_M1A_RailAtt", "Handguard_T1");
		AddDefaultAttachmentTier(config, "Expansion_MP5_RailAtt", "Handguard_T1");
		AddDefaultAttachmentTier(config, "AJW_Optic_MicroT2_Black", "LightOptic_T1");
		AddDefaultAttachmentTier(config, "AJW_Optic_MicroT2_FDE", "LightOptic_T1");
		AddDefaultAttachmentTier(config, "AJW_Optic_MicroT2_Unity_Black", "LightOptic_T1");
		AddDefaultAttachmentTier(config, "AJW_Optic_MicroT2_Unity_FDE", "LightOptic_T1");
		AddDefaultAttachmentTier(config, "AJW_Optic_HydraT2_Black", "LightOptic_T1");
		AddDefaultAttachmentTier(config, "AJW_Optic_HydraT2_FDE", "LightOptic_T1");
		AddDefaultAttachmentTier(config, "AJW_Optic_HydraXps_Black", "LightOptic_T1");
		AddDefaultAttachmentTier(config, "AJW_Optic_HydraXps_FDE", "LightOptic_T1");
		AddDefaultAttachmentTier(config, "AJW_Optic_EOTech_EXPS3_Black", "LightOptic_T1");
		AddDefaultAttachmentTier(config, "AJW_Optic_EOTech_EXPS3_FDE", "LightOptic_T1");
		AddDefaultAttachmentTier(config, "AJW_Optic_EOTech_EXPS3_TwoTone", "LightOptic_T1");
		AddDefaultAttachmentTier(config, "AJW_Optic_EOTech_EXPS3_Black_Wojack", "LightOptic_T1");
		AddDefaultAttachmentTier(config, "AJW_Optic_SRO_Black", "LightOptic_T1");
		AddDefaultAttachmentTier(config, "AJW_Optic_StrikeFire_Black", "LightOptic_T1");
		AddDefaultAttachmentTier(config, "AJW_Optic_StrikeFire_FDE", "LightOptic_T1");
		AddDefaultAttachmentTier(config, "AJW_Optic_OKP7", "LightOptic_T1");
		AddDefaultAttachmentTier(config, "AJW_BD_Car15_Optic", "LightOptic_T1");
		AddDefaultAttachmentTier(config, "AJW_Magnifier_G33", "LightOptic_T1");
		AddDefaultAttachmentTier(config, "AJW_Magnifier_G43", "LightOptic_T1");
		AddDefaultAttachmentTier(config, "AJW_Magnifier_Aimpoint3x_UnityTall", "LightOptic_T1");
		AddDefaultAttachmentTier(config, "AJW_Optic_ACOG_Chevron", "HeavyOptic_T2");
		AddDefaultAttachmentTier(config, "AJW_Optic_ACOG_Horseshoe", "HeavyOptic_T2");
		AddDefaultAttachmentTier(config, "AJW_Optic_ACOG_ACSS", "HeavyOptic_T2");
		AddDefaultAttachmentTier(config, "AJW_Optic_Accupower", "HeavyOptic_T2");
		AddDefaultAttachmentTier(config, "AJW_Optic_EoTechVudu", "HeavyOptic_T2");
		AddDefaultAttachmentTier(config, "AJW_Optic_Vortex", "HeavyOptic_T2");
		AddDefaultAttachmentTier(config, "AJW_Optic_ELCAN_Black", "HeavyOptic_T2");
		AddDefaultAttachmentTier(config, "AJW_Optic_ELCAN_FDE", "HeavyOptic_T2");
		AddDefaultAttachmentTier(config, "AJW_Optic_HAMR", "HeavyOptic_T2");
		AddDefaultAttachmentTier(config, "AJW_Optic_LeupoldHoloDEVO", "HeavyOptic_T2");
		AddDefaultAttachmentTier(config, "AJW_Optic_Leupold_M3A", "SniperOptic_T3");
		AddDefaultAttachmentTier(config, "AJW_Optic_K98", "SniperOptic_T3");
		AddDefaultAttachmentTier(config, "AJW_NGAL_Green", "Laser_Tactical");
		AddDefaultAttachmentTier(config, "AJW_NGAL_Red", "Laser_Tactical");
		AddDefaultAttachmentTier(config, "AJW_DBAL_Tan_Green", "Laser_Tactical");
		AddDefaultAttachmentTier(config, "AJW_DBAL_Tan_Red", "Laser_Tactical");
		AddDefaultAttachmentTier(config, "AJW_DBAL_Black_Green", "Laser_Tactical");
		AddDefaultAttachmentTier(config, "AJW_DBAL_Black_Red", "Laser_Tactical");
		AddDefaultAttachmentTier(config, "AJW_PEQ15_Tan_Green", "Laser_Tactical");
		AddDefaultAttachmentTier(config, "AJW_PEQ15_Tan_Red", "Laser_Tactical");
		AddDefaultAttachmentTier(config, "AJW_PEQ15_Black_Green", "Laser_Tactical");
		AddDefaultAttachmentTier(config, "AJW_PEQ15_Black_Red", "Laser_Tactical");
		AddDefaultAttachmentTier(config, "AJW_MAWL_Tan_Green", "Laser_Tactical");
		AddDefaultAttachmentTier(config, "AJW_MAWL_Tan_Red", "Laser_Tactical");
		AddDefaultAttachmentTier(config, "AJW_MAWL_Black_Green", "Laser_Tactical");
		AddDefaultAttachmentTier(config, "AJW_MAWL_Black_Red", "Laser_Tactical");
		AddDefaultAttachmentTier(config, "AJW_MOE_FG_Black", "Foregrip_T1");
		AddDefaultAttachmentTier(config, "AJW_MOE_FG_FDE", "Foregrip_T1");
		AddDefaultAttachmentTier(config, "AJW_AFG_FG_Black", "Foregrip_T2");
		AddDefaultAttachmentTier(config, "AJW_AFG_FG_FDE", "Foregrip_T2");
		AddDefaultAttachmentTier(config, "AJW_AFG2_FG_Black", "Foregrip_T2");
		AddDefaultAttachmentTier(config, "AJW_AFG2_FG_FDE", "Foregrip_T2");
		AddDefaultAttachmentTier(config, "AJW_Cobra_FG_Black", "Foregrip_T3");
		AddDefaultAttachmentTier(config, "AJW_CQR_FG_Black", "Foregrip_T3");
		AddDefaultAttachmentTier(config, "AJW_HK_FG_Black", "Foregrip_T3");
		AddDefaultAttachmentTier(config, "AJW_HK_FG_FDE", "Foregrip_T3");
		AddDefaultAttachmentTier(config, "AJW_Stark_FG_Black", "Foregrip_T3");
		AddDefaultAttachmentTier(config, "AJW_AK_PG_MOE_Black", "PistolGrip_T1");
		AddDefaultAttachmentTier(config, "AJW_AK_PG_MOE_Grey", "PistolGrip_T1");
		AddDefaultAttachmentTier(config, "AJW_AK_PG_MOE_FDE", "PistolGrip_T1");
		AddDefaultAttachmentTier(config, "AJW_AK_PG_MOE_OD", "PistolGrip_T1");
		AddDefaultAttachmentTier(config, "AJW_AK_PG_AK12_Black", "PistolGrip_T2");
		AddDefaultAttachmentTier(config, "AJW_AK_PG_AK12_Camo", "PistolGrip_T2");
		AddDefaultAttachmentTier(config, "AJW_AK_PG_AK12_FDE", "PistolGrip_T2");
		AddDefaultAttachmentTier(config, "AJW_AK_PG_MG47_Black", "PistolGrip_T2");
		AddDefaultAttachmentTier(config, "AJW_AK_PG_MG47_FDE", "PistolGrip_T2");
		AddDefaultAttachmentTier(config, "AJW_AK_PG_MG47_Red", "PistolGrip_T2");
		AddDefaultAttachmentTier(config, "AJW_AK_PG_MG47_Brass", "PistolGrip_T2");
		AddDefaultAttachmentTier(config, "AJW_AK_PG_MG47_Anared", "PistolGrip_T2");
		AddDefaultAttachmentTier(config, "AJW_AK_PG_RK3_Black", "PistolGrip_T3");
		AddDefaultAttachmentTier(config, "AJW_AK_PG_RK3_FDE", "PistolGrip_T3");
		AddDefaultAttachmentTier(config, "AJW_AK_PG_Scorpius_Grey", "PistolGrip_T3");
		AddDefaultAttachmentTier(config, "AJW_AK_PG_SI_Black", "PistolGrip_T3");
		AddDefaultAttachmentTier(config, "AJW_AK_PG_SI_FDE", "PistolGrip_T3");
		AddDefaultAttachmentTier(config, "AJW_AK_PG_TD_Black", "PistolGrip_T1");
		AddDefaultAttachmentTier(config, "AJW_AK_PG_TD_FDE", "PistolGrip_T1");
		AddDefaultAttachmentTier(config, "AJW_M4_Skele_PGrip", "PistolGrip_T3");
		AddDefaultAttachmentTier(config, "AJW_M4_PG_BCM_Black", "PistolGrip_T2");
		AddDefaultAttachmentTier(config, "AJW_M4_PG_BCM_FDE", "PistolGrip_T2");
		AddDefaultAttachmentTier(config, "AJW_M4_PG_DD_Black", "PistolGrip_T2");
		AddDefaultAttachmentTier(config, "AJW_M4_PG_DD_FDE", "PistolGrip_T2");
		AddDefaultAttachmentTier(config, "AJW_M4_PG_F1_Black", "PistolGrip_T3");
		AddDefaultAttachmentTier(config, "AJW_M4_PG_F1_Yellow", "PistolGrip_T3");
		AddDefaultAttachmentTier(config, "AJW_M4_PG_F1_Cyan", "PistolGrip_T3");
		AddDefaultAttachmentTier(config, "AJW_M4_PG_F1_OD", "PistolGrip_T3");
		AddDefaultAttachmentTier(config, "AJW_M4_PG_F1_Pink", "PistolGrip_T3");
		AddDefaultAttachmentTier(config, "AJW_M4_PG_F1_Red", "PistolGrip_T3");
		AddDefaultAttachmentTier(config, "AJW_M4_PG_Hogue_Black", "PistolGrip_T1");
		AddDefaultAttachmentTier(config, "AJW_M4_PG_Hogue_FDE", "PistolGrip_T1");
		AddDefaultAttachmentTier(config, "AJW_M4_PG_MOE_Black", "PistolGrip_T1");
		AddDefaultAttachmentTier(config, "AJW_M4_PG_MOE_FDE", "PistolGrip_T1");
		AddDefaultAttachmentTier(config, "AJW_M4_PG_HKERGO", "PistolGrip_T2");
		AddDefaultAttachmentTier(config, "AJW_M4_PG_HK_Black", "PistolGrip_T2");
		AddDefaultAttachmentTier(config, "AJW_M4_PG_HK_FDE", "PistolGrip_T2");
		AddDefaultAttachmentTier(config, "AJW_M4_PG_MOEK2_Black", "PistolGrip_T2");
		AddDefaultAttachmentTier(config, "AJW_M4_PG_MOEK2_FDE", "PistolGrip_T2");
		AddDefaultAttachmentTier(config, "AJW_M4_PG_TD_Black", "PistolGrip_T1");
		AddDefaultAttachmentTier(config, "AJW_M4_PG_TD_FDE", "PistolGrip_T1");
		AddDefaultAttachmentTier(config, "AJW_M4_PG_TD_Red", "PistolGrip_T1");
		AddDefaultAttachmentTier(config, "AJW_M4_CH_Aero", "Handguard_T1");
		AddDefaultAttachmentTier(config, "AJW_M4_CH_Aero_Black", "Handguard_T1");
		AddDefaultAttachmentTier(config, "AJW_M4_CH_Aero_ANred", "Handguard_T1");
		AddDefaultAttachmentTier(config, "AJW_M4_CH_Aero_Gold", "Handguard_T1");
		AddDefaultAttachmentTier(config, "AJW_Vityaz_DC_SN_Black", "Handguard_T1");
		AddDefaultAttachmentTier(config, "AJW_Vityaz_DC_SN_FDE", "Handguard_T1");
		AddDefaultAttachmentTier(config, "AJW_AK_DC_B33_Black", "Handguard_T1");
		AddDefaultAttachmentTier(config, "AJW_AK_DC_B33_FDE", "Handguard_T1");
		AddDefaultAttachmentTier(config, "AJW_74U_PDC_DC", "Handguard_T1");
		AddDefaultAttachmentTier(config, "AJW_HK_HG_STD_Quad_Grey", "Handguard_T2");
		AddDefaultAttachmentTier(config, "AJW_HK_HG_STD_Quad_Black", "Handguard_T2");
		AddDefaultAttachmentTier(config, "AJW_HK_HG_STD_Quad_FDE", "Handguard_T2");
		AddDefaultAttachmentTier(config, "AJW_HK_Geissele_HG10_Black", "Handguard_T2");
		AddDefaultAttachmentTier(config, "AJW_HK_Geissele_HG10_Grey", "Handguard_T2");
		AddDefaultAttachmentTier(config, "AJW_HK_Geissele_HG10_FDE", "Handguard_T2");
		AddDefaultAttachmentTier(config, "AJW_HK_Geissele_HG10_Rose", "Handguard_T2");
		AddDefaultAttachmentTier(config, "AJW_HK_Geissele_HG14_Grey", "Handguard_T3");
		AddDefaultAttachmentTier(config, "AJW_HK_Geissele_HG14_FDE", "Handguard_T3");
		AddDefaultAttachmentTier(config, "AJW_HK_Geissele_HG14_Rose", "Handguard_T3");
		AddDefaultAttachmentTier(config, "AJW_HK_Geissele_HG14_Black", "Handguard_T3");
		AddDefaultAttachmentTier(config, "AJW_M4_RISHndgrd", "Handguard_T2");
		AddDefaultAttachmentTier(config, "AJW_M4_BlockII_Hndgrd", "Handguard_T3");
		AddDefaultAttachmentTier(config, "AJW_M4_BlockII_HG_Black", "Handguard_T3");
		AddDefaultAttachmentTier(config, "AJW_M4_BlockII_HG_FDE", "Handguard_T3");
		AddDefaultAttachmentTier(config, "AJW_M4_BlockII_10_HG_Black", "Handguard_T2");
		AddDefaultAttachmentTier(config, "AJW_M4_BlockII_10_HG_FDE", "Handguard_T2");
		AddDefaultAttachmentTier(config, "AJW_M4_URX4_Hndgrd", "Handguard_T3");
		AddDefaultAttachmentTier(config, "AJW_M4_URX4_HG_Black", "Handguard_T3");
		AddDefaultAttachmentTier(config, "AJW_M4_URX4_HG_FDE", "Handguard_T3");
		AddDefaultAttachmentTier(config, "AJW_M4_URX4_10_HG_Black", "Handguard_T2");
		AddDefaultAttachmentTier(config, "AJW_M4_URX4_10_HG_FDE", "Handguard_T2");
		AddDefaultAttachmentTier(config, "AJW_M4_LVOA_HG_Black", "Handguard_T3");
		AddDefaultAttachmentTier(config, "AJW_M4_LVOA_HG_FDE", "Handguard_T3");
		AddDefaultAttachmentTier(config, "AJW_M4_URGI_10_HG_Black", "Handguard_T2");
		AddDefaultAttachmentTier(config, "AJW_M4_URGI_10_HG_FDE", "Handguard_T2");
		AddDefaultAttachmentTier(config, "AJW_M4_Honey_Hndgrd", "Handguard_T2");
		AddDefaultAttachmentTier(config, "AJW_M4_Honey_HG_Black", "Handguard_T2");
		AddDefaultAttachmentTier(config, "AJW_M4_Honey_HG_FDE", "Handguard_T2");
		AddDefaultAttachmentTier(config, "AJW_M4_Honey_HG_Badger", "Handguard_T2");
		AddDefaultAttachmentTier(config, "AJW_MCX_STD_HG_Black", "Handguard_T2");
		AddDefaultAttachmentTier(config, "AJW_MCX_STD_HG_FDE", "Handguard_T2");
		AddDefaultAttachmentTier(config, "AJW_MCX_STD_HG_Grey", "Handguard_T2");
		AddDefaultAttachmentTier(config, "AJW_MCX_LVAW_HG_Black", "Handguard_T3");
		AddDefaultAttachmentTier(config, "AJW_MCX_LVAW_HG_FDE", "Handguard_T3");
		AddDefaultAttachmentTier(config, "AJW_MCX_LT_HG_Black", "Handguard_T3");
		AddDefaultAttachmentTier(config, "AJW_MCX_LT_HG_FDE", "Handguard_T3");
		AddDefaultAttachmentTier(config, "AJW_MCX_LT_HG_OD", "Handguard_T3");
		AddDefaultAttachmentTier(config, "AJW_MCX_LCH_HG_Black", "Handguard_T3");
		AddDefaultAttachmentTier(config, "AJW_MCX_KM_HG_Black", "Handguard_T3");
		AddDefaultAttachmentTier(config, "AJW_MCX_KM_HG_FDE", "Handguard_T3");
		AddDefaultAttachmentTier(config, "AJW_MCX_KM_HG_OD", "Handguard_T3");
		AddDefaultAttachmentTier(config, "AJW_MCX_KM_HG_AnaRed", "Handguard_T3");
		AddDefaultAttachmentTier(config, "AJW_SCAR_MREX_HG_FDE", "Handguard_T3");
		AddDefaultAttachmentTier(config, "AJW_SCAR_MREX_HG_Black", "Handguard_T3");
		AddDefaultAttachmentTier(config, "AJW_SCAR_CASV_HG_FDE", "Handguard_T2");
		AddDefaultAttachmentTier(config, "AJW_SCAR_CASV_HG_Black", "Handguard_T2");
		AddDefaultAttachmentTier(config, "AJW_SCAR_PMM_HG_FDE", "Handguard_T3");
		AddDefaultAttachmentTier(config, "AJW_SCAR_PMM_HG_Black", "Handguard_T3");
		AddDefaultAttachmentTier(config, "AJW_AK_B30_HG_Black", "Handguard_T3");
		AddDefaultAttachmentTier(config, "AJW_AK_B30_HG_FDE", "Handguard_T3");
		AddDefaultAttachmentTier(config, "AJW_AK_Hexagon_HG_Black", "Handguard_T2");
		AddDefaultAttachmentTier(config, "AJW_AK_Hexagon_HG_FDE", "Handguard_T2");
		AddDefaultAttachmentTier(config, "AJW_AK_Hexagon_HG_Red", "Handguard_T2");
		AddDefaultAttachmentTier(config, "AJW_AK_MagpulL_HG_Black", "Handguard_T2");
		AddDefaultAttachmentTier(config, "AJW_AK_MagpulL_HG_FDE", "Handguard_T2");
		AddDefaultAttachmentTier(config, "AJW_AK_CMRD_HG_Black", "Handguard_T3");
		AddDefaultAttachmentTier(config, "AJW_AK_CMRD_HG_FDE", "Handguard_T3");
		AddDefaultAttachmentTier(config, "AJW_AK_AK100_HG", "Handguard_T1");
		AddDefaultAttachmentTier(config, "AJW_AK_B10_HG_Plastic", "Handguard_T1");
		AddDefaultAttachmentTier(config, "AJW_AK_B19_HG_Black", "Handguard_T2");
		AddDefaultAttachmentTier(config, "AJW_AK_B19_HG_FDE", "Handguard_T2");
		AddDefaultAttachmentTier(config, "AJW_AK_MagpulS_HG_Black", "Handguard_T2");
		AddDefaultAttachmentTier(config, "AJW_AK_MagpulS_HG_FDE", "Handguard_T2");
		AddDefaultAttachmentTier(config, "AJW_AK_Shark_HG_Wood", "Handguard_T1");
		AddDefaultAttachmentTier(config, "AJW_AK_SLR_HG_Black", "Handguard_T3");
		AddDefaultAttachmentTier(config, "AJW_AK_Sport1_HG_Black", "Handguard_T3");
		AddDefaultAttachmentTier(config, "AJW_AK_Sport1_HG_FDE", "Handguard_T3");
		AddDefaultAttachmentTier(config, "AJW_AK_Troy_HG_Black", "Handguard_T2");
		AddDefaultAttachmentTier(config, "AJW_AK_Troy_HG_FDE", "Handguard_T2");
		AddDefaultAttachmentTier(config, "AJW_AK74U_HG_STD", "Handguard_T1");
		AddDefaultAttachmentTier(config, "AJW_AK74U_HG_B11", "Handguard_T2");
		AddDefaultAttachmentTier(config, "AJW_AK74U_HG_Goliaf_Black", "Handguard_T3");
		AddDefaultAttachmentTier(config, "AJW_AK74U_HG_Goliaf_Copper", "Handguard_T3");
		AddDefaultAttachmentTier(config, "AJW_AR10_URX_HG_Black", "Handguard_T3");
		AddDefaultAttachmentTier(config, "AJW_AR10_URX_HG_FDE", "Handguard_T3");
		AddDefaultAttachmentTier(config, "AJW_AR10_CCMG_HG_Black", "Handguard_T3");
		AddDefaultAttachmentTier(config, "AJW_AR10_CCMG_HG_FDE", "Handguard_T3");
		AddDefaultAttachmentTier(config, "AJW_AR10_SWS_N6_HG", "Handguard_T3");
		AddDefaultAttachmentTier(config, "AJW_AR10_SWS_N6_10_HG", "Handguard_T2");
		AddDefaultAttachmentTier(config, "AJW_SA58_STD_HG_Grey", "Handguard_T1");
		AddDefaultAttachmentTier(config, "AJW_SA58_CASV_HG_Grey", "Handguard_T2");
		AddDefaultAttachmentTier(config, "AJW_Bipod_Harris", "Bipod_Special");
		AddDefaultAttachmentTier(config, "AJW_Surefire_Gunlight_Black", "Flashlight_Utility");
		AddDefaultAttachmentTier(config, "AJW_Surefire_Gunlight_FDE", "Flashlight_Utility");
		AddDefaultAttachmentTier(config, "AJW_Surefire_M600v_Gunlight_Black", "Flashlight_Utility");
		AddDefaultAttachmentTier(config, "AJW_Surefire_M600v_Gunlight_FDE", "Flashlight_Utility");
		AddDefaultAttachmentTier(config, "AJW_HKMk23SOCOM_LAM", "Laser_Tactical");
		AddDefaultAttachmentTier(config, "AJW_M1897_Bayonet", "Bayonet_Heavy");
		AddDefaultAttachmentTier(config, "AJW_12GA_MuzzleBreak", "Muzzle_T1");
		AddDefaultAttachmentTier(config, "AJW_M4_MD_Noveske_Black", "Muzzle_T2");
		AddDefaultAttachmentTier(config, "AJW_M4_MD_Noveske_FDE", "Muzzle_T2");
		AddDefaultAttachmentTier(config, "AJW_AK74M_Comp", "Muzzle_T2");
		AddDefaultAttachmentTier(config, "AJW_50cal_MD_M82_Black", "Muzzle_T3");
		AddDefaultAttachmentTier(config, "AJW_50cal_MD_AK50_Black", "Muzzle_T3");
		AddDefaultAttachmentTier(config, "AJW_SurefireRC2_Tan_Suppressor", "Suppressor_T2");
		AddDefaultAttachmentTier(config, "AJW_SurefireRC2_Black_Suppressor", "Suppressor_T2");
		AddDefaultAttachmentTier(config, "AJW_SurefireFA762K_Tan_Suppressor", "Suppressor_T2");
		AddDefaultAttachmentTier(config, "AJW_SurefireFA762K_Black_Suppressor", "Suppressor_T2");
		AddDefaultAttachmentTier(config, "AJW_HKG28_BTQD_Suppressor_Tan", "Suppressor_T3");
		AddDefaultAttachmentTier(config, "AJW_HKG28_BTQD_Suppressor_Black", "Suppressor_T3");
		AddDefaultAttachmentTier(config, "AJW_AACSDN_Suppressor_FDE", "Suppressor_T2");
		AddDefaultAttachmentTier(config, "AJW_AACSDN_Suppressor_Black", "Suppressor_T2");
		AddDefaultAttachmentTier(config, "AJW_Rotor43_Suppressor_Black", "Suppressor_T2");
		AddDefaultAttachmentTier(config, "AJW_Rotor43_Suppressor_Rattle", "Suppressor_T2");
		AddDefaultAttachmentTier(config, "AJW_Osprey_Suppressor_Black", "Suppressor_T2");
		AddDefaultAttachmentTier(config, "AJW_Osprey_Suppressor_FDE", "Suppressor_T2");
		AddDefaultAttachmentTier(config, "AJW_HKMk23SOCOM_Suppressor", "Suppressor_T2");
		AddDefaultAttachmentTier(config, "AJW_QDSSNT4_Suppressor_Black", "Suppressor_T3");
		AddDefaultAttachmentTier(config, "AJW_QDSSNT4_Suppressor_FDE", "Suppressor_T3");
		AddDefaultAttachmentTier(config, "AJW_Gemtech_Suppressor_Black", "Suppressor_T2");
		AddDefaultAttachmentTier(config, "AJW_Gemtech_Suppressor_FDE", "Suppressor_T2");
		AddDefaultAttachmentTier(config, "AJW_DTK4_Suppressor_Black", "Suppressor_T2");
		AddDefaultAttachmentTier(config, "AJW_DTK4_Suppressor_MC", "Suppressor_T2");
		AddDefaultAttachmentTier(config, "AJW_DTKP_Suppressor_Black", "Suppressor_T2");
		AddDefaultAttachmentTier(config, "AJW_DTKP_Suppressor_FDE", "Suppressor_T2");
		AddDefaultAttachmentTier(config, "AJW_Hexagon_Suppressor_Black", "Suppressor_T2");
		AddDefaultAttachmentTier(config, "AJW_PBS1_Suppressor", "Suppressor_T2");
		AddDefaultAttachmentTier(config, "AJW_PBS4_Suppressor", "Suppressor_T2");
		AddDefaultAttachmentTier(config, "AJW_50cal_Suppressor_Black", "Suppressor_T3");
		AddDefaultAttachmentTier(config, "AJW_50cal_Suppressor_Tan", "Suppressor_T3");
		AddDefaultAttachmentTier(config, "AJW_50cal_Suppressor_Wrapped_Black", "Suppressor_T3");
		AddDefaultAttachmentTier(config, "AJW_50cal_Suppressor_Wrapped_RG", "Suppressor_T3");
		AddDefaultAttachmentTier(config, "AJW_50cal_Suppressor_Wrapped_MC", "Suppressor_T3");
		AddDefaultAttachmentTier(config, "AJW_50cal_Suppressor_Wrapped_Tan", "Suppressor_T3");
		AddDefaultAttachmentTier(config, "AJW_50cal_Suppressor_Wrapped_TANMC", "Suppressor_T3");
		AddDefaultAttachmentTier(config, "AJW_50cal_Suppressor_Long_Black", "Suppressor_T3");
		AddDefaultAttachmentTier(config, "AJW_50cal_Suppressor_Long_Tan", "Suppressor_T3");
		AddDefaultAttachmentTier(config, "AJW_50cal_Suppressor_QDL_Black", "Suppressor_T3");
		AddDefaultAttachmentTier(config, "AJW_50cal_Suppressor_QDL_FDE", "Suppressor_T3");
		AddDefaultAttachmentTier(config, "AJW_SLX_Suppressor_FDE", "Suppressor_T3");
		AddDefaultAttachmentTier(config, "AJW_SLX_S_Suppressor_FDE", "Suppressor_T3");
		AddDefaultAttachmentTier(config, "AJW_BS_Magpul_MOE_FDE", "Stock_T1");
		AddDefaultAttachmentTier(config, "AJW_BS_Magpul_MOE_OD", "Stock_T1");
		AddDefaultAttachmentTier(config, "AJW_BS_Magpul_MOE_Green", "Stock_T1");
		AddDefaultAttachmentTier(config, "AJW_BS_Magpul_MOE_Grey", "Stock_T1");
		AddDefaultAttachmentTier(config, "AJW_BS_Magpul_MOE_Black", "Stock_T1");
		AddDefaultAttachmentTier(config, "AJW_BS_SOPMOD_Black", "Stock_T2");
		AddDefaultAttachmentTier(config, "AJW_BS_SOPMOD_FDE", "Stock_T2");
		AddDefaultAttachmentTier(config, "AJW_BS_PRS2_FDE", "Stock_T3");
		AddDefaultAttachmentTier(config, "AJW_BS_PRS2_Black", "Stock_T3");
		AddDefaultAttachmentTier(config, "AJW_BS_PRS3_FDE", "Stock_T3");
		AddDefaultAttachmentTier(config, "AJW_BS_PRS3_Black", "Stock_T3");
		AddDefaultAttachmentTier(config, "AJW_BS_PRS3_OD", "Stock_T3");
		AddDefaultAttachmentTier(config, "AJW_BS_PRS_Lite_FDE", "Stock_T3");
		AddDefaultAttachmentTier(config, "AJW_BS_PRS_Lite_Black", "Stock_T3");
		AddDefaultAttachmentTier(config, "AJW_BS_PRS_Lite_OD", "Stock_T3");
		AddDefaultAttachmentTier(config, "AJW_BS_HKG28_FDE", "Stock_T3");
		AddDefaultAttachmentTier(config, "AJW_BS_HKG28_Black", "Stock_T3");
		AddDefaultAttachmentTier(config, "AJW_MCX_Stock_Buffer", "Stock_T1");
		AddDefaultAttachmentTier(config, "AJW_BS_MCX_Buffer_Black", "Stock_T2");
		AddDefaultAttachmentTier(config, "AJW_BS_MCX_Buffer_AnaRed", "Stock_T2");
		AddDefaultAttachmentTier(config, "AJW_MCX_Stock_STD", "Stock_T2");
		AddDefaultAttachmentTier(config, "AJW_BS_MCX_Collapsible_Open", "Stock_T2");
		AddDefaultAttachmentTier(config, "AJW_BS_MCX_Collapsible_Closed", "Stock_T2");
		AddDefaultAttachmentTier(config, "AJW_BS_MCX_Skele", "Stock_T3");
		AddDefaultAttachmentTier(config, "AJW_BS_MCX_MiniSkele", "Stock_T3");
		AddDefaultAttachmentTier(config, "AJW_BS_MCX_Visor", "Stock_T2");
		AddDefaultAttachmentTier(config, "AJW_BS_AK12_Black", "Stock_T2");
		AddDefaultAttachmentTier(config, "AJW_BS_B5_Black", "Stock_T2");
		AddDefaultAttachmentTier(config, "AJW_BS_B5_FDE", "Stock_T2");
		AddDefaultAttachmentTier(config, "AJW_BS_Viper_Black", "Stock_T2");
		AddDefaultAttachmentTier(config, "AJW_BS_Viper_FDE", "Stock_T2");
		AddDefaultAttachmentTier(config, "AJW_BS_BCM_Black", "Stock_T2");
		AddDefaultAttachmentTier(config, "AJW_BS_BCM_FDE", "Stock_T2");
		AddDefaultAttachmentTier(config, "AJW_BS_CMMG_Black", "Stock_T2");
		AddDefaultAttachmentTier(config, "AJW_BS_DD_Black", "Stock_T2");
		AddDefaultAttachmentTier(config, "AJW_BS_DD_FDE", "Stock_T2");
		AddDefaultAttachmentTier(config, "AJW_BS_DS150_Black", "Stock_T2");
		AddDefaultAttachmentTier(config, "AJW_BS_DS150_FDE", "Stock_T2");
		AddDefaultAttachmentTier(config, "AJW_BS_FAB_GLC_Black", "Stock_T2");
		AddDefaultAttachmentTier(config, "AJW_BS_AK74M_Plastic", "Stock_T1");
		AddDefaultAttachmentTier(config, "AJW_BS_AK74M_PT1_Black", "Stock_T2");
		AddDefaultAttachmentTier(config, "AJW_BS_AK74M_PT3_Black", "Stock_T3");
		AddDefaultAttachmentTier(config, "AJW_BS_SA58_BRS_Black", "Stock_T2");
		AddDefaultAttachmentTier(config, "AJW_BS_SA58_Folding", "Stock_T2");
		AddDefaultAttachmentTier(config, "AJW_BS_HoneyBadger_FDE", "Stock_T3");
		AddDefaultAttachmentTier(config, "AJW_BS_HoneyBadger_Black", "Stock_T3");
		AddDefaultAttachmentTier(config, "AJW_BS_HoneyBadger_Badger", "Stock_T3");
		AddDefaultAttachmentTier(config, "AJW_EVO3_Stock_Standard_Grey", "Stock_T1");
		AddDefaultAttachmentTier(config, "AJW_EVO3_Stock_Standard_Black", "Stock_T1");
		AddDefaultAttachmentTier(config, "AJW_EVO3_Stock_Standard_FDE", "Stock_T1");
		AddDefaultAttachmentTier(config, "AJW_EVO3_Stock_Mini", "Stock_T2");
		AddDefaultAttachmentTier(config, "AJW_EVO3_Stock_BufferTube", "Stock_T2");
		AddDefaultAttachmentTier(config, "AJW_BD_Car15_Bttstck", "Stock_T1");
		AddDefaultAttachmentTier(config, "AJW_CZEVO3_Barrel_Long", "Handguard_T2");
		AddDefaultAttachmentTier(config, "AJW_CZEVO3_Barrel_Micro", "Handguard_T1");
		AddDefaultAttachmentTier(config, "AJW_SV98_OV_Chassis_FDE", "Stock_T3");
		AddDefaultAttachmentTier(config, "AJW_SV98_Suppressor_Black", "Suppressor_T3");
		AddDefaultAttachmentTier(config, "AJW_SVD_SAGChassis_Black", "Handguard_T3");
		AddDefaultAttachmentTier(config, "AJW_SVD_SAGChassis_Rattle", "Handguard_T3");
		AddDefaultAttachmentTier(config, "AJW_SVD_StockAdapt_Black", "Stock_T2");
		AddDefaultAttachmentTier(config, "AJW_R700_MagpulChassis_Black", "Stock_T3");
		AddDefaultAttachmentTier(config, "AJW_R700_MagpulChassis_OD", "Stock_T3");
		AddDefaultAttachmentTier(config, "AJW_R700_MagpulChassis_FDE", "Stock_T3");
		AddDefaultAttachmentTier(config, "AJW_MCX_Barrel_556", "Muzzle_T1");
		AddDefaultAttachmentTier(config, "AJW_MCX_Barrel_300", "Muzzle_T1");
		AddDefaultAttachmentTier(config, "AJW_M4_Trigger_Castellan_Black", "Neutral");
		AddDefaultAttachmentTier(config, "AJW_M4_Trigger_Castellan_Blue", "Neutral");
		AddDefaultAttachmentTier(config, "AJW_M4_Trigger_Castellan_BajaB", "Neutral");
		AddDefaultAttachmentTier(config, "AJW_M4_Trigger_Castellan_Orange", "Neutral");
		AddDefaultAttachmentTier(config, "AJW_M4_Trigger_Castellan_Pink", "Neutral");
		AddDefaultAttachmentTier(config, "AJW_M4_Trigger_Castellan_Purple", "Neutral");
		AddDefaultAttachmentTier(config, "AJW_M4_Trigger_Castellan_Red", "Neutral");
		AddDefaultAttachmentTier(config, "weaponLaserPointer", "Laser_Tactical");
		AddDefaultAttachmentTier(config, "weaponLaser", "Laser_Tactical");
		AddDefaultAttachmentTier(config, "PistolLaserPointer", "Laser_Tactical");
		AddDefaultAttachmentTier(config, "AJPEQLASER", "Laser_Tactical");
		AddDefaultAttachmentTier(config, "Expansion_ANPEQ15_Base", "Laser_Tactical");
		AddDefaultAttachmentTier(config, "Expansion_ANPEQ15_Red", "Laser_Tactical");
		AddDefaultAttachmentTier(config, "Expansion_ANPEQ15_Green", "Laser_Tactical");
		AddDefaultAttachmentTier(config, "Expansion_ANPEQ15_GreenNV", "Laser_Tactical");
		AddDefaultAttachmentTier(config, "Expansion_ANPEQ15_IR", "Laser_Tactical");
		AddDefaultAttachmentTier(config, "weaponFlashlight", "Flashlight_Utility");
		AddDefaultAttachmentTier(config, "weaponFlashlightRail", "Flashlight_Utility");
		AddDefaultAttachmentTier(config, "TLRLight", "Flashlight_Utility");
		AddDefaultAttachmentTier(config, "UniversalLight", "Flashlight_Utility");
		AddDefaultAttachmentTier(config, "weaponBayonet", "Bayonet_Heavy");
		AddDefaultAttachmentTier(config, "Bayonet", "Bayonet_Heavy");
		AddDefaultAttachmentTier(config, "M9A1Bayonet", "Bayonet_Heavy");
		AddDefaultAttachmentTier(config, "AK_Bayonet", "Bayonet_Heavy");
		AddDefaultAttachmentTier(config, "M9A1_Bayonet", "Bayonet_Heavy");
		AddDefaultAttachmentTier(config, "Mosin_Bayonet", "Bayonet_Heavy");
		AddDefaultAttachmentTier(config, "SKS_Bayonet", "Bayonet_Heavy");
		AddDefaultAttachmentTier(config, "AJ_SKS_Bayonet", "Bayonet_Heavy");
		AddDefaultAttachmentTier(config, "GCGN_M1Garand_Bayonet", "Bayonet_Heavy");
		AddDefaultAttachmentTier(config, "Expansion_Kar98_Bayonet", "Bayonet_Heavy");
		AddDefaultAttachmentTier(config, "Mosin_Compensator", "Muzzle_T1");
		AddDefaultAttachmentTier(config, "MP5_Compensator", "Muzzle_T1");
		AddDefaultAttachmentTier(config, "Aug_Barrel", "Muzzle_T1");
		AddDefaultAttachmentTier(config, "Groza_Barrel_Short", "Muzzle_T1");
		AddDefaultAttachmentTier(config, "GCGN_M1Garand_Muzzle", "Muzzle_T1");
		AddDefaultAttachmentTier(config, "AJShotgunchoke", "Muzzle_T1");
		AddDefaultAttachmentTier(config, "Groza_Barrel_Grip", "Muzzle_T2");
		AddDefaultAttachmentTier(config, "sr25Muzzle", "Muzzle_T2");
		AddDefaultAttachmentTier(config, "AJ50bmg", "Muzzle_T3");
		AddDefaultAttachmentTier(config, "ImprovisedSuppressor", "Suppressor_T1");
		AddDefaultAttachmentTier(config, "MakarovPBSuppressor", "Suppressor_T1");
		AddDefaultAttachmentTier(config, "ItemSuppressor", "Suppressor_T1");
		AddDefaultAttachmentTier(config, "22LRSuppressor", "Suppressor_T1");
		AddDefaultAttachmentTier(config, "M4_Suppressor", "Suppressor_T2");
		AddDefaultAttachmentTier(config, "AK_Suppressor", "Suppressor_T2");
		AddDefaultAttachmentTier(config, "PistolSuppressor", "Suppressor_T2");
		AddDefaultAttachmentTier(config, "Groza_Barrel_Suppressor", "Suppressor_T2");
		AddDefaultAttachmentTier(config, "ASH12Suppressor", "Suppressor_T2");
		AddDefaultAttachmentTier(config, "MP7A2Suppressor", "Suppressor_T2");
		AddDefaultAttachmentTier(config, "Suppressor9A91", "Suppressor_T2");
		AddDefaultAttachmentTier(config, "AJ_Normalized_Suppressor_Base", "Suppressor_T2");
		AddDefaultAttachmentTier(config, "AJ_Normalized_Suppressor_Black", "Suppressor_T2");
		AddDefaultAttachmentTier(config, "AJ_Normalized_Suppressor_Green", "Suppressor_T2");
		AddDefaultAttachmentTier(config, "AJ_Standardized_Suppressor_Base", "Suppressor_T2");
		AddDefaultAttachmentTier(config, "AJ_Standardized_Suppressor_Black", "Suppressor_T2");
		AddDefaultAttachmentTier(config, "AJ_Standardized_Suppressor_Green", "Suppressor_T2");
		AddDefaultAttachmentTier(config, "AJ_MPX_Suppressor_Base", "Suppressor_T2");
		AddDefaultAttachmentTier(config, "AJ_MPX_Suppressor_Black", "Suppressor_T2");
		AddDefaultAttachmentTier(config, "AJ_Agram_Suppressor_Base", "Suppressor_T2");
		AddDefaultAttachmentTier(config, "AJ_Agram_Suppressor_Black", "Suppressor_T2");
		AddDefaultAttachmentTier(config, "AJ_SPMOD", "Suppressor_T2");
		AddDefaultAttachmentTier(config, "AJSR3_SuppBase", "Suppressor_T2");
		AddDefaultAttachmentTier(config, "AJ_SR3Vikhr_Supp", "Suppressor_T2");
		AddDefaultAttachmentTier(config, "SR3_Vikhr_Supp", "Suppressor_T2");
		AddDefaultAttachmentTier(config, "AJAR15_SPR_SIL_Base", "Suppressor_T2");
		AddDefaultAttachmentTier(config, "AJAR15_SPR_SIL", "Suppressor_T2");
		AddDefaultAttachmentTier(config, "HoneyBadgerSuppressor", "Suppressor_T3");
		AddDefaultAttachmentTier(config, "QDLSuppressor", "Suppressor_T3");
		AddDefaultAttachmentTier(config, "AJ338_Suppressor", "Suppressor_T3");
		AddDefaultAttachmentTier(config, "AJ300acsupp", "Suppressor_T3");
		AddDefaultAttachmentTier(config, "AJ_SR25_Supp_Base", "Suppressor_T3");
		AddDefaultAttachmentTier(config, "AJ_SR25_Supp", "Suppressor_T3");
		AddDefaultAttachmentTier(config, "AJKivaari_338_Supp_Base", "Suppressor_T3");
		AddDefaultAttachmentTier(config, "AJKivaari_338_Supp", "Suppressor_T3");
		AddDefaultAttachmentTier(config, "AJ_ScarH_SIL_Base", "Suppressor_T3");
		AddDefaultAttachmentTier(config, "AJ_ScarH_SIL_Tan", "Suppressor_T3");
		AddDefaultAttachmentTier(config, "AJ_ScarH_SIL_Black", "Suppressor_T3");
		AddDefaultAttachmentTier(config, "AJGevar_Suppressor_Black", "Suppressor_T3");
		AddDefaultAttachmentTier(config, "AJGevar_Suppressor_Tan", "Suppressor_T3");
		AddDefaultAttachmentTier(config, "AJGevar_Suppressor_Green", "Suppressor_T3");
		AddDefaultAttachmentTier(config, "AJ_LNormalized_Suppressor_Base", "Suppressor_T3");
		AddDefaultAttachmentTier(config, "AJ_LNormalized_Suppressor_Black", "Suppressor_T3");
		AddDefaultAttachmentTier(config, "AJ_LNormalized_Suppressor_Green", "Suppressor_T3");
		AddDefaultAttachmentTier(config, "AJ_LStandardized_Suppressor_Base", "Suppressor_T3");
		AddDefaultAttachmentTier(config, "AJ_LStandardized_Suppressor_Black", "Suppressor_T3");
		AddDefaultAttachmentTier(config, "AJ_LStandardized_Suppressor_Green", "Suppressor_T3");
		AddDefaultAttachmentTier(config, "AJ_50bmg_Suppressor_Base", "Suppressor_T3");
		AddDefaultAttachmentTier(config, "AJ_50bmg_Suppressor_B", "Suppressor_T3");
		AddDefaultAttachmentTier(config, "AJ_50bmg_Suppressor_M", "Suppressor_T3");
		AddDefaultAttachmentTier(config, "AJ_50bmg_Suppressor_S", "Suppressor_T3");
		AddDefaultAttachmentTier(config, "AJ_50bmg_Suppressor_U", "Suppressor_T3");
		AddDefaultAttachmentTier(config, "AJ_50bmg_Suppressor_W", "Suppressor_T3");
		AddDefaultAttachmentTier(config, "AJ_408_Suppressor_T", "Suppressor_T3");
		AddDefaultAttachmentTier(config, "AJAR15_SPR_SQSIL_Base", "Suppressor_T3");
		AddDefaultAttachmentTier(config, "AJAR15_SPR_SQSIL", "Suppressor_T3");
		AddDefaultAttachmentTier(config, "GhillieAtt_ColorBase", "WeaponWrap_Utility");
		AddDefaultAttachmentTier(config, "Groza_LowerReceiver", "Handguard_T2");
		AddDefaultAttachmentTier(config, "GrozaGL_LowerReceiver", "Handguard_T2");
		AddDefaultAttachmentTier(config, "Mag_Expansion_M9_15Rnd", "StandardMag_Neutral");
		AddDefaultAttachmentTier(config, "Mag_Expansion_G36_30Rnd", "StandardMag_Neutral");
		AddDefaultAttachmentTier(config, "Mag_Expansion_M14_10Rnd", "StandardMag_Neutral");
		AddDefaultAttachmentTier(config, "Mag_Expansion_M14_20Rnd", "StandardMag_Neutral");
		AddDefaultAttachmentTier(config, "Mag_Expansion_MPX_50Rnd", "HighCap_Heavy");
		AddDefaultAttachmentTier(config, "Mag_Expansion_MP7_40Rnd", "HighCap_Heavy");
		AddDefaultAttachmentTier(config, "Mag_Expansion_Kedr_20Rnd", "StandardMag_Neutral");
		AddDefaultAttachmentTier(config, "Mag_Expansion_Vityaz_30Rnd", "StandardMag_Neutral");
		AddDefaultAttachmentTier(config, "Mag_Expansion_AWM_5rnd", "StandardMag_Neutral");
		AddDefaultAttachmentTier(config, "Mag_Expansion_Taser", "StandardMag_Neutral");
	}

	static void FillDefaultAttachmentStats(AJGunplayAdminConfig config)
	{
		AddDefaultAttachmentStatFromTier(config, "FGRIP", "Foregrip_T1");
		AddDefaultAttachmentStatFromTier(config, "AJar15afg", "Foregrip_T2");
		AddDefaultAttachmentStatFromTier(config, "weaponGripCQR", "Foregrip_T2");
		AddDefaultAttachmentStatFromTier(config, "weaponGripKAAR", "Foregrip_T3");
		AddDefaultAttachmentStatFromTier(config, "AJ_M249Grip", "Foregrip_T2");
		AddDefaultAttachmentStatFromTier(config, "AJSR3Grip", "Foregrip_T2");
		AddDefaultAttachmentStatFromTier(config, "weaponrgripAJ", "Foregrip_T2");
		AddDefaultAttachmentStatFromTier(config, "weaponGrip", "PistolGrip_T1");
		AddDefaultAttachmentStatFromTier(config, "weaponGripAK", "PistolGrip_T2");
		AddDefaultAttachmentStatFromTier(config, "weaponPistolGrip", "PistolGrip_T2");
		AddDefaultAttachmentStatFromTier(config, "AJMPXGRIP", "PistolGrip_T2");
		AddDefaultAttachmentStatFromTier(config, "AJ_M249Stock", "Stock_T2");
		AddDefaultAttachmentStatFromTier(config, "AJ_M200Stock", "Stock_T3");
		AddDefaultAttachmentStatFromTier(config, "AJ_AK_AR_Stock", "Stock_T2");
		AddDefaultAttachmentStatFromTier(config, "AJ_AK19_Stock", "Stock_T2");
		AddDefaultAttachmentStatFromTier(config, "M4_OEBttstck", "Stock_T1");
		AddDefaultAttachmentStatFromTier(config, "M4_MPBttstck", "Stock_T2");
		AddDefaultAttachmentStatFromTier(config, "M4_CQBBttstck", "Stock_T3");
		AddDefaultAttachmentStatFromTier(config, "AK_WoodBttstck", "Stock_T1");
		AddDefaultAttachmentStatFromTier(config, "AK74_WoodBttstck", "Stock_T1");
		AddDefaultAttachmentStatFromTier(config, "AK_PlasticBttstck", "Stock_T2");
		AddDefaultAttachmentStatFromTier(config, "AK_FoldingBttstck", "Stock_T2");
		AddDefaultAttachmentStatFromTier(config, "AKS74U_Bttstck", "Stock_T2");
		AddDefaultAttachmentStatFromTier(config, "MP5k_StockBttstck", "Stock_T2");
		AddDefaultAttachmentStatFromTier(config, "Red9Bttstck", "Stock_T1");
		AddDefaultAttachmentStatFromTier(config, "Fal_OeBttstck", "Stock_T2");
		AddDefaultAttachmentStatFromTier(config, "Fal_FoldingBttstck", "Stock_T3");
		AddDefaultAttachmentStatFromTier(config, "Saiga_Bttstck", "Stock_T2");
		AddDefaultAttachmentStatFromTier(config, "PP19_Bttstck", "Stock_T2");
		AddDefaultAttachmentStatFromTier(config, "AJWSR3Stock", "Stock_T2");
		AddDefaultAttachmentStatFromTier(config, "AJ_M249HG", "Handguard_T2");
		AddDefaultAttachmentStatFromTier(config, "AJM60Handguard", "Handguard_T2");
		AddDefaultAttachmentStatFromTier(config, "AJSR3HG", "Handguard_T2");
		AddDefaultAttachmentStatFromTier(config, "HandguardRIS", "Handguard_T2");
		AddDefaultAttachmentStatFromTier(config, "M4_OEBHandGuard", "Handguard_T1");
		AddDefaultAttachmentStatFromTier(config, "M4_MOLLEHandGuard", "Handguard_T2");
		AddDefaultAttachmentStatFromTier(config, "M4_PlasticHndgrd", "Handguard_T1");
		AddDefaultAttachmentStatFromTier(config, "M4_RISHndgrd", "Handguard_T2");
		AddDefaultAttachmentStatFromTier(config, "M4_MPHndgrd", "Handguard_T2");
		AddDefaultAttachmentStatFromTier(config, "AK_WoodHndgrd", "Handguard_T1");
		AddDefaultAttachmentStatFromTier(config, "AK74_Hndgrd", "Handguard_T1");
		AddDefaultAttachmentStatFromTier(config, "AK_PlasticHndgrd", "Handguard_T2");
		AddDefaultAttachmentStatFromTier(config, "AK_RailHndgrd", "Handguard_T3");
		AddDefaultAttachmentStatFromTier(config, "MP5_PlasticHndgrd", "Handguard_T1");
		AddDefaultAttachmentStatFromTier(config, "MP5_RailHndgrd", "Handguard_T2");
		AddDefaultAttachmentStatFromTier(config, "M249_Hndgrd", "Handguard_T1");
		AddDefaultAttachmentStatFromTier(config, "M249_RisHndgrd", "Handguard_T2");
		AddDefaultAttachmentStatFromTier(config, "weaponHGAJ10", "Handguard_T2");
		AddDefaultAttachmentStatFromTier(config, "weaponHGAJ10NA", "Handguard_T2");
		AddDefaultAttachmentStatFromTier(config, "weaponHGAJ14", "Handguard_T2");
		AddDefaultAttachmentStatFromTier(config, "weaponHGAJ14NA", "Handguard_T2");
		AddDefaultAttachmentStatFromTier(config, "weaponHGAJ16", "Handguard_T3");
		AddDefaultAttachmentStatFromTier(config, "weaponHGAJ16NA", "Handguard_T3");
		AddDefaultAttachmentStatFromTier(config, "AJweaponBipod", "Bipod_Special");
		AddDefaultAttachmentStatFromTier(config, "AJ_M249Bipod", "Bipod_Special");
		AddDefaultAttachmentStatFromTier(config, "AJ_M200B_BK", "Bipod_Special");
		AddDefaultAttachmentStatFromTier(config, "AJ_M200Bipod_Base", "Bipod_Special");
		AddDefaultAttachmentStatFromTier(config, "AJvsskBipod", "Bipod_Special");
		AddDefaultAttachmentStatFromTier(config, "sr25bipod", "Bipod_Special");
		AddDefaultAttachmentStatFromTier(config, "PKPBIPOD", "Bipod_Special");
		AddDefaultAttachmentStatFromTier(config, "AJ_RDS", "LightOptic_T1");
		AddDefaultAttachmentStatFromTier(config, "AJ_EOTech_EXPS3", "LightOptic_T1");
		AddDefaultAttachmentStatFromTier(config, "AJ_Aimpoint_M5", "LightOptic_T1");
		AddDefaultAttachmentStatFromTier(config, "AJ_Docter", "LightOptic_T1");
		AddDefaultAttachmentStatFromTier(config, "AJ_Elcan", "LightOptic_T1");
		AddDefaultAttachmentStatFromTier(config, "AJ_Hunting", "SniperOptic_T3");
		AddDefaultAttachmentStatFromTier(config, "AJM60ScopeMount", "LightOptic_T1");
		AddDefaultAttachmentStatFromTier(config, "AJ_Nightforce", "SniperOptic_T3");
		AddDefaultAttachmentStatFromTier(config, "AJ_AKNightforce", "SniperOptic_T3");
		AddDefaultAttachmentStatFromTier(config, "AJ_HNightforce", "SniperOptic_T3");
		AddDefaultAttachmentStatFromTier(config, "AJ_MNightforce", "SniperOptic_T3");
		AddDefaultAttachmentStatFromTier(config, "AJ_Tango6T", "HeavyOptic_T2");
		AddDefaultAttachmentStatFromTier(config, "AJ_Tango6T_Black", "HeavyOptic_T2");
		AddDefaultAttachmentStatFromTier(config, "AJ_Tango6T_Tan", "HeavyOptic_T2");
		AddDefaultAttachmentStatFromTier(config, "AJ_Tango6T_Wood", "HeavyOptic_T2");
		AddDefaultAttachmentStatFromTier(config, "AJ_Tango6T_Snow", "HeavyOptic_T2");
		AddDefaultAttachmentStatFromTier(config, "AJ_AKTango6T_Black", "HeavyOptic_T2");
		AddDefaultAttachmentStatFromTier(config, "AJ_AKTango6T_Tan", "HeavyOptic_T2");
		AddDefaultAttachmentStatFromTier(config, "AJ_AKTango6T_Wood", "HeavyOptic_T2");
		AddDefaultAttachmentStatFromTier(config, "AJ_AKTango6T_Snow", "HeavyOptic_T2");
		AddDefaultAttachmentStatFromTier(config, "AJ_MTango6T_Black", "HeavyOptic_T2");
		AddDefaultAttachmentStatFromTier(config, "AJ_MTango6T_Tan", "HeavyOptic_T2");
		AddDefaultAttachmentStatFromTier(config, "AJ_MTango6T_Wood", "HeavyOptic_T2");
		AddDefaultAttachmentStatFromTier(config, "AJ_MTango6T_Snow", "HeavyOptic_T2");
		AddDefaultAttachmentStatFromTier(config, "AJ_Leupold_MK8", "HeavyOptic_T2");
		AddDefaultAttachmentStatFromTier(config, "AJ_Leupold_Mark8", "HeavyOptic_T2");
		AddDefaultAttachmentStatFromTier(config, "AJ_AKLeupold_Mark8", "HeavyOptic_T2");
		AddDefaultAttachmentStatFromTier(config, "AJ_HLeupold_Mark8", "HeavyOptic_T2");
		AddDefaultAttachmentStatFromTier(config, "AJ_MLeupold_Mark8", "HeavyOptic_T2");
		AddDefaultAttachmentStatFromTier(config, "AJ_Kahles", "HeavyOptic_T2");
		AddDefaultAttachmentStatFromTier(config, "AJ_AKKahles", "HeavyOptic_T2");
		AddDefaultAttachmentStatFromTier(config, "AJ_HKahles", "HeavyOptic_T2");
		AddDefaultAttachmentStatFromTier(config, "AJ_MKahles", "HeavyOptic_T2");
		AddDefaultAttachmentStatFromTier(config, "AJ_Walther", "HeavyOptic_T2");
		AddDefaultAttachmentStatFromTier(config, "AJ_AKWalther", "HeavyOptic_T2");
		AddDefaultAttachmentStatFromTier(config, "AJ_HWalther", "HeavyOptic_T2");
		AddDefaultAttachmentStatFromTier(config, "AJ_MWalther", "HeavyOptic_T2");
		AddDefaultAttachmentStatFromTier(config, "GCGN_M84_Optic", "HeavyOptic_T2");
		AddDefaultAttachmentStatFromTier(config, "AJ_AKHuntingOptic", "SniperOptic_T3");
		AddDefaultAttachmentStatFromTier(config, "AJ_HHuntingOptic", "SniperOptic_T3");
		AddDefaultAttachmentStatFromTier(config, "AJ_HuntingOptic", "SniperOptic_T3");
		AddDefaultAttachmentStatFromTier(config, "AJ_M14Optic", "HeavyOptic_T2");
		AddDefaultAttachmentStatFromTier(config, "AJ_MHuntingOptic", "SniperOptic_T3");
		AddDefaultAttachmentStatFromTier(config, "M4_CarryHandleOptic", "LightOptic_T1");
		AddDefaultAttachmentStatFromTier(config, "BUISOptic", "LightOptic_T1");
		AddDefaultAttachmentStatFromTier(config, "M68Optic", "LightOptic_T1");
		AddDefaultAttachmentStatFromTier(config, "M4_T3NRDSOptic", "LightOptic_T1");
		AddDefaultAttachmentStatFromTier(config, "FNP45_MRDSOptic", "LightOptic_T1");
		AddDefaultAttachmentStatFromTier(config, "ReflexOptic", "LightOptic_T1");
		AddDefaultAttachmentStatFromTier(config, "KobraOptic", "LightOptic_T1");
		AddDefaultAttachmentStatFromTier(config, "PistolOptic", "LightOptic_T1");
		AddDefaultAttachmentStatFromTier(config, "SportingOptic", "LightOptic_T1");
		AddDefaultAttachmentStatFromTier(config, "ACOGOptic", "HeavyOptic_T2");
		AddDefaultAttachmentStatFromTier(config, "ACOGOptic_6x", "HeavyOptic_T2");
		AddDefaultAttachmentStatFromTier(config, "PSO1Optic", "HeavyOptic_T2");
		AddDefaultAttachmentStatFromTier(config, "PSO11Optic", "HeavyOptic_T2");
		AddDefaultAttachmentStatFromTier(config, "PSO6Optic", "HeavyOptic_T2");
		AddDefaultAttachmentStatFromTier(config, "GrozaOptic", "HeavyOptic_T2");
		AddDefaultAttachmentStatFromTier(config, "KashtanOptic", "LightOptic_T1");
		AddDefaultAttachmentStatFromTier(config, "PUScopeOptic", "HeavyOptic_T2");
		AddDefaultAttachmentStatFromTier(config, "LongrangeOptic", "SniperOptic_T3");
		AddDefaultAttachmentStatFromTier(config, "HuntingOptic", "SniperOptic_T3");
		AddDefaultAttachmentStatFromTier(config, "MK4Optic_ColorBase", "HeavyOptic_T2");
		AddDefaultAttachmentStatFromTier(config, "MK4Optic_Tan", "HeavyOptic_T2");
		AddDefaultAttachmentStatFromTier(config, "MK4Optic_Green", "HeavyOptic_T2");
		AddDefaultAttachmentStatFromTier(config, "MK4Optic_Black", "HeavyOptic_T2");
		AddDefaultAttachmentStatFromTier(config, "KazuarOptic", "HeavyOptic_T2");
		AddDefaultAttachmentStatFromTier(config, "StarlightOptic", "HeavyOptic_T2");
		AddDefaultAttachmentStatFromTier(config, "ExpansionDeltapointOptic", "LightOptic_T1");
		AddDefaultAttachmentStatFromTier(config, "ExpansionEXPS3HoloOptic", "LightOptic_T1");
		AddDefaultAttachmentStatFromTier(config, "ExpansionHAMROptic", "HeavyOptic_T2");
		AddDefaultAttachmentStatFromTier(config, "ExpansionKar98ScopeOptic", "SniperOptic_T3");
		AddDefaultAttachmentStatFromTier(config, "Expansion_PMII25Optic", "SniperOptic_T3");
		AddDefaultAttachmentStatFromTier(config, "ExpansionReflexMRSOptic", "LightOptic_T1");
		AddDefaultAttachmentStatFromTier(config, "Expansion_M1A_RailAtt", "Handguard_T1");
		AddDefaultAttachmentStatFromTier(config, "Expansion_MP5_RailAtt", "Handguard_T1");
		AddDefaultAttachmentStatFromTier(config, "AJW_Optic_MicroT2_Black", "LightOptic_T1");
		AddDefaultAttachmentStatFromTier(config, "AJW_Optic_MicroT2_FDE", "LightOptic_T1");
		AddDefaultAttachmentStatFromTier(config, "AJW_Optic_MicroT2_Unity_Black", "LightOptic_T1");
		AddDefaultAttachmentStatFromTier(config, "AJW_Optic_MicroT2_Unity_FDE", "LightOptic_T1");
		AddDefaultAttachmentStatFromTier(config, "AJW_Optic_HydraT2_Black", "LightOptic_T1");
		AddDefaultAttachmentStatFromTier(config, "AJW_Optic_HydraT2_FDE", "LightOptic_T1");
		AddDefaultAttachmentStatFromTier(config, "AJW_Optic_HydraXps_Black", "LightOptic_T1");
		AddDefaultAttachmentStatFromTier(config, "AJW_Optic_HydraXps_FDE", "LightOptic_T1");
		AddDefaultAttachmentStatFromTier(config, "AJW_Optic_EOTech_EXPS3_Black", "LightOptic_T1");
		AddDefaultAttachmentStatFromTier(config, "AJW_Optic_EOTech_EXPS3_FDE", "LightOptic_T1");
		AddDefaultAttachmentStatFromTier(config, "AJW_Optic_EOTech_EXPS3_TwoTone", "LightOptic_T1");
		AddDefaultAttachmentStatFromTier(config, "AJW_Optic_EOTech_EXPS3_Black_Wojack", "LightOptic_T1");
		AddDefaultAttachmentStatFromTier(config, "AJW_Optic_SRO_Black", "LightOptic_T1");
		AddDefaultAttachmentStatFromTier(config, "AJW_Optic_StrikeFire_Black", "LightOptic_T1");
		AddDefaultAttachmentStatFromTier(config, "AJW_Optic_StrikeFire_FDE", "LightOptic_T1");
		AddDefaultAttachmentStatFromTier(config, "AJW_Optic_OKP7", "LightOptic_T1");
		AddDefaultAttachmentStatFromTier(config, "AJW_BD_Car15_Optic", "LightOptic_T1");
		AddDefaultAttachmentStatFromTier(config, "AJW_Magnifier_G33", "LightOptic_T1");
		AddDefaultAttachmentStatFromTier(config, "AJW_Magnifier_G43", "LightOptic_T1");
		AddDefaultAttachmentStatFromTier(config, "AJW_Magnifier_Aimpoint3x_UnityTall", "LightOptic_T1");
		AddDefaultAttachmentStatFromTier(config, "AJW_Optic_ACOG_Chevron", "HeavyOptic_T2");
		AddDefaultAttachmentStatFromTier(config, "AJW_Optic_ACOG_Horseshoe", "HeavyOptic_T2");
		AddDefaultAttachmentStatFromTier(config, "AJW_Optic_ACOG_ACSS", "HeavyOptic_T2");
		AddDefaultAttachmentStatFromTier(config, "AJW_Optic_Accupower", "HeavyOptic_T2");
		AddDefaultAttachmentStatFromTier(config, "AJW_Optic_EoTechVudu", "HeavyOptic_T2");
		AddDefaultAttachmentStatFromTier(config, "AJW_Optic_Vortex", "HeavyOptic_T2");
		AddDefaultAttachmentStatFromTier(config, "AJW_Optic_ELCAN_Black", "HeavyOptic_T2");
		AddDefaultAttachmentStatFromTier(config, "AJW_Optic_ELCAN_FDE", "HeavyOptic_T2");
		AddDefaultAttachmentStatFromTier(config, "AJW_Optic_HAMR", "HeavyOptic_T2");
		AddDefaultAttachmentStatFromTier(config, "AJW_Optic_LeupoldHoloDEVO", "HeavyOptic_T2");
		AddDefaultAttachmentStatFromTier(config, "AJW_Optic_Leupold_M3A", "SniperOptic_T3");
		AddDefaultAttachmentStatFromTier(config, "AJW_Optic_K98", "SniperOptic_T3");
		AddDefaultAttachmentStatFromTier(config, "AJW_NGAL_Green", "Laser_Tactical");
		AddDefaultAttachmentStatFromTier(config, "AJW_NGAL_Red", "Laser_Tactical");
		AddDefaultAttachmentStatFromTier(config, "AJW_DBAL_Tan_Green", "Laser_Tactical");
		AddDefaultAttachmentStatFromTier(config, "AJW_DBAL_Tan_Red", "Laser_Tactical");
		AddDefaultAttachmentStatFromTier(config, "AJW_DBAL_Black_Green", "Laser_Tactical");
		AddDefaultAttachmentStatFromTier(config, "AJW_DBAL_Black_Red", "Laser_Tactical");
		AddDefaultAttachmentStatFromTier(config, "AJW_PEQ15_Tan_Green", "Laser_Tactical");
		AddDefaultAttachmentStatFromTier(config, "AJW_PEQ15_Tan_Red", "Laser_Tactical");
		AddDefaultAttachmentStatFromTier(config, "AJW_PEQ15_Black_Green", "Laser_Tactical");
		AddDefaultAttachmentStatFromTier(config, "AJW_PEQ15_Black_Red", "Laser_Tactical");
		AddDefaultAttachmentStatFromTier(config, "AJW_MAWL_Tan_Green", "Laser_Tactical");
		AddDefaultAttachmentStatFromTier(config, "AJW_MAWL_Tan_Red", "Laser_Tactical");
		AddDefaultAttachmentStatFromTier(config, "AJW_MAWL_Black_Green", "Laser_Tactical");
		AddDefaultAttachmentStatFromTier(config, "AJW_MAWL_Black_Red", "Laser_Tactical");
		AddDefaultAttachmentStatFromTier(config, "AJW_MOE_FG_Black", "Foregrip_T1");
		AddDefaultAttachmentStatFromTier(config, "AJW_MOE_FG_FDE", "Foregrip_T1");
		AddDefaultAttachmentStatFromTier(config, "AJW_AFG_FG_Black", "Foregrip_T2");
		AddDefaultAttachmentStatFromTier(config, "AJW_AFG_FG_FDE", "Foregrip_T2");
		AddDefaultAttachmentStatFromTier(config, "AJW_AFG2_FG_Black", "Foregrip_T2");
		AddDefaultAttachmentStatFromTier(config, "AJW_AFG2_FG_FDE", "Foregrip_T2");
		AddDefaultAttachmentStatFromTier(config, "AJW_Cobra_FG_Black", "Foregrip_T3");
		AddDefaultAttachmentStatFromTier(config, "AJW_CQR_FG_Black", "Foregrip_T3");
		AddDefaultAttachmentStatFromTier(config, "AJW_HK_FG_Black", "Foregrip_T3");
		AddDefaultAttachmentStatFromTier(config, "AJW_HK_FG_FDE", "Foregrip_T3");
		AddDefaultAttachmentStatFromTier(config, "AJW_Stark_FG_Black", "Foregrip_T3");
		AddDefaultAttachmentStatFromTier(config, "AJW_AK_PG_MOE_Black", "PistolGrip_T1");
		AddDefaultAttachmentStatFromTier(config, "AJW_AK_PG_MOE_Grey", "PistolGrip_T1");
		AddDefaultAttachmentStatFromTier(config, "AJW_AK_PG_MOE_FDE", "PistolGrip_T1");
		AddDefaultAttachmentStatFromTier(config, "AJW_AK_PG_MOE_OD", "PistolGrip_T1");
		AddDefaultAttachmentStatFromTier(config, "AJW_AK_PG_AK12_Black", "PistolGrip_T2");
		AddDefaultAttachmentStatFromTier(config, "AJW_AK_PG_AK12_Camo", "PistolGrip_T2");
		AddDefaultAttachmentStatFromTier(config, "AJW_AK_PG_AK12_FDE", "PistolGrip_T2");
		AddDefaultAttachmentStatFromTier(config, "AJW_AK_PG_MG47_Black", "PistolGrip_T2");
		AddDefaultAttachmentStatFromTier(config, "AJW_AK_PG_MG47_FDE", "PistolGrip_T2");
		AddDefaultAttachmentStatFromTier(config, "AJW_AK_PG_MG47_Red", "PistolGrip_T2");
		AddDefaultAttachmentStatFromTier(config, "AJW_AK_PG_MG47_Brass", "PistolGrip_T2");
		AddDefaultAttachmentStatFromTier(config, "AJW_AK_PG_MG47_Anared", "PistolGrip_T2");
		AddDefaultAttachmentStatFromTier(config, "AJW_AK_PG_RK3_Black", "PistolGrip_T3");
		AddDefaultAttachmentStatFromTier(config, "AJW_AK_PG_RK3_FDE", "PistolGrip_T3");
		AddDefaultAttachmentStatFromTier(config, "AJW_AK_PG_Scorpius_Grey", "PistolGrip_T3");
		AddDefaultAttachmentStatFromTier(config, "AJW_AK_PG_SI_Black", "PistolGrip_T3");
		AddDefaultAttachmentStatFromTier(config, "AJW_AK_PG_SI_FDE", "PistolGrip_T3");
		AddDefaultAttachmentStatFromTier(config, "AJW_AK_PG_TD_Black", "PistolGrip_T1");
		AddDefaultAttachmentStatFromTier(config, "AJW_AK_PG_TD_FDE", "PistolGrip_T1");
		AddDefaultAttachmentStatFromTier(config, "AJW_M4_Skele_PGrip", "PistolGrip_T3");
		AddDefaultAttachmentStatFromTier(config, "AJW_M4_PG_BCM_Black", "PistolGrip_T2");
		AddDefaultAttachmentStatFromTier(config, "AJW_M4_PG_BCM_FDE", "PistolGrip_T2");
		AddDefaultAttachmentStatFromTier(config, "AJW_M4_PG_DD_Black", "PistolGrip_T2");
		AddDefaultAttachmentStatFromTier(config, "AJW_M4_PG_DD_FDE", "PistolGrip_T2");
		AddDefaultAttachmentStatFromTier(config, "AJW_M4_PG_F1_Black", "PistolGrip_T3");
		AddDefaultAttachmentStatFromTier(config, "AJW_M4_PG_F1_Yellow", "PistolGrip_T3");
		AddDefaultAttachmentStatFromTier(config, "AJW_M4_PG_F1_Cyan", "PistolGrip_T3");
		AddDefaultAttachmentStatFromTier(config, "AJW_M4_PG_F1_OD", "PistolGrip_T3");
		AddDefaultAttachmentStatFromTier(config, "AJW_M4_PG_F1_Pink", "PistolGrip_T3");
		AddDefaultAttachmentStatFromTier(config, "AJW_M4_PG_F1_Red", "PistolGrip_T3");
		AddDefaultAttachmentStatFromTier(config, "AJW_M4_PG_Hogue_Black", "PistolGrip_T1");
		AddDefaultAttachmentStatFromTier(config, "AJW_M4_PG_Hogue_FDE", "PistolGrip_T1");
		AddDefaultAttachmentStatFromTier(config, "AJW_M4_PG_MOE_Black", "PistolGrip_T1");
		AddDefaultAttachmentStatFromTier(config, "AJW_M4_PG_MOE_FDE", "PistolGrip_T1");
		AddDefaultAttachmentStatFromTier(config, "AJW_M4_PG_HKERGO", "PistolGrip_T2");
		AddDefaultAttachmentStatFromTier(config, "AJW_M4_PG_HK_Black", "PistolGrip_T2");
		AddDefaultAttachmentStatFromTier(config, "AJW_M4_PG_HK_FDE", "PistolGrip_T2");
		AddDefaultAttachmentStatFromTier(config, "AJW_M4_PG_MOEK2_Black", "PistolGrip_T2");
		AddDefaultAttachmentStatFromTier(config, "AJW_M4_PG_MOEK2_FDE", "PistolGrip_T2");
		AddDefaultAttachmentStatFromTier(config, "AJW_M4_PG_TD_Black", "PistolGrip_T1");
		AddDefaultAttachmentStatFromTier(config, "AJW_M4_PG_TD_FDE", "PistolGrip_T1");
		AddDefaultAttachmentStatFromTier(config, "AJW_M4_PG_TD_Red", "PistolGrip_T1");
		AddDefaultAttachmentStatFromTier(config, "AJW_M4_CH_Aero", "Handguard_T1");
		AddDefaultAttachmentStatFromTier(config, "AJW_M4_CH_Aero_Black", "Handguard_T1");
		AddDefaultAttachmentStatFromTier(config, "AJW_M4_CH_Aero_ANred", "Handguard_T1");
		AddDefaultAttachmentStatFromTier(config, "AJW_M4_CH_Aero_Gold", "Handguard_T1");
		AddDefaultAttachmentStatFromTier(config, "AJW_Vityaz_DC_SN_Black", "Handguard_T1");
		AddDefaultAttachmentStatFromTier(config, "AJW_Vityaz_DC_SN_FDE", "Handguard_T1");
		AddDefaultAttachmentStatFromTier(config, "AJW_AK_DC_B33_Black", "Handguard_T1");
		AddDefaultAttachmentStatFromTier(config, "AJW_AK_DC_B33_FDE", "Handguard_T1");
		AddDefaultAttachmentStatFromTier(config, "AJW_74U_PDC_DC", "Handguard_T1");
		AddDefaultAttachmentStatFromTier(config, "AJW_HK_HG_STD_Quad_Grey", "Handguard_T2");
		AddDefaultAttachmentStatFromTier(config, "AJW_HK_HG_STD_Quad_Black", "Handguard_T2");
		AddDefaultAttachmentStatFromTier(config, "AJW_HK_HG_STD_Quad_FDE", "Handguard_T2");
		AddDefaultAttachmentStatFromTier(config, "AJW_HK_Geissele_HG10_Black", "Handguard_T2");
		AddDefaultAttachmentStatFromTier(config, "AJW_HK_Geissele_HG10_Grey", "Handguard_T2");
		AddDefaultAttachmentStatFromTier(config, "AJW_HK_Geissele_HG10_FDE", "Handguard_T2");
		AddDefaultAttachmentStatFromTier(config, "AJW_HK_Geissele_HG10_Rose", "Handguard_T2");
		AddDefaultAttachmentStatFromTier(config, "AJW_HK_Geissele_HG14_Grey", "Handguard_T3");
		AddDefaultAttachmentStatFromTier(config, "AJW_HK_Geissele_HG14_FDE", "Handguard_T3");
		AddDefaultAttachmentStatFromTier(config, "AJW_HK_Geissele_HG14_Rose", "Handguard_T3");
		AddDefaultAttachmentStatFromTier(config, "AJW_HK_Geissele_HG14_Black", "Handguard_T3");
		AddDefaultAttachmentStatFromTier(config, "AJW_M4_RISHndgrd", "Handguard_T2");
		AddDefaultAttachmentStatFromTier(config, "AJW_M4_BlockII_Hndgrd", "Handguard_T3");
		AddDefaultAttachmentStatFromTier(config, "AJW_M4_BlockII_HG_Black", "Handguard_T3");
		AddDefaultAttachmentStatFromTier(config, "AJW_M4_BlockII_HG_FDE", "Handguard_T3");
		AddDefaultAttachmentStatFromTier(config, "AJW_M4_BlockII_10_HG_Black", "Handguard_T2");
		AddDefaultAttachmentStatFromTier(config, "AJW_M4_BlockII_10_HG_FDE", "Handguard_T2");
		AddDefaultAttachmentStatFromTier(config, "AJW_M4_URX4_Hndgrd", "Handguard_T3");
		AddDefaultAttachmentStatFromTier(config, "AJW_M4_URX4_HG_Black", "Handguard_T3");
		AddDefaultAttachmentStatFromTier(config, "AJW_M4_URX4_HG_FDE", "Handguard_T3");
		AddDefaultAttachmentStatFromTier(config, "AJW_M4_URX4_10_HG_Black", "Handguard_T2");
		AddDefaultAttachmentStatFromTier(config, "AJW_M4_URX4_10_HG_FDE", "Handguard_T2");
		AddDefaultAttachmentStatFromTier(config, "AJW_M4_LVOA_HG_Black", "Handguard_T3");
		AddDefaultAttachmentStatFromTier(config, "AJW_M4_LVOA_HG_FDE", "Handguard_T3");
		AddDefaultAttachmentStatFromTier(config, "AJW_M4_URGI_10_HG_Black", "Handguard_T2");
		AddDefaultAttachmentStatFromTier(config, "AJW_M4_URGI_10_HG_FDE", "Handguard_T2");
		AddDefaultAttachmentStatFromTier(config, "AJW_M4_Honey_Hndgrd", "Handguard_T2");
		AddDefaultAttachmentStatFromTier(config, "AJW_M4_Honey_HG_Black", "Handguard_T2");
		AddDefaultAttachmentStatFromTier(config, "AJW_M4_Honey_HG_FDE", "Handguard_T2");
		AddDefaultAttachmentStatFromTier(config, "AJW_M4_Honey_HG_Badger", "Handguard_T2");
		AddDefaultAttachmentStatFromTier(config, "AJW_MCX_STD_HG_Black", "Handguard_T2");
		AddDefaultAttachmentStatFromTier(config, "AJW_MCX_STD_HG_FDE", "Handguard_T2");
		AddDefaultAttachmentStatFromTier(config, "AJW_MCX_STD_HG_Grey", "Handguard_T2");
		AddDefaultAttachmentStatFromTier(config, "AJW_MCX_LVAW_HG_Black", "Handguard_T3");
		AddDefaultAttachmentStatFromTier(config, "AJW_MCX_LVAW_HG_FDE", "Handguard_T3");
		AddDefaultAttachmentStatFromTier(config, "AJW_MCX_LT_HG_Black", "Handguard_T3");
		AddDefaultAttachmentStatFromTier(config, "AJW_MCX_LT_HG_FDE", "Handguard_T3");
		AddDefaultAttachmentStatFromTier(config, "AJW_MCX_LT_HG_OD", "Handguard_T3");
		AddDefaultAttachmentStatFromTier(config, "AJW_MCX_LCH_HG_Black", "Handguard_T3");
		AddDefaultAttachmentStatFromTier(config, "AJW_MCX_KM_HG_Black", "Handguard_T3");
		AddDefaultAttachmentStatFromTier(config, "AJW_MCX_KM_HG_FDE", "Handguard_T3");
		AddDefaultAttachmentStatFromTier(config, "AJW_MCX_KM_HG_OD", "Handguard_T3");
		AddDefaultAttachmentStatFromTier(config, "AJW_MCX_KM_HG_AnaRed", "Handguard_T3");
		AddDefaultAttachmentStatFromTier(config, "AJW_SCAR_MREX_HG_FDE", "Handguard_T3");
		AddDefaultAttachmentStatFromTier(config, "AJW_SCAR_MREX_HG_Black", "Handguard_T3");
		AddDefaultAttachmentStatFromTier(config, "AJW_SCAR_CASV_HG_FDE", "Handguard_T2");
		AddDefaultAttachmentStatFromTier(config, "AJW_SCAR_CASV_HG_Black", "Handguard_T2");
		AddDefaultAttachmentStatFromTier(config, "AJW_SCAR_PMM_HG_FDE", "Handguard_T3");
		AddDefaultAttachmentStatFromTier(config, "AJW_SCAR_PMM_HG_Black", "Handguard_T3");
		AddDefaultAttachmentStatFromTier(config, "AJW_AK_B30_HG_Black", "Handguard_T3");
		AddDefaultAttachmentStatFromTier(config, "AJW_AK_B30_HG_FDE", "Handguard_T3");
		AddDefaultAttachmentStatFromTier(config, "AJW_AK_Hexagon_HG_Black", "Handguard_T2");
		AddDefaultAttachmentStatFromTier(config, "AJW_AK_Hexagon_HG_FDE", "Handguard_T2");
		AddDefaultAttachmentStatFromTier(config, "AJW_AK_Hexagon_HG_Red", "Handguard_T2");
		AddDefaultAttachmentStatFromTier(config, "AJW_AK_MagpulL_HG_Black", "Handguard_T2");
		AddDefaultAttachmentStatFromTier(config, "AJW_AK_MagpulL_HG_FDE", "Handguard_T2");
		AddDefaultAttachmentStatFromTier(config, "AJW_AK_CMRD_HG_Black", "Handguard_T3");
		AddDefaultAttachmentStatFromTier(config, "AJW_AK_CMRD_HG_FDE", "Handguard_T3");
		AddDefaultAttachmentStatFromTier(config, "AJW_AK_AK100_HG", "Handguard_T1");
		AddDefaultAttachmentStatFromTier(config, "AJW_AK_B10_HG_Plastic", "Handguard_T1");
		AddDefaultAttachmentStatFromTier(config, "AJW_AK_B19_HG_Black", "Handguard_T2");
		AddDefaultAttachmentStatFromTier(config, "AJW_AK_B19_HG_FDE", "Handguard_T2");
		AddDefaultAttachmentStatFromTier(config, "AJW_AK_MagpulS_HG_Black", "Handguard_T2");
		AddDefaultAttachmentStatFromTier(config, "AJW_AK_MagpulS_HG_FDE", "Handguard_T2");
		AddDefaultAttachmentStatFromTier(config, "AJW_AK_Shark_HG_Wood", "Handguard_T1");
		AddDefaultAttachmentStatFromTier(config, "AJW_AK_SLR_HG_Black", "Handguard_T3");
		AddDefaultAttachmentStatFromTier(config, "AJW_AK_Sport1_HG_Black", "Handguard_T3");
		AddDefaultAttachmentStatFromTier(config, "AJW_AK_Sport1_HG_FDE", "Handguard_T3");
		AddDefaultAttachmentStatFromTier(config, "AJW_AK_Troy_HG_Black", "Handguard_T2");
		AddDefaultAttachmentStatFromTier(config, "AJW_AK_Troy_HG_FDE", "Handguard_T2");
		AddDefaultAttachmentStatFromTier(config, "AJW_AK74U_HG_STD", "Handguard_T1");
		AddDefaultAttachmentStatFromTier(config, "AJW_AK74U_HG_B11", "Handguard_T2");
		AddDefaultAttachmentStatFromTier(config, "AJW_AK74U_HG_Goliaf_Black", "Handguard_T3");
		AddDefaultAttachmentStatFromTier(config, "AJW_AK74U_HG_Goliaf_Copper", "Handguard_T3");
		AddDefaultAttachmentStatFromTier(config, "AJW_AR10_URX_HG_Black", "Handguard_T3");
		AddDefaultAttachmentStatFromTier(config, "AJW_AR10_URX_HG_FDE", "Handguard_T3");
		AddDefaultAttachmentStatFromTier(config, "AJW_AR10_CCMG_HG_Black", "Handguard_T3");
		AddDefaultAttachmentStatFromTier(config, "AJW_AR10_CCMG_HG_FDE", "Handguard_T3");
		AddDefaultAttachmentStatFromTier(config, "AJW_AR10_SWS_N6_HG", "Handguard_T3");
		AddDefaultAttachmentStatFromTier(config, "AJW_AR10_SWS_N6_10_HG", "Handguard_T2");
		AddDefaultAttachmentStatFromTier(config, "AJW_SA58_STD_HG_Grey", "Handguard_T1");
		AddDefaultAttachmentStatFromTier(config, "AJW_SA58_CASV_HG_Grey", "Handguard_T2");
		AddDefaultAttachmentStatFromTier(config, "AJW_Bipod_Harris", "Bipod_Special");
		AddDefaultAttachmentStatFromTier(config, "AJW_Surefire_Gunlight_Black", "Flashlight_Utility");
		AddDefaultAttachmentStatFromTier(config, "AJW_Surefire_Gunlight_FDE", "Flashlight_Utility");
		AddDefaultAttachmentStatFromTier(config, "AJW_Surefire_M600v_Gunlight_Black", "Flashlight_Utility");
		AddDefaultAttachmentStatFromTier(config, "AJW_Surefire_M600v_Gunlight_FDE", "Flashlight_Utility");
		AddDefaultAttachmentStatFromTier(config, "AJW_HKMk23SOCOM_LAM", "Laser_Tactical");
		AddDefaultAttachmentStatFromTier(config, "AJW_M1897_Bayonet", "Bayonet_Heavy");
		AddDefaultAttachmentStatFromTier(config, "AJW_12GA_MuzzleBreak", "Muzzle_T1");
		AddDefaultAttachmentStatFromTier(config, "AJW_M4_MD_Noveske_Black", "Muzzle_T2");
		AddDefaultAttachmentStatFromTier(config, "AJW_M4_MD_Noveske_FDE", "Muzzle_T2");
		AddDefaultAttachmentStatFromTier(config, "AJW_AK74M_Comp", "Muzzle_T2");
		AddDefaultAttachmentStatFromTier(config, "AJW_50cal_MD_M82_Black", "Muzzle_T3");
		AddDefaultAttachmentStatFromTier(config, "AJW_50cal_MD_AK50_Black", "Muzzle_T3");
		AddDefaultAttachmentStatFromTier(config, "AJW_SurefireRC2_Tan_Suppressor", "Suppressor_T2");
		AddDefaultAttachmentStatFromTier(config, "AJW_SurefireRC2_Black_Suppressor", "Suppressor_T2");
		AddDefaultAttachmentStatFromTier(config, "AJW_SurefireFA762K_Tan_Suppressor", "Suppressor_T2");
		AddDefaultAttachmentStatFromTier(config, "AJW_SurefireFA762K_Black_Suppressor", "Suppressor_T2");
		AddDefaultAttachmentStatFromTier(config, "AJW_HKG28_BTQD_Suppressor_Tan", "Suppressor_T3");
		AddDefaultAttachmentStatFromTier(config, "AJW_HKG28_BTQD_Suppressor_Black", "Suppressor_T3");
		AddDefaultAttachmentStatFromTier(config, "AJW_AACSDN_Suppressor_FDE", "Suppressor_T2");
		AddDefaultAttachmentStatFromTier(config, "AJW_AACSDN_Suppressor_Black", "Suppressor_T2");
		AddDefaultAttachmentStatFromTier(config, "AJW_Rotor43_Suppressor_Black", "Suppressor_T2");
		AddDefaultAttachmentStatFromTier(config, "AJW_Rotor43_Suppressor_Rattle", "Suppressor_T2");
		AddDefaultAttachmentStatFromTier(config, "AJW_Osprey_Suppressor_Black", "Suppressor_T2");
		AddDefaultAttachmentStatFromTier(config, "AJW_Osprey_Suppressor_FDE", "Suppressor_T2");
		AddDefaultAttachmentStatFromTier(config, "AJW_HKMk23SOCOM_Suppressor", "Suppressor_T2");
		AddDefaultAttachmentStatFromTier(config, "AJW_QDSSNT4_Suppressor_Black", "Suppressor_T3");
		AddDefaultAttachmentStatFromTier(config, "AJW_QDSSNT4_Suppressor_FDE", "Suppressor_T3");
		AddDefaultAttachmentStatFromTier(config, "AJW_Gemtech_Suppressor_Black", "Suppressor_T2");
		AddDefaultAttachmentStatFromTier(config, "AJW_Gemtech_Suppressor_FDE", "Suppressor_T2");
		AddDefaultAttachmentStatFromTier(config, "AJW_DTK4_Suppressor_Black", "Suppressor_T2");
		AddDefaultAttachmentStatFromTier(config, "AJW_DTK4_Suppressor_MC", "Suppressor_T2");
		AddDefaultAttachmentStatFromTier(config, "AJW_DTKP_Suppressor_Black", "Suppressor_T2");
		AddDefaultAttachmentStatFromTier(config, "AJW_DTKP_Suppressor_FDE", "Suppressor_T2");
		AddDefaultAttachmentStatFromTier(config, "AJW_Hexagon_Suppressor_Black", "Suppressor_T2");
		AddDefaultAttachmentStatFromTier(config, "AJW_PBS1_Suppressor", "Suppressor_T2");
		AddDefaultAttachmentStatFromTier(config, "AJW_PBS4_Suppressor", "Suppressor_T2");
		AddDefaultAttachmentStatFromTier(config, "AJW_50cal_Suppressor_Black", "Suppressor_T3");
		AddDefaultAttachmentStatFromTier(config, "AJW_50cal_Suppressor_Tan", "Suppressor_T3");
		AddDefaultAttachmentStatFromTier(config, "AJW_50cal_Suppressor_Wrapped_Black", "Suppressor_T3");
		AddDefaultAttachmentStatFromTier(config, "AJW_50cal_Suppressor_Wrapped_RG", "Suppressor_T3");
		AddDefaultAttachmentStatFromTier(config, "AJW_50cal_Suppressor_Wrapped_MC", "Suppressor_T3");
		AddDefaultAttachmentStatFromTier(config, "AJW_50cal_Suppressor_Wrapped_Tan", "Suppressor_T3");
		AddDefaultAttachmentStatFromTier(config, "AJW_50cal_Suppressor_Wrapped_TANMC", "Suppressor_T3");
		AddDefaultAttachmentStatFromTier(config, "AJW_50cal_Suppressor_Long_Black", "Suppressor_T3");
		AddDefaultAttachmentStatFromTier(config, "AJW_50cal_Suppressor_Long_Tan", "Suppressor_T3");
		AddDefaultAttachmentStatFromTier(config, "AJW_50cal_Suppressor_QDL_Black", "Suppressor_T3");
		AddDefaultAttachmentStatFromTier(config, "AJW_50cal_Suppressor_QDL_FDE", "Suppressor_T3");
		AddDefaultAttachmentStatFromTier(config, "AJW_SLX_Suppressor_FDE", "Suppressor_T3");
		AddDefaultAttachmentStatFromTier(config, "AJW_SLX_S_Suppressor_FDE", "Suppressor_T3");
		AddDefaultAttachmentStatFromTier(config, "AJW_BS_Magpul_MOE_FDE", "Stock_T1");
		AddDefaultAttachmentStatFromTier(config, "AJW_BS_Magpul_MOE_OD", "Stock_T1");
		AddDefaultAttachmentStatFromTier(config, "AJW_BS_Magpul_MOE_Green", "Stock_T1");
		AddDefaultAttachmentStatFromTier(config, "AJW_BS_Magpul_MOE_Grey", "Stock_T1");
		AddDefaultAttachmentStatFromTier(config, "AJW_BS_Magpul_MOE_Black", "Stock_T1");
		AddDefaultAttachmentStatFromTier(config, "AJW_BS_SOPMOD_Black", "Stock_T2");
		AddDefaultAttachmentStatFromTier(config, "AJW_BS_SOPMOD_FDE", "Stock_T2");
		AddDefaultAttachmentStatFromTier(config, "AJW_BS_PRS2_FDE", "Stock_T3");
		AddDefaultAttachmentStatFromTier(config, "AJW_BS_PRS2_Black", "Stock_T3");
		AddDefaultAttachmentStatFromTier(config, "AJW_BS_PRS3_FDE", "Stock_T3");
		AddDefaultAttachmentStatFromTier(config, "AJW_BS_PRS3_Black", "Stock_T3");
		AddDefaultAttachmentStatFromTier(config, "AJW_BS_PRS3_OD", "Stock_T3");
		AddDefaultAttachmentStatFromTier(config, "AJW_BS_PRS_Lite_FDE", "Stock_T3");
		AddDefaultAttachmentStatFromTier(config, "AJW_BS_PRS_Lite_Black", "Stock_T3");
		AddDefaultAttachmentStatFromTier(config, "AJW_BS_PRS_Lite_OD", "Stock_T3");
		AddDefaultAttachmentStatFromTier(config, "AJW_BS_HKG28_FDE", "Stock_T3");
		AddDefaultAttachmentStatFromTier(config, "AJW_BS_HKG28_Black", "Stock_T3");
		AddDefaultAttachmentStatFromTier(config, "AJW_MCX_Stock_Buffer", "Stock_T1");
		AddDefaultAttachmentStatFromTier(config, "AJW_BS_MCX_Buffer_Black", "Stock_T2");
		AddDefaultAttachmentStatFromTier(config, "AJW_BS_MCX_Buffer_AnaRed", "Stock_T2");
		AddDefaultAttachmentStatFromTier(config, "AJW_MCX_Stock_STD", "Stock_T2");
		AddDefaultAttachmentStatFromTier(config, "AJW_BS_MCX_Collapsible_Open", "Stock_T2");
		AddDefaultAttachmentStatFromTier(config, "AJW_BS_MCX_Collapsible_Closed", "Stock_T2");
		AddDefaultAttachmentStatFromTier(config, "AJW_BS_MCX_Skele", "Stock_T3");
		AddDefaultAttachmentStatFromTier(config, "AJW_BS_MCX_MiniSkele", "Stock_T3");
		AddDefaultAttachmentStatFromTier(config, "AJW_BS_MCX_Visor", "Stock_T2");
		AddDefaultAttachmentStatFromTier(config, "AJW_BS_AK12_Black", "Stock_T2");
		AddDefaultAttachmentStatFromTier(config, "AJW_BS_B5_Black", "Stock_T2");
		AddDefaultAttachmentStatFromTier(config, "AJW_BS_B5_FDE", "Stock_T2");
		AddDefaultAttachmentStatFromTier(config, "AJW_BS_Viper_Black", "Stock_T2");
		AddDefaultAttachmentStatFromTier(config, "AJW_BS_Viper_FDE", "Stock_T2");
		AddDefaultAttachmentStatFromTier(config, "AJW_BS_BCM_Black", "Stock_T2");
		AddDefaultAttachmentStatFromTier(config, "AJW_BS_BCM_FDE", "Stock_T2");
		AddDefaultAttachmentStatFromTier(config, "AJW_BS_CMMG_Black", "Stock_T2");
		AddDefaultAttachmentStatFromTier(config, "AJW_BS_DD_Black", "Stock_T2");
		AddDefaultAttachmentStatFromTier(config, "AJW_BS_DD_FDE", "Stock_T2");
		AddDefaultAttachmentStatFromTier(config, "AJW_BS_DS150_Black", "Stock_T2");
		AddDefaultAttachmentStatFromTier(config, "AJW_BS_DS150_FDE", "Stock_T2");
		AddDefaultAttachmentStatFromTier(config, "AJW_BS_FAB_GLC_Black", "Stock_T2");
		AddDefaultAttachmentStatFromTier(config, "AJW_BS_AK74M_Plastic", "Stock_T1");
		AddDefaultAttachmentStatFromTier(config, "AJW_BS_AK74M_PT1_Black", "Stock_T2");
		AddDefaultAttachmentStatFromTier(config, "AJW_BS_AK74M_PT3_Black", "Stock_T3");
		AddDefaultAttachmentStatFromTier(config, "AJW_BS_SA58_BRS_Black", "Stock_T2");
		AddDefaultAttachmentStatFromTier(config, "AJW_BS_SA58_Folding", "Stock_T2");
		AddDefaultAttachmentStatFromTier(config, "AJW_BS_HoneyBadger_FDE", "Stock_T3");
		AddDefaultAttachmentStatFromTier(config, "AJW_BS_HoneyBadger_Black", "Stock_T3");
		AddDefaultAttachmentStatFromTier(config, "AJW_BS_HoneyBadger_Badger", "Stock_T3");
		AddDefaultAttachmentStatFromTier(config, "AJW_EVO3_Stock_Standard_Grey", "Stock_T1");
		AddDefaultAttachmentStatFromTier(config, "AJW_EVO3_Stock_Standard_Black", "Stock_T1");
		AddDefaultAttachmentStatFromTier(config, "AJW_EVO3_Stock_Standard_FDE", "Stock_T1");
		AddDefaultAttachmentStatFromTier(config, "AJW_EVO3_Stock_Mini", "Stock_T2");
		AddDefaultAttachmentStatFromTier(config, "AJW_EVO3_Stock_BufferTube", "Stock_T2");
		AddDefaultAttachmentStatFromTier(config, "AJW_BD_Car15_Bttstck", "Stock_T1");
		AddDefaultAttachmentStatFromTier(config, "AJW_CZEVO3_Barrel_Long", "Handguard_T2");
		AddDefaultAttachmentStatFromTier(config, "AJW_CZEVO3_Barrel_Micro", "Handguard_T1");
		AddDefaultAttachmentStatFromTier(config, "AJW_SV98_OV_Chassis_FDE", "Stock_T3");
		AddDefaultAttachmentStatFromTier(config, "AJW_SV98_Suppressor_Black", "Suppressor_T3");
		AddDefaultAttachmentStatFromTier(config, "AJW_SVD_SAGChassis_Black", "Handguard_T3");
		AddDefaultAttachmentStatFromTier(config, "AJW_SVD_SAGChassis_Rattle", "Handguard_T3");
		AddDefaultAttachmentStatFromTier(config, "AJW_SVD_StockAdapt_Black", "Stock_T2");
		AddDefaultAttachmentStatFromTier(config, "AJW_R700_MagpulChassis_Black", "Stock_T3");
		AddDefaultAttachmentStatFromTier(config, "AJW_R700_MagpulChassis_OD", "Stock_T3");
		AddDefaultAttachmentStatFromTier(config, "AJW_R700_MagpulChassis_FDE", "Stock_T3");
		AddDefaultAttachmentStatFromTier(config, "AJW_MCX_Barrel_556", "Muzzle_T1");
		AddDefaultAttachmentStatFromTier(config, "AJW_MCX_Barrel_300", "Muzzle_T1");
		AddDefaultAttachmentStatFromTier(config, "AJW_M4_Trigger_Castellan_Black", "Neutral");
		AddDefaultAttachmentStatFromTier(config, "AJW_M4_Trigger_Castellan_Blue", "Neutral");
		AddDefaultAttachmentStatFromTier(config, "AJW_M4_Trigger_Castellan_BajaB", "Neutral");
		AddDefaultAttachmentStatFromTier(config, "AJW_M4_Trigger_Castellan_Orange", "Neutral");
		AddDefaultAttachmentStatFromTier(config, "AJW_M4_Trigger_Castellan_Pink", "Neutral");
		AddDefaultAttachmentStatFromTier(config, "AJW_M4_Trigger_Castellan_Purple", "Neutral");
		AddDefaultAttachmentStatFromTier(config, "AJW_M4_Trigger_Castellan_Red", "Neutral");
		AddDefaultAttachmentStatFromTier(config, "weaponLaserPointer", "Laser_Tactical");
		AddDefaultAttachmentStatFromTier(config, "weaponLaser", "Laser_Tactical");
		AddDefaultAttachmentStatFromTier(config, "PistolLaserPointer", "Laser_Tactical");
		AddDefaultAttachmentStatFromTier(config, "AJPEQLASER", "Laser_Tactical");
		AddDefaultAttachmentStatFromTier(config, "Expansion_ANPEQ15_Base", "Laser_Tactical");
		AddDefaultAttachmentStatFromTier(config, "Expansion_ANPEQ15_Red", "Laser_Tactical");
		AddDefaultAttachmentStatFromTier(config, "Expansion_ANPEQ15_Green", "Laser_Tactical");
		AddDefaultAttachmentStatFromTier(config, "Expansion_ANPEQ15_GreenNV", "Laser_Tactical");
		AddDefaultAttachmentStatFromTier(config, "Expansion_ANPEQ15_IR", "Laser_Tactical");
		AddDefaultAttachmentStatFromTier(config, "weaponFlashlight", "Flashlight_Utility");
		AddDefaultAttachmentStatFromTier(config, "weaponFlashlightRail", "Flashlight_Utility");
		AddDefaultAttachmentStatFromTier(config, "TLRLight", "Flashlight_Utility");
		AddDefaultAttachmentStatFromTier(config, "UniversalLight", "Flashlight_Utility");
		AddDefaultAttachmentStatFromTier(config, "weaponBayonet", "Bayonet_Heavy");
		AddDefaultAttachmentStatFromTier(config, "Bayonet", "Bayonet_Heavy");
		AddDefaultAttachmentStatFromTier(config, "M9A1Bayonet", "Bayonet_Heavy");
		AddDefaultAttachmentStatFromTier(config, "AK_Bayonet", "Bayonet_Heavy");
		AddDefaultAttachmentStatFromTier(config, "M9A1_Bayonet", "Bayonet_Heavy");
		AddDefaultAttachmentStatFromTier(config, "Mosin_Bayonet", "Bayonet_Heavy");
		AddDefaultAttachmentStatFromTier(config, "SKS_Bayonet", "Bayonet_Heavy");
		AddDefaultAttachmentStatFromTier(config, "AJ_SKS_Bayonet", "Bayonet_Heavy");
		AddDefaultAttachmentStatFromTier(config, "GCGN_M1Garand_Bayonet", "Bayonet_Heavy");
		AddDefaultAttachmentStatFromTier(config, "Expansion_Kar98_Bayonet", "Bayonet_Heavy");
		AddDefaultAttachmentStatFromTier(config, "Mosin_Compensator", "Muzzle_T1");
		AddDefaultAttachmentStatFromTier(config, "MP5_Compensator", "Muzzle_T1");
		AddDefaultAttachmentStatFromTier(config, "Aug_Barrel", "Muzzle_T1");
		AddDefaultAttachmentStatFromTier(config, "Groza_Barrel_Short", "Muzzle_T1");
		AddDefaultAttachmentStatFromTier(config, "GCGN_M1Garand_Muzzle", "Muzzle_T1");
		AddDefaultAttachmentStatFromTier(config, "AJShotgunchoke", "Muzzle_T1");
		AddDefaultAttachmentStatFromTier(config, "Groza_Barrel_Grip", "Muzzle_T2");
		AddDefaultAttachmentStatFromTier(config, "sr25Muzzle", "Muzzle_T2");
		AddDefaultAttachmentStatFromTier(config, "AJ50bmg", "Muzzle_T3");
		AddDefaultAttachmentStatFromTier(config, "ImprovisedSuppressor", "Suppressor_T1");
		AddDefaultAttachmentStatFromTier(config, "MakarovPBSuppressor", "Suppressor_T1");
		AddDefaultAttachmentStatFromTier(config, "ItemSuppressor", "Suppressor_T1");
		AddDefaultAttachmentStatFromTier(config, "22LRSuppressor", "Suppressor_T1");
		AddDefaultAttachmentStatFromTier(config, "M4_Suppressor", "Suppressor_T2");
		AddDefaultAttachmentStatFromTier(config, "AK_Suppressor", "Suppressor_T2");
		AddDefaultAttachmentStatFromTier(config, "PistolSuppressor", "Suppressor_T2");
		AddDefaultAttachmentStatFromTier(config, "Groza_Barrel_Suppressor", "Suppressor_T2");
		AddDefaultAttachmentStatFromTier(config, "ASH12Suppressor", "Suppressor_T2");
		AddDefaultAttachmentStatFromTier(config, "MP7A2Suppressor", "Suppressor_T2");
		AddDefaultAttachmentStatFromTier(config, "Suppressor9A91", "Suppressor_T2");
		AddDefaultAttachmentStatFromTier(config, "AJ_Normalized_Suppressor_Base", "Suppressor_T2");
		AddDefaultAttachmentStatFromTier(config, "AJ_Normalized_Suppressor_Black", "Suppressor_T2");
		AddDefaultAttachmentStatFromTier(config, "AJ_Normalized_Suppressor_Green", "Suppressor_T2");
		AddDefaultAttachmentStatFromTier(config, "AJ_Standardized_Suppressor_Base", "Suppressor_T2");
		AddDefaultAttachmentStatFromTier(config, "AJ_Standardized_Suppressor_Black", "Suppressor_T2");
		AddDefaultAttachmentStatFromTier(config, "AJ_Standardized_Suppressor_Green", "Suppressor_T2");
		AddDefaultAttachmentStatFromTier(config, "AJ_MPX_Suppressor_Base", "Suppressor_T2");
		AddDefaultAttachmentStatFromTier(config, "AJ_MPX_Suppressor_Black", "Suppressor_T2");
		AddDefaultAttachmentStatFromTier(config, "AJ_Agram_Suppressor_Base", "Suppressor_T2");
		AddDefaultAttachmentStatFromTier(config, "AJ_Agram_Suppressor_Black", "Suppressor_T2");
		AddDefaultAttachmentStatFromTier(config, "AJ_SPMOD", "Suppressor_T2");
		AddDefaultAttachmentStatFromTier(config, "AJSR3_SuppBase", "Suppressor_T2");
		AddDefaultAttachmentStatFromTier(config, "AJ_SR3Vikhr_Supp", "Suppressor_T2");
		AddDefaultAttachmentStatFromTier(config, "SR3_Vikhr_Supp", "Suppressor_T2");
		AddDefaultAttachmentStatFromTier(config, "AJAR15_SPR_SIL_Base", "Suppressor_T2");
		AddDefaultAttachmentStatFromTier(config, "AJAR15_SPR_SIL", "Suppressor_T2");
		AddDefaultAttachmentStatFromTier(config, "HoneyBadgerSuppressor", "Suppressor_T3");
		AddDefaultAttachmentStatFromTier(config, "QDLSuppressor", "Suppressor_T3");
		AddDefaultAttachmentStatFromTier(config, "AJ338_Suppressor", "Suppressor_T3");
		AddDefaultAttachmentStatFromTier(config, "AJ300acsupp", "Suppressor_T3");
		AddDefaultAttachmentStatFromTier(config, "AJ_SR25_Supp_Base", "Suppressor_T3");
		AddDefaultAttachmentStatFromTier(config, "AJ_SR25_Supp", "Suppressor_T3");
		AddDefaultAttachmentStatFromTier(config, "AJKivaari_338_Supp_Base", "Suppressor_T3");
		AddDefaultAttachmentStatFromTier(config, "AJKivaari_338_Supp", "Suppressor_T3");
		AddDefaultAttachmentStatFromTier(config, "AJ_ScarH_SIL_Base", "Suppressor_T3");
		AddDefaultAttachmentStatFromTier(config, "AJ_ScarH_SIL_Tan", "Suppressor_T3");
		AddDefaultAttachmentStatFromTier(config, "AJ_ScarH_SIL_Black", "Suppressor_T3");
		AddDefaultAttachmentStatFromTier(config, "AJGevar_Suppressor_Black", "Suppressor_T3");
		AddDefaultAttachmentStatFromTier(config, "AJGevar_Suppressor_Tan", "Suppressor_T3");
		AddDefaultAttachmentStatFromTier(config, "AJGevar_Suppressor_Green", "Suppressor_T3");
		AddDefaultAttachmentStatFromTier(config, "AJ_LNormalized_Suppressor_Base", "Suppressor_T3");
		AddDefaultAttachmentStatFromTier(config, "AJ_LNormalized_Suppressor_Black", "Suppressor_T3");
		AddDefaultAttachmentStatFromTier(config, "AJ_LNormalized_Suppressor_Green", "Suppressor_T3");
		AddDefaultAttachmentStatFromTier(config, "AJ_LStandardized_Suppressor_Base", "Suppressor_T3");
		AddDefaultAttachmentStatFromTier(config, "AJ_LStandardized_Suppressor_Black", "Suppressor_T3");
		AddDefaultAttachmentStatFromTier(config, "AJ_LStandardized_Suppressor_Green", "Suppressor_T3");
		AddDefaultAttachmentStatFromTier(config, "AJ_50bmg_Suppressor_Base", "Suppressor_T3");
		AddDefaultAttachmentStatFromTier(config, "AJ_50bmg_Suppressor_B", "Suppressor_T3");
		AddDefaultAttachmentStatFromTier(config, "AJ_50bmg_Suppressor_M", "Suppressor_T3");
		AddDefaultAttachmentStatFromTier(config, "AJ_50bmg_Suppressor_S", "Suppressor_T3");
		AddDefaultAttachmentStatFromTier(config, "AJ_50bmg_Suppressor_U", "Suppressor_T3");
		AddDefaultAttachmentStatFromTier(config, "AJ_50bmg_Suppressor_W", "Suppressor_T3");
		AddDefaultAttachmentStatFromTier(config, "AJ_408_Suppressor_T", "Suppressor_T3");
		AddDefaultAttachmentStatFromTier(config, "AJAR15_SPR_SQSIL_Base", "Suppressor_T3");
		AddDefaultAttachmentStatFromTier(config, "AJAR15_SPR_SQSIL", "Suppressor_T3");
		AddDefaultAttachmentStatFromTier(config, "GhillieAtt_ColorBase", "WeaponWrap_Utility");
		AddDefaultAttachmentStatFromTier(config, "Groza_LowerReceiver", "Handguard_T2");
		AddDefaultAttachmentStatFromTier(config, "GrozaGL_LowerReceiver", "Handguard_T2");
		AddDefaultAttachmentStatFromTier(config, "Mag_Expansion_M9_15Rnd", "StandardMag_Neutral");
		AddDefaultAttachmentStatFromTier(config, "Mag_Expansion_G36_30Rnd", "StandardMag_Neutral");
		AddDefaultAttachmentStatFromTier(config, "Mag_Expansion_M14_10Rnd", "StandardMag_Neutral");
		AddDefaultAttachmentStatFromTier(config, "Mag_Expansion_M14_20Rnd", "StandardMag_Neutral");
		AddDefaultAttachmentStatFromTier(config, "Mag_Expansion_MPX_50Rnd", "HighCap_Heavy");
		AddDefaultAttachmentStatFromTier(config, "Mag_Expansion_MP7_40Rnd", "HighCap_Heavy");
		AddDefaultAttachmentStatFromTier(config, "Mag_Expansion_Kedr_20Rnd", "StandardMag_Neutral");
		AddDefaultAttachmentStatFromTier(config, "Mag_Expansion_Vityaz_30Rnd", "StandardMag_Neutral");
		AddDefaultAttachmentStatFromTier(config, "Mag_Expansion_AWM_5rnd", "StandardMag_Neutral");
		AddDefaultAttachmentStatFromTier(config, "Mag_Expansion_Taser", "StandardMag_Neutral");
	}

	static bool HasTierMultiplier(AJGunplayAdminConfig config, string tierKey)
	{
		foreach (AJTierMultiplierOverride tierOverride : config.TierMultiplierOverrides)
		{
			if (tierOverride && tierOverride.TierKey == tierKey)
			{
				return true;
			}
		}

		return false;
	}

	static bool HasAttachmentTier(AJGunplayAdminConfig config, string className)
	{
		foreach (AJAttachmentTierOverride tierOverride : config.AttachmentTierOverrides)
		{
			if (tierOverride && tierOverride.ClassName == className)
			{
				return true;
			}
		}

		return false;
	}

	static bool HasAttachmentStat(AJGunplayAdminConfig config, string className)
	{
		foreach (AJAttachmentStatOverride statOverride : config.AttachmentStatOverrides)
		{
			if (statOverride && statOverride.ClassName == className)
			{
				return true;
			}
		}

		return false;
	}

	static void AddDefaultTierMultiplier(AJGunplayAdminConfig config, string tierKey)
	{
		if (HasTierMultiplier(config, tierKey))
		{
			return;
		}

		config.TierMultiplierOverrides.Insert(new AJTierMultiplierOverride(tierKey, 1.0, 1.0, 1.0, 1.0, 1.0));
	}

	static void AddDefaultAttachmentTier(AJGunplayAdminConfig config, string className, string tierKey)
	{
		if (HasAttachmentTier(config, className))
		{
			return;
		}

		config.AttachmentTierOverrides.Insert(new AJAttachmentTierOverride(className, tierKey));
	}

	static void AddDefaultAttachmentStatFromTier(AJGunplayAdminConfig config, string className, string tierKey)
	{
		if (HasAttachmentStat(config, className))
		{
			return;
		}

		if (tierKey == "Foregrip_T1")
		{
			config.AttachmentStatOverrides.Insert(new AJAttachmentStatOverride(className, "Foregrip", "T1", 0.70, 0.925, 1.03, 1.05, 0.90));
			return;
		}

		if (tierKey == "Foregrip_T2")
		{
			config.AttachmentStatOverrides.Insert(new AJAttachmentStatOverride(className, "Foregrip", "T2", 0.40, 0.85, 1.06, 1.10, 0.80));
			return;
		}

		if (tierKey == "Foregrip_T3")
		{
			config.AttachmentStatOverrides.Insert(new AJAttachmentStatOverride(className, "Foregrip", "T3", 0.10, 0.775, 1.08, 1.15, 0.70));
			return;
		}

		if (tierKey == "PistolGrip_T1")
		{
			config.AttachmentStatOverrides.Insert(new AJAttachmentStatOverride(className, "Pistol Grip", "T1", 0.70, 1.00, 1.05, 1.00, 0.90));
			return;
		}

		if (tierKey == "PistolGrip_T2")
		{
			config.AttachmentStatOverrides.Insert(new AJAttachmentStatOverride(className, "Pistol Grip", "T2", 0.40, 0.97, 1.10, 1.02, 0.80));
			return;
		}

		if (tierKey == "PistolGrip_T3")
		{
			config.AttachmentStatOverrides.Insert(new AJAttachmentStatOverride(className, "Pistol Grip", "T3", 0.10, 0.94, 1.15, 1.04, 0.70));
			return;
		}

		if (tierKey == "Stock_T1")
		{
			config.AttachmentStatOverrides.Insert(new AJAttachmentStatOverride(className, "Stock", "T1", 0.70, 0.85, 1.00, 1.05, 1.00));
			return;
		}

		if (tierKey == "Stock_T2")
		{
			config.AttachmentStatOverrides.Insert(new AJAttachmentStatOverride(className, "Stock", "T2", 0.40, 0.70, 0.99, 1.10, 1.00));
			return;
		}

		if (tierKey == "Stock_T3")
		{
			config.AttachmentStatOverrides.Insert(new AJAttachmentStatOverride(className, "Stock", "T3", 0.10, 0.55, 0.98, 1.15, 1.00));
			return;
		}

		if (tierKey == "Handguard_T1")
		{
			config.AttachmentStatOverrides.Insert(new AJAttachmentStatOverride(className, "Handguard", "T1", 1.00, 0.85, 1.02, 1.10, 0.90));
			return;
		}

		if (tierKey == "Handguard_T2")
		{
			config.AttachmentStatOverrides.Insert(new AJAttachmentStatOverride(className, "Handguard", "T2", 0.94, 0.70, 1.04, 1.20, 0.80));
			return;
		}

		if (tierKey == "Handguard_T3")
		{
			config.AttachmentStatOverrides.Insert(new AJAttachmentStatOverride(className, "Handguard", "T3", 0.88, 0.55, 1.06, 1.30, 0.70));
			return;
		}

		if (tierKey == "Bipod_Special")
		{
			config.AttachmentStatOverrides.Insert(new AJAttachmentStatOverride(className, "Bipod", "Special", 0.70, 0.43, 0.86, 1.16, 1.00));
			return;
		}

		if (tierKey == "LightOptic_T1")
		{
			config.AttachmentStatOverrides.Insert(new AJAttachmentStatOverride(className, "Optic", "T1", 1.00, 0.985, 1.05, 1.10, 1.00));
			return;
		}

		if (tierKey == "HeavyOptic_T2")
		{
			config.AttachmentStatOverrides.Insert(new AJAttachmentStatOverride(className, "Optic", "T2", 1.00, 0.97, 0.95, 1.20, 1.00));
			return;
		}

		if (tierKey == "SniperOptic_T3")
		{
			config.AttachmentStatOverrides.Insert(new AJAttachmentStatOverride(className, "Optic", "T3", 1.00, 0.955, 0.85, 1.30, 1.00));
			return;
		}

		if (tierKey == "Laser_Tactical")
		{
			config.AttachmentStatOverrides.Insert(new AJAttachmentStatOverride(className, "Laser", "Tactical", 1.00, 1.00, 1.00, 1.00, 0.55));
			return;
		}

		if (tierKey == "Flashlight_Utility")
		{
			config.AttachmentStatOverrides.Insert(new AJAttachmentStatOverride(className, "Flashlight", "Utility", 1.00, 1.04, 0.96, 1.00, 1.00));
			return;
		}

		if (tierKey == "Bayonet_Heavy")
		{
			config.AttachmentStatOverrides.Insert(new AJAttachmentStatOverride(className, "Bayonet", "Heavy", 1.00, 1.08, 0.92, 1.00, 1.00));
			return;
		}

		if (tierKey == "Muzzle_T1")
		{
			config.AttachmentStatOverrides.Insert(new AJAttachmentStatOverride(className, "Muzzle", "T1", 0.85, 0.925, 1.00, 1.05, 0.95));
			return;
		}

		if (tierKey == "Muzzle_T2")
		{
			config.AttachmentStatOverrides.Insert(new AJAttachmentStatOverride(className, "Muzzle", "T2", 0.70, 0.85, 0.99, 1.10, 0.90));
			return;
		}

		if (tierKey == "Muzzle_T3")
		{
			config.AttachmentStatOverrides.Insert(new AJAttachmentStatOverride(className, "Muzzle", "T3", 0.55, 0.775, 0.98, 1.15, 0.85));
			return;
		}

		if (tierKey == "Suppressor_T1")
		{
			config.AttachmentStatOverrides.Insert(new AJAttachmentStatOverride(className, "Suppressor", "T1", 0.85, 1.00, 0.98, 1.05, 0.95));
			return;
		}

		if (tierKey == "Suppressor_T2")
		{
			config.AttachmentStatOverrides.Insert(new AJAttachmentStatOverride(className, "Suppressor", "T2", 0.70, 1.01, 0.96, 1.10, 0.90));
			return;
		}

		if (tierKey == "Suppressor_T3")
		{
			config.AttachmentStatOverrides.Insert(new AJAttachmentStatOverride(className, "Suppressor", "T3", 0.55, 1.02, 0.94, 1.15, 0.85));
			return;
		}

		if (tierKey == "WeaponWrap_Utility")
		{
			config.AttachmentStatOverrides.Insert(new AJAttachmentStatOverride(className, "Wrap", "Utility", 1.00, 0.925, 0.97, 1.03, 1.00));
			return;
		}

		if (tierKey == "StandardMag_Neutral")
		{
			config.AttachmentStatOverrides.Insert(new AJAttachmentStatOverride(className, "Magazine", "Standard", 1.00, 1.00, 1.00, 1.00, 1.00));
			return;
		}

		if (tierKey == "HighCap_Heavy")
		{
			config.AttachmentStatOverrides.Insert(new AJAttachmentStatOverride(className, "Magazine", "HighCap", 1.02, 1.03, 0.98, 1.00, 1.00));
			return;
		}

		if (tierKey == "Neutral")
		{
			config.AttachmentStatOverrides.Insert(new AJAttachmentStatOverride(className, "Neutral", "Neutral", 1.00, 1.00, 1.00, 1.00, 1.00));
			return;
		}

		config.AttachmentStatOverrides.Insert(new AJAttachmentStatOverride(className, "Custom", tierKey, 1.0, 1.0, 1.0, 1.0, 1.0));
	}
}
