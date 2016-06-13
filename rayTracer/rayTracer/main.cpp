//
//  main.cpp
//  rayTracer
//
//  Created by Markus Ristich on 2016-05-22.
//  Copyright © 2016 Markus Ristich. All rights reserved.
//

#include <iostream>
#include "float.h"
#include "sphere.h"
#include "hitablelist.h"
#include "camera.h"

vec3 randomInUnitSphere(){
    vec3 p;
    do {
        p = 2.0*vec3(drand48(), drand48(), drand48()) - vec3(1,1,1);
    } while (p.lengthsquared() >= 1.0);
    return p;
}
vec3 color(const ray &r, hitable *world){
    hitRecord rec;
    if (world->hit(r, 0.001, MAXFLOAT, rec)){
        vec3 target = rec.p + rec.normal + randomInUnitSphere();
        return 0.5*color(ray(rec.p, target - rec.p), world);
    }
    else {
        vec3 unitDirection = unitVector(r.direction());
        float t = 0.5 * (unitDirection.y + 1.0);
        return (1.0 - t) * vec3(1.0, 1.0, 1.0) + t * vec3(0.5, 0.7, 1.0);

    }
}

int main(int argc, const char * argv[]) {
    
    int nx = 800;
    int ny = 400;
    int ns = 100;
    
    std::cout << "P3\n" << nx << " " << ny << "\n255\n";
    
    camera cam;
    hitable* list[2];
    list[0] = new sphere(vec3(0, 0, -1), 0.5);
    list[1] = new sphere(vec3(0, -100.5, -1), 100);
    hitable* world = new hitableList(list, 2);
    
    for (int j = ny-1; j > 0; j--){
        for (int i = 0; i < nx; i++){
            vec3 col(0, 0, 0);
            for (int s = 0; s < ns; s++){
                float u = (float)(i + drand48()) / (float)nx;
                float v = (float)(j + drand48()) / (float)ny;
                ray r = cam.getRay(u ,v);
                vec3 p = r.pointAtParameter(2.0);
                col += color(r, world);
                
            }

            col /= float(ns);
            col = vec3 (sqrt(col.x), sqrt(col.y), sqrt(col.z));
            int ir = (int)255.99*col.x;
            int ig = (int)255.99*col.y;
            int ib = (int)255.99*col.z;
            
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
