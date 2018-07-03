//
//  Transform.hpp
//  Battle2D-mobile
//
//  Created by welove-jiajiaju on 2018/7/2.
//

#ifndef Transform_hpp
#define Transform_hpp

#include <stdio.h>

#include "Vector2D.hpp"

struct Transform{
    Vector2D position;
    Vector2D velocity;
    Vector2D direction;
    float height = 0.0f;
    float zSpeed = 0.0f;
    float gravity = 0.0f;
    float radius = 0.0f;
};

#endif /* Transform_hpp */
