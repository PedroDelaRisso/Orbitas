#include "CelestialBody.h"

CelestialBody::CelestialBody(float radius, float orbitTime)
{
    this->body.setRadius(radius);
    this->orbitTime = orbitTime;
    body.setOrigin(+body.getRadius(), +body.getRadius());
    orbitRadius = 0;
    angle = 0.0f;
    totalTime = 0.0f;
}

void CelestialBody::Draw(sf::RenderWindow& window)
{
	window.draw(body);
}

void CelestialBody::OrbitAround(sf::Vector2f orbitCenter, float deltaTime)
{
    totalTime += deltaTime;
    body.setPosition(orbitCenter.x + cos(angle) * orbitRadius, orbitCenter.y + sin(angle) * orbitRadius);
    angle += (M_PI / 2) / orbitTime;
    if (angle >= M_PI * 2) angle = 0;


}

void CelestialBody::OrbitAround(CelestialBody parent, float deltaTime)
{
    this->OrbitAround(parent.GetPosition(), deltaTime);
}
