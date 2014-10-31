//
//  TollgateScene.h
//  pao
//
//  Created by zc on 14-10-16.
//
//

#ifndef __pao__TollgateScene__
#define __pao__TollgateScene__

#include <stdio.h>
#include "cocos2d.h"

USING_NS_CC;

class TollgateScene : public CCLayer {
public:
    CREATE_FUNC(TollgateScene);
    virtual bool init();
    static CCScene* scene();
    void addPlayer(CCTMXTiledMap* map);
};
#endif /* defined(__pao__TollgateScene__) */
