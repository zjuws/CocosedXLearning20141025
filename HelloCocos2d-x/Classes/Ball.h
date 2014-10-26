//
//  Ball.h
//  HelloCocos2d-x
//
//  Created by  ws on 14/10/25.
//
//

#ifndef __HelloCocos2d_x__Ball__
#define __HelloCocos2d_x__Ball__

#include <iostream>
#include "cocos2d.h"
using namespace cocos2d;
class Ball:public Sprite{
public:
    virtual bool init();
    CREATE_FUNC(Ball);
//    static Ball* create(){
//        Ball *b=new Ball();
//        b->init();
//        b->autorelease();
//        return b;
//    }
};

#endif /* defined(__HelloCocos2d_x__Ball__) */
