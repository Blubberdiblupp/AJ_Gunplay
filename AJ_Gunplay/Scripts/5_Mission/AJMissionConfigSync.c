modded class MissionServer extends MissionBase
{
	override void OnInit()
	{
		super.OnInit();
		AJGetAdminConfig();
		GetRPCManager().AddRPC("AJGunplayAdmin", "RPCAJGunplayAdminSettings", this, SingeplayerExecutionType.Both);
	}
	
	void RPCAJGunplayAdminSettings(CallType type, ParamsReadContext ctx, PlayerIdentity sender, Object target)
	{
		PlayerIdentity requestedBy = PlayerIdentity.Cast(sender);
		if (!requestedBy)
		{
			return;
		}
		
		GetRPCManager().SendRPC("AJGunplayAdmin", "RPCAJGunplayAdminSettings", new Param1<AJGunplayAdminConfig>(AJGetAdminConfig()), true, requestedBy);
	}
}

modded class MissionGameplay extends MissionBase
{
	void MissionGameplay()
	{
		GetRPCManager().AddRPC("AJGunplayAdmin", "RPCAJGunplayAdminSettings", this, SingeplayerExecutionType.Both);
	}
	
	override void OnMissionStart()
	{
		super.OnMissionStart();
		GetRPCManager().SendRPC("AJGunplayAdmin", "RPCAJGunplayAdminSettings", new Param1<AJGunplayAdminConfig>(NULL), true, NULL);
	}
	
	void RPCAJGunplayAdminSettings(CallType type, ParamsReadContext ctx, PlayerIdentity sender, Object target)
	{
		Param1<AJGunplayAdminConfig> data;
		if (!ctx.Read(data))
		{
			return;
		}
		
		AJSetAdminConfig(data.param1);
		Print("[AJ Gunplay] Admin settings received from server");
	}
}
