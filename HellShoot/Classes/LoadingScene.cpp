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
    
    // add the sprite as a child to this layer
    this->addChild(bg);
    
    auto logo =  Sprite::createWithSpriteFrameName("logo.png");
    this->addChild(logo);
    logo->setPosition(Vec2(visibleSize.width/2, visibleSize.height/2));
    
    auto sprite =  Sprite::createWithSpriteFrameName("loding4.png");
    this->addChild(sprite);
    sprite->setPosition(logo->getPosition() - Vec2(0, logo->getContentSize().height / 2 + 30));
   
    return true;
}
