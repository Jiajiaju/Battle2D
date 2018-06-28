//
//  BattleEngine.cpp
//  BattleDesign-mobile
//
//  Created by welove-jiajiaju on 2018/6/12.
//

#include "BattleEngine.hpp"

#include "BattleGround.hpp"
#include "BattleScene.hpp"
#include "BattleInfo.hpp"

void BattleEngine::enterBattle(){
    
    BattleInfo::getInstance()->init();
    
    this->_loadResource();
    
    cocos2d::Director* director = cocos2d::Director::getInstance();
    _battleScene = BattleScene::create();
    director->runWithScene(_battleScene);
    
    _initCharacters();
}

void BattleEngine::_loadResource(){
    cocos2d::SpriteFrameCache::getInstance()->addSpriteFramesWithFile("character/BeastMaster.plist");
}

void BattleEngine::_initCharacters(){
    cocos2d::Sprite* musketeer = cocos2d::Sprite::createWithSpriteFrameName("BeastMaster_00000.png");
    musketeer->setPosition(100, 100);
    _battleScene->battleGround->addChild(musketeer);
}
