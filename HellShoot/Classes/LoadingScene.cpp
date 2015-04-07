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
    
    
    //texture cache
    m_nNumberOfLoaded = 0;
    
    Director::getInstance()->getTextureCache()->addImageAsync("texture/home_texture.png",
                CC_CALLBACK_1(Loading::loadingTextureCallBack, this));
    
    Director::getInstance()->getTextureCache()->addImageAsync("texture/setting_texture.png",CC_CALLBACK_1(Loading::loadingTextureCallBack, this));
    
    Director::getInstance()->getTextureCache()->addImageAsync("texture/gameplay_texture.png", CC_CALLBACK_1(Loading::loadingTextureCallBack, this));
    
    //cache end
    
    
    //audio
    _loadingAudioThread = new std::thread(&Loading::loadingAudio,this);

    
    return true;
}



void Loading::loadingTextureCallBack(Texture2D *texture)
{
    
    switch (m_nNumberOfLoaded++)
    {
        case 0:
            SpriteFrameCache::getInstance()->addSpriteFramesWithFile("texture/home_texture.plist",texture);
            log("home textrue ok.");
            break;
        case 1:
            SpriteFrameCache::getInstance()->addSpriteFramesWithFile("texture/setting_texture.plist",texture);
            log("setting textrue ok.");
            break;
        case 2:
            SpriteFrameCache::getInstance()->addSpriteFramesWithFile("texture/gameplay_texture.plist",texture);
            log("gamepla textrue ok.");
            this->schedule(schedule_selector(Loading::delayCall),1,1,3);
            //float interval, unsigned int repeat, float delay
            break;
    }
    
}

void Loading::delayCall(float dt)
{
    //auto sc = HomeMenuLayer::createScene();
    //Director::getInstance()->replaceScene(sc);
}


void Loading::loadingAudio()
{
    log("loadAudio");
    //初始化 音乐
    SimpleAudioEngine::getInstance()->preloadBackgroundMusic(bg_music_1);
    SimpleAudioEngine::getInstance()->preloadBackgroundMusic(bg_music_2);
    //初始化音效  TODO  预处理后没有声音，移植的时候需要测试。
    //SimpleAudioEngine::getInstance()->preloadEffect(sound_1);
    
}


void Loading::onExit()
{
    Layer::onExit();
    _loadingAudioThread->join();
    CC_SAFE_DELETE(_loadingAudioThread);
    SpriteFrameCache::getInstance()->removeSpriteFramesFromFile("texture/loading_texture.plist");
    Director::getInstance()->getTextureCache()->removeTextureForKey("texture/loading_texture.png");
    this->unschedule(schedule_selector(Loading::delayCall));
}


