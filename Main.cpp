#include <vector>
#include <math.h>
#include "Player.h"
#include "Enemy.h"
#include "Bullet.h"
#include "Mate.h"
#include "FrameRate.h"

using namespace std;
using namespace sf;

int main()
{//--------------------------------------------------------------------INITIALIZE---------------------------------------------------------------------------------
	
	ContextSettings settings;
	settings.antialiasingLevel = 8;
	
	RenderWindow window(VideoMode(1620, 950), "Gabriel's Game" , Style::Default, settings);

	window.setVerticalSyncEnabled(true);
	//window.setFramerateLimit(350);
	window.setMouseCursorVisible(1);

	Player player;
	player.Initialize();

	Enemy enemy;
	enemy.Initialize();

	FrameRate fps;
	fps.Initialize();

	Clock clock;
	
	
	//--------------------------------------------------------------------INITIALIZE---------------------------------------------------------------------------------
	








	//--------------------------------------------------------------------LOAD---------------------------------------------------------------------------------
	player.Load();
	enemy.Load();
	fps.Load();
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
		
	   cout << "Diferenta dintre cadre este de :" << deltaTime << endl;
	
		//--------------------------------------------------------------------UPDATE---------------------------------------------------------------------------------












		//--------------------------------------------------------------------DRAW---------------------------------------------------------------------------------

		window.clear(Color::Black);
		player.Draw(window);
		enemy.Draw(window);
		fps.Draw(window);
		window.display();
		
		
		//--------------------------------------------------------------------DRAW---------------------------------------------------------------------------------
		
		
	}









	return 0;
}