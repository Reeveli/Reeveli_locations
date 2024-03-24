class CfgPatches
{
	class Reeveli_locations
	{
		units[]=
		{
			"Rev_Module_locationNew",
			"Rev_Module_locationRemove",
			"Rev_ModuleCurator_locationRemove",
			"Rev_ModuleCurator_locationNew"
		};
		weapons[]={};
		requiredVersion=2.14;
		requiredAddons[]=
		{
			"A3_Data_F_Decade_Loadorder"
		};
		author="Reeveli";
		authors[]= {"Reeveli"};
		name = "Add & Remove Map Labels";
		license = "https://www.bohemia.net/community/licenses/arma-public-license-share-alike";
		url = "https://www.youtube.com/@Reeveli";			
        version = 1.2;
        versionStr = "1.2.0";
        versionAr[] = {1, 2, 0};
	};
};

#include "dialogs.hpp"
#include "CfgFactionClasses.hpp"
#include "CfgFunctions.hpp"
#include "CfgVehicles.hpp"