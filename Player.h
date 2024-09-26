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
	
	float playerSpeed = 200.0f;
	float bulletCooldown = 0.2f;    
	float timeSinceLastShot = 0.0f;

	// X ,Y , width, height pentru a face animatia  
	int xIndex = 0;
	int yIndex = 0;

	float animationTimer = 0.0f;    
	float animationSpeed = 0.05f;    

	float width = 64;
	float height = 64;
	Vector2i frameSize = Vector2i(width, height); 
	



public :
	vector<Bullet> bullets;
	Sprite sprite;
	

public : 
	
	void Initialize();
	void Load();
	void Update(RenderWindow& window, Enemy& enemy, float deltaTime );
	void Draw(RenderWindow& window);

	
};