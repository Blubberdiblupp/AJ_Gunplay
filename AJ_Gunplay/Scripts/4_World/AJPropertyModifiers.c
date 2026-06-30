modded class PropertyModifiers
{
	override void UpdateModifiers()
	{
		super.UpdateModifiers();
		
		Weapon_Base weapon = Weapon_Base.Cast(m_OwnerItem);
		if (!weapon)
		{
			return;
		}
		
		if (!weapon.AJShouldApplyGunplay())
		{
			return;
		}
		
		float recoilModifier = weapon.GetAJWeaponRecoilModifier();
		float swayModifier = weapon.GetAJAimingSwayModifier();
		float swaySpeedModifier = weapon.GetAJAimingSwaySpeedModifier();
		
		if (recoilModifier > 0.0)
		{
			m_RecoilModifiers[0] = recoilModifier;
			m_RecoilModifiers[1] = recoilModifier;
			m_RecoilModifiers[2] = recoilModifier;
		}
		
		if (swayModifier > 0.0)
		{
			m_SwayModifiers[0] = swayModifier;
			m_SwayModifiers[1] = swayModifier;
			m_SwayModifiers[2] = swaySpeedModifier;
		}
		
		AJGunplayConfig config = AJGunplayConfig.GetInstance();
		if (config && config.DebugMode)
		{
			Print("[AJ Gunplay] Applied weapon property modifiers: " + weapon.GetType() + " recoil=" + recoilModifier + " sway=" + swayModifier);
		}
	}
}
