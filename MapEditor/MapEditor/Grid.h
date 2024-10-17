#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;


class Grid
{
private:
	
	VertexArray lines;
	int cellWidth;
	int cellHeight;
	int gridSize;
	


public:

	 Grid(int cellWidth, int cellHeight, int gridSize);
	~Grid();

	

	void Initialize();
	void Load(string filename);
	void Update(float deltatime);
	void Draw(RenderWindow &window);

};

