#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
using namespace std;

class Player
{
private:
	Texture texture;

public :

	Sprite sprite;
	

public : 
	
	void Initialize();
	void Load();
	void Update();
	void Draw(RenderWindow& window);

};