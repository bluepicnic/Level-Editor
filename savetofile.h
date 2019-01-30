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

#ifndef savetofile_h
#define savetofile_h
void saveToFile(I3DEngine* myEngine, vector <Entities> ent);
#endif // consts_h
#pragma once
