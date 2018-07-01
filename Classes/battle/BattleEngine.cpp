//
//  BattleEngine.cpp
//  BattleDesign-mobile
//
//  Created by welove-jiajiaju on 2018/6/12.
//

#include "BattleEngine.hpp"

#include "GameManager.hpp"
#include "BattleGround.hpp"
#include "BattleScene.hpp"

#include "Puppet.hpp"

void BattleEngine::enterBattle(){
    
    cocos2d::Director* director = cocos2d::Director::getInstance();
    
    BattleInfo::getInstance()->init();
    _initBattle();
    
    this->_loadResource();
    
    _battleScene = BattleScene::create();
    director->runWithScene(_battleScene);
    
    _initCharacters();
    
    director->getScheduler()->schedule([&](float dt){
        this->tick(dt);
    }, this, 0, -1, 0, false, "main_tick");
}

void BattleEngine::_initBattle(){
    _logicFPS = 8;
    _logicInterval = 1.0f / static_cast<float>(_logicFPS);
    _logicTimer = 0;
}

void BattleEngine::_loadResource(){
    cocos2d::SpriteFrameCache::getInstance()->addSpriteFramesWithFile("character/BeastMaster.plist");
    cocos2d::SpriteFrameCache::getInstance()->addSpriteFramesWithFile("character/Crabman.plist");
    cocos2d::SpriteFrameCache::getInstance()->addSpriteFramesWithFile("character/Hammerhold.plist");
    cocos2d::SpriteFrameCache::getInstance()->addSpriteFramesWithFile("character/Mage.plist");
    cocos2d::SpriteFrameCache::getInstance()->addSpriteFramesWithFile("character/Mirage.plist");
    cocos2d::SpriteFrameCache::getInstance()->addSpriteFramesWithFile("character/Pirate.plist");
    cocos2d::SpriteFrameCache::getInstance()->addSpriteFramesWithFile("character/Priest.plist");
}

void BattleEngine::_initCharacters(){
    cocos2d::Sprite* musketeer = cocos2d::Sprite::createWithSpriteFrameName("BeastMaster_00000.png");
    musketeer->setPosition(100, 100);
    _battleScene->battleGround->addChild(musketeer);
    
    _testPuppet = Puppet::create(GameManagerInstance->infoManager->characterAnimationInfo["Hammerhold"]);
    _testPuppet->setPosition(200, 100);
    _battleScene->battleGround->addChild(_testPuppet);
    _testPuppet->play("walk");
    _testPuppet->setLoop(true);
    
}

void BattleEngine::tick(float dt){
//    CCLOG("BattleEngine::tick, %.2f", dt);
    _testPuppet->tick(dt);
    _logicTimer -= dt;
    while (_logicTimer <= 0){
        _logicTimer = _logicInterval;
//        CCLOG("Logic Tick: %f", _logicInterval);
    }
    _battleScene->tick(dt);
}
