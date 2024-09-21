class Land_ZenIceSheet extends BuildingSuper
{
	void Land_ZenIceSheet()
	{
		SetAllowDamage(false);
	}

	override bool IsBuilding()
	{
		return false;
	}
}

class Land_ZenIceSheet_4x4 extends BuildingSuper
{
	void Land_ZenIceSheet_4x4()
	{
		SetAllowDamage(false);
	}

	override bool IsBuilding()
	{
		return false;
	}
}

class Land_ZenIceSheet_4x4_Hole extends BuildingSuper
{
	void Land_ZenIceSheet_4x4_Hole()
	{
		SetAllowDamage(false);
	}

	override bool IsBuilding()
	{
		return false;
	}

	override EWaterSourceObjectType GetWaterSourceObjectType()
	{
		return EWaterSourceObjectType.THROUGH;
	}

	override void SetActions()
	{
		super.SetActions();

		RemoveAction(ActionDrink);

		AddAction(ActionWashHandsWell);
		AddAction(ActionDrinkThroughContinuous);
	}
}
