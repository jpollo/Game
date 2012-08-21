//
//  MenuScene.cpp
//  Game
//
//  Created by mac on 12-8-6.
//
//

#include "MenuScene.h"
//#include "About.h"
//#include "GameScene.h"
#include "SimpleAudioEngine.h"
#include "SceneManager.h"

using namespace cocos2d;
using namespace CocosDenshion;


MenuScene::MenuScene()
{

}

MenuScene::~MenuScene()
{

}


CCScene* MenuScene::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    MenuScene *layer = MenuScene::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}


// on "init" you need to initialize your instance
bool MenuScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !CCLayer::init() )
    {
        return false;
    }
    
    /////////////////////////////
    //关闭按钮
    
    // add a "close" icon to exit the progress. it's an autorelease object
   // CCMenuItemImage *pCloseItem = CCMenuItemImage::create(
     //                                                     "CloseNormal.png",
       //                                                   "CloseSelected.png",
         //                                                 this,
         //                                                 menu_selector(MenuScene::menuCloseCallback) );
    //pCloseItem->setPosition( ccp(CCDirector::sharedDirector()->getWinSize().width - 20, 20) );
    
    // create menu, it's an autorelease object
    //CCMenu* pMenu = CCMenu::create(pCloseItem, NULL);
    //pMenu->setPosition( CCPointZero );
    //this->addChild(pMenu, 1);
    
    /////////////////////////////
    // 3. add your codes below...
    
    // add a label shows "Hello World"
    // create and initialize a label
    CCLabelTTF* pLabel = CCLabelTTF::create("凤凰传奇", "Thonburi", 34);
    
    // ask director the window size
    CCSize size = CCDirector::sharedDirector()->getWinSize();
    
    // position the label on the center of the screen
    pLabel->setPosition( ccp(size.width / 2, size.height - 20) );
    
    // add the label as a child to this layer
    this->addChild(pLabel, 1);
    
    // add "HelloWorld" splash screen"
    CCSprite* pSprite = CCSprite::create("logo.png");
    
    // position the sprite on the center of the screen
    pSprite->setPosition( ccp(size.width/2, size.height/2) );
    
    // add the sprite as a child to this layer
    this->addChild(pSprite, 0);
    
    
    //增加自己的菜单
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    //添加背景音乐
    SimpleAudioEngine::sharedEngine()->preloadBackgroundMusic("feng.mp3");
    SimpleAudioEngine::sharedEngine()->playBackgroundMusic("feng.mp3");
//
    double distance =60; //菜单之间相隔的距离
    
    CCMenuItemFont *start = CCMenuItemFont::create("Start", this, menu_selector(MenuScene::menuStartCallback));
    //start->setAnchorPoint(CCPointZero);
    start->setPosition(ccp(size.width/2,size.height/2+distance));
    
    CCMenuItemFont *about = CCMenuItemFont::create("About", this, menu_selector(MenuScene::menuAboutCallback));
    //about->setAnchorPoint(CCPointZero);
    about->setPosition(ccp(size.width/2,size.height/2));
    
    
    CCMenuItemFont *exit = CCMenuItemFont::create("Exit", this, menu_selector(MenuScene::menuCloseCallback));
    //exit->setAnchorPoint(CCPointZero);
    exit->setPosition(ccp(size.width/2,size.height/2-distance));
    
    CCMenu* pMenu2 = CCMenu::create(start, about, exit, NULL);
    pMenu2->setPosition(CCPointZero);
    this->addChild(pMenu2, 2);
    
    
#endif
    
    return true;
}

//void MenuScene::onEnter()
//{
//    //SimpleAudioEngine::sharedEngine()->playBackgroundMusic("feng.mp3", true);
//    //播放的时候 其他选项无法响应
//}


//退出时，关闭音乐
void MenuScene::onExit()
{
    SimpleAudioEngine::sharedEngine()->stopBackgroundMusic();
}



void MenuScene::menuCloseCallback(CCObject* pSender)
{
    CCDirector::sharedDirector()->end();
    
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}

void MenuScene::menuStartCallback(CCObject* pSender)
{
   
    SceneManager::loadScene(GAME_SCENE);

}

void MenuScene::menuAboutCallback(CCObject* pSender)
{
    SceneManager::loadScene(ABOUT_SCENE);
    
}