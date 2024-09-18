#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Bullet.h"
using namespace sf;
using namespace std;

class Player
{
private:
	Texture texture;
	Texture bulletTexture;

public :
	vector<Bullet> bullets;
	Sprite sprite;
	

public : 
	
	void Initialize();
	void Load();
	void Update(RenderWindow& window);
	void Draw(RenderWindow& window);
	
};