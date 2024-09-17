#include "Player.h"


void Player::Initialize()
{
	cout << "player created!" << endl;
}

void Player::Load()
{
	if (texture.loadFromFile("Assets/Player/Textures/spritesheets.png"))
	{
		cout << "Player image loaded!" << endl;
		sprite.setTexture(texture);
		// X ,Y , width, height
		int xIndex = 0;
		int yIndex = 0;

		sprite.setTextureRect(IntRect(xIndex * 32, yIndex * 32, 32, 32));
		sprite.scale(Vector2f(3, 3));
	}
	else
	{
		cout << "Player image failed loading!" << endl;
	}

	sprite.setPosition(Vector2f(600.00f, 308.21f));

}

void Player::Update()
{
	if (Keyboard::isKeyPressed(Keyboard::W))
	{
		sprite.setPosition(sprite.getPosition() + Vector2f(0.0f, -0.5f));
	}
	if (Keyboard::isKeyPressed(Keyboard::S))
	{
		sprite.setPosition(sprite.getPosition() + Vector2f(0.0f, 0.5f));
	}
	if (Keyboard::isKeyPressed(Keyboard::A))
	{
		sprite.setPosition(sprite.getPosition() + Vector2f(-0.5f, 0.0f));
	}
	if (Keyboard::isKeyPressed(Keyboard::D))
	{
		sprite.setPosition(sprite.getPosition() + Vector2f(0.5f, 0.0f));
	}
}

void Player::Draw(RenderWindow& window)
{
	window.draw(sprite);
}

