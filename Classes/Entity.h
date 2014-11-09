//
//  Entity.h
//  pao
//
//  Created by zc on 14-10-16.
//
//

#ifndef __pao__Entity__
#define __pao__Entity__

#include <stdio.h>
#include "cocos2d.h"
#include "ControlListen.h"
#include "control.h"
USING_NS_CC;
class Entity : public CCLayer,public ControlListen{
public:
    Entity();
    void bindSprite(CCSprite* sp);
    CCSprite* getSprite();
    void setControl(control* con);
    
    virtual void SetTagPosition(int x,int y);
    virtual CCPoint getTagPosition();
    virtual void SetTwotickFlag(bool flag);
    virtual bool getTwotickFlag();
protected:
    bool TwoTickFlag;
    CCSprite* mSprite;
    control* mKongzhi;
};
#endif /* defined(__pao__Entity__) */
