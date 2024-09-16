#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include <math.h>
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
	
	Texture playerTexture;
	Sprite playerSprite;
	Texture enemyTexture;
	Sprite enemySprite;
	Texture bulletTexture;
	vector <Sprite> bullets;
	Sprite newBullet;
	float bulletSpeed = 1.1f;


	CircleShape circle(50.21f);
	circle.setPosition(Vector2f(600.00f, 308.21f));
	circle.setFillColor(Color::White);
	circle.setOrigin(circle.getRadius(), circle.getRadius());


	
	

	

	

	
	//--------------------------------------------------------------------INITIALIZE---------------------------------------------------------------------------------
	



	//--------------------------------------------------------------------LOAD---------------------------------------------------------------------------------
	
	// creating an bullet

	if (bulletTexture.loadFromFile("Assets/Environment/Textures/bullet.png"))
	{
		cout << "Bullet image loaded!";
		newBullet.setTexture(bulletTexture);
		newBullet.setTextureRect(IntRect(0, 0, 6, 10));
	}
	else
	{
		cout << "Bullet image failed loading!";
	}
	
	// creating an player

	if (playerTexture.loadFromFile("Assets/Player/Textures/spritesheets.png"))
	{
		cout << "Player image loaded!" << endl;
		playerSprite.setTexture(playerTexture);
		// X ,Y , width, height
		int xIndex = 0;
		int yIndex = 0;
		
		playerSprite.setTextureRect(IntRect(xIndex * 32, yIndex * 32, 32, 32));
		playerSprite.scale(Vector2f(3, 3));
	}
	else
	{
		cout << "Player image failed loading!" << endl;
	}
	playerSprite.setPosition(Vector2f(600.00f, 308.21f));



	// creating an enemy

	if (enemyTexture.loadFromFile("Assets/Enemy/Textures/goblin.png"))
	{
		cout << "Enemy image loaded!" << endl;
		enemySprite.setTexture(enemyTexture);
		enemySprite.scale(2, 2);
		enemySprite.setTextureRect(IntRect(0, 0, 68, 62));
	}
	else
	{
		cout << "Enemy image failed loading!" << endl;
	}
	enemySprite.setPosition(Vector2f(650.00f, 308.21f));






	
	//--------------------------------------------------------------------LOAD---------------------------------------------------------------------------------







	// main game loop
	while (window.isOpen())
	{
		//--------------------------------------------------------------------UPDATE---------------------------------------------------------------------------------










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

		  


			// player controller

		
			if (Keyboard::isKeyPressed(Keyboard::W))
			{
				playerSprite.setPosition(playerSprite.getPosition() + Vector2f(0.0f, -0.5f));
			}
			if (Keyboard::isKeyPressed(Keyboard::S))
			{
				playerSprite.setPosition(playerSprite.getPosition() + Vector2f(0.0f, 0.5f));
			}
			if (Keyboard::isKeyPressed(Keyboard::A))
			{
				playerSprite.setPosition(playerSprite.getPosition() + Vector2f(-0.5f, 0.0f));
			}
			if (Keyboard::isKeyPressed(Keyboard::D))
			{
				playerSprite.setPosition(playerSprite.getPosition() + Vector2f(0.5f, 0.0f));
			}

			// Daca click e apasat creem un bullet in vectorul bullets si ii setam textura si pozitia

			if (Mouse::isButtonPressed(Mouse::Button::Left))
			{
				bullets.push_back(newBullet);
				newBullet.setPosition(playerSprite.getPosition());
				
				

				

				
			}
			// Calculam directia unde sa se indrepte glontul pentru fiecare glont

			for (size_t i = 0; i < bullets.size(); i++)
			{

				
				Vector2f direction = enemySprite.getPosition() - newBullet.getPosition();
				direction = normalizeVector(direction);
				bullets[i].setPosition(bullets[i].getPosition() + direction * bulletSpeed);
			}
		//--------------------------------------------------------------------UPDATE---------------------------------------------------------------------------------









		//--------------------------------------------------------------------DRAW---------------------------------------------------------------------------------

		window.clear(Color::Black);
	    window.draw(enemySprite);
		window.draw(playerSprite);
		for (int i = 0; i < bullets.size(); i++)
		{
			window.draw(bullets[i]);
		}
	
		window.display();
		

		//--------------------------------------------------------------------DRAW---------------------------------------------------------------------------------


	}














	return 0;
}