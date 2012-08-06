//
//  GameScene.h
//  Game
//
//  Created by mac on 12-8-6.
//
//

#ifndef Game_GameScene_h
#define Game_GameScene_h
#include "cocos2d.h"


class GameScene : public cocos2d::CCLayer
{
public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    // there's no 'id' in cpp, so we recommand to return the exactly class pointer
    static cocos2d::CCScene* scene();
    
      
    // implement the "static node()" method manually
    LAYER_CREATE_FUNC(GameScene);
};

#endif
