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

class GamePlayLayer : public cocos2d::Layer
{
private:
    

    
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();
    
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    void initBG();
    
    
    // implement the "static create()" method manually
    CREATE_FUNC(GamePlayLayer);
};

#endif /* defined(__HellShoot__GameScene__) */
