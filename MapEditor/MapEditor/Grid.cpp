#include "Grid.h"



Grid::Grid(int cellWidth, int cellHeight, int gridSize)
	:cellWidth(cellWidth), 
	cellHeight(cellHeight), 
	gridSize(gridSize),
	lines(VertexArray(Lines))
{
	
}


Grid::~Grid()
{
	lines.clear();
}


void Grid::Initialize()
{
	

	for (size_t y = 0; y <= gridSize; y++)
	{
		for (size_t x = 0; x <= gridSize; x++)
		{
			 if (x < gridSize)
            {
                lines.append(Vertex(Vector2f(100 + x * cellWidth, 20 + y * cellHeight), Color::Red));
                lines.append(Vertex(Vector2f(100 + (x  + 1) * cellWidth, 20 + y * cellHeight), Color::Red));
           }

      
            if (y < gridSize)
            {
                lines.append(Vertex(Vector2f(100 + x * cellWidth, 20 + y  * cellHeight), Color::Yellow));
                lines.append(Vertex(Vector2f(100 + x * cellWidth, 20 + (y + 1 ) * cellHeight), Color::Yellow));
            }

		}	
	}

}

void Grid::Load(string filename)
{
}

void Grid::Update(float deltatime)
{
}

void Grid::Draw(RenderWindow& window)
{
	window.draw(lines);
}

	
		
		
	
	
	

