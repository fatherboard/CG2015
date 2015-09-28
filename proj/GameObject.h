#include "Entity.h"

class GameObject :
	public Entity
{
public:
	GameObject(void);
	~GameObject(void);
	void draw();
	void update(double delta_t);
};

