#include "App.hpp"

App* App::myInstance = nullptr;

App::App()
    : myScreen  (Screen::MainMenu)
{

}

App::~App()
{

}

App* App::getInstance()
{
    if(!myInstance) {
        myInstance = new App;
    }

    return myInstance;
}

int App::launch()
{
    myWindow.create(sf::VideoMode(800, 600, 32), "project-4F5SDFG31");
    myWindow.setFramerateLimit(60);

    while(myScreen != Screen::Exit) {
        switch(myScreen) {
            case Screen::MainMenu:
                mainMenuFunction();
                break;
        }
    }

    myWindow.close();
    return EXIT_SUCCESS;
}

void App::mainMenuFunction()
{
    while(myScreen == Screen::MainMenu) {
        sf::Event event;
        while(myWindow.pollEvent(event)) {
            if(event.type == sf::Event::Closed
            || (event.type == sf::Event::KeyPressed
            && event.key.code == sf::Keyboard::Escape))
                myScreen = Screen::Exit;
        }

        myWindow.clear();
        myWindow.display();
    }
}
