#include "Game.h"
#include "Menu.h"
#include "Leaderboard.h"

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

int main(void) {
	
	srand(static_cast<unsigned>(time(NULL)));	

	
	sf::VideoMode vm(800, 600);
	sf::RenderWindow window(vm, "Timber");
	window.setFramerateLimit(60);

	Menu menu(&window);
	Game game(&window, &menu);
	Leaderboard leaderboard(int points);
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
				if (game.getLoseTimer() == 0.0f) {
					menu.backToMenu();
				}
				break;
			case 3:
				window.close();
		}
	}
	return 0;
}