//
//  control.h
//  pao
//
//  Created by zc on 14-10-16.
//
//

#ifndef __pao__control__
#define __pao__control__

#include <stdio.h>
#include "cocos2d.h"
#include "ControlListen.h"
USING_NS_CC;

class control : public CCLayer{
public:
    void setControlListen( ControlListen* conListener);
protected:
    ControlListen* mListener;
    
};

#endif /* defined(__pao__control__) */
