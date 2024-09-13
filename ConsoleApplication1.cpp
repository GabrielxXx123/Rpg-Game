#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;


int main()
{//--------------------------------------------------------------------INITIALIZE---------------------------------------------------------------------------------
	
	ContextSettings settings;
	settings.antialiasingLevel = 8;
	
	RenderWindow window(VideoMode(1200, 800), "Gabriel's Game" , Style::Default, settings);

	
	

	CircleShape circle(50.21f);
	circle.setPosition(Vector2f(600.00f, 308.21f));
	circle.setFillColor(Color::White);
	circle.setOrigin(circle.getRadius(), circle.getRadius());


	
	
	//--------------------------------------------------------------------INITIALIZE---------------------------------------------------------------------------------
	



	//--------------------------------------------------------------------LOAD---------------------------------------------------------------------------------
	Texture playerTexture;
	Sprite playerSprite;

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
		cout << "Player image failed loaded!" << endl;
	}
	playerSprite.setPosition(Vector2f(600.00f, 308.21f));

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



		//--------------------------------------------------------------------UPDATE---------------------------------------------------------------------------------









		//--------------------------------------------------------------------DRAW---------------------------------------------------------------------------------

		window.clear(Color::Black);
		//window.draw(circle);
		window.draw(playerSprite);
		window.display();
		

		//--------------------------------------------------------------------DRAW---------------------------------------------------------------------------------


	}














	return 0;
}