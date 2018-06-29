//
//  GameManager.cpp
//  Battle2D-mobile
//
//  Created by welove-jiajiaju on 2018/6/29.
//

#include "GameManager.hpp"

void GameManager::init(){
    battleEngine = BattleEngine::getInstance();
    battleManager = BattleManager::getInstance();
    battleInfo = BattleInfo::getInstance();
    infoManager = InfoManager::getInstance();
    
    infoManager->init();
}
