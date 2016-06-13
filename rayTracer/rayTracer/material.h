#ifndef MATERIALH
#define MATERIALH

class material {
public:
    virtual bool scatter(const ray& in, ray& scattered, vec3& attenuation, const hitRecord& rec) const = 0;
};
#endif