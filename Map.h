#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Tile.h"


using namespace sf;
using namespace std;

class Map
{  
   private:
	
    Texture mapTexture;
	
   Sprite* tilesMap;
   

    int id;
	int tileWidth;
	int tileHeight;

	int totalTilesX;
	int totalTilesY;
	int totalTiles;
	
	// ------------------------
	//objects

	int tableWitdh = 3;
	int tableHeight = 2;

	 int table[2][3] =
	 {
		 159,160,161,
		 189,190,191
	 };

	
	
	//objects
	// ------------------------

   public:

	    Map();
	   ~Map();

	void Initialize();
	void Load();
	void Update(float deltaTime);
	void Draw(RenderWindow& window);
};

