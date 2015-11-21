#pragma once

#ifndef __CANDLE__
#define __CANDLE__

#include "StaticObject.h"
#include "Candle.h"

class Candle : public StaticObject{

public:
	Candle(Vector3* pos, Vector3* pos_luz);
	~Candle();
	void draw();

};

#endif // CANDLE_H_INCLUDED
