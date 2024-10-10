#pragma once
#include <iostream>


using namespace std;

class MapLoader
{
private: 

	string line;
	bool mapExist = false;


public:

	void Load(string filename);
	void ContentExtract(string& line);
	
};

