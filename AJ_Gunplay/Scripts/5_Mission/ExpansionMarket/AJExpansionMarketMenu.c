#ifdef EXPANSIONMODMARKET
modded class ExpansionMarketMenu
{
	protected Widget m_AJMarketStatsDisplay;
	
	void ExpansionMarketMenu()
	{
		EnsureAJMarketStatsDisplay();
	}
	
	override void UpdatePreview()
	{
		super.UpdatePreview();
		UpdateAJMarketStats(EntityAI.Cast(m_CurrentPreviewObject), GetAJMarketItemType(), GetAJMarketAttachmentTypes());
	}
	
	protected void UpdateAJMarketStats(EntityAI item, string itemType, array<string> attachmentTypes)
	{
		EnsureAJMarketStatsDisplay();
		if (!m_AJMarketStatsDisplay)
		{
			return;
		}
		
		AJDisplayData displayData = AJDisplayStats.GetDisplay(item, itemType, attachmentTypes);
		if (!displayData)
		{
			m_AJMarketStatsDisplay.Show(false);
			return;
		}
		
		UpdateAJMarketStatsDisplay(displayData);
		
		m_AJMarketStatsDisplay.Show(true);
		HideCompetingAJMarketStatsDisplay();
		GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(this.HideCompetingAJMarketStatsDisplay, 1, false);
	}
	
	protected void UpdateAJMarketStatsDisplay(AJDisplayData displayData)
	{
		SetAJMarketText("tier_value", displayData.TierLabel, 0xFFFFFFFF);
		SetAJMarketText("recoil_label", displayData.Line1Label, 0xFFAF9442);
		SetAJMarketText("recoil_value", displayData.Line1Value, displayData.Line1Color);
		SetAJMarketText("sway_label", displayData.Line2Label, 0xFFAF9442);
		SetAJMarketText("sway_value", displayData.Line2Value, displayData.Line2Color);
		SetAJMarketText("ads_label", displayData.Line3Label, 0xFFAF9442);
		SetAJMarketText("ads_value", displayData.Line3Value, displayData.Line3Color);
		SetAJMarketText("precision_label", displayData.Line4Label, 0xFFAF9442);
		SetAJMarketText("precision_value", displayData.Line4Value, displayData.Line4Color);
		SetAJMarketText("hipfire_label", displayData.Line5Label, 0xFFAF9442);
		SetAJMarketText("hipfire_value", displayData.Line5Value, displayData.Line5Color);
		SetAJMarketLineVisible("hipfire", displayData.ShowLine5);
	}
	
	protected string GetAJMarketItemType()
	{
		if (m_CurrentPreviewObject)
		{
			return m_CurrentPreviewObject.GetType();
		}
		
		ExpansionMarketItem marketItem = GetSelectedMarketItem();
		if (marketItem)
		{
			return marketItem.ClassName;
		}
		
		return "";
	}
	
	protected array<string> GetAJMarketAttachmentTypes()
	{
		array<string> attachmentTypes = new array<string>;
		ExpansionMarketItem marketItem = GetSelectedMarketItem();
		if (!marketItem || !marketItem.SpawnAttachments)
		{
			return attachmentTypes;
		}
		
		foreach (string attachmentType : marketItem.SpawnAttachments)
		{
			if (attachmentType != "")
			{
				attachmentTypes.Insert(attachmentType);
			}
		}
		
		return attachmentTypes;
	}
	
	protected void EnsureAJMarketStatsDisplay()
	{
		if (m_AJMarketStatsDisplay)
		{
			return;
		}
		
		if (!m_LayoutRoot)
		{
			return;
		}
		
		Widget parent = m_LayoutRoot.FindAnyWidget("market_item_description_container");
		if (!parent)
		{
			parent = m_LayoutRoot;
		}
		
		m_AJMarketStatsDisplay = GetGame().GetWorkspace().CreateWidgets("AJ_Gunplay/GUI/layouts/AJExpansionMarketStats.layout", parent);
		if (m_AJMarketStatsDisplay)
		{
			m_AJMarketStatsDisplay.Show(false);
		}
	}
	
	protected void SetAJMarketText(string widgetName, string text, int color)
	{
		TextWidget widget = TextWidget.Cast(m_AJMarketStatsDisplay.FindAnyWidget(widgetName));
		if (!widget)
		{
			return;
		}
		
		widget.SetText(text);
		widget.SetColor(color);
	}
	
	protected void SetAJMarketLineVisible(string widgetName, bool visible)
	{
		Widget widget = m_AJMarketStatsDisplay.FindAnyWidget(widgetName);
		if (widget)
		{
			widget.Show(visible);
		}
	}
	
	protected void HideCompetingAJMarketStatsDisplay()
	{
		if (!m_LayoutRoot)
		{
			return;
		}
		
		Widget snafuMarketStatsDisplay = m_LayoutRoot.FindAnyWidget("SNAFUExpansionMarketStats");
		if (snafuMarketStatsDisplay)
		{
			snafuMarketStatsDisplay.Show(false);
		}
	}
}
#endif
