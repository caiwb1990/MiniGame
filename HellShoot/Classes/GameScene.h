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
    //plane
    Fighter* fighter;
    //menu
    cocos2d::Menu* menu;
    
    //touch
    cocos2d::EventListenerTouchOneByOne *touchFighterlistener;
    
    //contact
    cocos2d::EventListenerPhysicsContact *contactListener;
    
    //score
    int score;
    int scorePlaceholder;
    
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();
    
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    virtual void onExit();
    
    virtual void onEnter();
    virtual void onEnterTransitionDidFinish();
    
    void menuPauseCallback(cocos2d::Ref* pSender);
    void menuBackCallback(cocos2d::Ref* pSender);
    void menuResumeCallback(cocos2d::Ref* pSender);
    
    void initBG();
    void shootBullet(float dt);
    
    void updateStatusBarScore();
    void updateStatusBarFighter();
    
    void handleBulletCollidingWithEnemy(Enemy* enemy);
    
    void handleFighterCollidingWithEnemy(Enemy* enemy);

    // implement the "static create()" method manually
    CREATE_FUNC(GamePlayLayer);
};

#endif /* defined(__HellShoot__GameScene__) */
