#pragma once

#include <SFML/Graphics.hpp>
#include <memory>
#include <array>

class Puzzle
{
public:
    Puzzle();
    void run();

protected:
    void events();
    void draw();

private:
    std::unique_ptr<sf::RenderWindow> m_window;
    std::unique_ptr<sf::Event> m_event;

    sf::Texture m_texture;
    int m_w, m_n, m_x, m_y, m_dx, m_dy;
    std::array<std::array<int, 6>, 6> m_grid;
    std::array<sf::Sprite, 17> m_sprites;
};

