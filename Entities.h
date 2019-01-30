#pragma once
#include <TL-Engine.h>
#include <vector>

using namespace tle;

class Entities
{
private:
	float posX;
	float posY;
	float posZ;
	float rotX;
	float rotY;
	float rotZ;
public:
	
	IMesh *meshington;
	string meshFile;
	IModel *model;
	Entities();
	~Entities();
	void moveForward(I3DEngine* myEngine, IModel* model, float frameTime);
	void moveBackward(I3DEngine * myEngine, IModel * model, float frameTime);
	void moveLeft(I3DEngine * myEngine, IModel * model, float frameTime);
	void moveRight(I3DEngine * myEngine, IModel * model, float frameTime);
	void moveUp(I3DEngine* myEngine, IModel* model, float frameTime);
	void moveDown(I3DEngine* myEngine, IModel* model, float frameTime);
	void rotatePosX(I3DEngine* myEngine, IModel* model, float frameTime);
	void rotateNegX(I3DEngine* myEngine, IModel* model, float frameTime);
	void rotatePosZ(I3DEngine * myEngine, IModel * model, float frameTime);
	void rotateNegZ(I3DEngine * myEngine, IModel * model, float frameTime);
	void nextModel(I3DEngine* myEngine, IModel* model, int &index, int noOfFiles, vector<string>files);
	void previousModel(I3DEngine* myEngine, IModel* model, int &index, int noOfFiles, vector<string>files);
	void storeModel(I3DEngine* myEngine, vector<Entities>& ToStore, Entities ent);
	float getPosX();
	float getPosY();
	float getPosZ();
	void setPosX(float X);
	void setPosY(float Y);
	void setPosZ(float Z);
	float getRotX();
	float getRotY();
	float getRotZ();
	void setRotX(float X);
	void setRotY(float Y);
	void setRotZ(float Z);
};

