#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "MapLoader.h"



using namespace sf;
using namespace std;

class Map
{  
private :
    Texture mapTexture;
	
   Sprite* tilesMap;
   
   public:
	   string mapName;
	   string path;
    int id;
	unsigned int tileWidth;
	unsigned int tileHeight;

	unsigned int totalTilesX;
	unsigned int totalTilesY;
	unsigned int totalTiles;
	
	// ------------------------
	//objects

	int tableWitdh = 3;
	int tableHeight = 2;
	int tableLenght = tableWitdh * tableHeight;
	 int table[6] =
	 {	 159,160,161, 189,190,191
	 };

	
	
	//objects
	// ------------------------

   public:

	    Map();
	   ~Map();
	
    
	void Initialize(MapLoader &map);
	void Load();
	void Update(float deltaTime);
	void Draw(RenderWindow& window);
};

