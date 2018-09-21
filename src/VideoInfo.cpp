#include "VideoInfo.hpp"

VideoInfo::VideoInfo()
    : m_assetManager    (AssetManager::getInstance())
{
    m_background.setFillColor(sf::Color(255, 65, 54, 128));
    m_background.setSize(sf::Vector2f(300, 100));
    m_background.setPosition(sf::Vector2f(10, 10));
    m_framerateText.setCharacterSize(15);
    m_framerateText.setFont(m_assetManager->font(Font::Main));
    m_framerateText.setString("0 FPS");
    m_framerateText.setPosition(sf::Vector2f(20, 20));
    m_framerateText.setColor(sf::Color::White);
}

VideoInfo::~VideoInfo()
{

}

void VideoInfo::update()
{
    if (m_clock.getElapsedTime().asSeconds() > 1) {
        m_framerateText.setString(std::to_string((int)(1 / m_framerateClock.getElapsedTime().asSeconds())) + " FPS");
        m_clock.restart();
    }
    m_framerateClock.restart();
}

void VideoInfo::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(m_background, states);
    target.draw(m_framerateText, states);
}