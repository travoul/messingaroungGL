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
	float size = 50.f;

	sf::RenderWindow window(sf::VideoMode(1280, 760), "Messing Around!",sf::Style::Close,settings);
	sf::CircleShape shape(size);
	shape.setFillColor(sf::Color::Green);
	sf::Event event;
	bool running = true;
	int x0,y0,xf,yf;
	xf=yf=0;
	int push = 0;
	sf::Mouse mouse;

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
				x0 = mouse.getPosition(window).x;
				y0 = mouse.getPosition(window).y;
				std::cout << "X: " << x0 << "\tY :" << y0 << std::endl;
				xf -= x0;
				yf -=y0;
				if(xf>)xf = x0 ;
				if(xf<x0)xf = x0 ;
				if(yf>x0)xf = y0 ;
				if(yf<x0)xf = y0 ;
				
				std::cout << "Xf: " << xf << "\tYf: " << yf << std::endl;
				if (push == 1){
					shape.setPosition(mouse.getPosition(window).x,mouse.getPosition(window).y);
				}
				break;

				case sf::Event::MouseWheelMoved:

				shape.scale(1.2,1.2);

				break;
				case sf::Event::MouseButtonPressed:
				push=1;
				xf =x0 = mouse.getPosition(window).x;
				yf =y0 = mouse.getPosition(window).y;

				
				break;

				case sf::Event::MouseButtonReleased:
				std::cout << "Drop" << std::endl;
				push = 0;
				break;
			}
		}

		window.clear();
		window.draw(shape);
		window.display();
	}

	return 0;
}