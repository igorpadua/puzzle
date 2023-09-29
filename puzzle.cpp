#include "puzzle.hpp"

Puzzle::Puzzle(const std::vector<int>& nums) :
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

    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            ++m_n;
            m_sprites[m_n].setTexture(m_texture);
            m_sprites[m_n].setTextureRect(sf::IntRect(j * m_w, i * m_w, m_w, m_w));
            m_grid[i + 1][j + 1] = nums[m_n - 1];
        }
    }
}

void Puzzle::run()
{
    while (m_window->isOpen()) {
        events();
        draw();
    }
}

void Puzzle::logic()
{
    auto pos = sf::Mouse::getPosition(*m_window);
    m_x = pos.x / m_w + 1;
    m_y = pos.y / m_w + 1;

    if (m_grid[m_x + 1][m_y] == 16) {
        m_dx = 1;
    }

    if (m_grid[m_x - 1][m_y] == 16) {
        m_dx = -1;
    }

    if (m_grid[m_x][m_y + 1] == 16) {
        m_dy = 1;
    }

    if (m_grid[m_x][m_y - 1] == 16) {
        m_dy = -1;
    }

    m_n = m_grid[m_x][m_y];
    m_grid[m_x][m_y] = 16;
    m_grid[m_x + m_dx][m_y + m_dy] = m_n;
    m_dx = 0;
    m_dy = 0;
}

void Puzzle::events()
{
    while (m_window->pollEvent(*m_event)) {
        if (m_event->type == sf::Event::Closed) {
            m_window->close();
        }

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            logic();
        }
    }
}

void Puzzle::draw()
{
    m_window->clear(sf::Color::Black);
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            m_n = m_grid[i + 1][j + 1];
            m_sprites[m_n].setPosition(i * m_w, j * m_w);
            m_window->draw(m_sprites[m_n]);
        }
    }
    m_window->display();
}
