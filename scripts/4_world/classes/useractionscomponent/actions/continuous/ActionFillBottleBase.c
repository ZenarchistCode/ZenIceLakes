modded class ActionFillBottleBase
{
	override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item)
	{
		if (!super.ActionCondition(player, target, item))
			return false;

#ifndef SERVER
		//! ICE SHEETS - Check if standing on ice
		array<Object> objects = ZenFunctionsIceLakes.GetObjectsRayCastBeneath();
		for (int i = 0; i < objects.Count(); i++)
		{
			if (objects.Get(i).GetType().Contains("Land_ZenIceSheet") && !objects.Get(i).GetType().Contains("Hole"))
			{
				return false;
			}
		}
#endif

		return true;
	}

	override bool SetupAction(PlayerBase player, ActionTarget target, ItemBase item, out ActionData action_data, Param extra_data = NULL)
	{
		if (super.SetupAction(player, target, item, action_data, extra_data))
		{
			//! ICE SHEETS
			if (action_data.m_Target.GetObject() && action_data.m_Target.GetObject().Type() == Land_ZenIceSheet_4x4_Hole)
				m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_FILLBOTTLEPOND;

			return true;
		}

		return false;
	}
}