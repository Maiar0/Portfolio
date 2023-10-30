modded class ActionDeployBase: ActionContinuousBase
{
	override void MoveEntityToFinalPosition( ActionData action_data, vector position, vector orientation )
	{
		super.MoveEntityToFinalPosition(action_data, position, orientation);
		
		ItemBase m_ItemInHands = action_data.m_Player.GetItemInHands();
		if(m_ItemInHands.GetType() == "Maiar_PlacementTool")
		{
			vector adjpos = "180 0 0";
			vector CPorientationBF = action_data.m_Player.GetLocalProjectionOrientation();
			vector CPorientationAdjusted = CPorientationBF - adjpos;
			
			string CPposition = action_data.m_Player.GetLocalProjectionPosition().ToString();
			string CPorientation = CPorientationAdjusted.ToString();
			string KeyDoorInfoLong = "[Maiars Keycards] " + "Position: [" + CPposition + "], Orienation: [ " + CPorientation + "]";
			
			Print( KeyDoorInfoLong );
		}
		
	}
}

modded class ActionDeployObject: ActionDeployBase
{			 
	
	override void OnFinishProgressClient( ActionData action_data )
	{
		super.OnFinishProgressClient(action_data);
		
		ItemBase m_ItemInHands = action_data.m_Player.GetItemInHands();
		if(m_ItemInHands.GetType() == "Maiar_PlacementTool")
		{
			vector adjpos = "180 0 0";
			vector CPorientationBF = action_data.m_Player.GetLocalProjectionOrientation();
			vector CPorientationAdjusted = CPorientationBF - adjpos;
			
			string CPposition = action_data.m_Player.GetLocalProjectionPosition().ToString();
			string CPorientation = CPorientationAdjusted.ToString();
			string KeyDoorInfoLong = "[Maiars Keycards] " + "Position: [" + CPposition + "], Orienation: [ " + CPorientation + "]";
			
			Print( KeyDoorInfoLong );
			GetGame().CopyToClipboard( KeyDoorInfoLong );
		}
		
	}
	
	/*override void OnEndClient( ActionData action_data  )
	{
		PlaceObjectActionData poActionData;
		poActionData = PlaceObjectActionData.Cast(action_data);
		if ( !poActionData.m_AlreadyPlaced )
		{
			EntityAI entity_for_placing = action_data.m_MainItem;
			action_data.m_Player.PlacingCancelLocal();
		}
	}*/
	
};
