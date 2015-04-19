//
//  GameoverScene.h
//  HellShoot
//
//  Created by wenbin.cai on 15/4/19.
//
//

#ifndef __HellShoot__GameoverScene__
#define __HellShoot__GameoverScene__

#include "cocos2d.h"
#include "HellcUtils.h"

#include "HellcHeader.h"

class GameOverLayer : public cocos2d::Layer
{
    //当前玩家比赛分数
    int score;
public:
    
    GameOverLayer(int score);
    
    virtual bool init();
    virtual void onExit();
    
    static GameOverLayer* createWithScore(int score);
};
#endif /* defined(__HellShoot__GameoverScene__) */
