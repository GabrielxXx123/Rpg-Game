#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Bullet.h"
#include "Mate.h"
#include "Enemy.h"
using namespace sf;
using namespace std;

class Player
{
private:
	Texture texture;
	Texture bulletTexture;
	RectangleShape boundingRectangle;
	float width = 32;
	float height = 32;
	Vector2i size = Vector2i(32,32);
	float playerSpeed = 200.0f;
	float bulletCooldown = 0.2f;    
	float timeSinceLastShot = 0.0f;  


public :
	vector<Bullet> bullets;
	Sprite sprite;
	

public : 
	
	void Initialize();
	void Load();
	void Update(RenderWindow& window, Enemy& enemy, float deltaTime );
	void Draw(RenderWindow& window);
	
};