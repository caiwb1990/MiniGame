#ifndef __TELEPORT_H__
#define __TELEPORT_H__

#include "MTGame.h"

USING_NS_CC;

class Teleport : public CCObject
{
public:
	Teleport(const ValueMap &dict, int x, int y);
    
	~Teleport(void);
    
	//传送点所在位置
	CCPoint tileCoord;
    
	//传送到目标层后，勇士所在坐标
	CCPoint heroTileCoord;
    
	//目标地图的层数
	int targetMap;
    
	//唯一的ID
	int index;
    
	//图片纹理的文件路径
	std::string imagePath;
    
	CCSprite *teleportSprite;
};
#endif