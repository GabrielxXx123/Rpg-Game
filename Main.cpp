#include <vector>
#include <math.h>
#include "Player.h"
#include "Enemy.h"
#include "Bullet.h"

using namespace std;
using namespace sf;





Vector2f normalizeVector(Vector2f vector)
{
   float m = sqrt(vector.x * vector.x + vector.y * vector.y);
   Vector2f normalizedVector;

   normalizedVector.x = vector.x / m;
   normalizedVector.y = vector.y / m;

   return normalizedVector;
}

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

	if (!Bullet::Load()) {
		return -1;  // Dacă încărcarea eșuează, ieși din program
	}
	vector<Bullet> bullets;
	

	



	




	
	//--------------------------------------------------------------------LOAD---------------------------------------------------------------------------------







	// main game loop
	while (window.isOpen())
	{
		//--------------------------------------------------------------------UPDATE---------------------------------------------------------------------------------




		player.Update();
		enemy.Update();

		Bullet::HandleShooting(window, bullets);

		for (auto& bullet : bullets)
		{
			bullet.Update();
		}


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
		
		for (auto& bullet : bullets)
		{
			bullet.Draw(window);
		}
	
		window.display();

		//--------------------------------------------------------------------DRAW---------------------------------------------------------------------------------


	}














	return 0;
}