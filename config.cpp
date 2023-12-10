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
		license = "https://www.bohemia.net/community/licenses/arma-public-license-share-alike";
		url = "https://www.youtube.com/@Reeveli";			
        version = 1.0;
        versionStr = "1.0.1";
        versionAr[] = {1, 0, 1};
	};
};

#include "dialogs.hpp"
#include "CfgFactionClasses.hpp"
#include "CfgFunctions.hpp"
#include "CfgNotifications.hpp"
#include "CfgVehicles.hpp"