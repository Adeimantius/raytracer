#ifndef LAMBERTIANH
#define LAMBERTIANH

#include "material.h"

class lambertian : public material {
public:
    lambertian(const vec3& a) : albedo(a) {};
    virtual bool scatter(const ray& rIncident, ray& rScattered, vec3& attenuation, const hitRecord& rec) const {
        vec3 target = rec.p + rec.normal + randomInUnitSphere();
        rScattered = ray(rec.p, target - rec.p);
        attenuation = albedo;
        return true;
        
    }
    
    vec3 albedo;
};

#endif