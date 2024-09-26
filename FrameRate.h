#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;

class FrameRate
{
private:
	Text frameRateText;
	Font font;
	float timer;

	
	

public:
	FrameRate();
	~FrameRate();

	void Initialize();
	void Load();
	void Update(float deltaTime);
	void Draw(RenderWindow& window);
};

