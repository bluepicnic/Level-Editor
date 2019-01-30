#include "consts.h"
#include "Entities.h"
#include <TL-Engine.h>	// TL-Engine include file and namespace
#include <sstream>
#include <vector>
#include <fstream>
#include <iostream>
#include <filesystem>

using namespace tle;
using namespace std;

void saveToFile(I3DEngine* myEngine, vector <Entities> ent)
{
//save to file
if (myEngine->KeyHit(Key_Return))
{
	ofstream mapFile("map.txt");
	if (!mapFile)
	{
		cout << "cannot open output file" << endl;
		exit(1);
	}

	for (auto entit = ent.begin(); entit != ent.end(); entit++)
	{
		mapFile << (*entit).meshFile << " ";
		mapFile << (*entit).getPosX() << " ";
		mapFile << (*entit).getPosY() << " ";
		mapFile << (*entit).getPosZ() << endl;
	}

}
}
