//
//  HomeScene.cpp
//  HellShoot
//
//  Created by wenbin.cai on 15/4/7.
//
//

#include "HomeScene.h"

#include "SettingScene.h"
#include "HelpScene.h"
#include "GameScene.h"

USING_NS_CC;

enum
{
    kTagMenuItemStart,
    kTagMenuItemSetting,
    kTagMenuItemHelp ,
};

Scene* HomeMenuLayer::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HomeMenuLayer::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HomeMenuLayer::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    
    auto bg = TMXTiledMap::create("map/red_bg.tmx");
    addChild(bg);
    
    auto top = Sprite::createWithSpriteFrameName("home-top.png");
    top->setPosition(Vec2(visibleSize.width/2, visibleSize.height - top->getContentSize().height / 2));
    addChild(top);
    
    auto end = Sprite::createWithSpriteFrameName("home-end.png");
    end->setPosition(Vec2(visibleSize.width/2, end->getContentSize().height / 2));
    addChild(end);
    
    // 开始菜单
    auto startSpriteNormal = Sprite::createWithSpriteFrameName("home.button.start.png");
    auto startSpriteSelected = Sprite::createWithSpriteFrameName("home.button.start-on.png");
    auto startMenuItem = MenuItemSprite::create(
                                                startSpriteNormal,
                                                startSpriteSelected,
                                                CC_CALLBACK_1(HomeMenuLayer::menuItemCallback, this));
    startMenuItem->setTag(kTagMenuItemStart);
    
    // 设置菜单
    auto settingSpriteNormal = Sprite::createWithSpriteFrameName("home.button.setting.png");
    auto settingSpriteSelected = Sprite::createWithSpriteFrameName("home.button.setting-on.png");
    auto settingMenuItem = MenuItemSprite::create(
                                                  settingSpriteNormal,
                                                  settingSpriteSelected,
                                                  CC_CALLBACK_1(HomeMenuLayer::menuItemCallback, this));
    settingMenuItem->setTag(kTagMenuItemSetting);
    
    // 帮助菜单
    auto helppriteNormal = Sprite::createWithSpriteFrameName("home.button.help.png");
    auto helpSpriteSelected = Sprite::createWithSpriteFrameName("home.button.help-on.png");
    auto helpMenuItem = MenuItemSprite::create(
                                               helppriteNormal,
                                               helpSpriteSelected,
                                               CC_CALLBACK_1(HomeMenuLayer::menuItemCallback, this));
    helpMenuItem->setTag(kTagMenuItemHelp);
    
    auto mu = Menu::create(startMenuItem, settingMenuItem, helpMenuItem, NULL);
    
    mu->setPosition(visibleSize.width/2, visibleSize.height/2);
    mu->alignItemsVerticallyWithPadding(12);
    addChild(mu);
    
    return true;
}

void HomeMenuLayer::onEnterTransitionDidFinish()
{
    Layer::onEnterTransitionDidFinish();
    log("HomeMenuLayer onEnterTransitionDidFinish");
    
    UserDefault *defaults  = UserDefault::getInstance();
    if (defaults->getBoolForKey(MUSIC_KEY)) {
        SimpleAudioEngine::getInstance()->playBackgroundMusic(bg_music_1, true);
    }
}

void HomeMenuLayer::menuItemCallback(cocos2d::Ref *sender)
{
    
    if (UserDefault::getInstance()->getBoolForKey(SOUND_KEY)) {
        SimpleAudioEngine::getInstance()->playEffect(sound_1);
    }
    Scene* tsc = nullptr;
    
    MenuItem* menuItem = (MenuItem*)sender;
    log("MenuItem Tag = %d", menuItem->getTag());
    switch(menuItem->getTag())
    {
        case kTagMenuItemStart:
            tsc = TransitionFade::create(1.0f, GamePlayLayer::createScene());
            
            break;
        case kTagMenuItemHelp:
            tsc = TransitionFade::create(1.0f, HelpLayer::createScene());
           
            break;
        case kTagMenuItemSetting:
            tsc = TransitionFade::create(1.0f, SettingLayer::createScene());
            
            break;
    }
    if (tsc) 
        Director::getInstance()->pushScene(tsc);
    
}
