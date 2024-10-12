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

void Map::Initialize(MapLoader &map)
{
	
	id = 0;
	mapName = map.mapNameXML;
	tileHeight = map.tileHeightXML;
	tileWidth = map.tileWidthXML;
	path = map.pathXML;
	totalTiles = map.totalTilesXML;
	for (size_t i = 0; i < tableLenght && i < map.tableLengthXML; i++)
	{
		
			table[i] = map.tableXML[i];
		
	}
	 
	
}

void Map::Load()
{
	
	
	
		if (mapTexture.loadFromFile(path)) 
		{
			cout << "Map Texture loaded successfuly!" << endl;


			totalTilesX = mapTexture.getSize().x / tileWidth;
			totalTilesY = mapTexture.getSize().y / tileHeight;
			totalTiles = totalTilesX * totalTilesY;
			tilesMap = new  Sprite[totalTiles];

			
				
			
		}
		else
		{
			cout << "Failed to load the map texture! " << endl;
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
//	for (int y = 0; y < tableHeight; y++)
//	{
//		for (int x = 0; x < tableWitdh; x++)
//		{
//
//
//			int index = y * tableWitdh + x;
//			
//			FloatRect tableBounds = tilesMap[index].getGlobalBounds();
//
//		}
//	}

}

	


void Map::Draw(RenderWindow& window)
{
	// am desenat masa 

	for (int i = 0; i < tableLenght; i++)
	{
		
		int index = table[i];
		tilesMap[index].setScale(2, 2);
		tilesMap[index].setPosition(650 + tileWidth * (i % tableWitdh)* tilesMap[index].getScale().x, 320 + tileHeight *(i / tableWitdh) * tilesMap[index].getScale().y);
	   window.draw(tilesMap[index]);

	}
  }
