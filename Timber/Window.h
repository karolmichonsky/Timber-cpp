#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp> 

using namespace std;

#include <iostream>

class Window
{
public:
	sf::RenderWindow* window;
	sf::VideoMode videoMode;

	void initWindow();
	Window();
	virtual ~Window();
};

