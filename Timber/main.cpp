#include "Game.h"
#include "Menu.h"

int main(void) {
	
	srand(static_cast<unsigned>(time(NULL)));	

	Game game;
	Menu menu;
	sf::Clock clock;

	while (game.running()) {
		switch(menu.accessGameState()){
			case 0:
				cout << "aa";
				break;
			case 1:
				game.update();
				if (clock.getElapsedTime().asMilliseconds() > 2000 && game.getIsChopping() == 1) {
					game.setIsChopping();
					clock.restart();
				}
				game.lumberAnimation();
				game.render();
				break;
		}
	}
	return 0;
}