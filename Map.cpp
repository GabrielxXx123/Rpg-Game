#include "Map.h"

Map::Map()
	:tileHeight(0)
	, tileWidth(0)
	, totalTilesX(0)
	, totalTilesY(0)
	, totalTiles(0)
	, tilesMap(nullptr)
	, id(0)
	
	
	
{

}

Map::~Map()
{
	delete[] tilesMap;
	 
}

void Map::Initialize()
{
	tileHeight = 32;
	tileWidth = 32;
	id = 0;
	
}

void Map::Load()
{
	

	
		if (mapTexture.loadFromFile("Assets/Environment/Textures/Tiles.png")) 
		{
			cout << "Map Texture loaded successfuly!" << endl;


			totalTilesX = mapTexture.getSize().x / tileWidth;
			totalTilesY = mapTexture.getSize().y / tileHeight;
			totalTiles = totalTilesX * totalTilesY;
			tilesMap = new  Sprite[totalTiles];

			
				
			
		}
	




			for (int y = 0; y < totalTilesY; y++)
			{
				for (int x = 0; x < totalTilesX; x++)
				{
					
					tilesMap[id].setTexture(mapTexture);
					tilesMap[id].setTextureRect(IntRect(x * tileWidth, y * tileHeight, tileWidth, tileHeight));
					tilesMap[id].scale(2, 2);
					tilesMap[id].setPosition(120 +  x * tileWidth * tilesMap[id].getScale().x, 30 + y * tileHeight * tilesMap[id].getScale().y);
					id++;
					
				}
			}

			
			
		
}

void Map::Update(float deltaTime)						// SE LUCREAZA, voiam sa fac coliziune intre masa si restul.
{
	for (int y = 0; y < 2; y++)
	{
		for (int x = 0; x < 3; x++)
		{
			int index = table[y][x];

		     FloatRect tableBounds = tilesMap[index].getGlobalBounds();

		}

	}

	
}

void Map::Draw(RenderWindow& window)
{
	// am desenat masa 

	for (int y = 0; y < tableHeight; y++)
	{
		for (int x = 0; x < tableWitdh; x++)
		{
  
  
		int index = table[y][x];
		tilesMap[index].setScale(4, 2);
		tilesMap[index].setPosition(650 + tileWidth * x * tilesMap[index].getScale().x, 320 + tileHeight * y * tilesMap[index].getScale().y);
	   window.draw(tilesMap[index]);

		}
	}
}
