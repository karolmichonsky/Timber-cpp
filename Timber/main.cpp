#include "Game.h"
#include "Menu.h"

int main(void) {
	
	srand(static_cast<unsigned>(time(NULL)));	

	Window win;
	Game game;
	Menu menu;
	sf::Clock clock;
	//menu.updateMenu();
	while (game.running()) {
		switch(menu.accessGameState()){
			case 0:
				/*cout << menu.accessGameState();
				menu.updateMenu();
				break;*/
			case 1:
				game.update();
				if (clock.getElapsedTime().asMilliseconds() > 2000 && game.getIsChopping() == 1) {
					game.setIsChopping();
					clock.restart();
				}
				game.lumberAnimation();
				game.render();
				break;
			case 2:
				cout << "aa";
		}
	}
	return 0;
}