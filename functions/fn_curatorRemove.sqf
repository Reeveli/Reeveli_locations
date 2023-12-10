/*
 * Author: Reeveli
 * Part of Reeveli's Map locations mod.
 * Curator module function for Remove location -module.
 * Called locally by the curator via curator module.
 *	
 * Arguments:
 * 0: Module entiory <OBJECT>
 * 1: Synched unnits <ARRAY>
 * 2: Module activcation/deactivation <BOOLEAN> (default: true)
 *
 * Return Value: BOOLEAN
 *
1.1
	Added code to delete logic after use on all exitcodes
 */

if !(hasInterface) exitWith {false};

params [
	["_logic", objNull, [objNull]],
	["_units ", [], [[]]],
	["_activated", true, [true]]
];


private _pos = position _logic;

if (_activated) then
{
	private _name = [_pos] call Rev_locations_fnc_name;
	if !(_name select 0) then
	{
		playSound "FD_Start_F";
		[objNull, "No location found!"] call BIS_fnc_showCuratorFeedbackMessage;
	}
	else
	{
		["MapAreaRemoved", [_name select 1]] call BIS_fnc_showNotification;
		[_pos] remoteExec ["Rev_locations_fnc_remove",0,true];
	};
};

deleteVehicle _logic;

true;