class Maiar_ActionExtractSafezone: ActionInteractBase
{
	Maiar_SafezoneExtraction_base SP;
	
	protected ref Maiar_ExtractionSafezoneConfigManager m_CurrentsettingsExtractionSafeZone;
	int NOM = m_CurrentsettingsExtractionSafeZone.NumberofExtractionMachines
	
	void Maiar_ActionExtractSafezone()
	{
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_INTERACTONCE;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT | DayZPlayerConstants.STANCEMASK_CROUCH;
		m_HUDCursorIcon = CursorIcons.CloseHood;
	}

    override void CreateConditionComponents()  
	{
		m_ConditionTarget = new CCTObject(10);//CCTMan(10);
		m_ConditionItem = new CCINone;
	}

	override string GetText()
	{
		return "Extract";
	}

	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
    {
		if ( !target ) 
			return false;
		
		if ( !Class.CastTo(SP, target.GetObject()) ) return false;
		
		if ( NOM != 0 ) return false;
		
        return false;
    }
    
	override void OnEndServer( ActionData action_data )
	{
		vector pos;
		
		
		if ( !pos )
			Print( "!!! \"TeleportLocation\" has invalid format" );
		action_data.m_Player.SetPosition( pos );
	}
	
}

class Maiar_ActionExtractSafezone_One: ActionInteractBase
{
	
	Maiar_SafezoneExtraction_base SP;
	
	int NOM = GetMaiarsExtractionSafezonesConfig().NumberofExtractionMachines
	
	
	void Maiar_ActionExtractSafezone_One()
	{
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_INTERACTONCE;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT | DayZPlayerConstants.STANCEMASK_CROUCH;
		m_HUDCursorIcon = CursorIcons.CloseHood;
	}
	
	override void CreateConditionComponents()  
	{
		m_ConditionTarget = new CCTObject(10);//CCTMan(10);
		m_ConditionItem = new CCINone;
	}
	
	override string GetText()
	{
		return "Extraction Point One";
	}

	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
    {
		if ( !target ) 
			return false;
		
		if ( !Class.CastTo(SP, target.GetObject()) ) return false;
		
		if ( NOM >= 1 ) return true;
		
		return false;
		
    }
	
	
	override void OnEndServer( ActionData action_data )
	{
		vector pos = GetMaiarsExtractionSafezonesConfig().ExtractionMachine.Get(0).GetPositions();
		Print("[MaiarsExtractionSafezones] -> Sucessfully Teleported: " + pos + " NOM " + NOM );
		
		int range = GetMaiarsExtractionSafezonesConfig().RangeSafeExtraction
		
		float x = Randomize( pos[0],range)
		float z = Randomize( pos[2], range)
		float y = GetGame().SurfaceY( x, z)
		vector fpos = Vector(x,y,z);
		if ( !pos )
			Print( "!!! \"TeleportLocation\" has invalid format" );
		action_data.m_Player.SetPosition( fpos );
		
	}
	
	float Randomize(float input, float range)
	{
		float min = input - range;
		float max = input + range;
		float output = Math.RandomInt(min, max);
		Print("[MaiarsExtractionSafezones] -> Randomize: input " + input + " range " + range + " output " + output);
		return output;
	}
}

class Maiar_ActionExtractSafezone_Two: ActionInteractBase
{
	
	Maiar_SafezoneExtraction_base SP;
	
	int NOM = GetMaiarsExtractionSafezonesConfig().NumberofExtractionMachines
	
	
	void Maiar_ActionExtractSafezone_Two()
	{
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_INTERACTONCE;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT | DayZPlayerConstants.STANCEMASK_CROUCH;
		m_HUDCursorIcon = CursorIcons.CloseHood;
	}
	
	override void CreateConditionComponents()  
	{
		m_ConditionTarget = new CCTObject(10);//CCTMan(10);
		m_ConditionItem = new CCINone;
	}
	
	override string GetText()
	{
		return "Extraction Point Two";
	}

	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
    {
		if ( !target ) 
			return false;
		
		if ( !Class.CastTo(SP, target.GetObject()) ) return false;
		
		if ( NOM >= 2 ) return true;
		
		return false;
		
    }
	
	
	override void OnEndServer( ActionData action_data )
	{
		vector pos = GetMaiarsExtractionSafezonesConfig().ExtractionMachine.Get(1).GetPositions();
		Print("[MaiarsExtractionSafezones] -> Sucessfully Teleported: " + pos + " NOM " + NOM );
		
		int range = GetMaiarsExtractionSafezonesConfig().RangeSafeExtraction
		
		float x = Randomize( pos[0],range)
		float z = Randomize( pos[2], range)
		float y = GetGame().SurfaceY( x, z)
		vector fpos = Vector(x,y,z);
		if ( !pos )
			Print( "!!! \"TeleportLocation\" has invalid format" );
		action_data.m_Player.SetPosition( fpos );
		
	}
	
