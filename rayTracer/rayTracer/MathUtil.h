//#pragma once
//
//#include <random>
//#include <cmath>
//
//#include "vec3.h"
//#include "ray.h"
//
//namespace Math
//{
//    extern std::default_random_engine rng;
//    extern std::uniform_real_distribution<double> distrib;
//    
//    // Pick a random point with -1 <= x,y,z < 1, reject it if
//    // magnitude > 1 (outside of unit sphere)
//    vec3 randomInUnitSphere(){
//        vec3 p;
//        do {
//            p = 2.0*vec3(drand48(), drand48(), drand48()) - vec3(1,1,1);
//        } while (p.lengthsquared() >= 1.0);
//        return p;
//    }
//    double getRandom(){
//        return drand48();
//    };
//};