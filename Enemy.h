#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <random>
#include "Mate.h"

using namespace sf;
using namespace std;

class Enemy
{
public:

	Sprite sprite;
private:

	//explosion
	Texture expTexture;
	Sprite expSprite;
	float expAnimationTime = 0;
	float expAnimationSpeed = 0.1;
	int xExpIndex = 0;
	int yExpIndex = 8;
	Vector2f expSize = Vector2f(64.0f, 44.5f);
	bool expFinish = false;



	//enemy
	Texture texture;
    Vector2f size =	Vector2f(64,65);
	bool enemyDead = false;
	Vector2f direction = Vector2f(0.0f,0.0f);
	float enemySpeed = 100;
	int xIndex = 0;
	int yIndex = 0;
	float animationTimer = 0;
	float animationSpeed = 0.05f;

	//experiment
	float  xSpritePosition = sprite.getPosition().x;
	float  ySpritePosition = sprite.getPosition().y;
	Vector2f spritePosition = Vector2f(xSpritePosition, ySpritePosition);
	 


	// bounding square && healthbar
	RectangleShape boundingRectangle;
	int health = 10; 
	int maxHealth = 10;
	RectangleShape healthBar;
	RectangleShape healthBarBackground;



	

public :
	void ChangeDirection();
	void Initialize();
	void Load();
	void CheckDeadOfEnemy(float deltaTime);
	void Update(float deltaTime, RenderWindow &window);
	void Draw(RenderWindow& window);
	void TakeDamage(int damage);
	bool IsDead();






};