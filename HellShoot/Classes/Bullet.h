//
//  Bullet.h
//  HellShoot
//
//  Created by wenbin.cai on 15/4/17.
//
//

#ifndef __HellShoot__Bullet__
#define __HellShoot__Bullet__


#include "cocos2d.h"
#include "Fighter.h"

class Bullet : public cocos2d::Sprite
{
    CC_SYNTHESIZE(cocos2d::Vec2, velocity, Velocity);
    public :
    static Bullet* createWithSpriteFrameName(const char* spriteFrameName);
    
    void shootBulletFromFighter(Fighter* fighter);
    
    
    virtual void update(float dt);
    
};
#endif /* defined(__HellShoot__Bullet__) */
