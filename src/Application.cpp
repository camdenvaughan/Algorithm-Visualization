#include <SFML/Graphics.hpp>

#include "Resources.h"
#include "MenuScene.h"
#include "BinaryScene.h"
#include "SimpleScene.h"
#include "SelectionScene.h"
#include "QuickScene.h"
#include "BogaScene.h"

int main()
{
    // Window Size
    unsigned int windowWidth = 1000;
    unsigned int windowHeight = 900;

    // Create Window
    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Algorithms", sf::Style::Default);

    // Load Texture and Font into Renderer Singleton
    Resources::LoadTexture("res/textures/textures.png");
    Resources::LoadFont("res/fonts/coolvetica/coolvetica rg.ttf");

    // Create active scene pointer with a the menu as the current active scene
    Scene* activeScene =  new MenuScene(windowWidth, windowHeight);

    // Main Loop
    while (window.isOpen())
    {
        // Create SFML Event and check for Events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Lets scenes Poll for events and check for scene changes
            switch (activeScene->PollEvents(event, sf::Mouse::getPosition(window)))
            {
            case SceneState::CLOSE: // exit
                window.close();
                break;
            case SceneState::DEFAULT: // continue
                break;
            case SceneState::MENU: // set menu as active
                delete activeScene;
                activeScene = new MenuScene(windowWidth, windowHeight);
                break;
            case SceneState::BINARY: // set Binary Search Scene as active
                delete activeScene;
                activeScene = new BinaryScene(windowWidth, windowHeight);
                break;
            case SceneState::SIMPLE: // set Simple Search Scene as active
                delete activeScene;
                activeScene = new SimpleScene(windowWidth, windowHeight);
                break;
            case SceneState::SELECTION: // set Selection Sort Scene as active
                delete activeScene;
                activeScene = new SelectionScene(windowWidth, windowHeight);
                break;
            case SceneState::QUICK: // set Quick Sort Scene as active
                delete activeScene;
                activeScene = new QuickScene(windowWidth, windowHeight);
                break;
            case SceneState::BOGA:
                delete activeScene;
                activeScene = new BogaScene(windowWidth, windowHeight);
            }
        }

        // run the active scenes Update Method
        activeScene->OnUpdate();

        // Draw to window
        window.clear(sf::Color(132, 177, 184));
        window.draw(*activeScene);
        window.display();
    }

    delete activeScene;

    return 0;
}