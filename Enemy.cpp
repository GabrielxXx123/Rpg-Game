#include "Enemy.h"

void Enemy::Initialize()
{
	cout << "Enemy created!" << endl;
}

void Enemy::Load()
{
	if (texture.loadFromFile("Assets/Enemy/Textures/goblin.png"))
	{
		cout << "Enemy image loaded!" << endl;
		sprite.setTexture(texture);
		sprite.scale(2, 2);
		sprite.setTextureRect(IntRect(0, 0, 68, 62));
	}
	else
	{
		cout << "Enemy image failed loading!" << endl;
	}
	sprite.setPosition(Vector2f(650.00f, 308.21f));

}

void Enemy::Update()
{

}

void Enemy::Draw(RenderWindow& window)
{
	window.draw(sprite);
}
