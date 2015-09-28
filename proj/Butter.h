#include "Obstacle.h"
class Butter :
	public Obstacle
{
public:
	Butter(void);
	~Butter(void);
	void draw();
	
	Vector3 getPosition();
	Vector3 setPosition(double x, double y, double z);
	Vector3 setPosition(Vector3 const p);
};

