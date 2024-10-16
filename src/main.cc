#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(600, 600), "Maze", sf::Style::Default);
    //sf::CircleShape shape(300.f);
    //shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

	sf::RectangleShape r1(sf::Vector2f(100,200));
	sf::RectangleShape r2(sf::Vector2f(100,50));
	r2.setFillColor(sf::Color::Green);
	r1.setFillColor(sf::Color::Red);
        window.clear(sf::Color::Blue);
        window.draw(r1);
        window.draw(r2);
        window.display();
    }

    return 0;
}
