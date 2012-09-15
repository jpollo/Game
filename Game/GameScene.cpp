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
//TODO
//添加返回
//添加精灵
//触控支持

CCScene* GameScene::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    GameScene *layer = GameScene::create();
    
    // add layer as a child to scene
    //CCLayerColor colorLayer = CCLayerColor::CCLayerColor();
    
       
    scene->addChild(layer);

    
    
    // return the scene
    return scene;
}


// on "init" you need to initialize your instance
bool GameScene::init()
{
    //////////////////////////////
    // 1. super init first
//    if ( !CCLayer::init() )
//    {
//        return false;
//    }
    if(!CCLayerColor::initWithColor(ccc4(0, 0, 0, 0))) {
        return false;
    }

    
    CCSize size = CCDirector::sharedDirector()->getWinSize();
    
//为相应平台添加自己的东西
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
//add background
    
    CCMenuItemFont *backMenu = CCMenuItemFont::create("Back", this, menu_selector(GameScene::menuBackCallback));
    //exit->setAnchorPoint(CCPointZero);
    backMenu->setPosition(ccp(size.width/2,size.height/2));
    
    CCMenu* pMenu = CCMenu::create(backMenu, NULL);
    pMenu->setPosition(CCPointZero);
    this->addChild(pMenu, 1);
    
    //add static postion sprite
    CCSprite* pSprite = CCSprite::create("plane.jpg");
    pSprite->setPosition(ccp(60,60));
    this->addChild(pSprite, 2);
    
    //add moving sprites
    //schedule_selector
    this->schedule(schedule_selector(GameScene::gameLogic), 1.0);
    //set touch enabled
    this->setTouchEnabled(true);

#endif
    
//    if(CCLayerColor::initWithColor(ccc4(255, 255, 255, 255))) {
//        //CCLog("init color sucess!");
//        return true;
//    }else
//        return false;
    return true;
}

void GameScene::addTarget()
{
    CCSprite *target = CCSprite::create("plane.jpg");
    
    //Determin where to spawm the target along the Y axis;
    CCSize winSize = CCDirector::sharedDirector()->getWinSize();
    int minY = target->getContentSize().height/2;
    int maxY = winSize.height - target->getContentSize().height/2;
    
    int rangeY = maxY - minY;
    int actualY = (rand() % rangeY) + minY;
    
    //create the target slightly off-screen along the right edge and along a random position along the y axis as calculated
    target->setPosition(ccp(winSize.width + (target->getContentSize().width/2),actualY));

    this->addChild(target);
    
    //determine speed
    int minDuration = (int)2.0;
    int maxDuratoin = (int)4.0;
    int rangeDuration = maxDuratoin - minDuration;
    int actualDuration = (rand() % rangeDuration) + minDuration;
    
    //create the actions
    CCFiniteTimeAction* actionMove =
        CCMoveTo::create((float)actualDuration, ccp(0-target->getContentSize().width/2, actualY));
    //callFuncN selector
    CCFiniteTimeAction* actionMoveDone =
        CCCallFuncN::create(this, callfuncN_selector(GameScene::spriteMoveFinished));
    target->runAction(CCSequence::create(actionMove, actionMoveDone, NULL));

}

//move finished
void GameScene::spriteMoveFinished(CCNode* sender)
{
    CCSprite* sprite = (CCSprite *)sender;
    this->removeChild(sprite, true);
}

//Game logic
void GameScene::gameLogic(float dt)
{
//    CCLog("add a move sprite...");
    this->addTarget();
}


//menu back to home
void GameScene::menuBackCallback(CCObject* pSender) {
    SceneManager::loadScene(BACK_TO_HOME);
}

// new 2.0
void GameScene::registerWithTouchDispatcher()
{
    CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, 0, true);
}

bool GameScene::ccTouchBegan(cocos2d::CCTouch *touch, cocos2d::CCEvent *event)
{
    //获取触点坐标
    CCPoint touchLocation = touch->locationInView();
    touchLocation = CCDirector::sharedDirector()->convertToGL(touchLocation);
//    CCLog("touch began");
    
    
    return true;
}

void GameScene::ccTouchEnded(cocos2d::CCTouch * touch, cocos2d::CCEvent * event)
{

}

void GameScene::ccTouchMoved(cocos2d::CCTouch *touch, cocos2d::CCEvent * event)
{
    //移动精灵
    CCPoint touchLocation = touch->locationInView();
    CCPoint prevLocation = touch->previousLocationInView();
    touchLocation = CCDirector::sharedDirector()->convertToGL(touchLocation);
    prevLocation = CCDirector::sharedDirector()->convertToGL(prevLocation);
    
    //sprite -> setPosition

}

void GameScene::ccTouchCancelled(cocos2d::CCTouch* touch, cocos2d::CCEvent* event)
{

}


