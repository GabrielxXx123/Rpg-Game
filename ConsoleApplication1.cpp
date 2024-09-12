#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;


int main()
{//--------------------------------------------------------------------INITIALIZE---------------------------------------------------------------------------------
	
	ContextSettings settings;
	settings.antialiasingLevel = 8;
	
	RenderWindow window(VideoMode(1200, 800), "Gabriel's Game" , Style::Default, settings);

	RectangleShape shape(Vector2f(360.20f, 60.20f));
	shape.setPosition(Vector2f(600.00f, 400.00f));
	shape.setFillColor(Color::Cyan);
	shape.setOutlineColor(Color::Red);
	shape.setOutlineThickness(20.42f);
	shape.setOrigin(shape.getSize().x / 2.0f, shape.getSize().y / 2.0f);
	shape.setRotation(90.00f);
	

	CircleShape circle(50.21f);
	circle.setPosition(Vector2f(600.00f, 308.21f));
	circle.setFillColor(Color::White);
	circle.setOrigin(circle.getRadius(), circle.getRadius());


	CircleShape triangle(80, 3);
	triangle.setFillColor(Color::Yellow);
	triangle.setOutlineColor(Color::Magenta);
	triangle.setOrigin(triangle.getRadius(), triangle.getRadius());
	triangle.setPosition(window.getSize().x /2, 148);
	triangle.setOutlineThickness(13.21f);

	
	//--------------------------------------------------------------------INITIALIZE---------------------------------------------------------------------------------







	// mian game loop
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

		//--------------------------------------------------------------------UPDATE---------------------------------------------------------------------------------









		//--------------------------------------------------------------------DRAW---------------------------------------------------------------------------------

		window.clear(Color::Black);
		window.draw(shape);
		window.draw(circle);
		window.draw(triangle);
		window.display();
		

		//--------------------------------------------------------------------DRAW---------------------------------------------------------------------------------


	}














	return 0;
}