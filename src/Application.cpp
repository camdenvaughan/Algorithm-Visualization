#include <SFML/Graphics.hpp>
#include <ctime>

#include "Renderer.h"
#include "BinaryScene.h"
#include "SimpleScene.h"
#include "SelectionScene.h"
#include "MenuScene.h"

int main()
{
    srand((unsigned int)time(NULL));

    unsigned int windowWidth = 2000;
    unsigned int windowHeight = 1300;

    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Algorithms", sf::Style::Default);

    Renderer::LoadTexture("res/textures/textures.png");
    Renderer::LoadFont("res/fonts/coolvetica/coolvetica rg.ttf");

    Scene* activeScene = nullptr;
    MenuScene* menuScene = new MenuScene(windowWidth, windowHeight);
    BinaryScene* binaryScene = nullptr;
    SimpleScene* simpleScene = nullptr;
    SelectionScene* selectionScene = nullptr;
    //QuickScene* quickScene = new QuickScene(windowWidth, windowHeight);

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
                menuScene = new MenuScene(windowWidth, windowHeight);
                activeScene = (Scene*)menuScene;
                break;
            case SceneState::BINARY:
                delete activeScene;
                binaryScene = new BinaryScene(windowWidth, windowHeight);
                activeScene = (Scene*)binaryScene;
                break;
            case SceneState::SIMPLE:
                delete activeScene;
                simpleScene = new SimpleScene(windowWidth, windowHeight);
                activeScene = (Scene*)simpleScene;
                break;
            case SceneState::SELECTION:
                delete activeScene;
                selectionScene = new SelectionScene(windowWidth, windowHeight);
                activeScene = (Scene*)selectionScene;
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