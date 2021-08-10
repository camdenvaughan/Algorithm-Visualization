#include <SFML/Graphics.hpp>

#include "Renderer.h"
#include "BinaryScene.h"
#include "SimpleScene.h"
#include "SelectionScene.h"
#include "QuickScene.h"
#include "MenuScene.h"

int main()
{
    unsigned int windowWidth = 1000;
    unsigned int windowHeight = 900;

    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Algorithms", sf::Style::Default);

    Renderer::LoadTexture("res/textures/textures.png");
    Renderer::LoadFont("res/fonts/coolvetica/coolvetica rg.ttf");

    Scene* activeScene = nullptr;
    MenuScene* menuScene = new MenuScene(windowWidth, windowHeight);
    BinaryScene* binaryScene = nullptr;
    SimpleScene* simpleScene = nullptr;
    SelectionScene* selectionScene = nullptr;
    QuickScene* quickScene = nullptr;

    activeScene = menuScene;
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
                delete activeScene;
                activeScene = new MenuScene(windowWidth, windowHeight);
                break;
            case SceneState::BINARY:
                delete activeScene;
                activeScene = new BinaryScene(windowWidth, windowHeight);
                break;
            case SceneState::SIMPLE:
                delete activeScene;
                activeScene = new SimpleScene(windowWidth, windowHeight);
                break;
            case SceneState::SELECTION:
                delete activeScene;
                activeScene = new SelectionScene(windowWidth, windowHeight);
                break;
            case SceneState::QUICK:
                delete activeScene;
                activeScene = new QuickScene(windowWidth, windowHeight);
                break;
            }
        }
        activeScene->OnUpdate(1);
        window.clear();
        window.draw(*activeScene);
        window.display();
    }
    delete activeScene;

    return 0;
}