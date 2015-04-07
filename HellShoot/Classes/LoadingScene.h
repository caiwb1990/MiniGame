//
//  LoadingScene.h
//  HellShoot
//
//  Created by wenbin.cai on 15/4/7.
//
//

#ifndef __HellShoot__LoadingScene__
#define __HellShoot__LoadingScene__


#include "cocos2d.h"

#include "HellcHeader.h"


class Loading : public cocos2d::Layer
{
private:
    void delayCall(float dt);
    void loadingTextureCallBack(cocos2d::Texture2D* texture);
    int m_nNumberOfLoaded;
    
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();
    
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();

    
    // implement the "static create()" method manually
    CREATE_FUNC(Loading);
};
#endif /* defined(__HellShoot__LoadingScene__) */
