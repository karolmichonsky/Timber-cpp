#include "window.h"

void Window::initWindow()
{
	this->videoMode.height = 600;
	this->videoMode.width = 800;
	this->videoMode.getDesktopMode;
	this->window = new sf::RenderWindow(this->videoMode, "TimberTime");
	this->window->setFramerateLimit(60);
}

Window::Window() {
	this->window = nullptr;
}

Window::~Window() {
	delete this->window;
}