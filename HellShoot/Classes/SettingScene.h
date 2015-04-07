//
//  SettingScene.h
//  HellShoot
//
//  Created by wenbin.cai on 15/4/7.
//
//

#ifndef __HellShoot__SettingScene__
#define __HellShoot__SettingScene__

#include "cocos2d.h"

#include "MenuBaseLayer.h"

class SettingLayer : public MenuBaseLayer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();
    
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    void menuSoundToggleCallback(cocos2d::Ref* pSender);
    void menuMusicToggleCallback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(SettingLayer);
};
#endif /* defined(__HellShoot__SettingScene__) */