	float Randomize(float input, float range)
	{
		float min = input - range;
		float max = input + range;
		float output = Math.RandomInt(min, max);
		Print("[MaiarsExtractionSafezones] -> Randomize: input " + input + " range " + range + " output " + output);
		return output;
	}
}

class Maiar_ActionExtractSafezone_Three: ActionInteractBase
{
	
	Maiar_SafezoneExtraction_base SP;
	
	int NOM = GetMaiarsExtractionSafezonesConfig().NumberofExtractionMachines
	
	
	void Maiar_ActionExtractSafezone_Three()
	{
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_INTERACTONCE;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT | DayZPlayerConstants.STANCEMASK_CROUCH;
		m_HUDCursorIcon = CursorIcons.CloseHood;
	}
	
	override void CreateConditionComponents()  
	{
		m_ConditionTarget = new CCTObject(10);//CCTMan(10);
		m_ConditionItem = new CCINone;
	}
	
	override string GetText()
	{
		return "Extraction Point Three";
	}

	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
    {
		if ( !target ) 
			return false;
		
		if ( !Class.CastTo(SP, target.GetObject()) ) return false;
		
		if ( NOM >= 3 ) return true;
		
		return false;
		
    }
	
	
	override void OnEndServer( ActionData action_data )
	{
		vector pos = GetMaiarsExtractionSafezonesConfig().ExtractionMachine.Get(2).GetPositions();
		Print("[MaiarsExtractionSafezones] -> Sucessfully Teleported: " + pos + " NOM " + NOM );
		
		int range = GetMaiarsExtractionSafezonesConfig().RangeSafeExtraction
		
		float x = Randomize( pos[0],range)
		float z = Randomize( pos[2], range)
		float y = GetGame().SurfaceY( x, z)
		vector fpos = Vector(x,y,z);
		if ( !pos )
			Print( "!!! \"TeleportLocation\" has invalid format" );
		action_data.m_Player.SetPosition( fpos );
		
	}
	
	float Randomize(float input, float range)
	{
		float min = input - range;
		float max = input + range;
		float output = Math.RandomInt(min, max);
		Print("[MaiarsExtractionSafezones] -> Randomize: input " + input + " range " + range + " output " + output);
		return output;
	}
}

class Maiar_ActionExtractSafezone_Four: ActionInteractBase
{
	
	Maiar_SafezoneExtraction_base SP;
	
	int NOM = GetMaiarsExtractionSafezonesConfig().NumberofExtractionMachines
	
	
	void Maiar_ActionExtractSafezone_Four()
	{
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_INTERACTONCE;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT | DayZPlayerConstants.STANCEMASK_CROUCH;
		m_HUDCursorIcon = CursorIcons.CloseHood;
	}
	
	override void CreateConditionComponents()  
	{
		m_ConditionTarget = new CCTObject(10);//CCTMan(10);
		m_ConditionItem = new CCINone;
	}
	
	override string GetText()
	{
		return "Extraction Point Four";
	}

	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
    {
		if ( !target ) 
			return false;
		
		if ( !Class.CastTo(SP, target.GetObject()) ) return false;
		
		if ( NOM >= 4 ) return true;
		
		return false;
		
    }
	
	
	override void OnEndServer( ActionData action_data )
	{
		vector pos = GetMaiarsExtractionSafezonesConfig().ExtractionMachine.Get(3).GetPositions();
		Print("[MaiarsExtractionSafezones] -> Sucessfully Teleported: " + pos + " NOM " + NOM );
		
		int range = GetMaiarsExtractionSafezonesConfig().RangeSafeExtraction
		
		float x = Randomize( pos[0],range)
		float z = Randomize( pos[2], range)
		float y = GetGame().SurfaceY( x, z)
		vector fpos = Vector(x,y,z);
		if ( !pos )
			Print( "!!! \"TeleportLocation\" has invalid format" );
		action_data.m_Player.SetPosition( fpos );
		
	}
	
	float Randomize(float input, float range)
	{
		float min = input - range;
		float max = input + range;
		float output = Math.RandomInt(min, max);
		Print("[MaiarsExtractionSafezones] -> Randomize: input " + input + " range " + range + " output " + output);
		return output;
	}
}

class Maiar_ActionExtractSafezone_Five: ActionInteractBase
{
	
	Maiar_SafezoneExtraction_base SP;
	
	int NOM = GetMaiarsExtractionSafezonesConfig().NumberofExtractionMachines
	
	
	void Maiar_ActionExtractSafezone_Five()
	{
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_INTERACTONCE;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT | DayZPlayerConstants.STANCEMASK_CROUCH;
		m_HUDCursorIcon = CursorIcons.CloseHood;
	}
	
