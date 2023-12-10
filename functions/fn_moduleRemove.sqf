/*
 * Author: Reeveli
 * Part of Reeveli's Map locations mod.
 * Editor module function for Remove location -module. Called by the editor module.
 * Must be run globally on all clients (i.e. via using the module in mission editor).
 *	
 * Arguments:
 * 0: Module entiory <OBJECT>
 * 1: Synched unnits <ARRAY>
 * 2: Module activcation/deactivation <BOOLEAN> (default: true)
 *
 * Return Value: NONE
 *
 */

params [
	["_logic", objNull, [objNull]],
	["_units ", [], [[]]],
	["_activated", true, [true]]
];

private _pos = position _logic;

if (_activated) then
{
	[_pos] call Rev_locations_fnc_remove
};