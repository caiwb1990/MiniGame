//
//  MenuBaseLayer.h
//  HellShoot
//
//  Created by wenbin.cai on 15/4/6.
//
//

#ifndef __HellShoot__MenuBaseLayer__
#define __HellShoot__MenuBaseLayer__

#include "cocos2d.h"

#include "HellcHeader.h"

class MenuBaseLayer : public cocos2d::Layer
{
public:
    
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    virtual void onEnterTransitionDidFinish();
    
    void menuBackCallback(cocos2d::Ref* pSender);
    
};

#endif /* defined(__HellShoot__MenuBaseLayer__) */
