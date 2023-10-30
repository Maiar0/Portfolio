class Maiar_ExtractionPoint_base extends BuildingSuper
{
	Particle m_ParticleEfx;
	ExtractionLight 		m_ExtractLight;
	void Maiar_ExtractionPoint_base()
	{
		if ( !GetGame().IsDedicatedServer() )
		{
			//particles - Smoke
			m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(ParticleList.GRENADE_M18_GREEN_LOOP, this, Vector(0, 0.5, 0));
			
			//lights - green light
			m_ExtractLight = ExtractionLight.Cast( ScriptedLightBase.CreateLight( ExtractionLight, Vector(0, 0, 0) ) );
			m_ExtractLight.AttachOnMemoryPoint( this, "light" );
		}
	}
};

class Maiar_SafezoneExtraction_base extends BuildingSuper
{};