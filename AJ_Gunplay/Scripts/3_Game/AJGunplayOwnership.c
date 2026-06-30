class AJGunplayOwnership
{
	static bool IsModLoaded(string modName)
	{
		return GetGame().ConfigIsExisting("CfgPatches " + modName);
	}
	
	static bool OwnsCommonGunplay()
	{
		if (IsModLoaded("SNAFU_Gunplay")) return false;
		if (IsModLoaded("Vanilla_Gunplay")) return false;
		if (IsModLoaded("Expansion_Gunplay")) return false;
		
		return true;
	}
	
	static bool IsAJClass(string className)
	{
		if (className == "") return false;
		if (className.Contains("AJW_")) return true;
		if (className.Contains("AJs_")) return true;
		
		return false;
	}
	
	static bool ShouldOwnItemType(string itemType, array<string> attachmentTypes = null)
	{
		if (IsAJClass(itemType))
		{
			return true;
		}
		
		if (attachmentTypes)
		{
			foreach (string attachmentType : attachmentTypes)
			{
				if (IsAJClass(attachmentType))
				{
					return true;
				}
			}
		}
		
		return OwnsCommonGunplay();
	}
}
