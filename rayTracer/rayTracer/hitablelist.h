#ifndef HITABLELISTH
#define HITABLELISTH

#include "hitable.h"

class hitableList: public hitable {
public:
    hitableList(){};
    hitableList(hitable **l, int n){ list = l; listSize = n; };
    virtual bool hit(const ray &r, float tMin, float tMax, hitRecord& rec) const;
    hitable **list;
    int listSize;
};

bool hitableList::hit(const ray &r, float tMin, float tMax, hitRecord& rec) const {
    hitRecord tempRec;
    bool hitAnything = false;
    double closest = tMax;
    
    for (int i = 0; i < listSize; i++) {
        if(list[i]->hit(r, tMin, closest, tempRec)){
            hitAnything = true;
            closest = tempRec.t;
            rec = tempRec;
        }
    }
    
    return hitAnything;
}

#endif