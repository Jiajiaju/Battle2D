//
//  BattleInfo.hpp
//  BattleDesign-mobile
//
//  Created by welove-jiajiaju on 2018/6/13.
//

#ifndef BattleInfo_hpp
#define BattleInfo_hpp

#include <stdio.h>
#include "Singleton.hpp"

class BattleInfo: public Singleton<BattleInfo>{
private:
public:
    
    int battleWidth = 0;
    int battleHeight = 0;
    
    void init();
};

#define BattleInfoInstance (BattleInfo::getInstance())

#endif /* BattleInfo_hpp */
