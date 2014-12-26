#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__

//包含公用头文件
#include "MTGame.h"

//使用cocos2d命名空间
using namespace cocos2d;

//GameScene继承CCScene
class GameScene : public CCScene
{
public:
	GameScene(void);
	~GameScene(void);
    
	//初始化函数
	virtual bool init();
    
	CREATE_FUNC(GameScene);
    
	void switchMap();
	void resetGameLayer();
	void removeFadeLayer();
};

#endif