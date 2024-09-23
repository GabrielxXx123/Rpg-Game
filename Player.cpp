#include "Player.h"
#include "Enemy.h"


void Player::Initialize()
{
	cout << "player created!" << endl;
	boundingRectangle.setOutlineColor(Color::Blue);
	boundingRectangle.setOutlineThickness(2);
	boundingRectangle.setFillColor(Color::Transparent);
	sprite.scale(Vector2f(3, 3));
	boundingRectangle.setSize(Vector2f(size.x * sprite.getScale().x, size.y * sprite.getScale().y));
	sprite.setPosition(Vector2f(400.00f, 230.21f));

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

		sprite.setTextureRect(IntRect(xIndex * size.x, yIndex * size.y, size.x, size.y));
		
	}
	else
	{
		cout << "Player image failed loading!" << endl;
	}


	if (bulletTexture.loadFromFile("Assets/Environment/Textures/dildo.png"))
	{
		cout << "Bullet image loaded!"<< endl;
	}


	

}

void Player::Update(RenderWindow& window, Enemy& enemy, float deltaTime)
{
	timeSinceLastShot += deltaTime;

	Vector2f playerLastPosition = sprite.getPosition();

	if (Keyboard::isKeyPressed(Keyboard::W))
	{
		sprite.setPosition(sprite.getPosition() + Vector2f(0.0f, -playerSpeed * deltaTime ));
	}
	if (Keyboard::isKeyPressed(Keyboard::S))
	{
		sprite.setPosition(sprite.getPosition() + Vector2f(0.0f, playerSpeed * deltaTime));
	}
	if (Keyboard::isKeyPressed(Keyboard::A)) 
	{
		sprite.setPosition(sprite.getPosition() + Vector2f(-playerSpeed * deltaTime, 0.0f));
	}
	if (Keyboard::isKeyPressed(Keyboard::D))
	{
		sprite.setPosition(sprite.getPosition() + Vector2f(playerSpeed * deltaTime, 0.0f));
	}
	if (Mouse::isButtonPressed(Mouse::Left) && timeSinceLastShot >= bulletCooldown)
	{
		Vector2f mousePos = window.mapPixelToCoords(Mouse::getPosition(window));
		Bullet bullet(sprite.getPosition(), mousePos, bulletTexture);  
		bullets.push_back(bullet);
		timeSinceLastShot = 0.0f;
	}
	for (size_t i = 0; i < bullets.size(); ++i)
	{
		bullets[i].Update(deltaTime);

		if (Mate::checkCollision(bullets[i].sprite.getGlobalBounds(), enemy.sprite.getGlobalBounds()))
		{
			
			bullets.erase(bullets.begin() + i);
			enemy.takeDamage(1);
			
			cout << "Bullet hit the enemy!" << endl;
			if (enemy.isDead())
			{
				cout << "Enemy has been destroyed! YOU MURDERER!" << endl;
			}
			
			//--i;
		}
	}





	boundingRectangle.setPosition(sprite.getPosition());

	
	
	if (Mate::checkCollision(sprite.getGlobalBounds(), enemy.sprite.getGlobalBounds()))
	{
		sprite.setPosition(playerLastPosition);
		cout << "COLLISION!";
		
	}
	
}

void Player::Draw(RenderWindow& window)
{

	window.draw(sprite);

	for (size_t i = 0; i < bullets.size(); ++i)
	{
		bullets[i].Draw(window);
	}
	window.draw(boundingRectangle);
}

