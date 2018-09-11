#include "Level.hpp"

Level::Level()
{

}

Level::Level(const std::string& filename)
{
    loadFromFile(filename);
}

Level::Level(const Level& other)
{

}

Level::~Level()
{

}

bool Level::loadFromFile(const std::string& filename)
{
    return true;
}