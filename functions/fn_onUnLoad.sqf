/*
 * Author: Reeveli 
 * Part of Reeveli's Map locations mod.
 * Client side function to handle curator module dialog onUnload. Called from the Rev_locations_remove_dialog onUnload event.
 *
 * Arguments:
 * 0: Dialog <DISPLAY>
 * 1: Exit code <NUMBER> (default: 0)
 *
 * Exit codes:
 * 0 (default value for unknown cause, e.g. if win key is pressed)
 * 1 (OK)
 * 2 (Esc key used/abort)
 * 3 (Cancel button used)
 * 
 * Return Value: NONE
 *
 * Example:
 * [_display,_exitCode] call Rev_locations_fnc_onUnload
 *
 */

params [
	["_display",displayNull,[displayNull]],
	["_exitCode",0,[0]]
];

private _logic = (findDisplay 312) getVariable ["Rev_locations_modulePos", objNull];

if !(_exitCode == 1) exitWith {
	deleteVehicle _logic;
};

private _text = ctrlText 7011;
private _type = lbData [7012, lbCurSel 7012];
private _pos = getPos _logic;

[_type,_pos,_text] remoteExec ["Rev_locations_fnc_new",0,true];

["MapAreaAdded", [_text]] call BIS_fnc_showNotification;

(findDisplay 312) setVariable ["Rev_locations_modulePos", nil];