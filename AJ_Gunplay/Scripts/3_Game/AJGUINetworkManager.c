class AJGUINetworkManager
{
	protected static ref AJGUINetworkManager m_Instance;
	
	protected bool m_IsClientSideOnly;
	protected int m_LastStatUpdateFrame;
	protected int m_LocalFrameCounter;
	protected const int MIN_UPDATE_FRAMES = 10;
	
	static AJGUINetworkManager GetInstance()
	{
		if (!m_Instance)
		{
			m_Instance = new AJGUINetworkManager();
			m_Instance.Init();
		}
		return m_Instance;
	}
	
	void AJGUINetworkManager()
	{
	}
	
	void Init()
	{
		m_IsClientSideOnly = GetGame().IsClient();
		m_LastStatUpdateFrame = 0;
		m_LocalFrameCounter = 0;
		
		Print("[AJ Gunplay] GUI Network Manager initialized");
		Print("[AJ Gunplay] Client-side only calculations: " + m_IsClientSideOnly);
	}
	
	bool ShouldUpdateGUI()
	{
		m_LocalFrameCounter++;
		int currentFrame = m_LocalFrameCounter;
		
		if (currentFrame - m_LastStatUpdateFrame < MIN_UPDATE_FRAMES)
		{
			return false;
		}
		
		m_LastStatUpdateFrame = currentFrame;
		return true;
	}
	
	void ForceGUIUpdate()
	{
		m_LastStatUpdateFrame = 0;
		m_LocalFrameCounter = 0;
	}
	
	bool IsClientSideOnly()
	{
		return m_IsClientSideOnly;
	}
	
	void LogGUICalculation(string context)
	{
		AJGunplayConfig config = AJGunplayConfig.GetInstance();
		
		if (!config.DebugMode) return;
		
		if (m_IsClientSideOnly)
		{
			Print("[AJ Gunplay] [CLIENT] GUI Update: " + context);
		}
		else
		{
			Print("[AJ Gunplay] [SERVER] GUI Update: " + context);
		}
	}
}
