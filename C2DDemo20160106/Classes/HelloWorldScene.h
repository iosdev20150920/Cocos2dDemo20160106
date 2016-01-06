#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"

class HelloWorld : public cocos2d::Layer
{
public:
    
    virtual ~HelloWorld();
    
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    // a play event callback
    void buttonEventPlayCallback(cocos2d::Ref* pSender);
    
    // a pause event callback
    void buttonEventPauseCallback(cocos2d::Ref* pSender);
    
    
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);
    
private:
    void addTextObject();
    void addPlayAndPauseButtons();
    
    cocos2d::Label* textObj;
    cocos2d::Menu* playButton;
    cocos2d::Menu* pauseButton;
};

#endif // __HELLOWORLD_SCENE_H__
