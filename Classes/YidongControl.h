//
//  YidongControl.h
//  pao
//
//  Created by zc on 14-10-23.
//
//

#ifndef __pao__YidongControl__
#define __pao__YidongControl__

#include <stdio.h>
#include "cocos2d.h"
#include "control.h"
USING_NS_CC;

class YidongControl : public control{
public:
    CREATE_FUNC(YidongControl);
    virtual bool init();
    virtual void update(float dt);
    
    virtual void registerWithTouchDispatcher();
    virtual bool ccTouchBegan(CCTouch* pTouch,CCEvent* pEvent);
    virtual void ccTouchMoved(CCTouch* pTouch,CCEvent* pEvent);
    virtual void ccTouchEnded(CCTouch* pTouch,CCEvent* pEvent);
    void setXspeed(int value);
    void setYspeed(int value);
private:
    int mXspeed;
    int mYspeed;
};
#endif /* defined(__pao__YidongControl__) */
