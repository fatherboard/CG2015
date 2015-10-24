#pragma once

#ifndef __TRACK__
#define __TRACK__

#include "Header.h"
#include "Cheerio.h"
#include <list>

class Track : public StaticObject
{
	int wf;
public:
	Track();
	~Track();
	void draw();
	std::list<Cheerio *> getCheerios();

private:
    std::list<Cheerio *> _cheerios;
	void drawCheerio();
};

#endif
