#include "Bullet.h"

// Definirea variabilei statice pentru textura glonțului
Texture Bullet::bulletTexture;

// Încarcă textura pentru toate gloanțele
bool Bullet::Load()
{
    // Încarcă textura și returnează succesul
    if (bulletTexture.loadFromFile("Assets/Environment/Textures/bullet.png"))
    {
        cout << "Bullet loaded!" << endl;
        
    }
}

// Constructor pentru inițializarea unui nou glonț
Bullet::Bullet(const Vector2f& position, const Vector2f& dir, float speed)
    : direction(dir), bulletSpeed(speed)
{
    sprite.setTexture(bulletTexture);  // Setează textura statică încărcată
    sprite.setPosition(position);      // Poziționează glonțul la poziția inițială
}

// Funcție statică pentru a gestiona tragerea glonțelor
void Bullet::HandleShooting(RenderWindow& window, vector<Bullet>& bullets)
{
    if (Mouse::isButtonPressed(Mouse::Left))
    {
        // Direcția glonțului (în sus)
        Vector2f direction(0, -1);

        // Poziția inițială a glonțului (la poziția mouse-ului)
        Vector2f position = Vector2f(Mouse::getPosition(window));

        // Creează un nou glonț și adaugă-l în vector
        bullets.push_back(Bullet(position, direction, 5.0f));
    }
}

// Actualizează poziția glonțului
void Bullet::Update()
{
    // Mișcă glonțul în direcția sa
    sprite.move(direction * bulletSpeed);
}

// Desenează glonțul pe fereastră
void Bullet::Draw(RenderWindow& window)
{
    window.draw(sprite);
}
