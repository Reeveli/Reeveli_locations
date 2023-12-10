class CfgVehicles
{
	
	class Logic;
	class Module_F : Logic
	{
		class AttributesBase
		{
			class Default;
			class Edit;					// Default edit box (i.e. text input field)
			class Combo;				// Default combo box (i.e. drop-down menu)
			class Checkbox;				// Default checkbox (returned value is Boolean)
			class CheckboxNumber;		// Default checkbox (returned value is Number)
			class ModuleDescription;	// Module description
			class Units;				// Selection of units on which the module is applied
		};

		class ModuleDescription
		{};
	};
	
	class Rev_Module_locationNew : Module_F
	{
		author = "Reeveli";
		scope = 2;										// Editor visibility; 2 will show it in the menu, 1 will hide it.
		displayName = "Add new location";				// Name displayed in the menu
		icon = "a3\ui_f\data\igui\cfg\simpletasks\types\map_ca.paa";	// Map icon. Delete this entry to use the default icon.
		category = "MapLocations";

		function = "Rev_locations_fnc_moduleNew";	// Name of function triggered once conditions are met
		functionPriority = 10;				// Execution priority, modules with lower number are executed first. 0 is used when the attribute is undefined
		isGlobal = 2;						// 0 for server only execution, 1 for global execution, 2 for persistent global execution
		isTriggerActivated = 0;				// 1 for module waiting until all synced triggers are activated
		isDisposable = 1;					// 1 if modules is to be disabled once it is activated (i.e. repeated trigger activation will not work)
		is3DEN = 0;							// 1 to run init function in Eden Editor as well

		// Module attributes (uses https://community.bistudio.com/wiki/Eden_Editor:_Configuring_Attributes#Entity_Specific):
		class Attributes : AttributesBase
		{
			// Module-specific arguments:
			class LocationType : Combo
			{
				property = "Rev_Module_locations_type";	// Unique property (use "<tag>_<moduleClass>_<attributeClass>" format to ensure that the name is unique)
				displayName = "Location type";			// Argument label
				typeName = "STRING";							// Value type, can be "NUMBER", "STRING" or "BOOL"
				defaultValue = "'NameCity'";							// Default attribute value. Warning: this is an expression, and its returned value will be used

				// Listbox items
				class Values
				{
					class City		{ name = "City";					value = "NameCity"; };
					class Capital	{ name = "Capital City";			value = "NameCityCapital"; };
					class Village	{ name = "Village";					value = "NameVillage"; };
					class Local		{ name = "Local";					value = "NameLocal"; };
					class Marine	{ name = "Marine";					value = "NameMarine"; };					
					class Safety	{ name = "Safety Zone";				value = "SafetyZone"; };					
					class Strategic	{ name = "Strategic";				value = "Strategic"; };					
					class Rock		{ name = "Rock Area";				value = "RockArea"; };					
					class Hill		{ name = "Hill";					value = "Hill"; };					
					class Leaf		{ name = "Vegetation Broad Leaf";	value = "VegetationBroadleaf"; };					
					class Palm		{ name = "Vegetation Palm";			value = "VegetationPalm"; };					
					class Vineyard	{ name = "Vegetation Vineyard";		value = "VegetationVineyard"; };					
					class View		{ name = "View Point";				value = "ViewPoint"; };					
				};
			};
			class LocationName: Edit
			{
				displayName = "Location name";
				tooltip = "";
				property = "Rev_Module_locations_name";
				defaultValue = "'My Location'"; // Because this is an expression, one must have a string within a string to return a string
			};

			class ModuleDescription : ModuleDescription {}; // Module description should be shown last
		};

		// Module description (must inherit from base class, otherwise pre-defined entities won't be available)
		class ModuleDescription : ModuleDescription
		{
			description = "Place this module to where you want a new map location";	// Short description, will be formatted as structured text
		};
	};

	class Rev_Module_locationRemove : Rev_Module_locationNew
	{
		displayName = "Remove location";
		function = "Rev_locations_fnc_moduleRemove";
		category = "MapLocations";
		
		class Attributes : AttributesBase
		{
			class ModuleDescription : ModuleDescription {};
		};

		class ModuleDescription : ModuleDescription
		{
			description = "Place this module on top of a existing location you wish to remove. Search radius is 75m";
		};

	};
	
	class Rev_ModuleCurator_locationRemove : Rev_Module_locationRemove
	{
		function = "Rev_locations_fnc_curatorRemove";
		scope = 1;
		scopeCurator = 2;	
	};

	class Rev_ModuleCurator_locationNew : Rev_Module_locationNew
	{
		function = "Rev_locations_fnc_saveModulePos";
		scope = 1;
		scopeCurator = 2;	
		curatorInfoType = "Rev_locations_remove_dialog";
	};

};