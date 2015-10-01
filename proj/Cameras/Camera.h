/*
 * Camera.h
 *
 *  Created on: 30/09/2015
 *      Author: 5702pedro.bucho
 */

#ifndef PROJ_CAMERA_H_
#define PROJ_CAMERA_H_

#include "../GameMgr/Entity.h"
#include "../GameMgr/Vector3.h"

class Camera : public Entity{
protected:
	double _near;
	double _far;

private:
	Vector3 _up;
	Vector3 _center;
	Vector3 _at;

public:
	Camera();
	Camera(double near, double far);
	virtual ~Camera();

	virtual void update();
	virtual void computeProjectionMatrix();
	virtual void computeVisualizationMatrix();
};

#endif /* PROJ_CAMERA_H_ */
