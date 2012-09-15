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


class GameScene : public cocos2d::CCLayerColor
{
public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    // there's no 'id' in cpp, so we recommand to return the exactly class pointer
    static cocos2d::CCScene* scene();
    
      
    // implement the "static node()" method manually
    LAYER_CREATE_FUNC(GameScene);
    
    //关于 回调函数
    void menuBackCallback(CCObject* pSender);
    
    void addTarget();
    void spriteMoveFinished(CCNode* pSender);
    void gameLogic(float dt);
    
    virtual void registerWithTouchDispatcher();
    virtual bool ccTouchBegan(cocos2d::CCTouch *touch, cocos2d::CCEvent *pEvent);
    virtual void ccTouchMoved(cocos2d::CCTouch *pTouche, cocos2d::CCEvent *pEvent);
    virtual void ccTouchEnded(cocos2d::CCTouch *pTouche, cocos2d::CCEvent *pEvent);
    virtual void ccTouchCancelled(cocos2d::CCTouch *touch, cocos2d::CCEvent *event);

};

#endif
