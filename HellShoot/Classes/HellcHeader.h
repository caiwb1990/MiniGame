//
//  HellcHeader.h
//  HellShoot
//
//  Created by wenbin.cai on 15/4/6.
//
//

#ifndef HellShoot_HellcHeader_h
#define HellShoot_HellcHeader_h


#include "SimpleAudioEngine.h"
#include "HellcUtils.h"

#define SOUND_KEY "sound_key"
#define MUSIC_KEY "music_key"

#define HIGHSCORE_KEY "highscore_key"

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)

#define bg_music_1   "sound/home_bg.aifc"
#define bg_music_2  "sound/game_bg.aifc"
#define sound_1   "sound/Blip.caf"
#define sound_2   "sound/Explosion.caf"

#else

#define bg_music_1   "sound/home_bg.mp3"
#define bg_music_2  "sound/game_bg.mp3"
#define sound_1   "sound/Blip.wav"
#define sound_2   "sound/Explosion.wav"

#endif


//gameplay
#include "Enemy.h"
#include "Fighter.h"
#include "Bullet.h"
#include "GameoverScene.h"

#define GameSceneNodeBatchTagBackground				800

#define GameSceneNodeTagFighter						900
#define GameSceneNodeTagExplosionParticleSystem		901
#define GameSceneNodeBatchTagBullet					902
#define GameSceneNodeBatchTagEnemy					903

#define GameSceneBulletVelocity						300

#define GameSceneNodeTagStatusBarFighterNode		301
#define GameSceneNodeTagStatusBarLifeNode			302
#define GameSceneNodeTagStatusBarScore				303


//scores
typedef enum
{
    EnemyStone_Score = 5,
    Enemy1_Score = 10,
    Enemy2_Score = 15,
    EnemyPlanet_Score = 20
} EnemyScores;


using namespace CocosDenshion;


#endif
