#ifndef METALH
#define METALH

#include "material.h"
#include "MathUtil.h"

vec3 reflectV(const vec3& n, const vec3& v){
    return v - 2*n.dot(v)*n;
}

class metal : public material {
public:
    metal(const vec3& a) : albedo(a){};
    virtual bool scatter(const ray& rIncident, ray& rScattered, vec3& attenuation, const hitRecord& rec) const {
        vec3 vReflected = reflectV(unitVector(rIncident.direction()), rec.normal);
        rScattered = ray(rec.p, vReflected);
        return (rScattered.direction().dot(rec.normal) > 0);
    }
    vec3 albedo;
};


#endif