class DoorPosition
{
    string DoorsName;
    protected vector Position;
    protected vector Orienation;
    protected vector LootLocation;
    protected vector LootOrientaion;

    void DoorPosition(string Doorname, vector DoorPos, vector DoorOrientation, vector LootSpawnLocation, vector LootSpawnOrientation)
    {
        DoorsName = Doorname;
        Position = DoorPos;
        Orienation = DoorOrientation;
        LootLocation = LootSpawnLocation;
        LootOrientaion = LootSpawnOrientation;
    }
    
	string GetDoorsName()
    {
        return DoorsName;
    }
	
	vector GetDoorPosition()
    {
        return Position;
    }

    vector GetDoorOrientation()
    {
        return Orienation;
    }
	
	vector GetLootSpawnLocation()
    {
        return LootLocation;
    }
	vector GetLootSpawnOrientation()
    {
        return LootOrientaion;
    }
}
class KeyCardDoorLoot
{
	string Item;
	
	void KeyCardDoorLoot(string item)
    {
        Item = item; 
    }
	
	string GetLootItem()
    {
        return Item;
    }
}