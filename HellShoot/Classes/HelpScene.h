//
//  HelpScene.h
//  HellShoot
//
//  Created by wenbin.cai on 15/4/7.
//
//

#ifndef __HellShoot__HelpScene__
#define __HellShoot__HelpScene__


#include "cocos2d.h"
#include "MenuBaseLayer.h"

class HelpLayer : public MenuBaseLayer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();
    
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    // implement the "static create()" method manually
    CREATE_FUNC(HelpLayer);
};

#endif /* defined(__HellShoot__HelpScene__) */
