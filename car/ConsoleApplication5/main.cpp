#include <SFML/Graphics.hpp>
#include <iostream> 
#include <windows.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include "var.h"
#include "CarModel.h"

using namespace sf;
using namespace std;

void draw_objects(RenderWindow &window, CarModel &miniBus, RectangleShape background)
{
	window.clear();
	window.draw(background);
	window.draw(miniBus.bodyCarSprite);
	window.draw(miniBus.leftWheel);
	window.draw(miniBus.rightWheel);
	window.display();
}

void start_programm(RenderWindow &window, CarModel &miniBus, RectangleShape background)
{
	Clock clock;

	background.setSize(Vector2f(WINDOW_SIZE.x, WINDOW_SIZE.y));
	background.setPosition(0, 0);
	background.setFillColor(Color::White);

	while (window.isOpen()) {
		sf::Event event;
		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		time = time / 700;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
		}

		miniBus.counting_speed(event, time);
		draw_objects(window, miniBus, background);
	}
}

int main(){

	sf::RenderWindow window(sf::VideoMode(WINDOW_SIZE.x, WINDOW_SIZE.y), "Minibus");

	Texture bodyCarTexture, carWheelTexture;
	bodyCarTexture.loadFromFile("images/body.png");
	carWheelTexture.loadFromFile("images/wheel.png");

	CarModel miniBus;
	miniBus.bodyCarSprite.setTexture(bodyCarTexture);

	miniBus.leftWheel.setTexture(carWheelTexture);
	miniBus.leftWheel.setOrigin(RADIUS_WHEEL, RADIUS_WHEEL);

	miniBus.rightWheel.setTexture(carWheelTexture);
	miniBus.rightWheel.setOrigin(RADIUS_WHEEL, RADIUS_WHEEL);

	RectangleShape background;

	start_programm(window, miniBus, background);
	return 0;
}
