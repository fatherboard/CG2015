#include "Vector3.h"
class Entity
{
public:
	Entity(void);
	virtual ~Entity(void);
	virtual Vector3 getPosition();
	virtual Vector3 setPosition(double x, double y, double z);
	virtual Vector3 setPosition(Vector3 const p);
};

