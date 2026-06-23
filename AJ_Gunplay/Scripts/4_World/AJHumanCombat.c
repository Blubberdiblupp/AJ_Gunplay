modded class DayZPlayerImplement
{
	override void SwitchOptics(ItemOptics optic, bool state)
	{
		super.SwitchOptics(optic, state);
	}
	
	override bool IsShootingFromCamera()
	{
		AJGunplayConfig config = AJGunplayConfig.GetInstance();
		if (!config)
		{
			return super.IsShootingFromCamera();
		}

		if (!config.EnableHipFireNerf)
		{
			return super.IsShootingFromCamera();
		}

		PlayerBase player = PlayerBase.Cast(this);
		if (player && AJVehicleCombatHandler.IsPlayerInVehicle(player))
		{
			return super.IsShootingFromCamera();
		}
		
		if (player)
		{
			Weapon_Base weapon = Weapon_Base.Cast(player.GetItemInHands());
			if (weapon && !weapon.AJShouldApplyGunplay())
			{
				return super.IsShootingFromCamera();
			}
		}

		return false;
	}
}
