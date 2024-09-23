#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

class Bullet
{
public:
    
    Sprite sprite;
private:
   
    Texture texture;
    Vector2f direction;
    float speed;

public:
   
    Bullet(Vector2f startPos, Vector2f targetPos, const Texture& texture);
    void Update(float deltaTime);
    void Draw(RenderWindow& window);
    Vector2f getPosition();
};
