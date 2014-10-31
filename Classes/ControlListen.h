//
//  ControlListen.h
//  pao
//
//  Created by zc on 14-10-16.
//
//

#ifndef __pao__ControlListen__
#define __pao__ControlListen__

#include <stdio.h>
#include "cocos2d.h"
USING_NS_CC;
class ControlListen {
public:
    virtual void SetTagPosition(int x,int y)=0;
    virtual CCPoint getTagPosition()=0;
};
#endif /* defined(__pao__ControlListen__) */
