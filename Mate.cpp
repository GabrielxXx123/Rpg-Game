#include "Mate.h"
Vector2f Mate::normalizeVector(Vector2f vector)
{
	 float m = sqrt(vector.x * vector.x + vector.y * vector.y);
   Vector2f normalizedVector;

   normalizedVector.x = vector.x / m;
   normalizedVector.y = vector.y / m;

   return normalizedVector;
}

bool Mate::checkCollision(FloatRect obj1, FloatRect obj2)
{
	float obj1Stanga = obj1.left;
	float obj1Dreapta = obj1.left + obj1.width;
	float obj1Sus = obj1.top;
	float obj1Jos = obj1.top + obj1.height;


	float obj2Stanga = obj2.left;
	float obj2Dreapta = obj2.left + obj2.width;
	float obj2Sus = obj2.top;
	float obj2Jos = obj2.top + obj2.height;



	if (obj1Dreapta > obj2Stanga && obj1Stanga < obj2Dreapta
		&&
		obj1Jos > obj2Sus && obj1Sus < obj2Jos)
	{
		return true;
	}


	return false;
}
