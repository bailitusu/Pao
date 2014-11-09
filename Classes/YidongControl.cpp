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
    ticktimes = 0;
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

bool YidongControl::isInSprite(cocos2d::CCTouch *pTouch) {
    CCPoint touchPos = pTouch->getLocationInView();
    touchPos = CCDirector::sharedDirector()->convertToGL(touchPos);
    CCRect rect = getBoundBox();
    if (rect.containsPoint(touchPos)) {
        return true;
    }else {
        return false;
    }
}

CCRect YidongControl::getBoundBox() {
    if (control::mListener == NULL) {
        return CCRectMake(0, 0, 0, 0);
    }
//    CCSize spSize = ((CCSprite*)control::mListener)->getContentSize();
    CCPoint spPos = control::mListener->getTagPosition();
    CCSize pmSize = CCDirector::sharedDirector()->getVisibleSize();

    if (spPos.x > pmSize.width/2) {
        spPos.x = pmSize.width/2;
    }
    CCLOG("spPosX = %f,spPosY = %f",spPos.x,spPos.y);
//    return CCRectMake(spPos.x-spSize.width/2, spPos.y-spSize.height/2, spSize.width, spSize.height);
    return CCRectMake(spPos.x-90, spPos.y+20, 100, 100);
}

bool YidongControl::ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent) {
    
    if (this->isInSprite(pTouch)) {
        ticktimes++;
        if (ticktimes == 2) {
            control::mListener->SetTwotickFlag(true);
            ticktimes = 0;
        }
    }
    touch=true;
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
    touch=false;
    setYspeed(0);
}

void YidongControl::registerWithTouchDispatcher() {
    CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, 0, true);
}