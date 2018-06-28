//
//  BattleScene.hpp
//  BattleDesign-mobile
//
//  Created by welove-jiajiaju on 2018/6/12.
//

#ifndef BattleScene_hpp
#define BattleScene_hpp

#include <stdio.h>
#include "cocos2d.h"

class BattleGround;

class BattleScene: public cocos2d::Scene{
private:
public:
    
    BattleGround* battleGround = nullptr;
    
    static BattleScene* create();
    
    virtual bool init();
};

#endif /* BattleScene_hpp */
