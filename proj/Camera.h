#include "Entity.h"

class Camera :
	public Entity
{
protected:
	double _near;
	double _far;

public:
	Camera(void);
	Camera(double near, double far);
	virtual ~Camera(void);
	virtual void update();
	virtual void computeProjectionMatrix();
	virtual void computeVisualizationMatrix();
};

