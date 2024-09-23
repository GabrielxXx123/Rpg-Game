#pragma once

#include <vector>
#include <math.h>
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

class Mate
{
public:
	static Vector2f normalizeVector(Vector2f vector);
	static bool checkCollision(FloatRect obj1, FloatRect obj2);
};

