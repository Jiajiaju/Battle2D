//
//  BattleGround.cpp
//  BattleDesign-mobile
//
//  Created by welove-jiajiaju on 2018/6/13.
//

#include "BattleGround.hpp"

#include "BattleInfo.hpp"
#include "Vector2D.hpp"
#include "Array2D.hpp"

USING_NS_CC;

BattleGround* BattleGround::create(){
    BattleGround* battleGround = new (std::nothrow) BattleGround();
    if (battleGround && battleGround->init()){
        battleGround->autorelease();
        return battleGround;
    }
    
    delete battleGround;
    battleGround = nullptr;
    return nullptr;
}

bool BattleGround::init(){
    if (!Node::init()){
        return false;
    }
    
    Sprite* map = Sprite::create("ingame/map.png");
    map->setAnchorPoint(Vec2(0, 0));
    this->addChild(map);
    
    return true;
}
