#include <SFML/Graphics.hpp>
#include <ctime>

#include "Renderer.h"
#include "BinaryScene.h"
#include "SimpleScene.h"
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
    BinaryScene* binaryScene = new BinaryScene(windowWidth, windowHeight);
    SimpleScene* simpleScene = new SimpleScene(windowWidth, windowHeight);
    //SelectionScene* selectionScene = new SelectionScene(windowWidth, windowHeight);
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
                activeScene = (Scene*)menuScene;
                break;
            case SceneState::BINARY:
                activeScene = (Scene*)binaryScene;
                break;
            case SceneState::SIMPLE:
                activeScene = (Scene*)simpleScene;
                break;
            }
        }
        activeScene->OnUpdate(1);
        window.clear();
        window.draw(*activeScene);
        window.display();
    }
    delete menuScene;
    //delete binaryScene;
    //delete simpleScene;
    return 0;
}