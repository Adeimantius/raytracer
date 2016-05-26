//
//  main.cpp
//  rayTracer
//
//  Created by Markus Ristich on 2016-05-22.
//  Copyright © 2016 Markus Ristich. All rights reserved.
//

#include <iostream>
#include "ray.h"
#include "vec3.h"
bool hitSphere (const vec3& center, float radius, const ray &r ) {
    vec3 oc = r.origin() - center;
    float a = r.direction().dot(r.direction());
    float b = 2 * r.direction().dot(oc);
    float c = oc.dot(oc) - (radius * radius);
    float discriminant = (b * b) - (4 * a * c);
    // if discriminant is > 0, the ray intersects the sphere twice
    // if discriminant is == 0, the ray is tangent to the sphere
    // if discriminant is < 0, the ray does not intersect the sphere
    return (discriminant > 0);
};
vec3 color(const ray &r){
    if(hitSphere(vec3(0,0,-1), 0.5, r)){
        return vec3(1.0, 0.0, 0.0);
    }
    vec3 unitDirection = unitVector(r.direction());
    float t = 0.5 * unitDirection.y + 1.0;
    return (1.0 - t) * vec3(1.0, 1.0, 1.0) + t * vec3(0.5, 0.7, 1.0);
}

int main(int argc, const char * argv[]) {
    
    int nx = 800;
    int ny = 400;
    
    std::cout << "P3\n" << nx << " " << ny << "\n255\n";
    vec3 lowerLeft(-2.0, -1.0, -1.0);
    vec3 horizontal(4.0, 0.0, 0.0);
    vec3 vertical(0.0, 2.0, 0.0);
    vec3 origin(0.0, 0.0, 0.0);
    
    for (int j = ny-1; j > 0; j--){
        for (int i = 0; i < nx; i++){
            float u = (float)i / (float)nx;
            float v = (float)j / (float)ny;
            ray r(origin, lowerLeft + u * horizontal + v * vertical);
            
            vec3 col = color(r);
            int ir = (int)255.99*col.r;
            int ig = (int)255.99*col.g;
            int ib = (int)255.99*col.b;
            
            int tr = ir % 256;
            int tg = ig % 256;
            int tb = ib % 256;
            
            std::cout << tr << " " << tg << " " << tb << "\n";

        }
    };
    
    return 0;
}

/// Pattern 1, fan of rainbows
//for (int j = ny-1; j > 0; j--){
//    for (int i = 0; i < nx; i++){
//        vec3 col ((float)i / (float)nx, (float)j / (float)ny, (float)i / (float)j);
//        int ir = (int)255.99*col.r;
//        int ig = (int)255.99*col.g;
//        int ib = (int)255.99*col.b;
//        
//        int tr = ir % 256;
//        int tg = ig % 256;
//        int tb = ib % 256;
//        
//        std::cout << tr << " " << tg << " " << tb << "\n";
//        
//        }
//    };
