#ifndef __VEC3__
#define __VEC3__

#include <math.h>
#include <stdlib.h>
#include <iostream>

class vec3 {
public:
    vec3 () {}
    vec3(float e00, float e01, float e02){ e[0] = e00; e[1] = e01; e[2] = e02; }
    inline float x() const { return e[0]; }
    inline float y() const { return e[1]; }
    inline float z() const { return e[2]; }
    inline float r() const { return e[0]; }
    inline float g() const { return e[1]; }
    inline float b() const { return e[2]; }
    
    inline const vec3& operator+() const {return *this; };
    inline vec3 operator-() const {return vec3(-e[0], -e[1], -e[2]); };
    inline float operator[](int i) const {return e[i]; };
    inline float& operator[](int i) {return e[i]; };

    inline vec3& operator +=(const vec3 &v2);
    inline vec3& operator -=(const vec3 &v2);
    inline vec3& operator *=(const vec3 &v2);
    inline vec3& operator /=(const vec3 &v2);
    inline vec3& operator *=(const float t);
    inline vec3& operator /=(const float t);

    inline float length() const {
        return sqrt(e[0]*e[0] + e[1]*e[1] + e[2]*e[2]); }
    inline float squaredlength() const {
        return e[0]*e[0] + e[1]*e[1] + e[2]*e[2]; }
    inline void makeUnitVector();

    float e[3];
    
    
};
#endif