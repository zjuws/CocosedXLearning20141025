#include "HelloWorldScene.h"
#include "Ball.h"

USING_NS_CC;

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
    TableView * tv=TableView::create(this,Size(300,300));
    tv->setAnchorPoint(Point(0,0));
    tv->setPosition(Point(100,100));
    tv->setDelegate(this);
    addChild(tv);
    //-------------------------------------------
    //菜单项的用法
//    auto menu=Menu::create(MenuItemImage::create("CloseNormal.png", "CloseSelected.png", [](Object* obj){
//        log("menu item touched");
//    }), NULL);
//    addChild(menu);
    
    //--------------------------------------------
    //使用自定义类
//     Size visibleSize=Director::getInstance()->getVisibleSize();
//    auto b=Ball::create();
//    b->setPosition(200,200);
//    addChild(b);
    //-------------------------------------------------------
    //Textfield的使用
//    Size visibleSize=Director::getInstance()->getVisibleSize();
//    TextFieldTTF *tf=TextFieldTTF::textFieldWithPlaceHolder("在这里输入", "宋体", 20);
//    tf->setPosition(visibleSize.width/2,visibleSize.height/2);
//    addChild(tf);
//    auto listrner=EventListenerTouchOneByOne::create();
//    listrner->onTouchBegan=[tf](Touch *t,Event *event){
//        if (tf->getBoundingBox().containsPoint(t->getLocation())) {
////             log(">>>>>>");
//            tf->attachWithIME();
//        }
//        else{
//            tf->detachWithIME();
//        }
//       
//        return false;
//    };
//    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listrner, tf);
    //--------------------------------------------
    //labelTTF使用
//    Size size=Director::getInstance()->getVisibleSize();
//    LabelTTF *laber=LabelTTF::create();
//    laber->setString("Hello jikexuyuan");
//    laber->setPosition(size.width/2,size.height/2);
//    laber->setFontSize(36);
//    addChild(laber);
    return true;
}
Size HelloWorld::cellSizeForTable(cocos2d::extension::TableView *table){
    return Size(300,50);
}
TableViewCell* HelloWorld::tableCellAtIndex(cocos2d::extension::TableView *table, ssize_t idx){
    TableViewCell *cell=table->dequeueCell();
    LabelTTF *label;
    if (cell==NULL) {
        cell=TableViewCell::create();
        label=LabelTTF::create();
        label->setTag(2);
        label->setFontSize(24);
        label->setAnchorPoint(Point(0,0));
        cell->addChild(label);
    }
    else{
        label=(LabelTTF*)cell->getChildByTag(2);
        
    }
    label->setString(StringUtils::format("Label %d",(int)idx));
    return cell;
    
}
ssize_t HelloWorld::numberOfCellsInTableView(cocos2d::extension::TableView *table){
    return 100;
}
void HelloWorld::tableCellTouched(cocos2d::extension::TableView *table, cocos2d::extension::TableViewCell *cell){
    LabelTTF *label=(LabelTTF*)cell->getChildByTag(2);
    log("%s",label->getString().c_str());
}
void HelloWorld::menuCloseCallback(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
	MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
    return;
#endif

    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
