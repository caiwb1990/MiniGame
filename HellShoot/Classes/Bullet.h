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

class Bullet : public cocos2d::Sprite
{

    public :

    static Bullet* createWithSpriteFrameName(const char* spriteFrameName);
};
#endif /* defined(__HellShoot__Bullet__) */