	override void CreateConditionComponents()  
	{
		m_ConditionTarget = new CCTObject(10);//CCTMan(10);
		m_ConditionItem = new CCINone;
	}
	
	override string GetText()
	{
		return "Extraction Point Five";
	}

	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
    {
		if ( !target ) 
			return false;
		
		if ( !Class.CastTo(SP, target.GetObject()) ) return false;
		
		if ( NOM >= 5 ) return true;
		
		return false;
		
    }
	
	
	override void OnEndServer( ActionData action_data )
	{
		vector pos = GetMaiarsExtractionSafezonesConfig().ExtractionMachine.Get(4).GetPositions();
		Print("[MaiarsExtractionSafezones] -> Sucessfully Teleported: " + pos + " NOM " + NOM );
		
		int range = GetMaiarsExtractionSafezonesConfig().RangeSafeExtraction
		
		float x = Randomize( pos[0],range)
		float z = Randomize( pos[2], range)
		float y = GetGame().SurfaceY( x, z)
		vector fpos = Vector(x,y,z);
		if ( !pos )
			Print( "!!! \"TeleportLocation\" has invalid format" );
		action_data.m_Player.SetPosition( fpos );
		
	}
	
	float Randomize(float input, float range)
	{
		float min = input - range;
		float max = input + range;
		float output = Math.RandomInt(min, max);
		Print("[MaiarsExtractionSafezones] -> Randomize: input " + input + " range " + range + " output " + output);
		return output;
	}
}

class Maiar_ActionExtractSafezone_Six: ActionInteractBase
{
	
	Maiar_SafezoneExtraction_base SP;
	
	int NOM = GetMaiarsExtractionSafezonesConfig().NumberofExtractionMachines
	
	
	void Maiar_ActionExtractSafezone_Six()
	{
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_INTERACTONCE;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT | DayZPlayerConstants.STANCEMASK_CROUCH;
		m_HUDCursorIcon = CursorIcons.CloseHood;
	}
	
	override void CreateConditionComponents()  
	{
		m_ConditionTarget = new CCTObject(10);//CCTMan(10);
		m_ConditionItem = new CCINone;
	}
	
	override string GetText()
	{
		return "Extraction Point Six";
	}

	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
    {
		if ( !target ) 
			return false;
		
		if ( !Class.CastTo(SP, target.GetObject()) ) return false;
		
		if ( NOM >= 6 ) return true;
		
		return false;
		
    }
	
	
	override void OnEndServer( ActionData action_data )
	{
		vector pos = GetMaiarsExtractionSafezonesConfig().ExtractionMachine.Get(5).GetPositions();
		Print("[MaiarsExtractionSafezones] -> Sucessfully Teleported: " + pos + " NOM " + NOM );
		
		int range = GetMaiarsExtractionSafezonesConfig().RangeSafeExtraction
		
		float x = Randomize( pos[0],range)
		float z = Randomize( pos[2], range)
		float y = GetGame().SurfaceY( x, z)
		vector fpos = Vector(x,y,z);
		if ( !pos )
			Print( "!!! \"TeleportLocation\" has invalid format" );
		action_data.m_Player.SetPosition( fpos );
		
	}
	
	float Randomize(float input, float range)
	{
		float min = input - range;
		float max = input + range;
		float output = Math.RandomInt(min, max);
		Print("[MaiarsExtractionSafezones] -> Randomize: input " + input + " range " + range + " output " + output);
		return output;
	}
}


class Maiar_ActionExtractSafezone_Seven: ActionInteractBase
{
	
	Maiar_SafezoneExtraction_base SP;
	
	int NOM = GetMaiarsExtractionSafezonesConfig().NumberofExtractionMachines
	
	
	void Maiar_ActionExtractSafezone_Seven()
	{
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_INTERACTONCE;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT | DayZPlayerConstants.STANCEMASK_CROUCH;
		m_HUDCursorIcon = CursorIcons.CloseHood;
	}
	
	override void CreateConditionComponents()  
	{
		m_ConditionTarget = new CCTObject(10);//CCTMan(10);
		m_ConditionItem = new CCINone;
	}
	
