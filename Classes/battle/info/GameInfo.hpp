//
//  GameInfo.hpp
//  Battle2D-mobile
//
//  Created by welove-jiajiaju on 2018/6/29.
//

#ifndef GameInfo_hpp
#define GameInfo_hpp

#include <stdio.h>

struct CharacterAnimationInfo{
    std::string name = "";
    std::map<std::string, std::vector<int>> animationFrame;
};

#endif /* GameInfo_hpp */
