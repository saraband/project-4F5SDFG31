#ifndef LEVEL_HPP
#define LEVEL_HPP

#include <string>

class Level
{
    public:
        Level();
        Level(const std::string& filename);
        Level(const Level& other);
        ~Level();
        bool loadFromFile(const std::string& filename);
    private:
};

#endif