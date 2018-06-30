//
//  InfoManager.cpp
//  Battle2D-mobile
//
//  Created by welove-jiajiaju on 2018/6/29.
//

#include "InfoManager.hpp"

#include "json/rapidjson.h"
#include "json/document.h"
#include "json/writer.h"
#include "json/stringbuffer.h"

void InfoManager::init(){
    characterAnimationInfo.clear();
    
    cocos2d::FileUtils* fileUtils = cocos2d::FileUtils::getInstance();
    
    // character animation
    std::string animationString = fileUtils->getStringFromFile("config/animation.json");
    rapidjson::Document animationConfig;
    animationConfig.Parse<0>(animationString.c_str());
    for (rapidjson::SizeType i = 0; i < animationConfig.Size(); ++i){
        rapidjson::Value& item = animationConfig[i];
        CCLOG("%s", item["Name"].GetString());
        std::string name = item["Name"].GetString();
        CharacterAnimationInfo info;
        info.name = name;
        for (rapidjson::SizeType ii = 0; ii < item["Animations"].Size(); ++i){
//            rapidjson::Value animation = item["Animations"][ii];
//            info.animationFrame[animation["Name"].GetString()].push_back(animation["StartFrame"].GetInt());
        }
    }
}
