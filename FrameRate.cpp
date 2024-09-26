#include "FrameRate.h"




FrameRate::FrameRate()
	:timer(0)
{

}

FrameRate::~FrameRate()
{

}

void FrameRate::Initialize()
{

}

void FrameRate::Load()
{
	if (font.loadFromFile("Assets/Fonts/C64.ttf"))
	{
		cout << "Font loaded!" << endl;
		frameRateText.setFont(font);
	}
}

void FrameRate::Update(float deltaTime)
{
	timer += deltaTime;

	if (timer >= 0.1) {
		int fps = static_cast<int>(1.0f / deltaTime);
		string frameRateString = "FPS: " + to_string(fps);
		frameRateText.setString(frameRateString);
		frameRateText.setScale(0.7f, 0.7f);
		timer = 0;
	}
}

void FrameRate::Draw(RenderWindow& window)
{
	window.draw(frameRateText);
}
