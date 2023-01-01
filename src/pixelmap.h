#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>

class PixelMap
{
public:
    PixelMap(int stepSize, int mapSize, int margin);
    ~PixelMap();

    void draw(sf::RenderWindow &window);
    
private:
    int stepSize, mapSize, margin;
    sf::Vector2i start;
    sf::Vector2i end;

    std::vector<sf::RectangleShape *> rectangles;
    void initMap();
    // 0 - wall, 1 - none, 2 - path, 3 - start, 4 - end
    std::vector<int> occupants;
};

