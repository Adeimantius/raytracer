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
#include "material.h"
#include "metal.h"
#include "lambertian.h"


vec3 color(const ray &r, hitable *world, int depth){
    hitRecord rec;
    if (world->hit(r, 0.001, MAXFLOAT, rec)){
        ray scattered;
        vec3 attenuation;
        if (depth<50 && rec.mat_ptr->scatter(r, scattered, attenuation, rec)){
                return attenuation*color(scattered, world, depth+1);
        }
        else {
            return vec3(0,0,0);
        }
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
    int objectListLength = 1;
    hitable* list[objectListLength];
    lambertian lambertRed(vec3(0.8f, 0.3f, 0.3f));
    lambertian lambertPurple(vec3(0.8f, 0.8f, 0.0));
    metal metalDark(vec3(0.8f, 0.6f, 0.2f));
    metal metalLight(vec3(0.8f, 0.8f, 0.8f));

    list[0] = new sphere(vec3(0, 0, -1), 0.5, lambertRed);
//    list[1] = new sphere(vec3(0, -100.5, -1), 100, lambertPurple);
//    list[2] = new sphere(vec3(1, 0, -1), 0.5, metalDark);
//    list[3] = new sphere(vec3(-1, 0, -1), 0.5, metalLight);
    hitable* world = new hitableList(list, objectListLength);
    
    for (int j = ny-1; j > 0; j--){
        for (int i = 0; i < nx; i++){
            vec3 col(0, 0, 0);
            for (int s = 0; s < ns; s++){
                float u = (float)(i + drand48()) / (float)nx;
                float v = (float)(j + drand48()) / (float)ny;
                ray r = cam.getRay(u ,v);
                vec3 p = r.pointAtParameter(2.0);
                col += color(r, world, 0);
                
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
