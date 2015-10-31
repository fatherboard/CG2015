#pragma once

#ifndef __CANDLE__
#define __CANDLE__

#include "Header.h"

class Candle : public StaticObject{

    Vector3* _direction;
public:
	Candle(Vector3* pos, Vector3* dir);
	~Candle();
	void draw();

};

#endif // CANDLE_H_INCLUDED
