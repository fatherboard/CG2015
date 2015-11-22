/*
* GameManager.cpp
*
*  Created on: 30/09/2015
*      Author: 5702pedro.bucho
*/

#include "GameManager.h"


extern GameManager *gameManager;
int _wireframe;
bool backwards = false;
Track *track;

GameManager::GameManager() {
	car = 0;
	_wireframe = 0;
	_tempo_anterior = glutGet(GLUT_ELAPSED_TIME);
	_tempo_atual = glutGet(GLUT_ELAPSED_TIME);
}

GameManager::~GameManager() {
	for (GameObject *aux : getDynamicObjects()){
        delete(aux);
    }
	for (GameObject *aux : getStaticObjects()){
        delete(aux);
    }
	for (Camera *aux : getCameras()){
        delete(aux);
    }
}

void GameManager::setCandles(bool state){
    std::vector<LightSource*> candles = getLightSources();

    // comeca em 2 para nao modificar a iluminacao global nem o carro
    for(unsigned int i = 2; i < candles.size(); i++){
        candles[i]->setState(state);
    }
}

std::vector<Camera *> GameManager::getCameras(void) {
	return _cameras;
}

std::vector<Camera *> GameManager::setCameras(Camera* aux) {
	_cameras.push_back(aux);
	return _cameras;
}

std::vector<LightSource *> GameManager::getLightSources(void) {
	return _light_sources;
}

void GameManager::setLightSources(std::vector<LightSource *> lights) {
	_light_sources = lights;
}

LightSource* GameManager::getLight(int i){
    return _light_sources[i];
}

void GameManager::addLightSource(LightSource* light){
    _light_sources.push_back(light);
}

std::list<GameObject *> GameManager::getDynamicObjects(void) {
	return _dynamic_game_objects;
}

void GameManager::setDynamicObject(GameObject* aux) {
	_dynamic_game_objects.push_back(aux);
}
std::list<GameObject *> GameManager::getStaticObjects(void) {
	return _static_game_objects;
}
void GameManager::setStaticObject(GameObject* aux) {
	_static_game_objects.push_back(aux);
}

