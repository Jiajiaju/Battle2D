//
//  BattleEntity.hpp
//  Battle2D-mobile
//
//  Created by welove-jiajiaju on 2018/7/2.
//

#ifndef BattleEntity_hpp
#define BattleEntity_hpp

#include <stdio.h>

#include "Transform.hpp"

class BattleEntity{
private:
public:
    Transform transform;
    virtual ~BattleEntity() = 0;
    virtual void tick(float dt);
};

#endif /* BattleEntity_hpp */
