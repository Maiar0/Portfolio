class ExtractionMachines
{
    string ExtractionsName;
    protected vector Position;
    protected vector Orienation;

    void ExtractionMachines(string Extractionitem, vector ExtractionPos, vector ExtractionOrientation)
    {
        ExtractionsName = Extractionitem;
        Position = ExtractionPos;
        Orienation = ExtractionOrientation;
    }
    
	string GetName()
    {
        return ExtractionsName;
    }
	
	vector GetPositions()
    {
        return Position;
    }

    vector GetOrientation()
    {
        return Orienation;
    }
}

class SafezoneMachines
{
    string ExtractionsName;
    protected vector Position;
    protected vector Orienation;

    void SafezoneMachines(string SafezoneItem, vector ExtractorPos, vector ExtractorOrientation)
    {
        ExtractionsName = SafezoneItem;
        Position = ExtractorPos;
        Orienation = ExtractorOrientation;
    }
    
	string GetName()
    {
        return ExtractionsName;
    }
	
	vector GetPositions()
    {
        return Position;
    }
	
	vector GetOrientation()
    {
        return Orienation;
    }
	
}

class SafezonePositions
{
	protected vector PossibleLocations;
	
	void SafezonePositions(vector Position)
    {
        PossibleLocations = Position; 
    }
	
	vector GetPosition()
    {
        return PossibleLocations;
    }
	
}