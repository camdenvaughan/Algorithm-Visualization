#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

#include "algorithms/AlgData.h"
#include "algorithms/BinarySearch.h"
#include "algorithms/SimpleSearch.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1000, 500), "SFML works!", sf::Style::Default);

    sf::Texture texture;
    if (!texture.loadFromFile("res/textures/textures.png"))
    {
        std::cout << "Texture failed to load" << std::endl;
    }

    sf::Font font;
    if (!font.loadFromFile("res/fonts/coolvetica/coolvetica rg.ttf"))
    {
        std::cout << "Font failed to load" << std::endl;
    }

    std::vector<AlgData> data;
    data.reserve(30);
    sf::Vector2f position = sf::Vector2f(0.0f, 10.f);
    for (int i = 0; i < 30; i++)
    {
        data.emplace_back(i, position, texture, font);

        position.x += 64.f;
        if (position.x > 950)
        {
            position.x = 0.0f;
            position.y += 65.0f;
        }
    }


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyReleased)
            {
                if (event.key.code == sf::Keyboard::Space)
                {
                    // Binary Search
                    BinarySearch search(data, window);
                    for (AlgData obj : data)
                        obj.SetSearchState(State::EMPTY);
                    search.OnRun(29, sf::milliseconds(100));
                }                
                if (event.key.code == sf::Keyboard::A)
                {
                    // Simple Search
                    SimpleSearch search(data, window);
                    for (AlgData obj : data)
                        obj.SetSearchState(State::EMPTY);
                    search.OnRun(29, sf::milliseconds(100));
                }
                if (event.key.code == sf::Keyboard::R)
                {
                    for (AlgData& obj : data)
                        obj.SetSearchState(State::EMPTY);
                    std::cout << "reset" << std::endl;
                }
            }
       
        }

        window.clear();
        for (size_t i = 0; i < data.size(); i++)
        {
            window.draw(data[i].GetSprite());
            window.draw(data[i].GetText());
        }
        window.display();
    }

    return 0;
}