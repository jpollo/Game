//
//  SceneManager.h
//  Game
//
//  Created by mac on 12-8-17.
//
//

#ifndef Game_SceneManager_h
#define Game_SceneManager_h

#include"cocos2d.h"
#include "GameConstants.h"

using namespace cocos2d;

//存放一些于游戏的常量
enum SceneType{
    ABOUT_SCENE,
    INTRO_SCENE,
    GAME_SCENE,
    BACK_TO_HOME,
    EXIT,
};


class SceneManager {
public:
    
    static void loadScene(SceneType type);

private:
    
protected:

};





#endif
