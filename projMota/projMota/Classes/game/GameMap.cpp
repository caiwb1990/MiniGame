#include "GameMap.h"

GameMap::GameMap(void)
{
	sGlobal->gameMap = this;
}

GameMap::~GameMap(void)
{
	this->unscheduleAllSelectors();
}

//静态方法，用于生成GameMap实例
GameMap* GameMap::gameMapWithTMXFile(const char *tmxFile)
{
	//new一个对象
	GameMap *pRet = new GameMap();
    
	//调用init方法
	if (pRet->initWithTMXFile(tmxFile))
	{
		//调用额外的init方法
		pRet->extraInit();
        
		//将实例放入autorelease池，统一由引擎控制对象的生命周期
		pRet->autorelease();
		return pRet;
	}
    
	CC_SAFE_DELETE(pRet);
	return NULL;
}

//TliedMap额外的初始化方法
void GameMap::extraInit()
{
	//开启各个图层的纹理抗锯齿
	enableAnitiAliasForEachLayer();
    
	//初始化各层对象
	floorLayer = this->getLayer("floor");
	wallLayer = this->getLayer("wall");
	itemLayer = this->getLayer("item");
	doorLayer = this->getLayer("door");
    
	initEnemy();
	initObject();
}

void GameMap::initEnemy()
{
	//获取怪物层
	enemyLayer = this->getLayer("enemy");
    
	CCSize s = enemyLayer->getLayerSize();
    
	//遍历enemy层，将存在的怪物保存到数组中
	for (int x = 0; x < s.width; x++)
	{
		for (int y = 0; y < s.height; y++)
		{
			int gid = enemyLayer->getTileGIDAt(CCPoint(x, y));
			if (gid != 0)
			{
				Enemy* enemy = new Enemy();
                
				//保存怪物坐标
				enemy->position = CCPoint(x, y);
                
				//保存怪物起始的图块ID
				enemy->startGID = gid;
                
				//添加怪物对象到数组
				enemyArray.push_back(enemy);
			}
		}
	}
    
	//用于更新敌人动画
	schedule(schedule_selector(GameMap::updateEnemyAnimation), 0.2f);
}

//更新怪物的图块
void GameMap::updateEnemyAnimation(float time)
{
	std::vector<Enemy*>::iterator  iter;
	Enemy *enemy, *needRemove = NULL;
    
	//遍历保存所有怪物对象的数组
	for (iter = enemyArray.begin(); iter != enemyArray.end(); ++iter)
	{
		enemy = *iter;
		if (enemy != NULL)
		{
			//获取怪物当前的图块ID
			int gid = enemyLayer->getTileGIDAt(enemy->position);
            
			//如果怪物被删除了，需要把它在enemyArray中也删除
			if (gid == 0)
			{
				needRemove = enemy;
				continue;
			}
			gid++;
            
			//如果下一个图块ID 起始图块ID
			if (gid - enemy->startGID > 3)
			{
				gid = enemy->startGID;
			}
            
			//给怪物设置新的图块
			enemyLayer->setTileGID(gid, enemy->position);
		}
	}
    
	//删除被消灭的怪物
	if (needRemove != NULL)
	{
		enemyArray.eraseObject(needRemove);
	}
}

//初始化对象层
void GameMap::initObject()
{
	//获取对象层
	TMXObjectGroup* group = this->objectGroupNamed("object");
    
	//获取对象层内的所有对象
	const ValueVector &objects = group->getObjects();
    
	//遍历所有对象
	for(ValueVector::const_iterator it = objects.begin();
		it != objects.end(); it++)
	{
		const ValueMap &dict = (*it).asValueMap();
        
		std::string key = "x";
        
		//获取x坐标
		int x = dict.at(key).asInt();
		key = "y";
        
		//获取y坐标
		int y = dict.at(key).asInt();
		Point tileCoord = tileCoordForPosition(Point(x, y));
        
		//计算唯一ID
		int index = tileCoord.x + tileCoord.y * this->getMapSize().width;
		key = "type";
        
		//获取对象类别
		std::string type = dict.at(key).asString();
        
		//如果类型是传送门
		if (type == "teleport")
		{
			Teleport *teleport = new Teleport(dict, x, y);
			teleportDict.insert(index, teleport);
		}
		//如果类型是NPC对象
		else if (type == "npc")
		{
			NPC *npc = new NPC(dict, x, y);
			npcDict.insert(index, npc);
		}
	}
}

void GameMap::enableAnitiAliasForEachLayer()
{
	const Vector<Node *>&  childrenArray = this->getChildren();
    
	//遍历Tilemap的所有图层
	for (size_t i = 0, count = childrenArray.size(); i < count; i++)
	{
		SpriteBatchNode* child = (SpriteBatchNode*)childrenArray.at(i);
        
		if (!child)
		{
			break;
		}
        
		//给图层的纹理开启抗锯齿
		child->getTexture()->setAntiAliasTexParameters();
	}
}

//从cocos2d-x坐标转换为Tilemap坐标
Point GameMap::tileCoordForPosition(Point position)
{
	int x = position.x / this->getTileSize().width;
	int y = (((this->getMapSize().height - 1) * this->getTileSize().height) - position.y) / this->getTileSize().height;
	return Point(x, y);
}

//从Tilemap坐标转换为cocos2d-x坐标
Point GameMap::positionForTileCoord(Point tileCoord)
{
	Point pos = Point((tileCoord.x * this->getTileSize().width), ((this->getMapSize().height - tileCoord.y - 1) * this->getTileSize().height));
	return pos;
}

//更新怪物战斗时的颜色状态
void GameMap::updateEnemyHitEffect(float time)
{
	//更新次数加一
	fightCount++;
    
	if (fightCount % 2 == 1)
	{
		//设置怪物sprite颜色为白色
		fightingEnemy->setColor(ccWHITE);
	}
	else
	{
		//设置怪物sprite颜色为红色
		fightingEnemy->setColor(ccRED);
	}
    
	//切换5次后取消定时器
	if (fightCount == 5)
	{
		unschedule(schedule_selector(GameMap::updateEnemyHitEffect));
	}
}

//显示怪物打击动画
void GameMap::showEnemyHitEffect(Point tileCoord)
{
	//更新次数
	fightCount = 0;
    
	//获取怪物对应的CCSprite对象
	fightingEnemy = enemyLayer->tileAt(tileCoord);
    
	if (fightingEnemy == NULL)
	{
		return;
	}
    
	//设置怪物sprite颜色为红色
	fightingEnemy->setColor(ccRED);
    
	//启动定时器更新打击状态
	this->schedule(schedule_selector(GameMap::updateEnemyHitEffect), 0.18f);
}
