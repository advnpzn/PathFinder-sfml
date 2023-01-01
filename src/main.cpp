#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include "pixelmap.h"

int main()
{
    sf::String title = "Mitochondria";
    sf::RenderWindow window(sf::VideoMode(800, 800), title, sf::Style::Close);
    
    int mapSize = 20;
    int margin = 50;
    PixelMap map((800 - margin * 2) / mapSize, mapSize, margin);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }
        window.clear(sf::Color::White);
        map.draw(window);
        window.display();
    }
    

    return 0;

}

