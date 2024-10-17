#include <SFML/Graphics.hpp>
#include <iostream>
#include "Grid.h"

using namespace std;
using namespace sf;


int main()
{//--------------------------------------------------------------------INITIALIZE---------------------------------------------------------------------------------

	ContextSettings settings;
	settings.antialiasingLevel = 8;

	RenderWindow window(VideoMode(1320, 1050), "Map editor", Style::Default, settings);
	window.setVerticalSyncEnabled(true);
	window.setMouseCursorVisible(1);

	

	Clock clock;



	Grid grid(32,32,30);
	grid.Initialize();
	//--------------------------------------------------------------------INITIALIZE---------------------------------------------------------------------------------









	//--------------------------------------------------------------------LOAD---------------------------------------------------------------------------------
	//grid.Load();
	


	//--------------------------------------------------------------------LOAD---------------------------------------------------------------------------------






	// main game loop
	while (window.isOpen())
	{
		//--------------------------------------------------------------------UPDATE---------------------------------------------------------------------------------
		float deltaTime = clock.restart().asSeconds();



		

		Event event;

		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				window.close();
			}
			if (event.type == Event::KeyPressed)
			{
				if (event.key.code == Keyboard::Escape)
				{
					window.close();
				}
			}
		
		
			grid.Update(deltaTime);
		    
			Vector2f mousePosition = Vector2f(Mouse::getPosition(window));
		
		
		
		
		
		
		}



		//--------------------------------------------------------------------UPDATE---------------------------------------------------------------------------------












		//--------------------------------------------------------------------DRAW---------------------------------------------------------------------------------

		window.clear(Color::Black);
		
		grid.Draw(window);
		
		window.display();


		//--------------------------------------------------------------------DRAW---------------------------------------------------------------------------------


	}









	return 0;
}