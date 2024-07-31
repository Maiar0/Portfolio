modded class ModifiersManager
{
	
	void Init()
	{
		super.Init();
		AddModifier(new StimpackMdfr);
		AddModifier(new SupperStimpackMdfr);
		AddModifier(new BloodStimMdfr);
		
	}
}

enum StimModifiers: eModifiers
{
	MDF_STIMPACK
	MDF_SUPPERSTIMPACK
	MDF_BLOODSTIM
}

