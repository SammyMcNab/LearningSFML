#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Engine", sf::Style::Close | sf::Style::Titlebar);
    sf::CircleShape circle(100.0f);
    sf::CircleShape triangle(80.f, 3);
    sf::CircleShape square(80.f, 4);
    sf::CircleShape octagon(80.f, 8);

    triangle.setFillColor(sf::Color(100, 250, 50));
    triangle.setOrigin(80.f / 2, 80.f / 2);
    triangle.setPosition(sf::Vector2f(140, 140));

    square.setFillColor(sf::Color(250, 250, 50));
    square.setOrigin(80.f / 2, 80.f / 2);
    square.setPosition(sf::Vector2f(440, 140));

    octagon.setFillColor(sf::Color(0, 255, 255));
    octagon.setOrigin(80.f / 2, 80.f / 2);
    octagon.setPosition(sf::Vector2f(650, 140));

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
        //******************** UPDATE SECTION *************************

        //******************** DRAW SECTION *************************
        //clearing to red
        window.clear(sf::Color::Red);

        //**** ALL DRAWING HAPPENS BETWEEN CLEARING AND DISPLAYING
        window.draw(triangle);
        window.draw(square);
        window.draw(octagon);
        //display to window
        window.display();

        //******************** DRAW SECTION *************************
    }

    return 0;
}