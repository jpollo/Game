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
void SceneManager::loadScene(SceneType type) {
    switch (type) {
        case GAME_SCENE:
            CCLog("GAME SCENE");
            CCDirector::sharedDirector()->replaceScene(GameScene::scene());
            //return NULL;
            break;
        case ABOUT_SCENE:
            CCLog("About Scene");
            //return NULL;
            CCDirector::sharedDirector()->replaceScene(AboutScene::scene());
            break;
        case INTRO_SCENE:
            CCLog("Introduction Scene");
            //return NULL;
            break;
        case EXIT:
            CCLog("exit");
            break;
        default:
            break;
    }

}