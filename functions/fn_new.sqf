/*
 * Author: Reeveli
 * Part of Reeveli's Map locations mod.
 * Create a new map location. Must be run globally on all clients (JIP recommended).
 *
 * Name types: https://community.bistudio.com/wiki/Location#Arma_3
 *	
 * Arguments:
 * 0: Type <STRNG> (default: "NameVillage")
 * 1: Position <ARRAY>
 * 2: Location name <STRING> (default: "")
 *
 * Return Value: Created location <LOCATION>
 *
 * Example:
 * ["NameCity",_pos,"My New City"] call Rev_locations_fnc_new;
 *
 */


params
[
	["_type","NameVillage",[""]],
	["_pos",nil,[[]],[2,3]],
	["_name","",[""]]
];

private _location = createLocation [_type, _pos, 30, 30];
_location setText _name;

diag_log format ["Rev_locations_fnc_new: %1", _name];

_location;