//
//  GameScene.cpp
//  Game
//
//  Created by mac on 12-8-6.
//
//

#include "GameScene.h"
#include "SimpleAudioEngine.h"
#include "SceneManager.h"

using namespace cocos2d;
using namespace CocosDenshion;


CCScene* GameScene::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    GameScene *layer = GameScene::create();
    
    // add layer as a child to scene
    //CCLayerColor colorLayer = CCLayerColor::CCLayerColor();
    
       
    scene->addChild(layer);
    //TODO
    //添加返回
    //添加精灵
    //触控支持
    
    
    // return the scene
    return scene;
}


// on "init" you need to initialize your instance
bool GameScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !CCLayer::init() )
    {
        return false;
    }
    
    CCSize size = CCDirector::sharedDirector()->getWinSize();
//为相应平台添加自己的东西
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
//add background
    
    CCMenuItemFont *back = CCMenuItemFont::create("Back", this, menu_selector(GameScene::menuBackCallback));
    //exit->setAnchorPoint(CCPointZero);
    back->setPosition(ccp(size.width/2,size.height));
    
    CCMenu* pMenu = CCMenu::create(back, NULL);
    this->addChild(pMenu, 1);
//add sprite
    CCSprite* pSprite = CCSprite::create("plane.jpg");
    pSprite->setPosition(ccp(60,60));
    this->addChild(pSprite, 1);

#endif
    
    if(CCLayerColor::initWithColor(ccc4(255, 255, 255, 0))) {
        CCLog("init color sucess!");
        return true;
    }else
        return false;
}

//menu back to home
void GameScene::menuBackCallback(CCObject* pSender) {
    SceneManager::loadScene(BACK_TO_HOME);
}

