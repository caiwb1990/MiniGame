//
//  LoadingScene.cpp
//  HellShoot
//
//  Created by wenbin.cai on 15/4/7.
//
//

#include "LoadingScene.h"

USING_NS_CC;

Scene* Loading::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = Loading::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool Loading::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    ///////////////////////////////////////////////
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("texture/loading_texture.plist");
    
    // add "HelloWorld" splash screen"
    auto bg = TMXTiledMap::create("map/red_bg.tmx");
    if(bg)
        this->addChild(bg);
    
    auto logoSpr =  Sprite::createWithSpriteFrameName("logo.png");
    if(logoSpr)
    {
        this->addChild(logoSpr);
        logoSpr->setPosition(Vec2(visibleSize.width/2, visibleSize.height/2));
    }
    
    auto loadingSpr =  Sprite::createWithSpriteFrameName("loding4.png");
    if(loadingSpr)
    {
        this->addChild(loadingSpr);
        loadingSpr->setPosition(logoSpr->getPosition() - Vec2(0, logoSpr->getContentSize().height / 2 + 30));
    }
    
    
    
    /////////Anim
    Animation* animation = Animation::create();
    if(animation)
    {
        for( int i=1; i<= 4; i++)
        {
            __String *frameName = __String::createWithFormat("loding%d.png",i);
            log("frameName = %s",frameName->getCString());
            SpriteFrame *spriteFrame = SpriteFrameCache::getInstance()->getSpriteFrameByName(frameName->getCString());
            animation->addSpriteFrame(spriteFrame);
        }
        
        animation->setDelayPerUnit(0.5f);           //设置两个帧播放时间
        animation->setRestoreOriginalFrame(true);    //动画执行后还原初始状态
        
        Animate* loadingAction = Animate::create(animation);
        if(loadingAction && loadingSpr)
            loadingSpr->runAction(RepeatForever::create(loadingAction));
    }
    
    
    /////anim end
    return true;
}
