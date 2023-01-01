#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include "pixelmap.h"

int main()
{
    sf::String title = "Mitochondria";
    sf::RenderWindow window(sf::VideoMode(800, 800), title, sf::Style::Close);
    
    int mapSize = 40;
    int margin = 50;
    int stepSize = (800 - margin * 2) / mapSize;
    PixelMap map(stepSize, mapSize, margin);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::C))
            {
                map.clearAll();
            }

            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                sf::Vector2i pixelPos = {sf::Mouse::getPosition(window).x - margin, sf::Mouse::getPosition(window).y - margin};
                
                //std::cout << "MousePos (x,y) = "<< pixelPos.x << " " << pixelPos.y<<std::endl; 

                if (!(pixelPos.x < 0 || pixelPos.y < 0 || pixelPos.x > 800 - margin || pixelPos.y > 800 - margin))
                {
                    int x = pixelPos.x / stepSize;
                    int y = pixelPos.y / stepSize;
                    std::cout << "PixelPos (x,y) = "<< x<< " " << y<<std::endl; 
                    
                    map.putWall(x, y);
                }
            }
            else if(sf::Mouse::isButtonPressed(sf::Mouse::Right))
            {
                sf::Vector2i pixelPos = {sf::Mouse::getPosition(window).x - margin, sf::Mouse::getPosition(window).y - margin};
                
                //std::cout << "MousePos (x,y) = "<< pixelPos.x << " " << pixelPos.y<<std::endl; 

                if (!(pixelPos.x < 0 || pixelPos.y < 0 || pixelPos.x > 800 - margin || pixelPos.y > 800 - margin))
                {
                    int x = pixelPos.x / stepSize;
                    int y = pixelPos.y / stepSize;
                    std::cout << "PixelPos (x,y) = "<< x<< " " << y<<std::endl; 
                    
                    map.removeWall(x, y);
                }
            }
        }
        window.clear(sf::Color::White);
        map.draw(window);
        window.display();
    }
    

    return 0;

}