	override string GetText()
	{
		return "Extraction Point Seven";
	}

	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
    {
		if ( !target ) 
			return false;
		
		if ( !Class.CastTo(SP, target.GetObject()) ) return false;
		
		if ( NOM >= 7 ) return true;
		
		return false;
		
    }
	
	
	override void OnEndServer( ActionData action_data )
	{
		vector pos = GetMaiarsExtractionSafezonesConfig().ExtractionMachine.Get(6).GetPositions();
		Print("[MaiarsExtractionSafezones] -> Sucessfully Teleported: " + pos + " NOM " + NOM );
		
		int range = GetMaiarsExtractionSafezonesConfig().RangeSafeExtraction
		
		float x = Randomize( pos[0],range)
		float z = Randomize( pos[2], range)
		float y = GetGame().SurfaceY( x, z)
		vector fpos = Vector(x,y,z);
		if ( !pos )
			Print( "!!! \"TeleportLocation\" has invalid format" );
		action_data.m_Player.SetPosition( fpos );
		
	}
	
	float Randomize(float input, float range)
	{
		float min = input - range;
		float max = input + range;
		float output = Math.RandomInt(min, max);
		Print("[MaiarsExtractionSafezones] -> Randomize: input " + input + " range " + range + " output " + output);
		return output;
	}
}


class Maiar_ActionExtractSafezone_Eight: ActionInteractBase
{
	
	Maiar_SafezoneExtraction_base SP;
	
	int NOM = GetMaiarsExtractionSafezonesConfig().NumberofExtractionMachines
	
	
	void Maiar_ActionExtractSafezone_Eight()
	{
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_INTERACTONCE;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT | DayZPlayerConstants.STANCEMASK_CROUCH;
		m_HUDCursorIcon = CursorIcons.CloseHood;
	}
	
	override void CreateConditionComponents()  
	{
		m_ConditionTarget = new CCTObject(10);//CCTMan(10);
		m_ConditionItem = new CCINone;
	}
	
	override string GetText()
	{
		return "Extraction Point Eight";
	}

	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
    {
		if ( !target ) 
			return false;
		
		if ( !Class.CastTo(SP, target.GetObject()) ) return false;
		
		if ( NOM >= 8 ) return true;
		
		return false;
		
    }
	
	
	override void OnEndServer( ActionData action_data )
	{
		vector pos = GetMaiarsExtractionSafezonesConfig().ExtractionMachine.Get(7).GetPositions();
		Print("[MaiarsExtractionSafezones] -> Sucessfully Teleported: " + pos + " NOM " + NOM );
		
		int range = GetMaiarsExtractionSafezonesConfig().RangeSafeExtraction
		
		float x = Randomize( pos[0],range)
		float z = Randomize( pos[2], range)
		float y = GetGame().SurfaceY( x, z)
		vector fpos = Vector(x,y,z);
		if ( !pos )
			Print( "!!! \"TeleportLocation\" has invalid format" );
		action_data.m_Player.SetPosition( fpos );
		
	}
	
	float Randomize(float input, float range)
	{
		float min = input - range;
		float max = input + range;
		float output = Math.RandomInt(min, max);
		Print("[MaiarsExtractionSafezones] -> Randomize: input " + input + " range " + range + " output " + output);
		return output;
	}
}


class Maiar_ActionExtractSafezone_Nine: ActionInteractBase
{
	
	Maiar_SafezoneExtraction_base SP;
	
	int NOM = GetMaiarsExtractionSafezonesConfig().NumberofExtractionMachines
	
	
	void Maiar_ActionExtractSafezone_Nine()
	{
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_INTERACTONCE;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT | DayZPlayerConstants.STANCEMASK_CROUCH;
		m_HUDCursorIcon = CursorIcons.CloseHood;
	}
	
	override void CreateConditionComponents()  
	{
		m_ConditionTarget = new CCTObject(10);//CCTMan(10);
		m_ConditionItem = new CCINone;
	}
	
	override string GetText()
	{
		return "Extraction Point Nine";
	}

	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
    {
		if ( !target ) 
			return false;
		
		if ( !Class.CastTo(SP, target.GetObject()) ) return false;
		
		if ( NOM >= 9 ) return true;
		
		return false;
		
    }
	
	
	override void OnEndServer( ActionData action_data )
	{
		vector pos = GetMaiarsExtractionSafezonesConfig().ExtractionMachine.Get(8).GetPositions();
		Print("[MaiarsExtractionSafezones] -> Sucessfully Teleported: " + pos + " NOM " + NOM );
		
		int range = GetMaiarsExtractionSafezonesConfig().RangeSafeExtraction
		
		float x = Randomize( pos[0],range)
		float z = Randomize( pos[2], range)
		float y = GetGame().SurfaceY( x, z)
		vector fpos = Vector(x,y,z);
		if ( !pos )
			Print( "!!! \"TeleportLocation\" has invalid format" );
		action_data.m_Player.SetPosition( fpos );
		
	}
	
	float Randomize(float input, float range)
	{
		float min = input - range;
		float max = input + range;
		float output = Math.RandomInt(min, max);
		Print("[MaiarsExtractionSafezones] -> Randomize: input " + input + " range " + range + " output " + output);
		return output;
	}
}
