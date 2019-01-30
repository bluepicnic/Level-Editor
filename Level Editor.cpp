// Level Editor.cpp: A program using the TL-Engine
#include "consts.h"
#include "Entities.h"
#include "savetofile.h"
#include <TL-Engine.h>	// TL-Engine include file and namespace
#include <sstream>
#include <vector>
#include <fstream>
#include <iostream>
#include <filesystem>
namespace fs = std::experimental::filesystem;

using namespace std;
using namespace tle;


void main()
{
	// Create a 3D engine (using TLX engine here) and open a window for it
	I3DEngine* myEngine = New3DEngine(kTLX);
	myEngine->StartWindowed();

	// Add default folder for meshes and other media
	myEngine->AddMediaFolder("./Media");

	/**** Set up your scene here ****/
	/*create UI backdrop*/
	ISprite* uiBackdrop = myEngine->CreateSprite("backdrop.jpg", 0, 0);
	ISprite* uiBackdrop2 = myEngine->CreateSprite("backdrop.jpg", 600, 0);

	/*Load fonts to be used on the screen*/
	IFont* uiFont = myEngine->LoadFont("Verdana", 36);
	IFont* raceFont = myEngine->LoadFont("Comic Sans MS", 120);

	//array of models that are switched between. 
	vector<string>objFiles;

	int numFiles = 0;
	for (const auto& p : fs::directory_iterator("./Media"))
	{
		if (p.path().extension() == ".x")
		{
			string fileName = p.path().string();
			objFiles.push_back(fileName);
		}
	}

	//remove the beginning of the file path strings, they're not needed
	for (auto p = objFiles.begin(); p != objFiles.end(); p++)
	{
		(*p).erase(0,8);
		numFiles++;
	}
	int objIndex = 0;

	//make a basic floor
	IMesh * floorMesh = myEngine->LoadMesh("floor.x");
	IModel * groundFloor = floorMesh->CreateModel();

	Entities oof;
	oof.meshFile = objFiles[0];
	oof.meshington = myEngine->LoadMesh(oof.meshFile);
	oof.model = oof.meshington->CreateModel(0, 0, 0);
	oof.setRotX(0);
	oof.setRotY(0);
	oof.setRotZ(0);


	//an array of stored entities
	vector <Entities> entToStore;
	vector <Entities>::iterator entIt;

	ICamera *myCamera;
	myCamera = myEngine->CreateCamera(kManual, 0, 10, -30);
	//myCamera->AttachToParent(oof.model);
	myCamera->MoveY(kCameraOffset);
	myCamera->MoveZ(-20.0f);

	float frameTime;
	// The main game loop, repeat until engine is stopped
	while (myEngine->IsRunning())
	{
		// Draw the scene
		myEngine->DrawScene();
		frameTime = myEngine->Timer();

		/**** Update scene each frame here ****/

		/*Store position details each frame*/
		oof.setPosX(oof.model->GetX());
		oof.setPosY(oof.model->GetY());
		oof.setPosZ(oof.model->GetZ());

		stringstream PosText;
		PosText << oof.getPosX() << " " << oof.getPosY() << " " << oof.getPosZ();
		uiFont->Draw(PosText.str(), posTextloc, 0);

		stringstream RotText;
		RotText << oof.getRotX() << " " << oof.getRotY() << " " << oof.getRotZ();
		uiFont->Draw(RotText.str(), rotTextloc, 0);

	
		//model movement
		oof.moveForward(myEngine, oof.model, frameTime);
		oof.moveBackward(myEngine, oof.model, frameTime);
		oof.moveLeft(myEngine, oof.model, frameTime);
		oof.moveRight(myEngine, oof.model, frameTime);

		//Y Movement
		oof.moveUp(myEngine, oof.model, frameTime);
		oof.moveDown(myEngine, oof.model, frameTime);

		//rotate model upon X axis
		oof.rotatePosX(myEngine, oof.model, frameTime);
		oof.rotateNegX(myEngine, oof.model, frameTime);

		//rotate model upon Z axis
		oof.rotatePosZ(myEngine, oof.model, frameTime);
		oof.rotateNegZ(myEngine, oof.model, frameTime);

		//change model
		oof.nextModel(myEngine, oof.model, objIndex, numFiles, objFiles);
		oof.previousModel(myEngine, oof.model, objIndex, numFiles, objFiles);
	
		//Store model name and position details in a vector
		oof.storeModel(myEngine, entToStore, oof);

		saveToFile(myEngine, entToStore);

		if (myEngine->KeyHit(Key_Escape))
		{
			myEngine->Stop();
		}

	}

	// Delete the 3D engine now we are finished with it
	myEngine->Delete();
}

