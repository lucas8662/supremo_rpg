//--

#include <a_samp>
#include <foreach>
#include <streamer>

//--

#define MAX_GROUPS 					5
#define MAX_GROUP_OBJECTS 			500

enum enum_GroupInfo
{
	yagr_objectpivo,

	yagr_objectid[MAX_GROUP_OBJECTS],
	bool:yagr_objectdynamic[MAX_GROUP_OBJECTS],
	Float:yagr_originX[MAX_GROUP_OBJECTS],
	Float:yagr_originY[MAX_GROUP_OBJECTS],
	Float:yagr_originZ[MAX_GROUP_OBJECTS],
	Float:yagr_originRX[MAX_GROUP_OBJECTS],
	Float:yagr_originRY[MAX_GROUP_OBJECTS],
	Float:yagr_originRZ[MAX_GROUP_OBJECTS],

	Float:yagr_groupposition[6]
};
new GroupInfo[MAX_GROUPS][enum_GroupInfo],
	Iterator:ValidGroups<MAX_GROUPS>;

//--

yagr_CreateNewGroup()
{
	new index = Iter_Free(ValidGroups);
	if(index == -1)
		return -1;

	GroupInfo[index][yagr_objectpivo] = -1;

	GroupInfo[index][yagr_groupposition][0] = 0.0;
	GroupInfo[index][yagr_groupposition][1] = 0.0;
	GroupInfo[index][yagr_groupposition][2] = 0.0;
	GroupInfo[index][yagr_groupposition][3] = 0.0;
	GroupInfo[index][yagr_groupposition][4] = 0.0;
	GroupInfo[index][yagr_groupposition][5] = 0.0;

	for(new i; i < MAX_GROUP_OBJECTS; i ++)
	{
		GroupInfo[index][yagr_objectid][i] = -1;
		GroupInfo[index][yagr_originX][i] = 0.0;
		GroupInfo[index][yagr_originY][i] = 0.0;
		GroupInfo[index][yagr_originZ][i] = 0.0;
		GroupInfo[index][yagr_originRX][i] = 0.0;
		GroupInfo[index][yagr_originRY][i] = 0.0;
		GroupInfo[index][yagr_originRZ][i] = 0.0;
	}

	Iter_Add(ValidGroups, index);
	printf("Group %d created", index);
	return index;
}

yagr_DeleteGroup(groupid)
{
	if(!Iter_Contains(ValidGroups, groupid))
		return 0;

	Iter_Remove(ValidGroups, groupid);

	if(GroupInfo[index][yagr_objectpivo] != -1)
		DestroyObject(GroupInfo[index][yagr_objectpivo]), GroupInfo[index][yagr_objectpivo] = -1;

	GroupInfo[index][yagr_groupposition][0] = 0.0;
	GroupInfo[index][yagr_groupposition][1] = 0.0;
	GroupInfo[index][yagr_groupposition][2] = 0.0;
	GroupInfo[index][yagr_groupposition][3] = 0.0;
	GroupInfo[index][yagr_groupposition][4] = 0.0;
	GroupInfo[index][yagr_groupposition][5] = 0.0;

	for(new i; i < MAX_GROUP_OBJECTS; i ++)
	{
		GroupInfo[index][yagr_objectid][i] = -1;
		GroupInfo[index][yagr_originX][i] = 0.0;
		GroupInfo[index][yagr_originY][i] = 0.0;
		GroupInfo[index][yagr_originZ][i] = 0.0;
		GroupInfo[index][yagr_originRX][i] = 0.0;
		GroupInfo[index][yagr_originRY][i] = 0.0;
		GroupInfo[index][yagr_originRZ][i] = 0.0;
	}

	return 1;
}

yagr_AddObjectToGroup(groupid, objectid, bool:dynamic = false)
{
	if(!Iter_Contains(ValidGroups, groupid))
		return 0;

	for(new index; index < MAX_GROUP_OBJECTS; index ++)
	{
		if(GroupInfo[groupid][yagr_objectid][index] == -1)
		{
			GroupInfo[groupid][yagr_objectid][index] = objectid;
			GroupInfo[groupid][yagr_objectdynamic][index] = dynamic;

			if(dynamic)
			{
				GetDynamicObjectPos(objectid, GroupInfo[groupid][yagr_originX][index], GroupInfo[groupid][yagr_originY][index], GroupInfo[groupid][yagr_originZ][index]);
				GetDynamicObjectRot(objectid, GroupInfo[groupid][yagr_originRX][index], GroupInfo[groupid][yagr_originRY][index], GroupInfo[groupid][yagr_originRZ][index]);
			}
			else
			{
				GetObjectPos(objectid, GroupInfo[groupid][yagr_originX][index], GroupInfo[groupid][yagr_originY][index], GroupInfo[groupid][yagr_originZ][index]);
				GetObjectRot(objectid, GroupInfo[groupid][yagr_originRX][index], GroupInfo[groupid][yagr_originRY][index], GroupInfo[groupid][yagr_originRZ][index]);
			}

			UpdatePivo(groupid);
			return 1;
		}
	}
	return 0;
}

