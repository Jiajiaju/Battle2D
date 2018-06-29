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

class BattleScene;

class BattleEngine: public Singleton<BattleEngine>{
private:
    
    BattleScene* _battleScene = nullptr;
    
    void _loadResource();
    
    void _initCharacters();
public:
    
    void enterBattle();
};

#endif /* BattleEngine_hpp */
