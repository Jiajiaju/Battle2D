//
//  BattleEngine.hpp
//  BattleDesign-mobile
//
//  Created by welove-jiajiaju on 2018/6/12.
//

#ifndef BattleEngine_hpp
#define BattleEngine_hpp

#include <stdio.h>
#include "Singleton.hpp"

#include "Puppet.hpp"

class BattleScene;

class BattleEngine: public Singleton<BattleEngine>{
private:
    
    BattleScene* _battleScene = nullptr;
    
    void _initBattle();
    void _loadResource();
    void _initCharacters();
    
    int _logicFPS = 0;
    float _logicInterval = 0.0f;
    float _logicTimer = 0.0f;
    
    Puppet* _testPuppet;
public:
    void enterBattle();
    
    void tick(float dt);
};

#endif /* BattleEngine_hpp */
