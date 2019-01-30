#include "Entities.h"
#include <TL-Engine.h>
#include "consts.h"

using namespace tle;


Entities::Entities()
{
}


Entities::~Entities()
{
}

void Entities::moveForward(I3DEngine * myEngine, IModel * model, float frameTime)
{
	if (myEngine->KeyHeld(Key_W))
	{
		model->MoveZ(kItemSpeed * frameTime);
	}
}

void Entities::moveBackward(I3DEngine * myEngine, IModel * model, float frameTime)
{
	if (myEngine->KeyHeld(Key_S))
	{
		model->MoveZ(-kItemSpeed * frameTime);
	}
}

void Entities::moveLeft(I3DEngine * myEngine, IModel * model, float frameTime)
{
	if (myEngine->KeyHeld(Key_A))
	{
		model->MoveX(-kItemSpeed * frameTime);
	}
}

void Entities::moveRight(I3DEngine * myEngine, IModel * model, float frameTime)
{
	if (myEngine->KeyHeld(Key_D))
	{
		model->MoveX(kItemSpeed * frameTime);
	}
}

void Entities::moveUp(I3DEngine * myEngine, IModel * model, float frameTime)
{
	if (myEngine->KeyHeld(Key_Q))
	{
		model->MoveY(kItemSpeed * frameTime);
	}
}

void Entities::moveDown(I3DEngine * myEngine, IModel * model, float frameTime)
{
	if (myEngine->KeyHeld(Key_E))
	{
		model->MoveY(-kItemSpeed * frameTime);
	}
}

void Entities::rotatePosX(I3DEngine * myEngine, IModel * model, float frameTime)
{
	if (myEngine->KeyHeld(Key_Z))
	{
		model->RotateLocalX((kItemSpeed / 2)* frameTime);
		rotX += ((kItemSpeed / 2)* frameTime);
	}
}

void Entities::rotateNegX(I3DEngine * myEngine, IModel * model, float frameTime)
{
	if (myEngine->KeyHeld(Key_X))
	{
		model->RotateLocalX((-kItemSpeed / 2)* frameTime);
		rotX += ((-kItemSpeed / 2)* frameTime);
	}
}

void Entities::rotatePosZ(I3DEngine * myEngine, IModel * model, float frameTime)
{
	if (myEngine->KeyHeld(Key_C))
	{
		model->RotateLocalZ((kItemSpeed / 2)* frameTime);
		rotZ += ((kItemSpeed / 2)* frameTime);
	}
}

void Entities::rotateNegZ(I3DEngine * myEngine, IModel * model, float frameTime)
{
	if (myEngine->KeyHeld(Key_V))
	{
		model->RotateLocalZ((-kItemSpeed / 2)* frameTime);
		rotZ += ((-kItemSpeed / 2)* frameTime);
	}
}

void Entities::nextModel(I3DEngine* myEngine, IModel* models, int &index, int noOfFiles, vector<string>files)
{
	if (myEngine->KeyHit(Key_Right))
	{
		index++;
		if (index < noOfFiles)
		{
			meshington->RemoveModel(model);
			/*file needs to be removed, but is not referred to again until another file is in its place*/
			meshFile = files[index];
			meshington = myEngine->LoadMesh(meshFile);
			model = meshington->CreateModel(posX, posY, posZ);
		}
		
		if (index > noOfFiles)
		{
			//loop back round
			index = 0;
		}
		rotX = 0;
		rotY = 0;
		rotZ = 0;
	}
}

void Entities::previousModel(I3DEngine* myEngine, IModel* models, int &index, int noOfFiles, vector<string>files)
{
	if (myEngine->KeyHit(Key_Left))
	{
		if (index < noOfFiles)
		{
			meshington->RemoveModel(model);
			/*file needs to be removed, but is not referred to again until another file is in its place*/
			meshFile = files[index];
			meshington = myEngine->LoadMesh(meshFile);
			model = meshington->CreateModel(posX, posY, posZ);
		}
		index--;
		if (index < 0)
		{
			//loop back round
			index = noOfFiles;
		}
		rotX = 0;
		rotY = 0;
		rotZ = 0;
	}
}

void Entities::storeModel(I3DEngine* myEngine, vector<Entities>& ToStore, Entities ent)
{
	//place file names into vector
	if (myEngine->KeyHit(Key_Space))
	{
		ToStore.push_back(ent);
		ToStore.back().model = ToStore.back().meshington->CreateModel(ToStore.back().getPosX(), ToStore.back().getPosY(), ToStore.back().getPosZ());
		ToStore.back().model->RotateX(rotX);
		ToStore.back().model->RotateY(rotY);
		ToStore.back().model->RotateZ(rotZ);


	}
}

float Entities::getPosX()
{
	return posX;
}

float Entities::getPosY()
{
	return posY;
}

float Entities::getPosZ()
{
	return posZ;
}

void Entities::setPosX(float X)
{
	posX = X;
}

void Entities::setPosY(float Y)
{
	posY = Y;
}

void Entities::setPosZ(float Z)
{
	posZ = Z;
}

float Entities::getRotX()
{
	return rotX;
}

float Entities::getRotY()
{
	return rotY;
}

float Entities::getRotZ()
{
	return rotZ;
}

void Entities::setRotX(float X)
{
	rotX = X;
}

void Entities::setRotY(float Y)
{
	rotY = Y;
}

void Entities::setRotZ(float Z)
{
	rotZ = Z;
}


