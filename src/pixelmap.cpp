#include "pixelmap.h"
#include <stdlib.h>

PixelMap::PixelMap(int stepSize, int mapSize, int margin)
{
    this->stepSize = stepSize;
    this->mapSize = mapSize;
    this->margin = margin;

    start = sf::Vector2i(0, 0);
    end = sf::Vector2i(mapSize - 1, mapSize - 1);

    this->rectangles.reserve(mapSize * mapSize);
    this->occupants.reserve(mapSize * mapSize);
    for (int i = 0; i < mapSize; ++i)
    {
        for (int j = 0; j < mapSize; ++j)
        {
            rectangles.push_back(new sf::RectangleShape(sf::Vector2f(stepSize, stepSize)));
        }
    }
    initMap();
}

PixelMap::~PixelMap()
{
    for (int i = 0; i < mapSize; ++i)
    {
        for (int j = 0; j < mapSize; ++j)
        {
            delete (rectangles.at(i * mapSize + j));
        }
    }
}


void PixelMap::draw(sf::RenderWindow &window)
{
    for (int i = 0; i < mapSize; ++i)
    {
        for (int j = 0; j < mapSize; ++j)
        {
            window.draw(sf::RectangleShape(*rectangles.at(i * mapSize + j)));
        }
    }
}

void PixelMap::initMap()
{
    for (int i = 0; i < mapSize; ++i)
    {
        for (int j = 0; j < mapSize; ++j)
        {
            if (i == start.x && j == start.y)
            {
                rectangles.at(i * mapSize + j)->setFillColor(sf::Color::Green);
                occupants.push_back(3);
            }
            else if (i == end.x && j == end.y)
            {
                rectangles.at(i * mapSize + j)->setFillColor(sf::Color::Red);
                occupants.push_back(4);
            }
            else
            {
                rectangles.at(i * mapSize + j)->setFillColor(sf::Color::White);
                occupants.push_back(1);
            }
            //std::cout << "Pos " << i << " " << j << " = " << i * stepSize + margin << std::endl;
            rectangles.at(i * mapSize + j)->setPosition(sf::Vector2f(i * stepSize + margin, j * stepSize + margin));
            rectangles.at(i * mapSize + j)->setOutlineThickness(1.0f);
            rectangles.at(i * mapSize + j)->setOutlineColor(sf::Color::Black);
        }
    }
}


void PixelMap::putWall(int x, int y)
{
    if (x + 1 > mapSize || y + 1 > mapSize || x < 0 || y < 0)
        return;
    occupants.at(x * mapSize + y) = 0;
    rectangles.at(x * mapSize + y)->setFillColor(sf::Color::Black);
}


void PixelMap::clearAll()
{
    for (int i = 0; i < mapSize; i++)
    {
        for (int j = 0; j < mapSize; j++)
        {
            if (occupants.at(i * mapSize + j) == 0)
            {
                rectangles.at(i * mapSize + j)->setFillColor(sf::Color::White);
                occupants.at(i * mapSize + j) == 1;

            }
        }
    }
}

void PixelMap::removeWall(int x, int y)
{
    if (x + 1 > mapSize || y + 1 > mapSize || x < 0 || y < 0)
        return;
    occupants.at(x * mapSize + y) = 1;
    rectangles.at(x * mapSize + y)->setFillColor(sf::Color::White);
}
