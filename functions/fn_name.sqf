/*
 * Author: Reeveli
 * Part of Reeveli's Map locations mod.
 * Return the textual name of the closest location (reach radius 75m).
 *
 * Arguments:
 * 0: Position <ARRAY>
 *
 * Return Value: <ARRAY>
 * 0: Was a location found in radius <BOOLEAN>
 * 1: Name of location <STRING>
 *
 * Example:
 * [getpos player] call Rev_locations_fnc_name;
 *
 */


params
[
	["_pos",nil,[[]],[2,3]]
];

private _location = (nearestLocation [_pos,"",75]);

if (isNull _location) exitWith {
	diag_log "Rev_locations_fnc_name: No location found";
	[false,"NULL"];
};

private _text = text _location;
[true,_text];