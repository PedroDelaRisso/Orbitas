#include "CelestialBody.h"

CelestialBody::CelestialBody(float radius, float orbitSpeed)
{
    this->body.setRadius(radius);
    this->orbitSpeed = orbitSpeed;
    body.setOrigin(+body.getRadius(), +body.getRadius());
    orbitRadius = 0;
    angle = 0.0f;
}

void CelestialBody::Draw(sf::RenderWindow& window)
{
	window.draw(body);
}

void CelestialBody::OrbitAround(sf::Vector2f orbitCenter)
{
    if (angle < 2 * M_PI)
    {
        body.setPosition(orbitCenter.x + cos(angle) * orbitRadius, orbitCenter.y + sin(angle) * orbitRadius);
        angle += orbitSpeed / 10000.0f;
    }
    else angle = 0;
}

void CelestialBody::OrbitAround(CelestialBody parent)
{
    this->OrbitAround(parent.GetPosition());
}
