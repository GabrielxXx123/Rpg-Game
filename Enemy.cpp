#include "Enemy.h"

void Enemy::Initialize()
{
	cout << "Enemy created!" << endl;
	boundingRectangle.setFillColor(Color::Transparent);
	boundingRectangle.setOutlineThickness(2);
	boundingRectangle.setOutlineColor(Color::Red);
	sprite.scale(2, 2);
	boundingRectangle.setSize(Vector2f(size.x * sprite.getScale().x, size.y * sprite.getScale().y));
	
	healthBarBackground.setFillColor(Color::White);
	healthBarBackground.setPosition(sprite.getPosition().x + 30, sprite.getPosition().y - 10);
	healthBarBackground.setSize(Vector2f(80.0f,8.0f));

	healthBar.setSize(Vector2f(80.0f, 8.0f)); 
	healthBar.setFillColor(Color::Green);
	healthBar.setPosition(sprite.getPosition().x + 30, sprite.getPosition().y - 10);
	healthBar.setOutlineColor(Color::Red);
	healthBar.setOutlineThickness(1);
}

void Enemy::Load()
{
	if (texture.loadFromFile("Assets/Enemy/Textures/goblin.png"))
	{
		cout << "Enemy image loaded!" << endl;
		int xIndex = 0;
		int yIndex = 0;
		sprite.setTexture(texture);
		sprite.setTextureRect(IntRect(xIndex * size.x, yIndex * size.y, size.x, size.y));
		sprite.setPosition(Vector2f(650.00f, 308.21f));
	}
	else
	{
		cout << "Enemy image failed loading!" << endl;
	}
	

}

void Enemy::Update(float deltaTime)
{
	healthBarBackground.setPosition(sprite.getPosition().x + 30, sprite.getPosition().y - 10);
	healthBar.setPosition(sprite.getPosition().x + 30, sprite.getPosition().y - 10);
	boundingRectangle.setPosition(sprite.getPosition());
	float healthPercentage = static_cast<float>(health) / maxHealth;
	healthBar.setSize(Vector2f(80.0f * healthPercentage, 8.0f));
}

void Enemy::Draw(RenderWindow& window)
{
	window.draw(sprite);
	window.draw(boundingRectangle);

	window.draw(healthBarBackground); 
	window.draw(healthBar);
}

void Enemy::takeDamage(int damage)
{

	health -= damage;
	if (health < 0)
	{
		health = 0;
	}
}

bool Enemy::isDead()
{
	return health <= 0;
}
