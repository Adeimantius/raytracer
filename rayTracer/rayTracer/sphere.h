#ifndef SPHEREH
#define SPHEREH

#include "hitable.h"
#include "material.h"

class sphere: public hitable {
public:
//    sphere() {};
//    sphere(vec3 cen, float r) : center(cen), radius(r) {};
    sphere(vec3 cen, float r, const material mat) : center(cen), radius(r), m_material(mat) {};
    virtual bool hit(const ray& r, float tMin, float tMax, hitRecord& rec) const;
    vec3 center;
    float radius;
    const material& m_material;

};

bool sphere::hit(const ray& r, float tMin, float tMax, hitRecord& rec) const {
    vec3 oc = r.origin() - center;
    float a = r.direction().dot(r.direction());
    float b = r.direction().dot(oc);
    float c = oc.dot(oc) - (radius * radius);
    float discriminant = (b * b) - (a * c);
    // if discriminant is > 0, the ray intersects the sphere twice (check twice)
    // if discriminant is == 0, the ray is tangent to the sphere
    // if discriminant is < 0, the ray does not intersect the sphere
    if (discriminant > 0){
        float temp = (-b - sqrt(b*b-a*c))/a;
        if (temp > tMin && temp < tMax){  // check low
            rec.t = temp;
            rec.p = r.pointAtParameter(rec.t);
            rec.normal = (rec.p - center) / radius;
            return true;
        }
        
        temp = (-b + sqrt(b*b-a*c))/a;
        if (temp > tMin && temp < tMax){  // check high
            rec.t = temp;
            rec.p = r.pointAtParameter(rec.t);
            rec.normal = (rec.p - center) / radius;
            return true;
        }
        
    }
    return false;
    
}
#endif

//float hitSphere (const vec3& center, float radius, const ray &r ) {
//    vec3 oc = r.origin() - center;
//    float a = r.direction().dot(r.direction());
//    float b = 2 * r.direction().dot(oc);
//    float c = oc.dot(oc) - (radius * radius);
//    float discriminant = (b * b) - (4 * a * c);
//    // if discriminant is > 0, the ray intersects the sphere twice
//    // if discriminant is == 0, the ray is tangent to the sphere
//    // if discriminant is < 0, the ray does not intersect the sphere
//    if (discriminant < 0){
//        return -1.0;
//    }
//    else {
//        return ( -b - sqrt(discriminant) ) / (2 * a);
//    };
//};