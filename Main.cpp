#include <vector>
#include <math.h>
#include "Player.h"
#include "Enemy.h"
#include "Bullet.h"

using namespace std;
using namespace sf;

int main()
{//--------------------------------------------------------------------INITIALIZE---------------------------------------------------------------------------------
	
	ContextSettings settings;
	settings.antialiasingLevel = 8;
	
	RenderWindow window(VideoMode(1620, 950), "Gabriel's Game" , Style::Default, settings);
	
	Player player;
	player.Initialize();

	Enemy enemy;
	enemy.Initialize();
	
	//--------------------------------------------------------------------INITIALIZE---------------------------------------------------------------------------------
	








	//--------------------------------------------------------------------LOAD---------------------------------------------------------------------------------
	player.Load();
	enemy.Load();
	//--------------------------------------------------------------------LOAD---------------------------------------------------------------------------------







	// main game loop
	while (window.isOpen())
	{
		//--------------------------------------------------------------------UPDATE---------------------------------------------------------------------------------
		player.Update(window);
		enemy.Update();
		


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

		player.Draw(window);
		enemy.Draw(window);
	
		

	
		window.display();

		//--------------------------------------------------------------------DRAW---------------------------------------------------------------------------------


	}









	return 0;
}