modded class InspectMenuNew
{
	protected Widget m_AJInspectStatsDisplay;
	
	override void SetItem(EntityAI item)
	{
		super.SetItem(item);
		UpdateAJInspectStats(item);
	}
	
	protected void UpdateAJInspectStats(EntityAI item)
	{
		EnsureAJInspectStatsDisplay();
		if (!m_AJInspectStatsDisplay)
		{
			return;
		}
		
		AJDisplayData displayData = AJDisplayStats.GetDisplay(item);
		if (!displayData)
		{
			m_AJInspectStatsDisplay.Show(false);
			return;
		}
		
		UpdateAJInspectStatsDisplay(displayData);
		
		m_AJInspectStatsDisplay.Show(true);
		HideCompetingAJInspectStatsDisplay();
		GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(this.HideCompetingAJInspectStatsDisplay, 1, false);
	}
	
	protected void UpdateAJInspectStatsDisplay(AJDisplayData displayData)
	{
		SetAJInspectText("tier_value", displayData.TierLabel, 0xFFFFFFFF);
		SetAJInspectText("recoil_label", displayData.Line1Label, 0xFFAF9442);
		SetAJInspectText("recoil_value", displayData.Line1Value, displayData.Line1Color);
		SetAJInspectText("sway_label", displayData.Line2Label, 0xFFAF9442);
		SetAJInspectText("sway_value", displayData.Line2Value, displayData.Line2Color);
		SetAJInspectText("ads_label", displayData.Line3Label, 0xFFAF9442);
		SetAJInspectText("ads_value", displayData.Line3Value, displayData.Line3Color);
		SetAJInspectText("precision_label", displayData.Line4Label, 0xFFAF9442);
		SetAJInspectText("precision_value", displayData.Line4Value, displayData.Line4Color);
		SetAJInspectText("hipfire_label", displayData.Line5Label, 0xFFAF9442);
		SetAJInspectText("hipfire_value", displayData.Line5Value, displayData.Line5Color);
		SetAJInspectLineVisible("hipfire", displayData.ShowLine5);
	}
	
	protected void EnsureAJInspectStatsDisplay()
	{
		if (m_AJInspectStatsDisplay)
		{
			return;
		}
		
		if (!layoutRoot)
		{
			return;
		}
		
		Widget parent = layoutRoot.FindAnyWidget("ItemFrameWidgetPanel");
		if (!parent)
		{
			parent = layoutRoot;
		}
		
		m_AJInspectStatsDisplay = GetGame().GetWorkspace().CreateWidgets("AJ_Gunplay/GUI/layouts/AJItemStatsInspect.layout", parent);
		if (m_AJInspectStatsDisplay)
		{
			m_AJInspectStatsDisplay.Show(false);
		}
	}
	
	protected void SetAJInspectText(string widgetName, string text, int color)
	{
		TextWidget widget = TextWidget.Cast(m_AJInspectStatsDisplay.FindAnyWidget(widgetName));
		if (!widget)
		{
			return;
		}
		
		widget.SetText(text);
		widget.SetColor(color);
	}
	
	protected void SetAJInspectLineVisible(string widgetName, bool visible)
	{
		Widget widget = m_AJInspectStatsDisplay.FindAnyWidget(widgetName);
		if (widget)
		{
			widget.Show(visible);
		}
	}
	
	protected void HideCompetingAJInspectStatsDisplay()
	{
		if (!layoutRoot)
		{
			return;
		}
		
		Widget snafuStatsDisplay = layoutRoot.FindAnyWidget("SNAFUStatsDisplay");
		if (snafuStatsDisplay)
		{
			snafuStatsDisplay.Show(false);
		}
	}
}
