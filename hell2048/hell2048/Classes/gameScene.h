#ifndef __game2048_SCENE_H__
#define __game2048_SCENE_H__

#include "cocos2d.h"

class game2048 : public cocos2d::CCLayer
{
public:
    virtual bool init();
    static cocos2d::CCScene* scene();
    
    //重写生命周期函数
    virtual void onEnter();
    virtual void onExit();
    
    //重写触屏回调函数
    virtual bool ccTouchBegan(cocos2d::CCTouch *touch, cocos2d::CCEvent *unused_event);
    virtual void ccTouchEnded(cocos2d::CCTouch *touch, cocos2d::CCEvent *unused_event);
    
private:
    //坐标
    float beginX;
    float beginY;
    float endX;
    float endY;
    
    //滑向上下左右的方法
    bool swipeUp();
    bool swipeDown();
    bool swipeLeft();
    bool swipeRight();
    
    CREATE_FUNC(game2048);
};

#endif // __game2048_SCENE_H__
