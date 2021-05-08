#pragma once
#include <SFML/Graphics.hpp>
#include <cmath>
#define M_PI           3.14159265358979323846

class CelestialBody
{
public:
    CelestialBody(float radius, float orbitTime);

    void Draw(sf::RenderWindow& window);
    void SetColor(sf::Color color) { body.setFillColor(color); };
    void SetRadius(float radius) { body.setRadius(radius); };
    void SetPosition(sf::Vector2f pos) { body.setPosition(pos); };
    void SetOrbitRadius(float orbitRadius) { this->orbitRadius = orbitRadius; };
    void SetOrbitSpeed(float orbitTime) { this->orbitTime = orbitTime; };
    sf::Vector2f GetPosition() { return body.getPosition(); };
    float GetRadius() { return body.getRadius(); };

    void OrbitAround(sf::Vector2f orbitCenter, float deltaTime);
    void OrbitAround(CelestialBody parent, float deltaTime);

private:
    sf::CircleShape body;
    float orbitRadius;
    float angle;
    float orbitTime;
    float totalTime;
};

