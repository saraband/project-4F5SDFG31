/*
**  App Singleton
*/

#include <SFML/Graphics.hpp>
#include <iostream>
#include "ScreenType.hpp"
#include "AssetManager.hpp"
#include "ui/Manager.hpp"
#include "ui/Button.hpp"

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
        static App*         m_instance;
        sf::RenderWindow    m_window;
        Screen::Type		m_screen;
};

#endif
