#include "puzzle.hpp"

Puzzle::Puzzle() :
    m_window(std::make_unique<sf::RenderWindow>(sf::VideoMode(512, 512), "Puzzle", sf::Style::Titlebar | sf::Style::Close))
  , m_event(std::make_unique<sf::Event>())
  , m_w(128)
  , m_n(0)
  , m_x(0)
  , m_y(0)
  , m_dx(0)
  , m_dy(0)
  , m_grid({0})
{
    m_window->setPosition(sf::Vector2i(50, 50));
    m_window->setFramerateLimit(60);

    m_texture.loadFromFile("./assets/puzzle.png");

    m_sprite.setTexture(m_texture);
}

void Puzzle::run()
{

}

void Puzzle::events()
{

}

void Puzzle::draw()
{

}
