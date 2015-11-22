#include "AngleMap.h"
#include <cmath>

AngleMap::AngleMap(){

    sinMap = (float *) malloc(360 * sizeof(malloc));
    cosMap = (float *) malloc(360 * sizeof(malloc));

    generateValues();

}

AngleMap::~AngleMap(){

    free(sinMap);
    free(cosMap);

}

void AngleMap::generateValues(){

    for(float i = 0.0f; i <= 360.0f; i++){
        sinMap[i] = toDeg(sin(toRad(i)));
        cosMap[i] = toDeg(cos(toRad(i)));
    }

}

void AngleMap::getSin(float deg){
    if(deg > 360){
        deg %= 360;
    }
}

float AngleMap::toRad(float deg){
    return deg * 2.0f * M_PI / 360.0f;
}

float AngleMap::toDeg(float rad){
    return rad * 360.0f / (2.0f * M_PI);
}
