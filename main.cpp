#define GLEW_S
#include <iostream>
#include <SFML/Graphics.hpp>
#include <GL/glew.h>

int main(int argc, char *argv[])
{
	sf::ContextSettings settings;
	settings.depthBits = 24;
	settings.stencilBits = 8;
	settings.antialiasingLevel = 2;

	sf::RenderWindow window(sf::VideoMode(1280, 760), "Messing Around!",sf::Style::Close,settings);
	sf::CircleShape shape(50.0f);
	shape.setFillColor(sf::Color::Blue);
	shape.setOrigin(50.0f,50.0f);
	shape.setPosition(1280.0/2.0,760/2.0);
	sf::Event event;
	bool running = true;
	bool isObjectSelected = false;

	while (running)
	{
		while (window.pollEvent(event))
		{
			switch(event.type)
			{
				case sf::Event::Closed:
				running = false;
				break;

				case sf::Event::MouseMoved:
					if (isObjectSelected){
						shape.setPosition(sf::Mouse::getPosition(window).x,sf::Mouse::getPosition(window).y);
					}
				break;

				case sf::Event::MouseWheelMoved:
					shape.scale(1.05f,1.05f);
				break;

				case sf::Event::MouseButtonPressed:
					isObjectSelected = true;
				break;

				case sf::Event::MouseButtonReleased:
					isObjectSelected = false;
				break;
			}
		}

		window.clear();
		window.draw(shape);
		window.display();
	}

	return 0;
}