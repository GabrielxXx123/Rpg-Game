#include "Background.h"

void Background::Initialize()
{
}

void Background::Load()
{
	if (texture.loadFromFile("Assets/Environment/Textures/background2.jpg"))
	{
		sprite.setTexture(texture);
		cout << "Background loaded sucessfully" << endl;
	}
}

void Background::Update()
{
}

void Background::Draw(RenderWindow& window)
{
	window.draw(sprite);
}

void Background::ResizeAfterWindow(RenderWindow& window)
{
	Vector2f marimeBackground = sprite.getGlobalBounds().getSize();
	Vector2f marimeWindow =static_cast<Vector2f>(window.getSize());
	float newX = marimeWindow.x / marimeBackground.x;
	float newY = marimeWindow.y / marimeBackground.y;
	sprite.setScale(newX, newY);
	
}
