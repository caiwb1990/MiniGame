#include "Global.h"

DECLARE_SINGLETON_MEMBER(Global);

Global::Global(void)
{
	gameScene = NULL;
    
	gameLayer = NULL;
    
	controlLayer = NULL;
    
	gameMap = NULL;
    
	hero = NULL;
    
	//新游戏，当前地图层数为0
	currentLevel = 0;
    
	//勇士出生位置
	heroSpawnTileCoord = CCPoint(1, 11);
}

Global::~Global(void)
{
    
}