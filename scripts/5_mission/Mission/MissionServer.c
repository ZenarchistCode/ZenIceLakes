#ifdef SERVER
#include "$profile:\\Zenarchist\\ZenIceLakes.c"
#endif

modded class MissionServer
{
	override void OnInit()
	{
		super.OnInit();

        // #ifdef is necessary because this code compiles client-side too even though it's not run, causing client to not know the contents of ZenIceLakes.c and crashing
        #ifdef SERVER
        string worldName = "empty";
        GetGame().GetWorldName(worldName);
        worldName.ToUpper();
        ZenIcePlanesDefault.CheckDefaultCFile(worldName);
        IGNORE_ICE_PLANE_POSITIONS = new array<string>;
        ZenIceLakes_Spawn();
        IGNORE_ICE_PLANE_POSITIONS.Clear();
        delete IGNORE_ICE_PLANE_POSITIONS;
        #endif
	}
}

static ref array<string> IGNORE_ICE_PLANE_POSITIONS;

static void SpawnZenIcePlanes(string pointAS, string pointBS, string pointCS, string pointDS, float height = 0.0, float gridSizeMeters = 8.0)
{
    if (height == 0.0)
        return;

    pointAS.Replace("/", "0");
    pointBS.Replace("/", "0");
    pointCS.Replace("/", "0");
    pointDS.Replace("/", "0");

    vector pointA = pointAS.ToVector();
    vector pointB = pointBS.ToVector();
    vector pointC = pointCS.ToVector();
    vector pointD = pointDS.ToVector();

    // Find the min/max bounds for X and Z from the 4 points
    float minX = Math.Min(pointA[0], Math.Min(pointB[0], Math.Min(pointC[0], pointD[0])));
    float maxX = Math.Max(pointA[0], Math.Max(pointB[0], Math.Max(pointC[0], pointD[0])));
    float minZ = Math.Min(pointA[2], Math.Min(pointB[2], Math.Min(pointC[2], pointD[2])));
    float maxZ = Math.Max(pointA[2], Math.Max(pointB[2], Math.Max(pointC[2], pointD[2])));

    // Calculate grid counts based on the bounding box
    int gridXCount = Math.Ceil((maxX - minX) / gridSizeMeters);
    int gridZCount = Math.Ceil((maxZ - minZ) / gridSizeMeters);

    int objectSpawnCount = 0;

    float spawnX;
    float spawnZ;
    vector spawnPos;
    vector checkWater;
    bool skipThis;
    float surfaceY;
    float diff;
    float waterDepth;

    // Spawn the ice planes within the bounds
    for (int x = 0; x < gridXCount; x++)
    {
        for (int z = 0; z < gridZCount; z++)
        {
            // Calculate the position for each ice plane
            spawnX = minX + (x * gridSizeMeters);
            spawnZ = minZ + (z * gridSizeMeters);
            spawnPos = Vector(spawnX, height, spawnZ);

            skipThis = false;
            for (int i = 0; i < IGNORE_ICE_PLANE_POSITIONS.Count(); i++)
            {
                if (vector.Distance(IGNORE_ICE_PLANE_POSITIONS.Get(i).ToVector(), spawnPos) < 0.1)
                    skipThis = true;
            }

            checkWater = spawnPos;
            checkWater[1] = surfaceY;
            waterDepth = GetGame().GetWaterDepth(checkWater);
            surfaceY = GetGame().SurfaceY(spawnX, spawnZ);
            diff = spawnPos[1] - surfaceY;

            if (diff < -5 && waterDepth < 0) // If we're 5+ meters underground and not in water, we probably don't need this ice plane.
                skipThis = true;

            if (skipThis)
                continue;

            // Spawn the ice plane
            ZenIceLakes_SpawnObject("Land_ZenIceSheet_4x4", spawnPos, "0 0 0");
            objectSpawnCount++;
        }
    }

    Print("[ZenIceLakes] Spawned " + objectSpawnCount + " ice planes @ " + pointA);
}

static Object ZenIceLakes_SpawnObject(string type, vector position, vector orientation = "0 0 0")
{
    Object obj = GetGame().CreateObjectEx(type, position, ECE_SETUP | ECE_UPDATEPATHGRAPH | ECE_CREATEPHYSICS);
    if (!obj)
    {
        Error("Failed to create object " + type);
        return NULL;
    }

    obj.SetPosition(position);
    obj.SetOrientation(orientation);
    obj.SetOrientation(obj.GetOrientation());
    obj.Update();
    obj.SetAffectPathgraph(true, false);

    if (obj.CanAffectPathgraph())
    {
        GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(GetGame().UpdatePathgraphRegionByObject, 100, false, obj);
    }

    return obj;
}