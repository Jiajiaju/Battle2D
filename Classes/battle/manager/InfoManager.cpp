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
        std::string name = item["Name"].GetString();
        CharacterAnimationInfo info;
        info.name = name;
        for (rapidjson::SizeType ii = 0; ii < item["Animations"].Size(); ++ii){
            rapidjson::Value& animation = item["Animations"][ii];
            info.animationFrame[animation["Name"].GetString()].push_back(animation["StartFrame"].GetInt());
            info.animationFrame[animation["Name"].GetString()].push_back(animation["EndFrame"].GetInt());
            info.animationFrame[animation["Name"].GetString()].push_back(animation["EventFrame"].GetInt());
        }
        characterAnimationInfo[info.name] = info;
    }
    
    for (auto iter = characterAnimationInfo.begin(); iter != characterAnimationInfo.end(); ++iter){
        CCLOG("\n%s, %s", iter->first.c_str(), iter->second.name.c_str());
        for (auto iteriter = iter->second.animationFrame.begin(); iteriter != iter->second.animationFrame.end(); ++iteriter){
            CCLOG("%s ", iteriter->first.c_str());
            for (auto iteriteriter = iteriter->second.begin(); iteriteriter != iteriter->second.end(); ++iteriteriter){
                CCLOG("%d, ", *iteriteriter);
            }
        }
    }
}
