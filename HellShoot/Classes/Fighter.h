//
//  Fighter.h
//  HellShoot
//
//  Created by wenbin.cai on 15/4/15.
//
//

#ifndef __HellShoot__Fighter__
#define __HellShoot__Fighter__


#include "cocos2d.h"

class Fighter : public cocos2d::Sprite
{
    CC_SYNTHESIZE(int, hitPoints, HitPoints);
    CC_SYNTHESIZE(cocos2d::Vec2, velocity, Velocity);
    
    public :
    
    void setPosition(const cocos2d::Vec2& newPosition);
    static Fighter* createWithSpriteFrameName(const char* spriteFrameName);
    
};

#endif /* defined(__HellShoot__Fighter__) */
