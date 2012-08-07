//
//  About.cpp
//  Game
//
//  Created by mac on 12-8-7.
//
//
#include "cocos2d.h"
#include "About.h"
#include "MenuScene.h"
#include "SimpleAudioEngine.h"

using namespace cocos2d;
using namespace CocosDenshion;

CCScene* AboutScene::scene()
{
    CCScene* scene = CCScene::create();
    
    AboutScene* layer = AboutScene::create();
    
    scene->addChild(layer);
    return scene;
}

bool AboutScene::init()
{
    
    // 1. super init first
    if ( !CCLayer::init() )
    {
        return false;
    }

    //--------------------------
    //加入简介和图片
    
    // ask director the window size
    CCSize size = CCDirector::sharedDirector()->getWinSize();
    // add "HelloWorld" splash screen"
    CCSprite* pSprite = CCSprite::create("HelloWorld.png");
    
    // position the sprite on the center of the screen
    pSprite->setPosition( ccp(size.width/2, size.height/2) );
    
    // add the sprite as a child to this layer
    this->addChild(pSprite, 0);
    
    //  TODO 坐标有问题
    CCMenuItemFont* back = CCMenuItemFont::create("Back", this, menu_selector(AboutScene::menuBackCallback));
    back->setPosition(ccp(50, 100));
    
    CCMenu *pMenu = CCMenu::create(back, NULL);
    
    this->addChild(pMenu, 0);
    return true;
    
}

//返回上一层菜单
void AboutScene::menuBackCallback(CCObject* pSender)
{

    CCDirector::sharedDirector()->replaceScene(MenuScene::scene());

}




