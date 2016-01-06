#include "HelloWorldScene.h"

USING_NS_CC;

HelloWorld::~HelloWorld()
{
    textObj->release();
    textObj = nullptr;
    
    playButton->release();
    playButton = nullptr;
    
    pauseButton->release();
    pauseButton = nullptr;
}

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
    
	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    ///< 添加播放暂停
    this->addPlayAndPauseButtons();
    
    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label
    
    auto label = Label::createWithTTF("Hello World", "fonts/Marker Felt.ttf", 24);
    
    // position the label on the center of the screen
    label->setPosition(Vec2(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - label->getContentSize().height));

    // add the label as a child to this layer
    this->addChild(label, 1);
    
    ///< 添加一段显示文字
    this->addTextObject();

    // add "HelloWorld" splash screen"
    auto sprite = Sprite::create("HelloWorld.png");

    // position the sprite on the center of the screen
    sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

    // add the sprite as a child to this layer
    this->addChild(sprite, 0);
    
    return true;
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}

void HelloWorld::addTextObject()
{
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    //    auto textObj = Label::createWithTTF("测试Demo,HelloWorl", "fonts/arial.ttf", 12); ///<中文文字显示乱码
    auto textObj = Label::createWithSystemFont("测试Demo,HelloWorl", "Helvetica Neue", 12);
    ///< 设置显示的位置
    textObj->setPosition(origin.x + visibleSize.width - textObj->getContentSize().width, origin.y + visibleSize.height - textObj->getContentSize().height);
    ///< 将文本对象添加到层节点
    this->addChild(textObj, 1);
    
    this->textObj = textObj;
    this->textObj->retain();
}

///< 添加播放/暂停事件按钮
void HelloWorld::addPlayAndPauseButtons()
{
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    // add a "close" icon to exit the progress. it's an autorelease object
    auto buttonItem = MenuItemImage::create("res/Buttons/btn-play-normal.png", "res/Buttons/btn-play-selected.png", CC_CALLBACK_1(HelloWorld::buttonEventPlayCallback, this));
    
    buttonItem->setPosition(Vec2(origin.x + visibleSize.width - buttonItem->getContentSize().width/2 ,
                                origin.y + buttonItem->getContentSize().height/2 + 50));
    
    // create menu, it's an autorelease object
    auto menu = Menu::create(buttonItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);
    
    this->playButton = menu;
    this->playButton->retain();
}

// a play event callback
void HelloWorld::buttonEventPlayCallback(cocos2d::Ref* pSender)
{
    bool bRet = Director::getInstance()->isPaused();
    if (bRet)
    {
        Director::getInstance()->resume();
    }
    else
    {
        Director::getInstance()->pause();
    }
}

// a pause event callback
void HelloWorld::buttonEventPauseCallback(cocos2d::Ref* pSender)
{
    
}

