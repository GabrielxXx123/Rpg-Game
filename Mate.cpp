#include "Mate.h"
Vector2f Mate::normalizeVector(Vector2f vector)
{
	 float m = sqrt(vector.x * vector.x + vector.y * vector.y);
   Vector2f normalizedVector;

   normalizedVector.x = vector.x / m;
   normalizedVector.y = vector.y / m;

   return normalizedVector;
}