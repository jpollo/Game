//
//  SceneManager.cpp
//  Game
//
//  Created by mac on 12-8-17.
//
//

#include "SceneManager.h"
//include some scenes
#include "About.h"
#include "GameScene.h"

//include some layers
//

cocos2d::CCScene SceneManager::loadScene(SceneType type) {
    switch (type) {
        case GAME_SCENE:
            CCLog("GAME SCENE");
            return NULL;
            break;
        case ABOUT_SCENE:
            CCLog("About Scene");
            return NULL;
            break;
        case INTRO_SCENE:
            CCLog("Introduction Scene");
            return NULL;
            break;
        default:
            break;
    }

}