#ifndef __GAME_MAP_H__
#define __GAME_MAP_H__

#include "MTGame.h"

USING_NS_CC;

class NPC;
class Teleport;

//继承自CCTMXTIledMap
class GameMap : public CCTMXTiledMap
{
	//只读变量，获取各图层CC_PROPERTY_READONLY
	CC_SYNTHESIZE(CCTMXLayer*, floorLayer, FloorLayer);
	CC_SYNTHESIZE(CCTMXLayer*, wallLayer, WallLayer);
	CC_SYNTHESIZE(CCTMXLayer*, enemyLayer, EnemyLayer);
	CC_SYNTHESIZE(CCTMXLayer*, itemLayer, ItemLayer);
	CC_SYNTHESIZE(CCTMXLayer*, doorLayer, DoorLayer);
    
public:
	GameMap(void);
	~GameMap(void);
    
	//静态方法，用于生成GameMap实例
	static GameMap* gameMapWithTMXFile(const char *tmxFile);
    
	//TiledMap和cocos2d-x坐标系相互转换的方法
	CCPoint tileCoordForPosition(CCPoint position);
	CCPoint positionForTileCoord(CCPoint tileCoord);
	void showEnemyHitEffect(CCPoint tileCoord);
    
	//存放地图上怪物、传送门以及npc
    std::vector<Enemy*> enemyArray;
    std::map<int, Teleport*> teleportDict;
    std::map<int, NPC*> npcDict;
    
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
	CCSprite* fightingEnemy;
    
	//临时保存打击次数
	int fightCount;
    
	//更新怪物战斗时的颜色状态
	void updateEnemyHitEffect(float time);
};

#endif