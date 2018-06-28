//
//  BattleGround.hpp
//  BattleDesign-mobile
//
//  Created by welove-jiajiaju on 2018/6/13.
//

#ifndef BattleGround_hpp
#define BattleGround_hpp

#include <stdio.h>
#include "cocos2d.h"

class BattleGround: public cocos2d::Node{
private:
public:
    
    static BattleGround* create();
    
    virtual bool init();
    
};

#endif /* BattleGround_hpp */
