#include "CelestialBody.h"

CelestialBody::CelestialBody(float radius, float orbitSpeed)
{
    this->body.setRadius(radius);
    this->orbitSpeed = orbitSpeed;
    body.setOrigin(+body.getRadius(), +body.getRadius());

    angle = 0.0f;
}

void CelestialBody::Draw(sf::RenderWindow& window)
{
    window.draw(body);
}

void CelestialBody::SetColor(sf::Color color)
{
    body.setFillColor(color);
}

void CelestialBody::OrbitAround(CelestialBody parent)
{
    if(angle < 2 * M_PI)
    {
        body.setPosition(parent.GetPosition().x + cos(angle) * orbitRadius, parent.GetPosition().y + sin(angle) * orbitRadius);
        angle += orbitSpeed / 100.0f;
    }
    else angle = 0;
}
