#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

using namespace sf;
using namespace std;

class Bullet {
private:
    Sprite sprite;        // Sprite-ul glonțului
    Vector2f direction;   // Direcția în care se mișcă glonțul
    float bulletSpeed;    // Viteza glonțului
    static Texture bulletTexture;  // Textura pentru toate gloanțele (statică, o singură dată)

public:
    // Constructor care primește poziția și direcția
    Bullet(const Vector2f& position, const Vector2f& dir, float speed);

    // Funcție statică pentru a încărca textura
    static bool Load();

    // Funcție statică pentru a gestiona tragerea glonțelor
    static void HandleShooting(RenderWindow& window, vector<Bullet>& bullets);

    // Funcție pentru actualizarea poziției glonțului
    void Update();

    // Funcție pentru a desena glonțul pe fereastră
    void Draw(RenderWindow& window);

    // Returnează poziția curentă a glonțului
    Vector2f getPosition() const { return sprite.getPosition(); }
};
