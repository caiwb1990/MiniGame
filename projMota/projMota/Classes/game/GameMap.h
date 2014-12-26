#ifndef __GAME_MAP_H__
#define __GAME_MAP_H__

#include "MTGame.h"

USING_NS_CC;

class NPC;
class Teleport;

//继承自CCTMXTIledMap
class GameMap : public TMXTiledMap
{
	//只读变量，获取各图层CC_PROPERTY_READONLY
	CC_SYNTHESIZE(TMXLayer*, floorLayer, FloorLayer);
	CC_SYNTHESIZE(TMXLayer*, wallLayer, WallLayer);
	CC_SYNTHESIZE(TMXLayer*, enemyLayer, EnemyLayer);
	CC_SYNTHESIZE(TMXLayer*, itemLayer, ItemLayer);
	CC_SYNTHESIZE(TMXLayer*, doorLayer, DoorLayer);
    
public:
	GameMap(void);
	~GameMap(void);
    
	//静态方法，用于生成GameMap实例
	static GameMap* gameMapWithTMXFile(const char *tmxFile);
    
	//TiledMap和cocos2d-x坐标系相互转换的方法
	Point tileCoordForPosition(Point position);
	Point positionForTileCoord(Point tileCoord);
	void showEnemyHitEffect(Point tileCoord);
    
	//存放地图上怪物、传送门以及npc
	Vector<Enemy*> enemyArray;
	Map<int, Teleport*> teleportDict;
	Map<int, NPC*> npcDict;
    
protected:
	//TiledMap额外的初始化方法
	void extraInit();
    
	//初始化怪物数组
	void initEnemy();
    
	//初始化对象
	void initObject();
    
	//开启各图层的纹理抗锯齿
	void enableAnitiAliasForEachLayer();
    
	//更新怪物动画
	void updateEnemyAnimation(float time);
    
	//临时保存战斗时的怪物
	Sprite* fightingEnemy;
    
	//临时保存打击次数
	int fightCount;
    
	//更新怪物战斗时的颜色状态
	void updateEnemyHitEffect(float time);
};

#endif