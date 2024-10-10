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
	healthBarBackground.setSize(Vector2f(80.0f,8.0f));

	healthBar.setSize(Vector2f(80.0f, 8.0f)); 
	healthBar.setFillColor(Color::Green);
	healthBar.setOutlineColor(Color::Red);
	healthBar.setOutlineThickness(1);
}

void Enemy::Load()
{
	if (texture.loadFromFile("Assets/Enemy/Textures/goblin.png"))       
	{
		cout << "Enemy image loaded!" << endl;
		sprite.setTexture(texture);
		sprite.setTextureRect(IntRect(xIndex * size.x, yIndex * size.y, size.x, size.y));
		sprite.setPosition(Vector2f(650.00f, 308.21f));
	}
	else
	{
		cout << "Enemy image failed loading!" << endl;
	}
	

}

void Enemy::Update(float deltaTime, RenderWindow &window)
{
	healthBarBackground.setPosition(sprite.getPosition().x + 30, sprite.getPosition().y - 10);
	healthBar.setPosition(sprite.getPosition().x + 30, sprite.getPosition().y - 10);
	boundingRectangle.setPosition(sprite.getPosition());


	float healthPercentage = static_cast<float>(health) / maxHealth;
	healthBar.setSize(Vector2f(80.0f * healthPercentage, 8.0f));
   
	CheckDeadOfEnemy(deltaTime);

	animationTimer += deltaTime;

	if (direction.x == 0 && direction.y == enemySpeed)
	{
		sprite.setPosition(sprite.getPosition() + direction * deltaTime);


			if (animationTimer >= animationSpeed)
			{

				xIndex++;
				yIndex = 0;
				if (xIndex == 10)
				{
					xIndex = 0;
				}
				sprite.setTextureRect(IntRect(xIndex * size.x, yIndex * size.y, size.x, size.y));

				animationTimer = 0;
			}
	}
	
	if (direction.x == enemySpeed && direction.y == 0 )
	{
		sprite.setPosition(sprite.getPosition() + direction * deltaTime);


			if (animationTimer >= animationSpeed)
			{

				xIndex++;
				yIndex = 1;
				if (xIndex == 10)
				{
					xIndex = 0;
				}
				sprite.setTextureRect(IntRect(xIndex * size.x, yIndex * size.y, size.x, size.y));

				animationTimer = 0;
			}
	}

	if (direction.x == 0 && direction.y == -enemySpeed)
	{
		sprite.setPosition(sprite.getPosition() + direction * deltaTime);


			if (animationTimer >= animationSpeed)
			{

				xIndex++;
				yIndex = 2;
				if (xIndex == 10)
				{
					xIndex = 0;
				}
				sprite.setTextureRect(IntRect(xIndex * size.x, yIndex * size.y, size.x, size.y));

				animationTimer = 0;
			} 
	}
	
	if (direction.x == -enemySpeed && direction.y == 0)
	{
		sprite.setPosition(sprite.getPosition() + direction * deltaTime);


			if (animationTimer >= animationSpeed)
			{

				xIndex++;
				yIndex = 3;
				if (xIndex == 10)
				{
					xIndex = 0;
				}
				sprite.setTextureRect(IntRect(xIndex * size.x, yIndex * size.y, size.x, size.y));

				animationTimer = 0;
			}  
	}
	
	FloatRect windowBounds(0.0f, 0.0f, static_cast<float>(window.getSize().x), static_cast<float>(window.getSize().y));
	FloatRect enemyBounds = sprite.getGlobalBounds();
	if (enemyBounds.left <= windowBounds.left ||
		enemyBounds.left + enemyBounds.width >= windowBounds.width ||
		enemyBounds.top <= windowBounds.top ||
		enemyBounds.top + enemyBounds.height >= windowBounds.height)
	{
		ChangeDirection();
	}
	
}

void Enemy::Draw(RenderWindow& window)
{   
	if (!enemyDead)
	{
		window.draw(sprite);
		window.draw(boundingRectangle);
		window.draw(healthBarBackground);
		window.draw(healthBar);
	}

	 

	if (!expFinish) 
	{
		window.draw(expSprite);
	}
}

void Enemy::TakeDamage(int damage)
{

	health -= damage;  
	if (health < 0)
	{
		health = 0;
		
	} 
}

bool Enemy::IsDead()
{
	return health <= 0;
}





void Enemy::CheckDeadOfEnemy(float deltaTime)
{
	if (health == 0)
	{
		enemyDead = true;
	}

	if (IsDead() == true)
	{

		expAnimationTime += deltaTime;


		if (expAnimationTime >= expAnimationSpeed)
		{
			xExpIndex++;

			if (xExpIndex == 4)
			{
				xExpIndex = 0;
				yExpIndex++;

				if (yExpIndex == 9)
				{
					expFinish = true;
				}
			}

			expTexture.loadFromFile("Assets/Enemy/Textures/Zombie.png");
			expSprite.setTexture(expTexture);
			expSprite.setScale(3, 3);

			expSprite.setTextureRect(IntRect(xExpIndex * expSize.x, yExpIndex * expSize.y, expSize.x, expSize.y));
			expSprite.setPosition(sprite.getPosition().x - 20, sprite.getPosition().y + 10);
			expAnimationTime = 0;
		}
	}

}

void Enemy::ChangeDirection()
{
	int randomDir = rand() % 4;


	switch (randomDir)
	{
	case 0:
		direction = Vector2f(enemySpeed, 0);
		break;
	case 1:
		direction = Vector2f(-enemySpeed, 0.0f);
		break;

	case 2:
		direction = Vector2f(0.0f, enemySpeed);
		break;
	
	case 3:
		direction = Vector2f(0.0f, -enemySpeed);
		break;
	}

}