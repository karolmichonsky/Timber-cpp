#include "Game.h"

int main(void) {
	
	srand(static_cast<unsigned>(time(NULL)));	

	Game game;
	sf::Clock clock;

	while (game.running()) {
		
		game.update();

		
		if (clock.getElapsedTime().asMilliseconds() > 2000 && game.isChopping == 1) {
			game.isChopping = 0;
			clock.restart();
		}

		game.lumberAnimation();

		game.render();
	}
	return 0;
}