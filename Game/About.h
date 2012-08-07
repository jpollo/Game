//
//  About.h
//  Game
//
//  Created by mac on 12-8-7.
//
//

#ifndef Game_About_h
#define Game_About_h

class AboutScene : public cocos2d::CCLayer
{
public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    // there's no 'id' in cpp, so we recommand to return the exactly class pointer
    static cocos2d::CCScene* scene();
    
    // 退出回调函数
    void menuBackCallback(CCObject* pSender);

    
    // implement the "static node()" method manually
    LAYER_CREATE_FUNC(AboutScene);
};


#endif
