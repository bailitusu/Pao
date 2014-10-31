//
//  YidongControl.cpp
//  pao
//
//  Created by zc on 14-10-23.
//
//

#include "YidongControl.h"

bool YidongControl::init() {
    this->mXspeed = 0;
    this->mYspeed = 0;
    this->scheduleUpdate();
    return true;
}

void YidongControl::update(float dt) {
    if (control::mListener  == NULL) {
        return;
    }
    CCPoint dangqianPos = control::mListener->getTagPosition();
    dangqianPos.x = dangqianPos.x+mXspeed;
    dangqianPos.y = dangqianPos.y+mYspeed;
    control::mListener->SetTagPosition(dangqianPos.x, dangqianPos.y);
}

void YidongControl::setXspeed(int value) {
    this->mXspeed = value;
}
void YidongControl::setYspeed(int value) {
    this->mYspeed = value;
}
bool YidongControl::ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent) {
    return true;
}

void YidongControl::ccTouchMoved(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent) {
    CCPoint touchLocation = pTouch->getLocationInView();
    touchLocation = CCDirector::sharedDirector()->convertToGL(touchLocation);
    
    CCPoint pos = control::mListener->getTagPosition();
    int speed = 0;
    if (touchLocation.y > pos.y) {
        speed = 5;
    }else {
        speed = -5;
    }
    setYspeed(speed);
}

void YidongControl::ccTouchEnded(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent) {
    setYspeed(0);
}

void YidongControl::registerWithTouchDispatcher() {
    CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, 0, true);
}