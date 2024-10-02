#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
using namespace std;

class Map
{  
   private:
	
    Texture mapTexture;
    Sprite* tiles = nullptr;
	int id = 0;

	int tileWidth;
	int tileHeight;

	int totalTilesX;
	int totalTilesY;
	int totalTiles;
	
	

   public:

	    Map();
	   ~Map();

	void Initialize();
	void Load();
	void Update(float deltaTime);
	void Draw(RenderWindow& window);
};

