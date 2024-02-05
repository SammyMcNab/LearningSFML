#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode(800, 600), "Engine", sf::Style::Close | sf::Style::Titlebar);
    sf::Texture playerTexture;
    sf::Sprite playerSprite;

    if (playerTexture.loadFromFile("assets/player/Textures/knight.png")) {

        std::cout << "Player image loaded successfully\n";
        playerSprite.setTexture(playerTexture);

        //X, Y, WIDTH, HEIGHT
        int xIndex = 0;
        int yIndex = 0;
        playerSprite.setTextureRect(sf::IntRect(xIndex * 32, yIndex * 32, 32, 32));
        playerSprite.scale(sf::Vector2f(3, 3));
    }
    else {
        std::cout << "Player image failed to load\n";
    }

    // run the program as long as the window is open
    while (window.isOpen())
    {
        //******************** UPDATE SECTION *************************
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }

        //sf::Vector2f position = playerSprite.getPosition();

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            sf::Vector2f position = playerSprite.getPosition();
            playerSprite.setPosition(position + sf::Vector2f(0.05, 0));
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            sf::Vector2f position = playerSprite.getPosition();
            playerSprite.setPosition(position + sf::Vector2f(-0.05, 0));
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
            sf::Vector2f position = playerSprite.getPosition();
            playerSprite.setPosition(position + sf::Vector2f(0, -0.05));
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            sf::Vector2f position = playerSprite.getPosition();
            playerSprite.setPosition(position + sf::Vector2f(0, 0.05));
        }
        //******************** UPDATE SECTION *************************

        //******************** DRAW SECTION *************************
        //clearing to red
        window.clear(sf::Color::Black);

        //**** ALL DRAWING HAPPENS BETWEEN CLEARING AND DISPLAYING
        window.draw(playerSprite);
        //display to window
        window.display();

        //******************** DRAW SECTION *************************
    }

    return 0;
}