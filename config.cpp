class CfgPatches
{
	class ZenIceLakes
	{
		requiredVersion = 0.1;
		requiredAddons[] =
		{
			"DZ_Data",
			"DZ_Scripts",
			"DZ_Gear_Tools"
		};
	};
};

class CfgMods
{
	class ZenIceLakes
	{
		dir = "ZenIceLakes";
		picture = "";
		action = "";
		hideName = 1;
		hidePicture = 1;
		name = "ZenIceLakes";
		credits = "";
		author = "Zenarchist";
		authorID = "0";
		version = "1.0";
		extra = 0;
		type = "mod";
		dependencies[] = { "Game","World","Mission" };
		class defs
		{
			class gameScriptModule
			{
				value = "";
				files[] = { "ZenIceLakes/scripts/3_game" };
			};
			class worldScriptModule
			{
				value = "";
				files[] = { "ZenIceLakes/scripts/4_world" };
			};
			class missionScriptModule
			{
				value = "";
				files[] = { "ZenIceLakes/scripts/5_mission" };
			};
		};
	};
};

class CfgVehicles
{
	// Fix translation strings for ice axe
	class Inventory_Base;
	class Iceaxe : Inventory_Base
	{
		displayName = "$STR_CfgVehicles_ZenIceaxe0";
		descriptionShort = "$STR_CfgVehicles_ZenIceaxe1";
	};

	//! Ice plane (useful for winter/snow maps to block certain lakes etc)
	class HouseNoDestruct;
	class Land_ZenIceSheet : HouseNoDestruct
	{
		scope = 2;
		model = "\zenicelakes\data\models\iceplane\ice_plane_simple.p3d";
		forceFarBubble = "true";
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 99999;
					healthLevels[] =
					{

						{
							1,

							{
								"zenicelakes\data\textures\iceplane\iceplane.rvmat"
							}
						},

						{
							0.69999999,

							{
								"zenicelakes\data\textures\iceplane\iceplane.rvmat"
							}
						},

						{
							0.5,

							{
								"zenicelakes\data\textures\iceplane\iceplane.rvmat"
							}
						},

						{
							0.30000001,

							{
								"zenicelakes\data\textures\iceplane\iceplane.rvmat"
							}
						},

						{
							0,

							{
								"zenicelakes\data\textures\iceplane\iceplane.rvmat"
							}
						}
					};
				};
			};
		};
	};
	class Land_ZenIceSheet_4x4 : HouseNoDestruct
	{
		scope = 2;
		model = "\zenicelakes\data\models\iceplane\ice_plane_4x4.p3d";
		forceFarBubble = "true";
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 99999;
					healthLevels[] =
					{

						{
							1,

							{
								"zenicelakes\data\textures\iceplane\iceplane.rvmat"
							}
						},

						{
							0.69999999,

							{
								"zenicelakes\data\textures\iceplane\iceplane.rvmat"
							}
						},

						{
							0.5,

							{
								"zenicelakes\data\textures\iceplane\iceplane.rvmat"
							}
						},

						{
							0.30000001,

							{
								"zenicelakes\data\textures\iceplane\iceplane.rvmat"
							}
						},

						{
							0,

							{
								"zenicelakes\data\textures\iceplane\iceplane.rvmat"
							}
						}
					};
				};
			};
		};
	};
	class Land_ZenIceSheet_4x4_Hole : HouseNoDestruct
	{
		scope = 2;
		model = "\zenicelakes\data\models\iceplane\ice_plane_4x4_hole.p3d";
		forceFarBubble = "true";
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 99999;
					healthLevels[] =
					{

						{
							1,

							{
								"zenicelakes\data\textures\iceplane\iceplane.rvmat"
							}
						},

						{
							0.69999999,

							{
								"zenicelakes\data\textures\iceplane\iceplane.rvmat"
							}
						},

						{
							0.5,

							{
								"zenicelakes\data\textures\iceplane\iceplane.rvmat"
							}
						},

						{
							0.30000001,

							{
								"zenicelakes\data\textures\iceplane\iceplane.rvmat"
							}
						},

						{
							0,

							{
								"zenicelakes\data\textures\iceplane\iceplane.rvmat"
							}
						}
					};
				};
			};
		};
	};
};