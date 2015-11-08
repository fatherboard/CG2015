#pragma once

#ifndef __CANDLE__
#define __CANDLE__

#include "Candle.h"

class Candle : public StaticObject{

public:
	Candle(Vector3* pos);
	~Candle();
	void draw();

};

#endif // CANDLE_H_INCLUDED
