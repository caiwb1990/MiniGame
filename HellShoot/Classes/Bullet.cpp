//
//  Bullet.cpp
//  HellShoot
//
//  Created by wenbin.cai on 15/4/17.
//
//

#include "Bullet.h"


USING_NS_CC;

Bullet* Bullet::createWithSpriteFrameName(const char* spriteFrameName)
{
    Bullet *bullet = new Bullet();
    if (bullet && bullet->initWithSpriteFrameName(spriteFrameName)) {
        bullet->autorelease();
        bullet->setVisible(false);
        
        auto body = PhysicsBody::createBox(bullet->getContentSize());
        
        body->setCategoryBitmask(0x01);			//0001
        body->setCollisionBitmask(0x02);		//0010
        body->setContactTestBitmask(0x01);
        
        bullet->setPhysicsBody(body);
        
        return bullet;
    }
    CC_SAFE_DELETE(bullet);
    return nullptr;
}