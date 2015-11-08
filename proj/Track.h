#pragma once

#ifndef __TRACK__
#define __TRACK__

#include <list>
#include "Cheerio.h"

class Track : public StaticObject
{
	int wf;

public:
	Track();
	~Track();
	void draw();
	std::list<Cheerio *> getCheerios();

	int track_lim_coord = 50;

private:
    std::list<Cheerio *> _cheerios;
};

#endif
