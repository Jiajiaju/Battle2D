//
//  Puppet.cpp
//  Battle2D-mobile
//
//  Created by welove-jiajiaju on 2018/6/29.
//

#include "Puppet.hpp"

#include "GameManager.hpp"

USING_NS_CC;

Puppet* Puppet::create(const CharacterAnimationInfo& info){
    Puppet* puppet = new (std::nothrow) Puppet(info);
    if (puppet && puppet->init()){
        puppet->autorelease();
        return puppet;
    }
    
    delete puppet;
    puppet = nullptr;
    return nullptr;
}

Puppet::Puppet(const CharacterAnimationInfo& info):_info(info){
    _elasped = 0.0;
    _currentAniamtion = "walk";
    _frameNumber = _info.animationFrame[_currentAniamtion][0];
}

bool Puppet::init(){
    if (!Sprite::initWithSpriteFrameName(_getSpriteFrameName())){
        return false;
    }
    return true;
}

void Puppet::play(const std::string& animationName){
    if (_info.animationFrame.find(animationName) != _info.animationFrame.end()){
        _currentAniamtion = animationName;
        _frameNumber = _info.animationFrame[animationName][0];
        _animationTimer = 0.0;
    }
}

void Puppet::tick(float dt){
    _elasped += dt;
    
    if (!_isLoop && _frameNumber > _info.animationFrame[_currentAniamtion][1]){
        return;
    }
    
    _animationTimer -= dt;
    while (_animationTimer <= 0.0){
        _animationTimer += 1 / static_cast<float>(GameManagerInstance->battleInfo->animationFPS);
        ++_frameNumber;
        if (_frameNumber > _info.animationFrame[_currentAniamtion][1] && _isLoop){
            _frameNumber = _info.animationFrame[_currentAniamtion][0];
        }
        this->setSpriteFrame(_getSpriteFrameName());
    }
}

std::string Puppet::_getSpriteFrameName(){
    int frameNumber = _frameNumber;
    std::string spriteName = _info.name + "_";
    while (frameNumber < 10000){
        frameNumber *= 10;
        spriteName += "0";
    }
    spriteName = spriteName + std::to_string(_frameNumber) + ".png";
    return spriteName;
}
