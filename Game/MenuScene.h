//
//  MenuScene.h
//  Game
//
//  Created by mac on 12-8-6.
//
//

#ifndef __Game__MenuScene__
#define __Game__MenuScene__

#include <iostream>
#include "cocos2d.h"


class MenuScene : public cocos2d::CCLayer
{
public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    // there's no 'id' in cpp, so we recommand to return the exactly class pointer
    static cocos2d::CCScene* scene();
    
    // 退出回调函数
    void menuCloseCallback(CCObject* pSender);
    
    //游戏开始菜单回调函数
    void menuStartCallback(CCObject* pSender);
    
    
    //关于 回调函数
    void menuAboutCallback(CCObject* pSender);
    
    // implement the "static node()" method manually
    LAYER_CREATE_FUNC(MenuScene);
};


#endif /* defined(__Game__MenuScene__) */
