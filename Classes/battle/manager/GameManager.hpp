//
//  GameManager.hpp
//  Battle2D-mobile
//
//  Created by welove-jiajiaju on 2018/6/29.
//

#ifndef GameManager_hpp
#define GameManager_hpp

#include <stdio.h>
#include "Singleton.hpp"

#include "BattleEngine.hpp"
#include "BattleInfo.hpp"
#include "BattleManager.hpp"
#include "InfoManager.hpp"

class GameManager: public Singleton<GameManager>{
private:
public:
    
    BattleEngine* battleEngine = nullptr;
    BattleInfo* battleInfo = nullptr;
    BattleManager* battleManager = nullptr;
    InfoManager* infoManager = nullptr;
    
    void init();
};

#define GameManagerInstance (GameManager::getInstance())

#endif /* GameManager_hpp */
