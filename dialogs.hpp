
#define REV_LOC_GRID_SIZE				36

#define REV_LOC_W						REV_LOC_GRID_SIZE * pixelGridNoUIScale * pixelW
#define REV_LOC_H						REV_LOC_GRID_SIZE * (1/6) * pixelGridNoUIScale * pixelH
#define REV_LOC_BAR_H					0.8 * pixelGridNoUIScale * pixelH
#define REV_LOC_GAB_W					0.2 * pixelGridNoUIScale * pixelW
#define REV_LOC_GAB_H					0.2 * pixelGridNoUIScale * pixelH
#define REV_LOC_BUTTON_W				REV_LOC_W * 0.2
#define REV_LOC_BUTTON_H				2 * REV_LOC_BAR_H


#define REV_LOC_X						safezoneX + (safezoneW * 0.50) - ((REV_LOC_GRID_SIZE * pixelGridNoUIScale * pixelW) * 0.5)
#define REV_LOC_Y						safeZoneY + (safeZoneH * 0.50) - (REV_LOC_BUTTON_H * 0.5) - (REV_LOC_GAB_H * 0.5) - (REV_LOC_H * 0.5)

class RscButton;
class RscCombo;
class RscEdit;
class RscText;

class Rev_locations_remove_dialog
{
	idd = 7010;
	movingEnable = true;
	onLoad = "uiNamespace setVariable ['Rev_loc_remove_display', _this select 0]";
	onUnload = "params ['_display','_exitCode']; uiNamespace setVariable ['Rev_loc_remove_display', DisplayNull]; [_display,_exitCode] call Rev_locations_fnc_onUnload";
	class ControlsBackground
	{
		class Bar_title: RscText
		{
			x = REV_LOC_X;
			y = REV_LOC_Y;
			w = REV_LOC_W;
			h = REV_LOC_BUTTON_H;
			text = "Add map location";
			font = "PuristaSemibold";
			style = 0x00; //ST_LEFT
			colorBackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.77])","(profilenamespace getvariable ['GUI_BCG_RGB_G',0.51])","(profilenamespace getvariable ['GUI_BCG_RGB_B',0.08])","(profilenamespace getvariable ['GUI_BCG_RGB_A',0.8])"};
			moving = true;
			SizeEx = 1.6 * pixelGridNoUIScale * pixelH;			
		};
		class BG_main: RscText
		{
			x = REV_LOC_X;
			y = REV_LOC_Y + REV_LOC_BUTTON_H + REV_LOC_GAB_H;
			w = REV_LOC_W;
			h = REV_LOC_H;
			colorBackground[] = {0,0,0,0.8};
			moving = true;			
		};
	};
	class Controls
	{
		class Text_name: RscText
		{
			x = REV_LOC_X + 2 * REV_LOC_GAB_W;
			y = REV_LOC_Y + REV_LOC_BUTTON_H + REV_LOC_GAB_H + 1 * REV_LOC_BAR_H;
			w = REV_LOC_BUTTON_W;
			h = 2 * REV_LOC_BAR_H;
			text = "Location name:"
			colorBackground[] = {0,0,0,0};
			sizeEx = 1.5 * pixelGridNoUIScale * pixelH;
			moving = true;			
		};
		class Edit_name: RscEdit
		{
			idc = 7011;
			x = REV_LOC_X + 4 * REV_LOC_GAB_W + REV_LOC_BUTTON_W;
			y = REV_LOC_Y + REV_LOC_BUTTON_H + REV_LOC_GAB_H + 1 * REV_LOC_BAR_H;
			w = REV_LOC_W - 7 * REV_LOC_GAB_W - REV_LOC_BUTTON_W;
			h = 2 * REV_LOC_BAR_H;
			text = ""
			sizeEx = 1.5 * pixelGridNoUIScale * pixelH;
		};
		class Text_type: Text_name
		{
			y = REV_LOC_Y + REV_LOC_BUTTON_H + REV_LOC_GAB_H + 4 * REV_LOC_BAR_H;
			text = "Location type:";
		};
		class ListBox_type: RscCombo
		{
			idc = 7012
			x = REV_LOC_X + 4 * REV_LOC_GAB_W + REV_LOC_BUTTON_W;
			y = REV_LOC_Y + REV_LOC_BUTTON_H + REV_LOC_GAB_H + 4 * REV_LOC_BAR_H;
			w = REV_LOC_W - 7 * REV_LOC_GAB_W - 2 * REV_LOC_BUTTON_W;
			h = 2 * REV_LOC_BAR_H;
			sizeEx = 1.5 * pixelGridNoUIScale * pixelH;
			colorBackground[] = {0,0,0,1};
			rows = 3;
			wholeHeight = 27 * REV_LOC_BAR_H;
			class Items
			{
				class City
				{
					text = "City";
					default = 1;
					data = "NameCity";
				};
				class Capital
				{
					text = "Capital City";
					data = "NameCityCapital";
				};
				class Village
				{
					text = "Village";
					data = "NameVillage";
				};
				class Local
				{
					text = "Local";
					data = "NameLocal";
				};
				class Marine
				{
					text = "Marine";
					data = "NameMarine";
				};
				class Safety
				{
					text = "Safety Zone";
					data = "SafetyZone";
				};
				class Strategic
				{
					text = "Strategic";
					data = "Strategic";
				};
				class Rock
				{
					text = "Rock Area";
					data = "RockArea";
				};
				class Hill
				{
					text = "Hill";
					data = "Hill";
				};
				class Leaf
				{
					text = "Vegetation Broad Leaf";
					data = "VegetationBroadleaf";
				};
				class Palm
				{
					text = "Vegetation Palm";
					data = "VegetationPalm";
				};
				class Vine
				{
					text = "Vegetation Vineyard";
					data = "VegetationVineyard";
				};
				class View
				{
					text = "View Point";
					data = "ViewPoint";
				};
			};
		};
		class Text_warning: Text_name
		{
			x = REV_LOC_X + 4 * REV_LOC_GAB_W + REV_LOC_BUTTON_W;
			y = REV_LOC_Y + REV_LOC_BUTTON_H + REV_LOC_H + REV_LOC_GAB_H;
			w = REV_LOC_W - 7 * REV_LOC_GAB_W - 2 * REV_LOC_BUTTON_W;
			h = 4 * REV_LOC_BAR_H;
			style = 0x10; // ST_MULTI
			text = "Warning: Location added will NOT be visible while in curator view, only on 'normal' map.";			
			colorBackground[] = {0,0,0,0.8};
		};
		class Button_ok: RscButton
		{
			idc = 1;
			x = REV_LOC_X + REV_LOC_W - REV_LOC_BUTTON_W;
			y = REV_LOC_Y + REV_LOC_BUTTON_H + 2 * REV_LOC_GAB_H + REV_LOC_H;
			w = REV_LOC_BUTTON_W;
			h = 2 * REV_LOC_BAR_H;
			text = "Ok";
			colorBackground[] = {0,0,0,1};
			colorFocused[] = {0.2,0.2,0.2,1};
			colorBackgroundActive[] = {0.2,0.2,0.2,1};
			sizeEx = 1.5 * pixelGridNoUIScale * pixelH;
			onButtonClick = "params ['_control'];closeDialog 1";	
		};
		class Button_cancel: Button_ok
		{
			idc = 2;
			x = REV_LOC_X;
			text = "Cancel";
			onButtonClick = "params ['_control'];closeDialog 3;";
		};
	};
};