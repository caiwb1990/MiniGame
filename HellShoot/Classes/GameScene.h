//
//  GameScene.h
//  HellShoot
//
//  Created by wenbin.cai on 15/4/7.
//
//

#ifndef __HellShoot__GameScene__
#define __HellShoot__GameScene__

#include "cocos2d.h"

#include "HellcHeader.h"

class Fighter;
class GamePlayLayer : public cocos2d::Layer
{
private:
    Fighter* fighter;
    cocos2d::Menu* menu;
    
    cocos2d::EventListenerTouchOneByOne *touchFighterlistener;
    
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();
    
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    virtual void onExit();
    
    virtual void onEnter();
    
    void menuPauseCallback(cocos2d::Ref* pSender);
    void menuBackCallback(cocos2d::Ref* pSender);
    void menuResumeCallback(cocos2d::Ref* pSender);
    
    void initBG();
    void shootBullet(float dt);
    
    
    // implement the "static create()" method manually
    CREATE_FUNC(GamePlayLayer);
};

#endif /* defined(__HellShoot__GameScene__) */
