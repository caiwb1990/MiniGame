#ifndef __GAME_LAYER_H__
#define __GAME_LAYER_H__

#include "cocos2d.h"
#include "MTGame.h"

using namespace cocos2d;

class GameMap;
class Hero;

class GameLayer : public CCLayer
{
public:
	GameLayer(void);
	~GameLayer(void);
    
	virtual bool init();
    
	CREATE_FUNC(GameLayer);
    
	void update(float time);
	void setSceneScrollPosition(CCPoint position);
    
	//显示tip
	void showTip(const char *tip, CCPoint position);
    
protected:
	GameMap *map;
	Hero *hero;
	void onShowTipDone(CCNode* pSender);
};

#endif