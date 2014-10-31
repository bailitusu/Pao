//
//  TollgateScene.cpp
//  pao
//
//  Created by zc on 14-10-16.
//
//

#include "TollgateScene.h"
#include "Player.h"
#include "EasyMoveControl.h"
#include "YidongControl.h"
bool TollgateScene::init() {
    CCTMXTiledMap* map = CCTMXTiledMap::create("level01.tmx");
    this->addChild(map);
    addPlayer(map);
    return true;
}

CCScene* TollgateScene::scene() {
    CCScene* mScene = CCScene::create();
    TollgateScene* mLayer = TollgateScene::create();
    mScene->addChild(mLayer);
    return mScene;
}

void TollgateScene::addPlayer(CCTMXTiledMap *map) {
    CCSize pmSize = CCDirector::sharedDirector()->getVisibleSize();
    CCSprite* spplayer = CCSprite::create("zhujiao1.png");
    Player* mPlayer = Player::create();
    mPlayer->bindSprite(spplayer);
    mPlayer->setTileMap(map);

    mPlayer->setPosition(ccp(200,pmSize.height/2));
    map->addChild(mPlayer,2);
    mPlayer->run();

    YidongControl *moveCon = YidongControl::create();
    moveCon->setXspeed(2);
    moveCon->setYspeed(0);
    this->addChild(moveCon);
    mPlayer->setControl(moveCon);
    moveCon->setTouchEnabled(true);

}