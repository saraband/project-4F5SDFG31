#include "App.hpp"

App* App::m_instance = nullptr;

App::App()
    : m_screen          (Screen::MainMenu)
    , m_showVideoInfo   (false)
{

}

App::~App()
{

}

App* App::getInstance()
{
    if (!m_instance) {
        m_instance = new App;
    }

    return m_instance;
}

int App::launch()
{
    m_window.create(sf::VideoMode(1200, 850, 32), "project-4F5SDFG31");

    while (m_screen != Screen::Exit) {
        switch (m_screen) {
            case Screen::MainMenu:
                mainMenuFunction();
                break;
        }
    }

    m_window.close();
    return EXIT_SUCCESS;
}

void App::mainMenuFunction()
{
    // TEST ZONE
    ui::Button button("Hello world", sf::FloatRect(50, 50, 200, 50));
    button.bindEvent(ui::Event::Click, [](){
        std::cout << "Click !" << std::endl;
    });
    ui::Manager manager(m_window);
    manager.addElement(&button);

    while (m_screen == Screen::MainMenu) {
        // Event handling
        sf::Event event;
        while (m_window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                m_screen = Screen::Exit;
            else if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Escape)
                    m_screen = Screen::Exit;
                else if (event.key.code == sf::Keyboard::F1)
                    m_showVideoInfo = !m_showVideoInfo;
            }

            manager.processEvent(event);
        }

        if (m_showVideoInfo)
            m_videoInfo.update();

        // Display
        m_window.clear();
        manager.draw(m_window);
        if (m_showVideoInfo)
            m_window.draw(m_videoInfo);
        m_window.display();
    }
}
