#include "GameObject.h"
class DynamicObject :
	public GameObject
{
public:
	DynamicObject(void);
	virtual ~DynamicObject(void);
	virtual void update(double const delta);
	virtual void setSpeed(Vector3 const speed);
	virtual void setSpeed(double x, double y, double z);
	virtual Vector3 getSpeed();
};

