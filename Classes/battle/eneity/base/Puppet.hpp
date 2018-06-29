//
//  Puppet.hpp
//  Battle2D-mobile
//
//  Created by welove-jiajiaju on 2018/6/29.
//

#ifndef Puppet_hpp
#define Puppet_hpp

#include <stdio.h>
#include "cocos2d.h"

#include "GameInfo.hpp"

class Puppet: public cocos2d::Sprite{
private:
    CharacterAnimationInfo _info;
    std::string _currentAniamtion = "walk";
    float _elasped = 0.0;
    float _animationTimer = 0.0;
    int _frameNumber = 0;
    bool _isLoop = false;
    
    std::string _getSpriteFrameName();
public:
    
    static Puppet* create(const CharacterAnimationInfo& info);
    
    Puppet(const CharacterAnimationInfo& info);
    virtual bool init();
    
    void play(const std::string& animationName);
    void setLoop(bool isLoop){ _isLoop = isLoop; }
    
    void tick(float dt);
};

#endif /* Puppet_hpp */
