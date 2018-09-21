#ifndef VIDEO_INFO_HPP
#define VIDEO_INFO_HPP

#include <SFML/Graphics.hpp>
#include "AssetManager.hpp"

class VideoInfo : public sf::Drawable
{
    public:
        VideoInfo();
        ~VideoInfo();
        void update();
    private:
        AssetManager*       m_assetManager;
        sf::RectangleShape  m_background;
        sf::Text            m_framerateText;
        sf::Clock           m_clock;
        sf::Clock           m_framerateClock;
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

#endif