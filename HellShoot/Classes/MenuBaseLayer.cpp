//
//  MenuBaseLayer.cpp
//  HellShoot
//
//  Created by wenbin.cai on 15/4/6.
//
//

#include "MenuBaseLayer.h"



USING_NS_CC;

// on "init" you need to initialize your instance
bool MenuBaseLayer::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    auto bg = TMXTiledMap::create("map/red_bg.tmx");
    addChild(bg);
    
    //眼镜精灵.
    auto glassesSprite = Sprite::createWithSpriteFrameName("setting.glasses.png");
    glassesSprite->setPosition(Vec2(visibleSize.width - glassesSprite->getContentSize().width /2, 160));
    addChild(glassesSprite);
    
    //手套精灵.
    auto handSprite = Sprite::createWithSpriteFrameName("setting.hand.png");
    handSprite->setPosition(Vec2(handSprite->getContentSize().width /2, 60));
    addChild(handSprite);
    
    //Ok菜单.
    auto okNormal = Sprite::createWithSpriteFrameName("setting.button.ok.png");
    auto okSelected = Sprite::createWithSpriteFrameName("setting.button.ok-on.png");
    
    auto okMenuItem = MenuItemSprite::create(okNormal, okSelected, CC_CALLBACK_1(MenuBaseLayer::menuBackCallback, this));
    auto mu = Menu::create(okMenuItem, NULL);
    mu->setPosition(Vec2(visibleSize.width - mu->getContentSize().width /2 + 60, 60));
    addChild(mu);
    
    
    return true;
}


void MenuBaseLayer::menuBackCallback(Ref* pSender)
{
    Director::getInstance()->popScene();
    
    if (UserDefault::getInstance()->getBoolForKey(SOUND_KEY)) {
        SimpleAudioEngine::getInstance()->playEffect(sound_1);
    }
}


void MenuBaseLayer::onEnterTransitionDidFinish()
{
    Layer::onEnterTransitionDidFinish();
    
    log("BaseLayer onEnterTransitionDidFinish");
    
    UserDefault *defaults  = UserDefault::getInstance();
    
    if (defaults->getBoolForKey(MUSIC_KEY)) {
        SimpleAudioEngine::getInstance()->playBackgroundMusic(bg_music_1, true);
    }
}