void GameManager::display() {

	glClearColor(0,0,0, 0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	

	glViewport(0, 0, _w, _h);
	camera_atual->computeProjectionMatrix();
	camera_atual->update(_w, _h);
	camera_atual->computeVisualizationMatrix();
	
	for(LightSource *ls : getLightSources()){
        ls->draw();
	}

	track->draw();
	for (unsigned int i = 0; i < _static_game_objects.size(); i++) {
		_static_game_objects.front()->draw();
		_static_game_objects.push_back(_static_game_objects.front());
		_static_game_objects.pop_front();
	}

	for (unsigned int i = 0; i < _dynamic_game_objects.size(); i++) {
		_dynamic_game_objects.front()->draw();
		_dynamic_game_objects.push_back(_dynamic_game_objects.front());
		_dynamic_game_objects.pop_front();
	}
	car->draw();
	glViewport(0, 0, _w, _h);
	
	getCameras()[0]->computeProjectionMatrix();
	getCameras()[0]->update(_w, _h);
	getCameras()[0]->computeVisualizationMatrix();
	
	glDisable(GL_LIGHTING);
	drawLifes();
	drawInfo();
	if (_lights_active)	glEnable(GL_LIGHTING);
	
	
	glutSwapBuffers();
	glFlush();
}
void GameManager::reshape(GLsizei w, GLsizei h) {
	glViewport(0, 0, w, h);
	_w = w;
	_h = h;
}

void GameManager::specialKeyPressed(unsigned char key) {
	switch (key) {
	case GLUT_KEY_LEFT:
		car->Esquerda(_delta_t);
		break; //left key

	case GLUT_KEY_UP:
		car->carAcelera(_delta_t);
		break; //up key

	case GLUT_KEY_RIGHT:
		car->Direita(_delta_t);
		break; //right key

	case GLUT_KEY_DOWN:
		car->carTrava(_delta_t);
		backwards = true;
		break; //bottom key
	}
}

void GameManager::specialKeyUP(unsigned char key) {
	switch (key) {
	case GLUT_KEY_LEFT:
		car->setRadian(car->getRadian());
		break; //left key

	case GLUT_KEY_UP:
		car->setSpeed(0, 0, car->getSpeed()->getZ());
		break; //up key

	case GLUT_KEY_RIGHT:
		car->setRadian(car->getRadian());
		break; //right key

	case GLUT_KEY_DOWN:
		car->setSpeed(0, 0, 0);
		backwards = false;
		break; //bottom key
	}
}

void GameManager::keyPressed(unsigned char key) {
	switch (key) {
	// wireframe
	case 'a':
		glClearColor(0, 0, 0, 1);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		if (_wireframe)
			_wireframe = 0;
		else
			_wireframe = 1;
		break;
    // camaras
    case '1':
        // orthogonal
        camera_atual_id = 0;
        camera_atual = getCameras()[0];
        break;
    case '2':
        // perspective
        camera_atual_id = 1;
        camera_atual = getCameras()[1];
        break;
    case '3':
        // 3rd person
        camera_atual_id = 2;
        camera_atual = getCameras()[2];
        break;
    // luzes
    case 'n':
        _modo_dia = !_modo_dia;
		getLight(0)->setState(_modo_dia);
		break;
	case 'l':
        _lights_active = !_lights_active;
		if (_lights_active){
            glEnable(GL_LIGHTING);
		}else{
            glDisable(GL_LIGHTING);
		}
		break;
    case 'g':
	_smooth = !_smooth;
	if(_smooth){
	  glShadeModel(GL_SMOOTH);
	}else{
	  glShadeModel(GL_FLAT);
	}
        break;
    case 'c':
        _lights_on = !_lights_on;
        setCandles(_lights_on);
        break;
    case 'h':
		car->toggleLight();
		break;
	case 's': 
		if(!_dead) 
			paused = !paused; 
		break;
    // extra
    case 'q':
        exit(0);
        break;
	}
}

void GameManager::onTimer() {
	_tempo_atual = glutGet(GLUT_ELAPSED_TIME);
	gameManager->update((paused) ? 0 : _tempo_atual - _tempo_anterior);
	_tempo_anterior = _tempo_atual;
}

void GameManager::idle() {}

void GameManager::update(unsigned long delta_t) {

	_delta_t = delta_t;

	for (unsigned int i = 0; i < _dynamic_game_objects.size(); i++) {
		_dynamic_game_objects.front()->update(delta_t);
		_dynamic_game_objects.push_back(_dynamic_game_objects.front());
		_dynamic_game_objects.pop_front();
	}

	if (camera_atual_id == 2) {
		camera_atual->setAt(car->getPosition()->getX(), car->getPosition()->getY(), car->getPosition()->getZ());
		camera_atual->setUp(0, 0, 1);
	}
	Vector3 *posAnterior = new Vector3(car->getPosition());
	car->update(delta_t);

    GameObject* collided = checkCollisions();
	if(collided != NULL){
        Orange* v = dynamic_cast<Orange*>(collided);
        if (v != 0) {
            // e uma laranja
            //car->setPosition(pos_init);
        }else{
            Vector3* obj_pos = collided->getPosition();
            Vector3* car_dir = car->getDirecao();
            if(backwards){
                collided->setPosition(obj_pos->getX()-car_dir->getX(), obj_pos->getY()-car_dir->getY(), obj_pos->getZ());
            }else{
                collided->setPosition(obj_pos->getX()+car_dir->getX(), obj_pos->getY()+car_dir->getY(), obj_pos->getZ());
            }
            car->setPosition(posAnterior);
        }
	}
	glutPostRedisplay();
}

void GameManager::init() {
	
	TexturePause = Texture::load_textures("Pause.bmp");
	TextureGameOver = Texture::load_textures("GameOver.bmp");
	
	setCameras(camera_atual = new OrthogonalCamera(-60, 60, -60, 60, -60, 60));
	setCameras(new PerspectiveCamera(90, 1, 1, 400));


    track = new Track();
	//setStaticObject(track);
	std::list<Cheerio *> cheerios = track->getCheerios();

	for(Cheerio* cheerio : cheerios){
        setStaticObject(cheerio);
	}

    // iluminacao global - SOL
	LightSource *aux = new LightSource(getLightSources().size());
    aux->setPosition(-200, -200, 500, 0);
    aux->setDirection(0, 0, 0);
    aux->setSpecular(1.0, 1.0, 1.0, 1.0);
    aux->setDiffuse(1.0, 1.0, 1.0, 1.0);
    aux->setAmbient(0.2, 0.2, 0.2, 1.0);
    aux->setState(getModoDia());
    addLightSource(aux);

	pos_init = new Vector3(-30, 35, 0);
	car = new Car(pos_init);
	//setDynamicObject(car = new Car(pos));
	setCameras(new PerspectiveCamera(90, 1, 1, 400,car));

	setStaticObject(new Butter(Vector3(-33, 20, 50), 2, 3));  //((posicao), largura, altura
	setStaticObject(new Butter(Vector3(29, 20, 50), 2, 3));
	setStaticObject(new Butter(Vector3(-13, -8, 50), 2, 3));
	setStaticObject(new Butter(Vector3(35, -23, 50), 2, 3));
	setStaticObject(new Butter(Vector3(-20, -32, 50), 2, 3));

	setDynamicObject(new Orange(new Vector3(-39, 34, 50), 3));
	setDynamicObject(new Orange(new Vector3(35, 34, 50), 3));
	setDynamicObject(new Orange(new Vector3(-39, -34, 50), 3));

    // velas (as lightsources são criadas pelo Candle e adicionadas
    // a lista de lightsources)
    setStaticObject(new Candle(new Vector3(-45, 45, 55), new Vector3(-45, 45, 60)));
    setStaticObject(new Candle(new Vector3(0, 45, 55), new Vector3(0, 45, 58)));
    setStaticObject(new Candle(new Vector3(45, 45, 55), new Vector3(45, 45, 60)));

    setStaticObject(new Candle(new Vector3(-45, -45, 55), new Vector3(-45, -45, 60)));
    setStaticObject(new Candle(new Vector3(0, -45, 55), new Vector3(0, -45, 60)));
    setStaticObject(new Candle(new Vector3(45, -45, 55), new Vector3(45, -45, 60)));
}

GameObject* GameManager::checkCollisions(){

    double car_radius = car->getObjRadius();
    bool collision = false;

    for (unsigned int i = 0; i < _static_game_objects.size(); i++) {
		GameObject* obj = _static_game_objects.front();
		double obj_radius = obj->getObjRadius();
		double distance = sqrt(pow(obj->getPosition()->getX()-car->getPosition()->getX(),2)+
                               pow(obj->getPosition()->getY()-car->getPosition()->getY(),2));
        if(pow(distance,2) <= pow(car_radius,2) + pow(obj_radius,2)){
            collision = true;
        }
		_static_game_objects.push_back(_static_game_objects.front());
		_static_game_objects.pop_front();
		if(collision){
            return obj;
        }
	}

	for (unsigned int i = 0; i < _dynamic_game_objects.size(); i++) {
        GameObject* obj = _dynamic_game_objects.front();
		double obj_radius = obj->getObjRadius();

		if(isOutOfTable(obj)){
			obj->setPosition(randomPosition());
		}

		double distance = sqrt(pow(obj->getPosition()->getX()-car->getPosition()->getX(),2)+
                               pow(obj->getPosition()->getY()-car->getPosition()->getY(),2));
        if(pow(distance,2) <= pow(car_radius,2) + pow(obj_radius,2)){
            collision = true;
        }
		_dynamic_game_objects.push_back(_dynamic_game_objects.front());
		_dynamic_game_objects.pop_front();
		if(collision){
            return obj;
        }
	}

	return NULL;
}

bool GameManager::isOutOfTable(GameObject* obj){

    Vector3* pos = obj->getPosition();

    if(abs(pos->getX()) > track->track_lim_coord || abs(pos->getY()) > track->track_lim_coord)
        return true;

    return false;

}

Vector3* GameManager::randomPosition() {

	int x = rand() % track->track_lim_coord;
	int y = rand() % track->track_lim_coord;
	int z = 50;

	int sigX = (rand() % 2) == 0 ? -1 : 1;
	int sigY = (rand() % 2) == 0 ? -1 : 1;

	return new Vector3(x*sigX, y*sigY, z);

}

bool GameManager::getModoDia(){
    return _modo_dia;
}
void GameManager::setModoDia(bool modo){
    _modo_dia = modo;
}
bool GameManager::getLightsOn(){
    return _lights_on;
}
void GameManager::setLightsOn(bool modo){
    _lights_on = modo;
}
bool GameManager::getLightsActive(){
    return _lights_active;
}
void GameManager::setLightsActive(bool modo){
    _lights_active = modo;
}

Car* GameManager::getCar(){
    return car;
}

bool GameManager::getSmooth(){
   return _smooth;
}

void GameManager::setSmooth(bool smooth){
   _smooth = smooth;
}

void GameManager::drawLifes(){
	Car *aux = new Car(new Vector3(0, 0,0));
	glPushMatrix();
	glScalef(0.5,0.5,0.5);
	
	for(int i = 1; i < 6; i++){
		glPushMatrix();
		glRotatef(90,0,0,1);
		aux->setPosition(110, 5+i*15 ,50);
		aux->draw();
		glPopMatrix;
	}
	
	glPopMatrix();
	delete(aux);
}

void GameManager::drawInfo(){
	if (!paused && !_dead) return;
	glPushMatrix();
	glTranslatef(-25, -25, 51);
	glScalef(50, 50, 1);
	glColor4f(1, 1, 1, 0);

	glEnable(GL_TEXTURE_2D);

	if (paused)	glBindTexture(GL_TEXTURE_2D, gameManager->getTexturePause());
	if (_dead)	glBindTexture(GL_TEXTURE_2D, gameManager->getTextureGameOver());
	
	glBegin(GL_POLYGON);
	
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0, 0, 0);

	glTexCoord2f(0.0f, 1.0);
	glVertex3f(0, 1, 0);

	glTexCoord2f(1.0, 1.0);
	glVertex3f(1, 1, 0);

	glTexCoord2f(1.0, 0.0f);
	glVertex3f(1, 0, 0);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	
	glPopMatrix();
}
