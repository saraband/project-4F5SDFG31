/*
**  App Singleton
*/

#include <SFML/Graphics.hpp>
#include <iostream>
#include "ScreenType.hpp"
#include "AssetManager.hpp"

#ifndef APP_HPP
#define APP_HPP

class App
{
    public:
        ~App();
        static App* getInstance();
        int launch();
    private:
        App();
        void mainMenuFunction();
        static App*         myInstance;
        sf::RenderWindow    myWindow;
        Screen::Type		myScreen;
};

#endif
