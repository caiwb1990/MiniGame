//
//  HomeScene.h
//  HellShoot
//
//  Created by wenbin.cai on 15/4/7.
//
//

#ifndef __HellShoot__HomeScene__
#define __HellShoot__HomeScene__



#include "cocos2d.h"

#include "HellcHeader.h"

class HomeMenuLayer : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();
    
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    virtual void onEnterTransitionDidFinish();
    
    void menuItemCallback(cocos2d::Ref *sender);
    
    // implement the "static create()" method manually
};
#endif /* defined(__HellShoot__HomeScene__) */
