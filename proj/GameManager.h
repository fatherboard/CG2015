#include <GL/glut.h>
class GameManager
{
public:
	GameManager(void);
	~GameManager(void);
	void display();
	void reshape(GLsizei w, GLsizei h);
	void keyPressed();
	void onTimer();
	void idle();
	void update();
	void init();
};

