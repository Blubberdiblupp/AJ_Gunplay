modded class RifleBoltLock_Base
{
	override void EEItemAttached(EntityAI item, string slot_name)
	{
		super.EEItemAttached(item, slot_name);
		
		if (m_AJStatsManager)
		{
			m_AJStatsDirty = true;
			AJRecalculateStats();
		}
	}
	
	override void EEItemDetached(EntityAI item, string slot_name)
	{
		super.EEItemDetached(item, slot_name);
		
		if (m_AJStatsManager)
		{
			m_AJStatsDirty = true;
			AJRecalculateStats();
		}
	}
}
