#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
using namespace std;

class Enemy
{

private:
	float width = 68;
	float height = 62;
	Texture texture;
    Vector2i size =	Vector2i(68,62);
	RectangleShape boundingRectangle;
	int health =10;
	int maxHealth = 10;
	RectangleShape healthBar;
	RectangleShape healthBarBackground;
public:

	Sprite sprite;

public :

	void Initialize();
	void Load();
	void Update(float deltaTime);
	void Draw(RenderWindow& window);
	void takeDamage(int damage);
	bool isDead();



};