#include "Player.h"
#include "Enemy.h"
#include "FrameRate.h"
#include "Background.h"
#include "Map.h"

using namespace std;
using namespace sf;

int main()
{//--------------------------------------------------------------------INITIALIZE---------------------------------------------------------------------------------
	
	ContextSettings settings;
	settings.antialiasingLevel = 8;
	
	RenderWindow window(VideoMode(1620, 950), "Gabriel's Game" , Style::Default, settings);
	window.setVerticalSyncEnabled(true);
	window.setMouseCursorVisible(1);
	
	Player player;
	player.Initialize();

	Enemy enemy;
	enemy.Initialize();

	FrameRate fps;
	fps.Initialize();

	Background background;
	background.Initialize();
	
	Map map;
	map.Initialize();

	Clock clock;
	
	
	
	//--------------------------------------------------------------------INITIALIZE---------------------------------------------------------------------------------
	



	




	//--------------------------------------------------------------------LOAD---------------------------------------------------------------------------------
	map.Load();
	player.Load();
	enemy.Load();
	fps.Load();
	background.Load();
	background.ResizeAfterWindow(window);
	//--------------------------------------------------------------------LOAD---------------------------------------------------------------------------------

	
	



	// main game loop
	while (window.isOpen())
	{
		//--------------------------------------------------------------------UPDATE---------------------------------------------------------------------------------
		float deltaTime = clock.restart().asSeconds();
		
		

		player.Update(window,enemy, deltaTime);
		enemy.Update(deltaTime);
		fps.Update(deltaTime);

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
		}	
		
	 
	
		//--------------------------------------------------------------------UPDATE---------------------------------------------------------------------------------












		//--------------------------------------------------------------------DRAW---------------------------------------------------------------------------------

		window.clear(Color::Black);
		//background.Draw(window);
		map.Draw(window);
		player.Draw(window);
		enemy.Draw(window);
		fps.Draw(window);
		window.display();
		
		
		//--------------------------------------------------------------------DRAW---------------------------------------------------------------------------------
		
		
	}









	return 0;
}