//
//  GameScene.cpp
//  HellShoot
//
//  Created by wenbin.cai on 15/4/7.
//
//

#include "GameScene.h"

USING_NS_CC;

#define GameSceneNodeBatchTagBackground				800

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