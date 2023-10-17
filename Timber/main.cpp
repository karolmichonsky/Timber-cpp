#include <iostream>
#include <cstdlib>
#include <queue>
#include <conio.h>
#include <ctime>
#include <time.h> 
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp> 

using namespace std;

void branchUpdate(queue<int> branches) {
	srand(time(0));
	int random = (rand() % 3);
	branches.pop();
	branches.push(random);
}

void displayBranches(queue<int> branches) {
	system("cls");
	queue<int> displayBranches(branches);
	for (int i = 0; i < 5; i++) {
		if (displayBranches.front() == 0) {
			cout << "--[   ]  " << endl;
		}
		else if (displayBranches.front() == 1) {
			cout << "  [   ]--  " << endl;
		}
		else {
			cout << "  [   ]" << endl;
		}
		displayBranches.pop();
	}
	
}

int main(void) {
	
	sf::Window window(sf::VideoMode(800, 600), "TimberTime");
	srand(time(0));
	queue<int> branches;
	
	for (int i = 0; i < 5; i++) {
		
		int random = (rand() % 3);
		cout << random;
		branches.push(random);
	}
	displayBranches(branches);

	while (window.isOpen()) {
		sf::Event event;
		displayBranches(branches);
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
			if (event.type == sf::Event::KeyPressed) {
				if (event.key.code == sf::Keyboard::A) {
					if (branches.front() == 0) {
						window.close();
					}	
					int random = (rand() % 3);
					branches.pop();
					branches.push(random);
				}
				else if (event.key.code == sf::Keyboard::D) {
					if (branches.front() == 1) {
						window.close();
					}
					int random = (rand() % 3);
					branches.pop();
					branches.push(random);
				}
			}		
		}
	}
	system("pause");
	return 0;
	}