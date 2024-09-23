#include <vector>
#include <math.h>
#include "Player.h"
#include "Enemy.h"
#include "Bullet.h"
#include "Mate.h"

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


	Clock clock;
	
	//--------------------------------------------------------------------INITIALIZE---------------------------------------------------------------------------------
	








	//--------------------------------------------------------------------LOAD---------------------------------------------------------------------------------
	player.Load();
	enemy.Load();
	//--------------------------------------------------------------------LOAD---------------------------------------------------------------------------------






	// main game loop
	while (window.isOpen())
	{
		//--------------------------------------------------------------------UPDATE---------------------------------------------------------------------------------
		
		
		float deltaTime = clock.restart().asSeconds();

		player.Update(window,enemy, deltaTime);
		enemy.Update(deltaTime);
		

		
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
		
		cout << "Diferenta dintre cadre este de :" << deltaTime << endl;
	
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