//
//  Entity.cpp
//  pao
//
//  Created by zc on 14-10-16.
//
//

#include "Entity.h"

void Entity::bindSprite(CCSprite *sp) {
    mSprite = sp;
    this->addChild(mSprite);
}

CCSprite* Entity::getSprite() {
    return this->mSprite;
}

void Entity::setControl(control *con) {
    this->mKongzhi = con;
    mKongzhi->setControlListen(this);
}

void Entity::SetTagPosition(int x, int y){
    setPosition(ccp(x,y));
}

CCPoint Entity::getTagPosition() {
    return getPosition();
}

