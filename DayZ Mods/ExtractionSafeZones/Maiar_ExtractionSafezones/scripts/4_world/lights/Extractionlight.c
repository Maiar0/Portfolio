class ExtractionLight extends PointLightBase
{
	void ExtractionLight()
	{
		SetVisibleDuringDaylight(true);
		SetRadiusTo(24);
		SetBrightnessTo(3);
		SetCastShadow(false);
		SetDiffuseColor(0.7, 0.7, 1.0);
		SetFlareVisible(true);
		SetFlickerAmplitude(0.5);
		SetFlickerSpeed(1);
	}
}