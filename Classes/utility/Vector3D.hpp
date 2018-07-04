//
//  Vector3D.hpp
//  Battle2D-mobile
//
//  Created by welove-jiajiaju on 2018/7/4.
//

#ifndef Vector3D_hpp
#define Vector3D_hpp

#include <stdio.h>

#define EPSILON 0.00001

class Vector3D{
private:
public:
    float x = 0.0f;
    float y = 0.0f;
    float z = 0.0f;
    
    Vector3D(): x(0.0f), y(0.0f), z(0.0f){}
    Vector3D(float xx, float yy, float zz): x(xx), y(yy), z(zz){}
    Vector3D(const Vector3D& vector3D): x(vector3D.x), y(vector3D.y), z(vector3D.z){}
    ~Vector3D(){}
    
    Vector3D& operator=(const Vector3D& vector3D){
        x = vector3D.x;
        y = vector3D.y;
        z = vector3D.z;
        return *this;
    }
    
    inline void zero(){
        x = 0.0f;
        y = 0.0f;
        z = 0.0f;
    }
    inline bool isZero() const {
        return std::abs(x - 0.0) < EPSILON && std::abs(y - 0.0) < EPSILON && std::abs(z - 0.0) < EPSILON;
    }
    
    inline float length() const {
        return std::sqrt((x * x) + (y * y) + (z * z));
    }
    inline float lengthSq() const {
        return (x * x) + (y * y) + (z * z);
    }
    
    inline void normalize(){
        float selfLength = this->length();
        x = x / selfLength;
        y = y / selfLength;
        z = z / selfLength;
    }
    
    inline void truncate(float maxLength){
        float ratio = std::sqrt((maxLength * maxLength) / (x * x + y * y + z * z));
        if (ratio < 1){
            x *= ratio;
            y *= ratio;
            z *= ratio;
        }
    }
    
    inline float distance(const Vector3D& vector3D) const {
        return std::sqrt((x - vector3D.x) * (x - vector3D.x) + (y - vector3D.y) * (y - vector3D.y) + (z - vector3D.x) * (z - vector3D.z));
    }
    inline float distanceSq(const Vector3D& vector3D) const {
        return (x - vector3D.x) * (x - vector3D.x) + (y - vector3D.y) * (y - vector3D.y) + (z - vector3D.z) * (z - vector3D.z);
    }
    
    inline Vector3D getReverse() const {
        Vector3D result = Vector3D(-x, -y, -z);
        return result;
    }
    
    inline const Vector3D& operator+=(const Vector3D& vector3D){
        x += vector3D.x;
        y += vector3D.y;
        z += vector3D.z;
        return *this;
    }
    inline const Vector3D& operator-=(const Vector3D& vector3D){
        x -= vector3D.x;
        y -= vector3D.y;
        z -= vector3D.z;
        return *this;
    }
    inline const Vector3D& operator*=(float number){
        x *= number;
        y *= number;
        z *= number;
        return *this;
    }
    inline const Vector3D& operator/=(float number){
        x /= number;
        y /= number;
        z /= number;
        return *this;
    }
    inline bool operator==(const Vector3D& vector3D) const {
        return (std::abs(x - vector3D.x) < EPSILON) && (std::abs(y - vector3D.y) < EPSILON) && (std::abs(z - vector3D.z) < EPSILON);
    }
    inline bool operator!=(const Vector3D& vector3D) const {
        return (std::abs(x - vector3D.x) >= EPSILON) || (std::abs(y - vector3D.y) >= EPSILON) || (std::abs(z - vector3D.z) >= EPSILON);
    }
    
    inline Vector3D operator+(const Vector3D& vector3D) const {
        Vector3D result = Vector3D(x + vector3D.x, y + vector3D.y, z + vector3D.z);
        return result;
    }
    inline Vector3D operator-(const Vector3D& vector3D) const {
        Vector3D result = Vector3D(x - vector3D.x, y - vector3D.y, z - vector3D.z);
        return result;
    }
    inline float operator*(const Vector3D& vector3D) const {
        return x * vector3D.x + y * vector3D.y + z * vector3D.z;
    }
    inline Vector3D operator*(float number) const {
        Vector3D result = Vector3D(x * number, y * number, z * number);
        return result;
    }
    inline Vector3D operator/(float number) const {
        Vector3D result = Vector3D(x / number, y / number, z / number);
        return result;
    }
};

#endif /* Vector3D_hpp */
