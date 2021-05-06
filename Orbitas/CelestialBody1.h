#pragma once
#include <SFML\Graphics.hpp>
#include <cmath>
#define M_PI           3.14159265358979323846

class CelestialBody
{
public:
    CelestialBody(float radius, float orbitSpeed);

    void Draw(sf::RenderWindow& window);
    void SetColor(sf::Color color);
    void SetRadius(float radius) { body.setRadius(radius); };
    void SetPosition(sf::Vector2f pos) { body.setPosition(pos); } ;
    void SetOrbitRadius(float orbitRadius) { this->orbitRadius = orbitRadius; } ;
    sf::Vector2f GetPosition() { return body.getPosition(); };

    void OrbitAround(CelestialBody cBody);

private:
    sf::CircleShape body;
    float radius;
    float orbitSpeed;
    float orbitRadius;
    static float angle;
};
