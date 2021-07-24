#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <ctime>

//#include "Renderer.h"
#include "algorithms/AlgData.h"
#include "algorithms/BinarySearch.h"
#include "algorithms/SimpleSearch.h"
#include "algorithms/SelectionSort.h"
#include "algorithms/QuickSort.h"
#include "BinaryScene.h"
#include "MenuScene.h"

int main()
{
    srand((unsigned int)time(NULL));

    unsigned int windowWidth = 2000;
    unsigned int windowHeight = 1300;

    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Algorithms", sf::Style::Default);
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
    int vectorSize = 30;
    data.reserve(vectorSize);

    std::vector<int> valueVector;
    for (int i = 0; i < vectorSize; i++)
    {
        valueVector.push_back(i);
    }

   // std::random_shuffle(valueVector.begin(), valueVector.end());

    for (int i = 0; i < 30; i++)
        data.emplace_back(valueVector[i], sf::Vector2f(0.0f, 10.f), texture, font);
    Helpers::OrganizePositions(data, sf::Vector2f(0.0f, 10.f));

    Scene* activeScene;
    MenuScene* menuScene = new MenuScene();
    BinaryScene* binaryScene = new BinaryScene();
    activeScene = (Scene*)menuScene;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyReleased)
            {
                // Randomize Items
                if (event.key.code == sf::Keyboard::Space)
                {
 
                    activeScene = (Scene*)binaryScene;

                    //for (AlgData& obj : data)
                    //    obj.SetSearchState(State::EMPTY);
                    //std::random_shuffle(valueVector.begin(), valueVector.end());
                    //for (int i = 0; i < valueVector.size(); i++)
                    //    data[i].SetValue(valueVector[i]);
                }
                // Binary Search
                //if (event.key.code == sf::Keyboard::Q)
                //{
                //    BinarySearch search(data, window);
                //    for (AlgData& obj : data)
                //        obj.SetSearchState(State::EMPTY);
                //    search.OnRun(29, sf::milliseconds(100));
                //}
                //// Simple Search
                //if (event.key.code == sf::Keyboard::W)
                //{
                //    SimpleSearch search(data, window);
                //    for (AlgData& obj : data)
                //        obj.SetSearchState(State::EMPTY);
                //    search.OnRun(29, sf::milliseconds(100));

                //}
                //// Selection Sort
                //if (event.key.code == sf::Keyboard::E)
                //{
                //    for (AlgData& obj : data)
                //        obj.SetSearchState(State::EMPTY);
                //    SelectionSort sort(data, window);
                //    sort.OnRun(10, sf::milliseconds(100));
                //}
                //if (event.key.code == sf::Keyboard::A)
                //{
                //    for (AlgData& obj : data)
                //        obj.SetSearchState(State::EMPTY);
                //    QuickSort sort(data, window);
                //    sort.OnRun(10, sf::milliseconds(100));
                //    for (AlgData& obj : data)
                //        std::cout << obj.GetValue() << ", ";
                //    std::cout << std::endl;
                //}
                //// Reset Items
                //if (event.key.code == sf::Keyboard::R)
                //{
                //    activeScene = (Scene*)menuScene;
                //}
            }
       
        }
        //switch (activeScene->PollEvents(event))
        //{
        //case SceneState::DEFAULT:
        //    break;
        //case SceneState::MENU:
        //    activeScene = (Scene*)menuScene;
        //    break;
        //case SceneState::BINARY:
        //    activeScene = (Scene*)binaryScene;
        //    break;
        //}
        window.clear();
        window.draw(*activeScene);
        window.display();
    }
    delete menuScene;
    delete binaryScene;
    return 0;
}