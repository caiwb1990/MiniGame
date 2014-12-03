#include "gameScene.h"
#include "SimpleAudioEngine.h"

using namespace cocos2d;
using namespace CocosDenshion;


CCScene* game2048::scene()
{
    CCScene *scene = CCScene::create();
    game2048 *layer = game2048::create();
    scene->addChild(layer);

    return scene;
}

bool game2048::init()
{
    if ( !CCLayer::init() )
    {
        return false;
    }

    return true;
}

void game2048::onEnter()
{
    CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, 0, false);
    CCLayer::onEnter();
}

void game2048::onExit()
{
    CCDirector::sharedDirector()->getTouchDispatcher()->removeDelegate(this);
    CCLayer::onExit();
}

//监听事件回调：触摸开始和触摸结束
bool game2048::ccTouchBegan(cocos2d::CCTouch *touch, cocos2d::CCEvent *unused_event)
{
    
    CCPoint curPoint = touch->getLocation();
    touch->getLocationInView();

    beginX=curPoint.x;
    beginY=curPoint.y;
    
    return true;
}

void game2048::ccTouchEnded(cocos2d::CCTouch *touch, cocos2d::CCEvent *unused_event)
{
    //获取X轴和Y轴的移动范围
    CCPoint curPoint=touch->getLocation();
    
    endX=beginX - curPoint.x;
    endY=beginY - curPoint.y;
    
    //判断X轴和Y轴的移动距离，如果X轴的绝对值大，则向左右滑动，如果Y轴的绝对值大，则向上下滑动
    if(abs(endX) > abs(endY))
    {
        //判断向左还是向右
        if(endX + 5 >= 0)
        {
            swipeLeft();
        }
        else
        {
            swipeRight();
        }
    }
    else
    {
        //判断手势向上还是向下
        if(endY + 5 >= 0)
        {
            swipeDown();
        }
        else
        {
            swipeUp();
        }
    }
    
    
}

bool game2048::swipeUp()
{
    CCLOG("swipeUp");
    return true;
}

bool game2048::swipeDown()
{
    CCLOG("swipeDown");
    return true;
}

bool game2048::swipeLeft()
{
    CCLOG("swipeLeft");
    return true;
}

bool game2048::swipeRight()
{
    CCLOG("swipeRight");
    return true;
}






