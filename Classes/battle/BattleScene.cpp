//
//  BattleScene.cpp
//  BattleDesign-mobile
//
//  Created by welove-jiajiaju on 2018/6/12.
//

#include "BattleScene.hpp"
#include "BattleGround.hpp"

USING_NS_CC;

BattleScene* BattleScene::create(){
    BattleScene* scene = new (std::nothrow) BattleScene();
    if (scene && scene->init()){
        scene->autorelease();
        return scene;
    }
    
    delete scene;
    scene = nullptr;
    return nullptr;
}

bool BattleScene::init(){
    if (!Scene::init()){
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    
    LayerColor* layer = LayerColor::create(Color4B(255, 255, 255, 255), visibleSize.width, visibleSize.height);
    this->addChild(layer);
    
    battleGround = BattleGround::create();
    this->addChild(battleGround);
    
    return true;
}
