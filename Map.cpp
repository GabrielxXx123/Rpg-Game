#include "Map.h"

Map::Map()
	:tileHeight(0)
	, tileWidth(0)
	, totalTilesX(0)
	, totalTilesY(0)
	, totalTiles(0)
	, tiles(nullptr)
	
{

}

Map::~Map()
{
	delete[] tiles;
}

void Map::Initialize()
{
	tileHeight = 32;
	tileWidth = 32;
	
}

void Map::Load()
{
	
		if (mapTexture.loadFromFile("Assets/Environment/Textures/Tiles.png")) 
		{
			cout << "Map Texture loaded successfuly!" << endl;


			totalTilesX = mapTexture.getSize().x / tileWidth;
			totalTilesY = mapTexture.getSize().y / tileHeight;
			totalTiles = totalTilesX * totalTilesY;
			tiles = new  Sprite[totalTiles];

			
		}
		


			for (size_t y = 0; y < totalTilesY; y++)
			{
				for (size_t x = 0; x < totalTilesX; x++)
				{
					tiles[id].setTexture(mapTexture);
					tiles[id].setTextureRect(IntRect(x * tileWidth, y * tileHeight, tileWidth, tileHeight));
					tiles[id].scale(2, 2);
					tiles[id].setPosition(120 +  x * tileWidth * 2, 30 + y * tileHeight * 2);
					id++;
				}
			}
		
}

void Map::Update(float deltaTime)
{
}

void Map::Draw(RenderWindow& window)
{
	for (int i = 0; i < totalTiles; i++)
	{
	 window.draw(tiles[i]);
	}
}
