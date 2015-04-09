//
//  Enemy.h
//  HellShoot
//
//  Created by wenbin.cai on 15/4/9.
//
//

#ifndef __HellShoot__Enemy__
#define __HellShoot__Enemy__


#include "cocos2d.h"

//定义敌人名称 也是敌人精灵帧的名字
#define Enemy_Stone "gameplay.stone1.png"
#define Enemy_1 "gameplay.enemy-1.png"
#define Enemy_2 "gameplay.enemy-2.png"
#define Enemy_Planet "gameplay.enemy.planet.png"

//定义敌人类型
typedef enum
{
    EnemyTypeStone = 0,     //陨石
    EnemyTypeEnemy1,      //敌机1
    EnemyTypeEnemy2,      //敌机2
    EnemyTypePlanet       //行星
} EnemyTypes;


class Enemy : public cocos2d::Sprite
{
    //    EnemyTypes type;            //敌人类型
    //    int initialHitPoints;       //初始的生命值
    //    int hitPoints;              //当前的生命值
    //    cocos2d::Vec2 velocity;    //速度
    
    CC_SYNTHESIZE(EnemyTypes, enemyType, EnemyType);
    CC_SYNTHESIZE(int, initialHitPoints, InitialHitPoints);
    CC_SYNTHESIZE(int, hitPoints, HitPoints);
    CC_SYNTHESIZE(cocos2d::Vec2, velocity, Velocity);
    
    public :
    Enemy(EnemyTypes enemyType);
    
    void spawn();
    virtual void update(float dt);
    static Enemy* createWithEnemyTypes(EnemyTypes enemyType);
};


#endif /* defined(__HellShoot__Enemy__) */
