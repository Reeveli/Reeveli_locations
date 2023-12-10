/*
 * Author: Reeveli
 * Part of Reeveli's Map locations mod.
 * Remove closest location (search radius 75m). Must be run globally on all clients.
 *
 * Arguments:
 * 0: Position <ARRAY>
 *
 * Return Value: BOOLEAN
 *
 * Example:
 * [_pos] call Rev_locations_fnc_remove;
 *
 */

params
[
	["_pos",nil,[[]],[2,3]]
];

private _location = nearestLocation [_pos,"",75];

if (isNull _location) exitWith {
	diag_log "Rev_locations_fnc_remove: No location found";
	false;
};

diag_log format ["Rev_locations_fnc_remove: %1", _location];

_location setType "Invisible";								
private _invisible = createLocation [_location];		
_invisible setType "Invisible";	

true;