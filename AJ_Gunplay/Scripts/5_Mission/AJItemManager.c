modded class ItemManager
{
	protected Widget m_AJStatsDisplay;
	protected Widget m_AJStatsParent;
	
	void ItemManager(Widget root)
	{
		Widget statsParent;
		if (root)
		{
			statsParent = root.FindAnyWidget("GridSpacerWidget1");
		}
		
		if (statsParent)
		{
			m_AJStatsParent = statsParent;
			m_AJStatsDisplay = GetGame().GetWorkspace().CreateWidgets("AJ_Gunplay/GUI/layouts/AJItemStatsToolTip.layout", statsParent);
			if (m_AJStatsDisplay)
			{
				m_AJStatsDisplay.Show(false);
			}
		}
	}
	
	override void PrepareTooltip(EntityAI item, int x = 0, int y = 0)
	{
		super.PrepareTooltip(item, x, y);
		
		if (!m_AJStatsDisplay)
		{
			return;
		}
		
		if (!item)
		{
			m_AJStatsDisplay.Show(false);
			return;
		}
		
		AJDisplayData displayData = AJDisplayStats.GetDisplay(item);
		if (!displayData)
		{
			m_AJStatsDisplay.Show(false);
			return;
		}
		
		UpdateAJStatsTooltip(displayData);
		m_AJStatsDisplay.Show(true);
		HideCompetingAJStatsDisplay();
		GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(this.HideCompetingAJStatsDisplay, 1, false);
	}
	
	protected void UpdateAJStatsTooltip(AJDisplayData displayData)
	{
		SetAJText("tier_value", displayData.TierLabel, 0xFFFFFFFF);
		SetAJText("recoil_label", displayData.Line1Label, 0xFFAF9442);
		SetAJText("recoil_value", displayData.Line1Value, displayData.Line1Color);
		SetAJText("sway_label", displayData.Line2Label, 0xFFAF9442);
		SetAJText("sway_value", displayData.Line2Value, displayData.Line2Color);
		SetAJText("ads_label", displayData.Line3Label, 0xFFAF9442);
		SetAJText("ads_value", displayData.Line3Value, displayData.Line3Color);
		SetAJText("precision_label", displayData.Line4Label, 0xFFAF9442);
		SetAJText("precision_value", displayData.Line4Value, displayData.Line4Color);
		SetAJText("hipfire_label", displayData.Line5Label, 0xFFAF9442);
		SetAJText("hipfire_value", displayData.Line5Value, displayData.Line5Color);
		SetAJLineVisible("hipfire", displayData.ShowLine5);
	}
	
	protected void SetAJText(string widgetName, string text, int color)
	{
		TextWidget widget = TextWidget.Cast(m_AJStatsDisplay.FindAnyWidget(widgetName));
		if (!widget)
		{
			return;
		}
		
		widget.SetText(text);
		widget.SetColor(color);
	}
	
	protected void SetAJLineVisible(string widgetName, bool visible)
	{
		Widget widget = m_AJStatsDisplay.FindAnyWidget(widgetName);
		if (widget)
		{
			widget.Show(visible);
		}
	}
	
	protected void HideCompetingAJStatsDisplay()
	{
		if (!m_AJStatsParent)
		{
			return;
		}
		
		Widget snafuStatsDisplay = m_AJStatsParent.FindAnyWidget("SNAFUStatsDisplay");
		if (snafuStatsDisplay)
		{
			snafuStatsDisplay.Show(false);
		}
	}
	
	protected string FormatAJDelta(float multiplier)
	{
		if (Math.AbsFloat(multiplier - 1.0) < 0.001)
		{
			return "0%";
		}
		
		int rounded = Math.Round((multiplier - 1.0) * 100.0);
		if (rounded > 0)
		{
			return string.Format("+%1%%", rounded);
		}
		
		return string.Format("%1%%", rounded);
	}
	
	protected int GetAJDeltaColor(float multiplier, bool higherIsBetter)
	{
		if (Math.AbsFloat(multiplier - 1.0) < 0.001)
		{
			return 0xFFFFFFFF;
		}
		
		bool improved;
		if (higherIsBetter)
		{
			improved = multiplier > 1.0;
		}
		else
		{
			improved = multiplier < 1.0;
		}
		
		if (improved)
		{
			return 0xFF22DD66;
		}
		
		return 0xFFFF5555;
	}
}
