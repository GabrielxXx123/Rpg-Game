#include "Bullet.h"
#include <cmath>

Bullet::Bullet(Vector2f startPos, Vector2f targetPos, const Texture& texture)
{
    sprite.setTexture(texture);  
    sprite.setTextureRect(IntRect(0, 0, 512, 512));
    sprite.setScale(Vector2f(0.052f, 0.052f));  

    sprite.setPosition(startPos);

   
    Vector2f directionVec = targetPos - startPos;
    float magnitude = sqrt(directionVec.x * directionVec.x + directionVec.y * directionVec.y);
    direction = directionVec / magnitude; 

    speed = 5.2f; 
}



void Bullet::Update()
{
    sprite.move(direction * speed); 
}

void Bullet::Draw(RenderWindow& window)
{
    window.draw(sprite);
}

Vector2f Bullet::getPosition()
{
    return sprite.getPosition();
}
