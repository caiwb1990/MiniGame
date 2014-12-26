#ifndef _ENEMY_H_
#define _ENEMY_H_

#include "cocos2d.h"

USING_NS_CC;

class Enemy : public Ref
{
public:
	Enemy(void);
	~Enemy(void);
    
	//怪物在TileMap上的方位
	Point position;
    
	//怪物初始的图块ID
	int startGID;
    
	//怪物在字典中的index
	int index;
};

#endif