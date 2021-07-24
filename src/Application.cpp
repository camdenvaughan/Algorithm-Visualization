#include <SFML/Graphics.hpp>
#include <ctime>

#include "Renderer.h"
#include "BinaryScene.h"
#include "MenuScene.h"

int main()
{
    srand((unsigned int)time(NULL));

    unsigned int windowWidth = 2000;
    unsigned int windowHeight = 1300;

    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Algorithms", sf::Style::Default);

    Renderer::GetInstance().LoadTexture("res/textures/textures.png");
    Renderer::GetInstance().LoadFont("res/fonts/coolvetica/coolvetica rg.ttf");

    Scene* activeScene;
    MenuScene* menuScene = new MenuScene();
    BinaryScene* binaryScene = new BinaryScene();
    activeScene = (Scene*)menuScene;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch (activeScene->PollEvents(event, sf::Mouse::getPosition(window)))
            {
            case SceneState::CLOSE:
                window.close();
                break;
            case SceneState::DEFAULT:
                break;
            case SceneState::MENU:
                activeScene = (Scene*)menuScene;
                break;
            case SceneState::BINARY:
                activeScene = (Scene*)binaryScene;
                break;
            }
        }

        window.clear();
        window.draw(*activeScene);
        window.display();
    }
    delete menuScene;
    delete binaryScene;
    return 0;
}