#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

Vector2f WINDOW_SIZE = { 1800, 700 };
static const int LEFT_WHEEL_X = 220;
static const int LEFT_WHEEL_Y = 220;
static const int RIGHT_WHEEL_X = 560;
static const int RIGHT_WHEEL_Y = 220;
static const int RADIUS_WHEEL = 50;
static const float CIRCLE_LENGTH = RADIUS_WHEEL * 2 * M_PI;