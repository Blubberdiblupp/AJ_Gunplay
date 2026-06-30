class CfgPatches
{
	class AJ_Gunplay
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 1.25;
		requiredAddons[] = 
		{
			"DZ_Data",
			"DZ_Weapons_Firearms",
			"DZ_Weapons_Magazines",
			"DZ_Weapons_Ammunition",
			"DZ_Weapons_Muzzles",
			"DZ_Weapons_Optics",
			"DZ_Weapons_Supports",
			"AJs_Weapons_8mm",
			"AJs_Weapons_Ammo",
			"AJs_Weapons_AnimsIDs",
			"AJs_Weapons_AssultRifles",
			"AJs_Weapons_Attachments",
			"AJs_Weapons_Attachments_Handguards",
			"AJs_Weapons_Attachments_Lights",
			"AJs_Weapons_Attachments_Magazines",
			"AJs_Weapons_Attachments_Muzzles",
			"AJs_Weapons_Attachments_Stocks",
			"AJs_Weapons_Data",
			"AJs_Weapons_Firearms",
			"AJs_Weapons_Firearms_ACR",
			"AJs_Weapons_Firearms_AJW_Car15",
			"AJs_Weapons_Firearms_AK105",
			"AJs_Weapons_Firearms_AK5C",
			"AJs_Weapons_Firearms_AK74M",
			"AJs_Weapons_Firearms_AKS74U",
			"AJs_Weapons_Firearms_HK416",
			"AJs_Weapons_Firearms_HoneyBadger",
			"AJs_Weapons_Firearms_M4A1",
			"AJs_Weapons_Firearms_MCX",
			"AJs_Weapons_Firearms_SA58",
			"AJs_Weapons_Firearms_SCARH",
			"AJs_Weapons_Firearms_SCARL",
			"AJs_Weapons_Firearms_SMG",
			"AJs_Weapons_Firearms_XM7",
			"AJs_Weapons_Lasers",
			"AJs_Weapons_Lasers_Impacts",
			"AJs_Weapons_LMG",
			"AJs_Weapons_LMG_M60E6",
			"AJs_Weapons_LMG_PKM",
			"AJs_Weapons_Optics",
			"AJs_Weapons_Optics_AccuPower",
			"AJs_Weapons_Optics_ACOG",
			"AJs_Weapons_Optics_Car15",
			"AJs_Weapons_Optics_DEVO",
			"AJs_Weapons_Optics_ELCAN",
			"AJs_Weapons_Optics_EOTech_EXPS3",
			"AJs_Weapons_Optics_HAMROptic",
			"AJs_Weapons_Optics_HydraMounts",
			"AJs_Weapons_Optics_MicroT2",
			"AJs_Weapons_Optics_OKP7",
			"AJs_Weapons_Optics_SRO",
			"AJs_Weapons_Optics_StrikeFire",
			"AJs_Weapons_Optics_Vudu",
			"AJs_Weapons_Pistols",
			"AJs_Weapons_Pistols_10mm",
			"AJs_Weapons_Pistols_Beretta92FS",
			"AJs_Weapons_Pistols_CM_TaranTactical",
			"AJs_Weapons_Pistols_CZP09",
			"AJs_Weapons_Pistols_DesertEagle",
			"AJs_Weapons_Pistols_DWX",
			"AJs_Weapons_Pistols_HKMk23SOCOM",
			"AJs_Weapons_Pistols_Kimber1911",
			"AJs_Weapons_Rifles",
			"AJs_Weapons_Rifles_EBR_SASS",
			"AJs_Weapons_Rifles_Gewehr43",
			"AJs_Weapons_Rifles_HKG28",
			"AJs_Weapons_Rifles_MarlinTactical",
			"AJs_Weapons_Rifles_MK12",
			"AJs_Weapons_Rifles_SR25",
			"AJs_Weapons_Scripts",
			"AJs_Weapons_Shotguns",
			"AJs_Weapons_Shotguns_DMK12",
			"AJs_Weapons_Shotguns_M1897",
			"AJs_Weapons_Shotguns_Mossberg590",
			"AJs_Weapons_SMGs_EVO3",
			"AJs_Weapons_SMGs_PPSH",
			"AJs_Weapons_SMGs_Vityaz",
			"AJs_Weapons_Snipers",
			"AJs_Weapons_Snipers_AK50",
			"AJs_Weapons_Snipers_AWM",
			"AJs_Weapons_Snipers_GOL",
			"AJs_Weapons_Snipers_K98_Tac",
			"AJs_Weapons_Snipers_Kar98",
			"AJs_Weapons_Snipers_M40A3",
			"AJs_Weapons_Snipers_M82A1CQ",
			"AJs_Weapons_Snipers_R700",
			"AJs_Weapons_Snipers_SV98",
			"AJs_Weapons_Snipers_SVD",
			"AJs_Weapons_Sounds",
			"AJs_Weapons_Triggers"
		};
	};
};

class CfgMods
{
	class AJ_Gunplay
	{
		dir = "AJ_Gunplay";
		picture = "";
		action = "";
		hideName = 0;
		hidePicture = 0;
		name = "";
		credits = "";
		author = "Blubber";
		authorID = "0";
		version = "1.0";
		extra = 0;
		type = "mod";
		dependencies[] = {"Game","World","Mission"};
		
		class defs
		{
			class gameScriptModule
			{
				value = "";
				files[] = {"AJ_Gunplay/Scripts/3_Game"};
			};
			class worldScriptModule
			{
				value = "";
				files[] = {"AJ_Gunplay/Scripts/4_World"};
			};
			class missionScriptModule
			{
				value = "";
				files[] = {"AJ_Gunplay/Scripts/5_Mission"};
			};
		};
	};
};
