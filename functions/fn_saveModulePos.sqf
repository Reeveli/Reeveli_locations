/*
 * Author: Reeveli
 * Part of Reeveli's Map locations mod.
 * Client side function to save curator module for later use.
 * Called by the curator module.
 *
 * Arguments:
 * 0: Module entiory <OBJECT>
 * 1: Synched unnits <ARRAY>
 * 2: Module activcation/deactivation <BOOLEAN> (default: true)
 *
 * Return Value: BOOLEAN
 *
 */

params [
	["_logic", objNull, [objNull]],
	["_units ", [], [[]]],
	["_activated", true, [true]]
];

if (isNull findDisplay 312) exitWith {
	diag_log "Rev_locations_fnc_saveModulePos: Function called when not curator!";
	false;
};

(findDisplay 312) setVariable ["Rev_locations_modulePos", _logic];

true;