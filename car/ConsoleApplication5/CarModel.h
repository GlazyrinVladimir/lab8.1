#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

struct CarModel
{
	float acceleration = 0.0004;
	float rotation = 0;
	float speed = 0;

	Sprite bodyCarSprite;
	Sprite leftWheel;
	Sprite rightWheel;

	sf::Vector2f carCoordinate = { 0, 200 };

	void counting_speed(Event event, float time)
	{
		if (event.type == Event::KeyPressed && event.key.code == Keyboard::Right) {
			speed += acceleration * time;
		}
		else if (event.type == Event::KeyPressed && event.key.code == Keyboard::Left) {
			speed -= acceleration * time;
		}
		else {
			if (speed > 0)
				speed -= (acceleration * time) / 2;
			if (speed < 0)
				speed += (acceleration * time) / 2;
		}
		counting_rotation(event, time);
	}

	void counting_rotation(Event event, float time)
	{
		carCoordinate.x += speed;
		rotation = carCoordinate.x * 360 / CIRCLE_LENGTH;
		set_car_position();
	}

	void set_car_position()
	{
		rightWheel.setRotation(rotation);
		rightWheel.setPosition(carCoordinate.x + RIGHT_WHEEL_X, carCoordinate.y + RIGHT_WHEEL_Y);

		leftWheel.setRotation(rotation);
		leftWheel.setPosition(carCoordinate.x + LEFT_WHEEL_X, carCoordinate.y + LEFT_WHEEL_Y);

		bodyCarSprite.setPosition(carCoordinate);
	}
};