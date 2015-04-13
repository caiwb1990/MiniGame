//
//  GameScene.cpp
//  HellShoot
//
//  Created by wenbin.cai on 15/4/7.
//
//

#include "GameScene.h"
#include "Enemy.h"

USING_NS_CC;

#define GameSceneNodeBatchTagBackground				800

#define GameSceneNodeBatchTagEnemy					903

Scene* GamePlayLayer::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::createWithPhysics();
    PhysicsWorld* phyWorld = scene->getPhysicsWorld();
    //phyWorld->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
    //0,0不受到重力的影响
    phyWorld->setGravity(Vect(0,0));
    
    // 'layer' is an autorelease object
    auto layer = GamePlayLayer::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool GamePlayLayer::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    this->initBG();
    
    return true;
}

void GamePlayLayer::onEnter()
{
    Layer::onEnter();
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    
    //初始化暂停按钮.
    auto pauseSprite = Sprite::createWithSpriteFrameName("gameplay.button.pause.png");
    auto pauseMenuItem = MenuItemSprite::create(pauseSprite, pauseSprite,
                                                CC_CALLBACK_1(GamePlayLayer::menuPauseCallback, this));
    auto pauseMenu = Menu::create(pauseMenuItem, NULL);
    pauseMenu->setPosition(Vec2(30, visibleSize.height - 28));
    this->addChild(pauseMenu,20,999);
    
    //添加陨石1.
    auto stone1 = Enemy::createWithEnemyTypes(EnemyTypeStone);
    stone1->setVelocity(Vec2(0, -100));
    this->addChild(stone1, 10 , GameSceneNodeBatchTagEnemy);
    
    //添加行星.
    auto planet = Enemy::createWithEnemyTypes(EnemyTypePlanet);
    planet->setVelocity(Vec2(0, -50));
    this->addChild(planet, 10 , GameSceneNodeBatchTagEnemy);
    
    //添加敌机1.
    auto enemyFighter1 = Enemy::createWithEnemyTypes(EnemyTypeEnemy1);
    enemyFighter1->setVelocity(Vec2(0, -80));
    this->addChild(enemyFighter1, 10 , GameSceneNodeBatchTagEnemy);
    
    //添加敌机2.
    auto enemyFighter2 = Enemy::createWithEnemyTypes(EnemyTypeEnemy2);
    enemyFighter2->setVelocity(Vec2(0, -100));
    this->addChild(enemyFighter2, 10 , GameSceneNodeBatchTagEnemy);
    

    
}


void GamePlayLayer::menuPauseCallback(Ref* pSender)
{
    log("menuPauseCallback");
    if (UserDefault::getInstance()->getBoolForKey(SOUND_KEY)) {
        SimpleAudioEngine::getInstance()->playEffect(sound_1);
    }
    
    //暂停当前层中的node
    this->pause();
    
    for(const auto& node:this->getChildren())
    {
        node->pause();
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    
    //返回主菜单
    auto backNormal = Sprite::createWithSpriteFrameName("gameplay.button.back.png");
    auto backSelected = Sprite::createWithSpriteFrameName("gameplay.button.back-on.png");
    
    auto backMenuItem = MenuItemSprite::create(backNormal, backSelected,
                                               CC_CALLBACK_1(GamePlayLayer::menuBackCallback, this));
    
    //继续游戏菜单
    auto resumeNormal = Sprite::createWithSpriteFrameName("gameplay.button.resume.png");
    auto resumeSelected = Sprite::createWithSpriteFrameName("gameplay.button.resume-on.png");
    
    auto resumeMenuItem = MenuItemSprite::create(resumeNormal, resumeSelected,
                                                 CC_CALLBACK_1(GamePlayLayer::menuResumeCallback, this));
    
    menu = Menu::create(backMenuItem,resumeMenuItem, NULL);
    menu->alignItemsVertically();
    menu->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
    
    addChild(menu,20,1000);
    
}

void GamePlayLayer::menuBackCallback(Ref* pSender)
{
    log("menuBackCallback");
    Director::getInstance()->popScene();
    
    if (UserDefault::getInstance()->getBoolForKey(SOUND_KEY)) {
        SimpleAudioEngine::getInstance()->playEffect(sound_1);
    }
}

void GamePlayLayer::menuResumeCallback(Ref* pSender)
{
    log("menuResumeCallback");
    if (UserDefault::getInstance()->getBoolForKey(SOUND_KEY)) {
        SimpleAudioEngine::getInstance()->playEffect(sound_1);
    }
    
    this->resume();
    
    for(const auto& node : this->getChildren())
    {
        node->resume();
    }
    removeChild(menu);
}



void GamePlayLayer::onExit()
{
    Layer::onExit();
   
    
    auto nodes = this->getChildren();
    for (const auto& node : nodes) {
        //如果是背景不进行remove
        if (node->getTag() != GameSceneNodeBatchTagBackground)
        {
            this->removeChild(node);
        }
    }
}


//初始化游戏背景.
void GamePlayLayer::initBG()
{
    Size visibleSize = Director::getInstance()->getVisibleSize();
    //添加背景地图.
    auto bg = TMXTiledMap::create("map/blue_bg.tmx");
    this->addChild(bg,0,GameSceneNodeBatchTagBackground);
    
    //放置发光粒子背景
    ParticleSystem *ps = ParticleSystemQuad::create("particle/light.plist");
    ps->setPosition(Vec2(visibleSize.width, visibleSize.height) / 2);
    this->addChild(ps,0,GameSceneNodeBatchTagBackground);
    
    //添加背景精灵1.
    auto sprite1 = Sprite::createWithSpriteFrameName("gameplay.bg.sprite-1.png");
    sprite1->setPosition(Vec2(-50, -50));
    addChild(sprite1,0,GameSceneNodeBatchTagBackground);
    
    FiniteTimeAction * ac1 = (FiniteTimeAction *)MoveBy::create(20, Vec2(500, 600));
    FiniteTimeAction * ac2 = ((FiniteTimeAction *)ac1)->reverse();
    ActionInterval * as1 = Sequence::create(ac1, ac2, NULL);
    sprite1->runAction(RepeatForever::create(EaseSineInOut::create(as1)));
    
    //添加背景精灵2.
    auto sprite2 = Sprite::createWithSpriteFrameName("gameplay.bg.sprite-2.png");
    sprite2->setPosition(Vec2(visibleSize.width, 0));
    addChild(sprite2,0,GameSceneNodeBatchTagBackground);
    
    FiniteTimeAction * ac3 = (FiniteTimeAction *)MoveBy::create(10, Vec2(-500, 600));
    FiniteTimeAction * ac4 = ((FiniteTimeAction *)ac3)->reverse();
    ActionInterval * as2 = Sequence::create(ac3, ac4, NULL);
    sprite2->runAction(RepeatForever::create(EaseExponentialInOut::create(as2)));
    
}