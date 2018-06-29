//
//  InfoManager.hpp
//  Battle2D-mobile
//
//  Created by welove-jiajiaju on 2018/6/29.
//

#ifndef InfoManager_hpp
#define InfoManager_hpp

#include <stdio.h>
#include "Singleton.hpp"

#include "GameInfo.hpp"

class InfoManager: public Singleton<InfoManager>{
private:
public:
    
    std::map<std::string, CharacterAnimationInfo> characterAnimationInfo;
    
    void init();
};

#endif /* InfoManager_hpp */
