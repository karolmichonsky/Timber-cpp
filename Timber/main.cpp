#include "Game.h"
#include "Menu.h"

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

int main(void) {
	
	srand(static_cast<unsigned>(time(NULL)));	

	sf::Vector2f videoSize(800, 600);
	sf::VideoMode vm(videoSize.x, videoSize.y);
	sf::RenderWindow window(vm, "Timber");
	window.setFramerateLimit(60);

	Game game(&window);
	Menu menu(&window);
	sf::Clock clock;

	while (game.running()) {
		switch(menu.accessGameState()){
			case -1:
				menu.updateMenu();
				break;
			case 0:
				game.update();
				if (clock.getElapsedTime().asMilliseconds() > 2000 && game.getIsChopping() == 1) {
					game.setIsChopping();
					clock.restart();
				}
				game.lumberAnimation();
				game.render();
				break;
			case 1:
				cout << "aa";
				break;
		}
	}
	return 0;
}