UpdatePivo(groupid)
{
	if(!Iter_Contains(ValidGroups, groupid))
		return 0;

	if(GroupInfo[groupid][yagr_objectpivo] != -1)
		DestroyObject(GroupInfo[groupid][yagr_objectpivo]);

	new Float:X, Float:Y, Float:Z, Float:ObjectPos[6];
	yagr_GetCenterCoords(groupid, X, Y, Z);
	GroupInfo[groupid][yagr_objectpivo] = CreateObject(1, X, Y, Z, 0.0, 0.0, 0.0);
	for(new i; i < MAX_GROUP_OBJECTS; i ++)
	{
		if(GroupInfo[groupid][yagr_objectid][i] != -1)
		{
			yagr_GetObjectPos(groupid, GroupInfo[groupid][yagr_objectid][i], ObjectPos[0], ObjectPos[1], ObjectPos[2], ObjectPos[3], ObjectPos[4], ObjectPos[5]);
			AttachObjectToObject(GroupInfo[groupid][yagr_objectid][i], GroupInfo[groupid][yagr_objectpivo], (ObjectPos[0]-X), (ObjectPos[1]-Y), (ObjectPos[2]-Z), ObjectPos[3], ObjectPos[4], ObjectPos[5], 1);
		}
	}
	return 1;
}

yagr_RemoveGroupObject(groupid, objectid)
{
	if(!Iter_Contains(ValidGroups, groupid))
		return 0;
	for(new i; i < MAX_GROUP_OBJECTS; i ++)
	{
		if(GroupInfo[groupid][yagr_objectid][i] == objectid)
		{
			GroupInfo[groupid][yagr_objectid][i] == -1;
			GroupInfo[groupid][yagr_objectdynamic][i] = false;

			GroupInfo[groupid][yagr_originX][i] = 0.0;
			GroupInfo[groupid][yagr_originY][i] = 0.0;
			GroupInfo[groupid][yagr_originZ][i] = 0.0;
			GroupInfo[groupid][yagr_originRX][i] = 0.0;
			GroupInfo[groupid][yagr_originRY][i] = 0.0;
			GroupInfo[groupid][yagr_originRZ][i] = 0.0;
			return 1;
		}
	}
	return 0;
}

yagr_MoveGroup(groupid, Float:X, Float:Y, Float:Z, Float:Speed, Float:rX = -1000.0, Float:rY = -1000.0, Float:rZ = -1000.0)
{
	if(!Iter_Contains(ValidGroups, groupid))
		return 0;
	return MoveObject(GroupInfo[groupid][yagr_objectpivo], X, Y, Z, Speed, rX, rY, rZ);
}

yagr_GetObjectIndex(groupid, objectid)
{
	if(!Iter_Contains(ValidGroups, groupid))
		return -1;

	for(new i; i < MAX_GROUP_OBJECTS; i ++)
	{
		if(GroupInfo[groupid][yagr_objectid][i] == objectid)
			return i;
	}

	return -1;
}

yagr_GetObjectPos(groupid, objectid, &Float:X, &Float:Y, &Float:Z, &Float:rX, &Float:rY, &Float:rZ)
{
	if(!Iter_Contains(ValidGroups, groupid))
		return 0;

	new index = yagr_GetObjectIndex(groupid, objectid);
	if(index == -1)
		return 0;

	if(GroupInfo[groupid][yagr_objectdynamic][index])
	{
		GetDynamicObjectPos(objectid, X, Y, Z);
		GetDynamicObjectRot(objectid, rX, rY, rZ);
	}
	else
	{
		GetObjectPos(objectid, X, Y, Z);
		GetObjectRot(objectid, rX, rY, rZ);
	}
	return 1;
}

yagr_GetCenterCoords(groupid, &Float:X, &Float:Y, &Float:Z)
{
	new Float:highX = -9999999.0;
	new Float:highY = -9999999.0;
	new Float:highZ = -9999999.0;

	new Float:lowX  = 9999999.0;
	new Float:lowY  = 9999999.0;
	new Float:lowZ  = 9999999.0;

	new count, Float:oX, Float:oY, Float:oZ, Float:null;

	for(new i; i < MAX_GROUP_OBJECTS; i ++)
	{
		if(GroupInfo[groupid][yagr_objectid][i] != -1)
		{
			yagr_GetObjectPos(groupid, GroupInfo[groupid][yagr_objectid][i], oX, oY, oZ, null, null, null);
			if(oX > highX) highX = oX;
			if(oY > highY) highY = oY;
			if(oZ > highZ) highZ = oZ;
			if(oX < lowX) lowX = oX;
			if(oY < lowY) lowY = oY;
			if(oZ < lowZ) lowZ = oZ;
			count++;
		}
	}

	if(count < 1) return 0;

	X = (highX + lowX) / 2;
	Y = (highY + lowY) / 2;
	Z = (highZ + lowZ) / 2;
	return 1;
}
