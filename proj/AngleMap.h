#pragma once
#ifndef __ANGLEMAP__
#define __ANGLEMAP__

#ifndef M_PI
#define M_PI (4.0 * std::atan2(1.0, 1.0))
#endif

class AngleMap {

    public:
        AngleMap();
        ~AngleMap();
        float getSin(float deg);
        float getCos(float deg);
        float getASin(float deg);
        float getACos(float deg);

    private:
        float *sinMap, *cosMap;

        void generateValues();
        float toRad(float deg);
        float toDeg(float rad);

}

#endif
