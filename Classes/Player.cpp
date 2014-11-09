//
//  Player.cpp
//  pao
//
//  Created by zc on 14-10-16.
//
//

#include "Player.h"
Player::Player() {
    mditu = NULL;
}
Player::~Player() {
    CC_SAFE_RELEASE(mditu);
}
bool Player::init() {
    return true;
}

void Player::run() {
    CCSpriteFrame *frame = NULL;
    int picNum = 13;
    CCArray* ArrayFrame = CCArray::create();
    for (int i = 1; i<=picNum; i++) {
        frame = CCSpriteFrame::create(CCString::createWithFormat("zhujiao%d.png",i)->getCString(), CCRectMake(0, 0, 200, 200));
        ArrayFrame->addObject(frame);
    }
    
    CCAnimation* donghua = CCAnimation::createWithSpriteFrames(ArrayFrame);
    donghua->setLoops(-1);
    donghua->setDelayPerUnit(0.04f);
    CCAnimate* act = CCAnimate::create(donghua);
    getSprite()->runAction(act);
}

void Player::setViewPoint() {
    if (mSprite == NULL) {
        return;
    }
    CCLayer * parent = (CCLayer*)getParent();
    CCSize mapTildNum = mditu->getMapSize();
    CCSize tiledSize = mditu->getTileSize();
    CCSize mapSize = CCSize::CCSize(mapTildNum.width*tiledSize.width,mapTildNum.height*tiledSize.height);
    CCSize visblesize = CCDirector::sharedDirector()->getVisibleSize();
    
    CCPoint posSp = getPosition();
    
    float x =fmax(posSp.x,visblesize.width/2);
    float y = fmax(posSp.y,visblesize.height/2);
    x = fmin(x, mapSize.width-visblesize.width/2);
    y = fmin(y, mapSize.height-visblesize.height/2);
    
    CCPoint TagPos = CCPoint::CCPoint(x,y);
    CCPoint centerPos = CCPoint::CCPoint(visblesize.width/2,visblesize.height/2);
    CCPoint viewPos = ccpSub(centerPos, TagPos);
    parent->setPosition(viewPos);
}

void Player::SetTagPosition(int x, int y) {
    CCSize spSize = mSprite->getContentSize();
    CCPoint mudiPos = CCPoint(x+spSize.width/2, y+spSize.height/2);
//    CCLOG("mudi pos x=%f,y=%f",mudiPos.x,mudiPos.y);
    CCPoint tiledPos = ChangeCoord(ccp(mudiPos.x, mudiPos.y));
    CCLOG("x=%f,y=%f",tiledPos.x,tiledPos.y);
    int tiledGid = sucai->tileGIDAt(tiledPos);
    if (tiledGid != 0) {
        CCDictionary* shuxing = mditu->propertiesForGID(tiledGid);
        const CCString* value = shuxing->valueForKey("zaw");
        if (value->m_sString.compare("true")==0) {
            if(Entity::getTwotickFlag()== true) {
                x = x-2;
                y = y-3;
                Entity::SetTwotickFlag(false);
            }else {
                return;
            }
        }
    }

    Entity::SetTagPosition(x, y);
    setViewPoint();
}

CCPoint Player::ChangeCoord(CCPoint pos){
    CCSize pisSize = mditu->getTileSize();
    int x = pos.x/pisSize.width;
    int y = (640-pos.y)/pisSize.width;
    if (x>0) {
        x= x-4;
    }
    if (y>0) {
        y=y+2;
    }
    return ccp(x,y);
}

void Player::setTileMap(CCTMXTiledMap *map){
    CC_SAFE_RETAIN(map);
    CC_SAFE_RELEASE(map);
    
    this->mditu = map;
    this->sucai = mditu->layerNamed("sucai");
    this->sucai->setVisible(false);
    this->sucai->retain();
}

