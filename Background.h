#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

class Background
{
private:
	Texture texture;
	Sprite sprite;


public:
	void Initialize();
	void Load();
	void Update();
	void Draw(RenderWindow& window);
	void ResizeAfterWindow(RenderWindow& window);


};