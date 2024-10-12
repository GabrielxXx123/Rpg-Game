#pragma once
#include <iostream>



using namespace std;







class MapLoader
{
 
private:
	string line;
	string  value;
	string  tag;
	string cell;
	bool mapExist = false;

public: 
	unsigned int tileWidthXML;
	unsigned int tileHeightXML;
	unsigned int totalTilesXML;

	string mapNameXML;
	string pathXML;
	
	
	int tableWitdhXML = 3;
	int tableHeightXML = 2;
	const int tableLengthXML = tableHeightXML * tableWitdhXML;
	int tableXML[6];
	

public:

	void Load(string filename);
	void ContentExtract(string& line);
	
};

