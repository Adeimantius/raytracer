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

vec3 color(const ray &r){
    vec3 unitDirection = unitVector(r.direction());
    float t = 0.5 * unitDirection.y() + 1.0;
    return (1.0 - t) * vec3(1.0, 1.0, 1.0) + t * vec3(0.5, 0.7, 1.0);
}

int main(int argc, const char * argv[]) {
    
    int nx = 800;
    int ny = 400;
    
    std::cout << "P3\n" << nx << " " << ny << "\n255\n";
    
    for (int j = ny-1; j > 0; j--){
        for (int i = 0; i < nx; i++){
            vec3 col ((float)i / (float)nx, (float)j / (float)ny, (float)i / (float)j);
            int ir = (int)255.99*col.r();
            int ig = (int)255.99*col.g();
            int ib = (int)255.99*col.b();
            
            int tr = ir % 256;
            int tg = ig % 256;
            int tb = ib % 256;
            
            std::cout << tr << " " << tg << " " << tb << "\n";

        }
    };
    
    
    return 0;
}
