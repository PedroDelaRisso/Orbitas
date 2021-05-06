#include "CelestialBody.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1280, 720), "Orbitas");
    sf::Vector2f windowCenter((float)window.getSize().x / 2.0f, (float)window.getSize().y / 2.0f);

    CelestialBody sun(50.0f, 0.0f);
    CelestialBody mercury(3.0f, 2.0f);
    CelestialBody venus(8.0f, 2.5f);
    CelestialBody earth(10.0f, 3.0f);
    CelestialBody moon(2.0f, 12.0f);
    CelestialBody mars(4.0f, 1.5f);
    CelestialBody phobos(1.0f, 15.0f);
    CelestialBody deimos(1.0f, 20.0f);

    sun.SetPosition(windowCenter);
    sun.SetOrbitRadius(0.0f);
    mercury.SetOrbitRadius(60.0f);
    venus.SetOrbitRadius(150.0f);
    earth.SetOrbitRadius(200.0f);
    moon.SetOrbitRadius(25.0f);
    mars.SetOrbitRadius(300.0f);
    deimos.SetOrbitRadius(20.0f);
    phobos.SetOrbitRadius(15.0f);

    sun.SetColor(sf::Color(255, 255, 255));
    mercury.SetColor(sf::Color(150,150,100));
    venus.SetColor(sf::Color(255, 200, 0));
    earth.SetColor(sf::Color(0, 150, 255));
    moon.SetColor(sf::Color(140, 140, 140));
    mars.SetColor(sf::Color(255, 50, 0));
    deimos.SetColor(sf::Color(140, 140, 140));
    phobos.SetColor(sf::Color(140, 140, 140));


    while(window.isOpen())
    {
        sf::Event evnt;
        while(window.pollEvent(evnt))
        {
            switch (evnt.type)
            {
                case sf::Event::Closed:
                    window.close();
                    break;
            }
        }
        sf::Vector2i mousePosi = sf::Mouse::getPosition(window);
        sf::Vector2f mousePosf((float)mousePosi.x, (float)mousePosi.y);
        sf::Vector2f delta(mousePosf.x - sun.GetPosition().x, mousePosf.y - sun.GetPosition().y);
        if (sqrt((delta.x * delta.x) + (delta.y * delta.y)) <= sun.GetRadius())
        {
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                sun.SetPosition(mousePosf);
            }
        }


        mercury.OrbitAround(sun.GetPosition());
        venus.OrbitAround(sun.GetPosition());
        earth.OrbitAround(sun);
        moon.OrbitAround(earth.GetPosition());
        mars.OrbitAround(sun.GetPosition());
        deimos.OrbitAround(mars.GetPosition());
        phobos.OrbitAround(mars.GetPosition());

        window.clear();
        sun.Draw(window);
        mercury.Draw(window);
        venus.Draw(window);
        earth.Draw(window);
        moon.Draw(window);
        mars.Draw(window);
        phobos.Draw(window);
        deimos.Draw(window);
        window.display();
    }


    return 0;
}