class CfgPatches
{
	class Maiar_DeployableItems
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = 
		{
		"DZ_Data",
		"DZ_Scripts",
		"DZ_Characters_Shoes",
		"pitstop_stuff",
		"PITSTOP_AirForce1",
		"PITSTOP_HuntressShoes",
		"PITSTOP_Sneakers",
		"PITSTOP_SpecOpsBoots",
		"PITSTOP_YeezyV2",
		"MSP_Scripts"
		};
	};
};

class cfgvehicles
{
	class Inventory_Base;
	class Container_Base;
	class Msp_Kit;
	class Msp_Item;
	class Maiar_Shoerack_Kit: Msp_Kit
	{
		scope = 2;
		displayName = "Shoe Rack Kit";
		kitItemName = "Maiar_Shoerack";
	};
	class Maiar_Shoerack: Msp_Item
	{
		scope = 2;
		displayName = "Shoe Rack";
		kitName = "Maiar_Shoerack_Kit";
		descriptionShort = "Displays your sick ass shoes! Donated by [ESP]!";
		model = "Maiar_DeployableAssets\Shoerack\Shoerack.p3d";
		hiddenSelections[] = 
		{
			"camo"
		};
		hiddenSelectionsTextures[] = 
		{
			"Maiar_DeployableAssets\Shoerack\ShoeRackData\Shoerack_co.paa"
		};
		attachments[]=
		{
			"feet",
			"feet2",
			"feet3",
			"feet4",
			"feet5",
			"feet6",
			"feet7"
		};
	};
	class Clothing_Base;
	class Clothing: Clothing_Base{};
	class AthleticShoes_ColorBase:Clothing
	{
		inventorySlot[]=
		{
			"feet","feet2","feet3","feet4","feet5","feet6","feet7"
		};
	};
	class HikingBoots_ColorBase: Clothing
	{
		inventorySlot[]=
		{
			"feet","feet2","feet3","feet4","feet5","feet6","feet7"
		};
	};
	class HikingBootsLow_ColorBase: Clothing
	{
		inventorySlot[]=
		{
			"feet","feet2","feet3","feet4","feet5","feet6","feet7"
		};
	};
	class Wellies_ColorBase: Clothing
	{
		inventorySlot[]=
		{
			"feet","feet2","feet3","feet4","feet5","feet6","feet7"
		};
	};
	class WorkingBoots_ColorBase: Clothing
	{
		inventorySlot[]=
		{
			"feet","feet2","feet3","feet4","feet5","feet6","feet7"
		};
	};
	class JungleBoots_ColorBase: Clothing
	{
		inventorySlot[]=
		{
			"feet","feet2","feet3","feet4","feet5","feet6","feet7"
		};
	};
	class DressShoes_ColorBase: Clothing
	{
		inventorySlot[]=
		{
			"feet","feet2","feet3","feet4","feet5","feet6","feet7"
		};
	};
	class MilitaryBoots_ColorBase: Clothing
	{
		inventorySlot[]=
		{
			"feet","feet2","feet3","feet4","feet5","feet6","feet7"
		};
	};
	class CombatBoots_ColorBase: Clothing
	{
		inventorySlot[]=
		{
			"feet","feet2","feet3","feet4","feet5","feet6","feet7"
		};
	};
	class JoggingShoes_ColorBase: Clothing
	{
		inventorySlot[]=
		{
			"feet","feet2","feet3","feet4","feet5","feet6","feet7"
		};
	};
	class LeatherShoes_ColorBase: Clothing
	{
		inventorySlot[]=
		{
			"feet","feet2","feet3","feet4","feet5","feet6","feet7"
		};
	};
	class Sneakers_ColorBase: Clothing
	{
		inventorySlot[]=
		{
			"feet","feet2","feet3","feet4","feet5","feet6","feet7"
		};
	};
	class NBCBootsBase: Clothing
	{
		inventorySlot[]=
		{
			"feet","feet2","feet3","feet4","feet5","feet6","feet7"
		};
	};
	class Ballerinas_ColorBase: Clothing
	{
		inventorySlot[]=
		{
			"feet","feet2","feet3","feet4","feet5","feet6","feet7"
		};
	};
	class TTSKOBoots: Clothing
	{
		inventorySlot[]=
		{
			"feet","feet2","feet3","feet4","feet5","feet6","feet7"
		};
	};
	class PITSTOP_Sneakers_Base: Clothing
	{
		inventorySlot[]=
		{
			"feet","feet2","feet3","feet4","feet5","feet6","feet7"
		};
	};
	class PITSTOP_SpecOpsBoots_Base: Clothing
	{
		inventorySlot[]=
		{
			"feet","feet2","feet3","feet4","feet5","feet6","feet7"
		};
	};
	class PITSTOP_YeezyV2_Base: Clothing
	{
		inventorySlot[]=
		{
			"feet","feet2","feet3","feet4","feet5","feet6","feet7"
		};
	};
	class PITSTOP_AirForce_Base: Clothing
	{
		inventorySlot[]=
		{
			"feet","feet2","feet3","feet4","feet5","feet6","feet7"
		};
	};
	
};
class CfgNonAIVehicles
{
    class ProxyAttachment;
    class ProxyMaiar_Shoes: ProxyAttachment
    {
        scope=2;
        inventorySlot="feet";
        model="Maiar_DeployableAssets\proxy\Maiar_Shoes.p3d";
    };
	class ProxyMaiar_Shoes2: ProxyAttachment
    {
        scope=2;
        inventorySlot="feet2";
        model="Maiar_DeployableAssets\proxy\Maiar_Shoes2.p3d";
    };
	class ProxyMaiar_Shoes3: ProxyAttachment
    {
        scope=2;
        inventorySlot="feet3";
        model="Maiar_DeployableAssets\proxy\Maiar_Shoes3.p3d";
    };
	class ProxyMaiar_Shoes4: ProxyAttachment
    {
        scope=2;
        inventorySlot="feet4";
        model="Maiar_DeployableAssets\proxy\Maiar_Shoes4.p3d";
    };
	class ProxyMaiar_Shoes5: ProxyAttachment
    {
        scope=2;
        inventorySlot="feet5";
        model="Maiar_DeployableAssets\proxy\Maiar_Shoes5.p3d";
    };
	class ProxyMaiar_Shoes6: ProxyAttachment
    {
        scope=2;
        inventorySlot="feet6";
        model="Maiar_DeployableAssets\proxy\Maiar_Shoes6.p3d";
    };
	class ProxyMaiar_Shoes7: ProxyAttachment
    {
        scope=2;
        inventorySlot="feet7";
        model="Maiar_DeployableAssets\proxy\Maiar_Shoes7.p3d";
    };
};
class CfgSlots
{
	class Maiar_Shoes2
    {
        name = "feet2";
        displayName = "Shoes";
        ghostIcon = "set:dayz_inventory image:feet";
    };
	class Maiar_Shoes3
    {
        name = "feet3";
        displayName = "Shoes";
        ghostIcon = "set:dayz_inventory image:feet";
    };
	class Maiar_Shoes4
    {
        name = "feet4";
        displayName = "Shoes";
        ghostIcon = "set:dayz_inventory image:feet";
    };
	class Maiar_Shoes5
    {
        name = "feet5";
        displayName = "Shoes";
        ghostIcon = "set:dayz_inventory image:feet";
    };
	class Maiar_Shoes6
    {
        name = "feet6";
        displayName = "Shoes";
        ghostIcon = "set:dayz_inventory image:feet";
    };
	class Maiar_Shoes7
    {
        name = "feet7";
        displayName = "Shoes";
        ghostIcon = "set:dayz_inventory image:feet";
    };
};