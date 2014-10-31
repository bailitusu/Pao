//
//  Player.h
//  pao
//
//  Created by zc on 14-10-16.
//
//

#ifndef __pao__Player__
#define __pao__Player__

#include <stdio.h>
#include "cocos2d.h"
#include "Entity.h"
USING_NS_CC;

class Player : public Entity {
public:
    Player();
    ~Player();
    CREATE_FUNC(Player);
    virtual bool init();
    void run();
    void setViewPoint();
    void setTileMap(CCTMXTiledMap* map);
    virtual void SetTagPosition(int x,int y);
private:
    CCTMXLayer* sucai;
    CCPoint ChangeCoord(CCPoint pos);
    CCTMXTiledMap* mditu;
};
#endif /* defined(__pao__Player__) */
