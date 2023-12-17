#include "Theme.h"

Theme::Theme(sf::RenderWindow* window, Game* game, Menu* menu) : menu(menu), game(game)
{

	this->window = window;
	initCheckBox(styleClassic, 150, sf::Color(0, 64, 0));
	initCheckBox(styleWinter, 300, sf::Color(255, 250, 250));
	initCheckBox(styleHell, 450, sf::Color(125, 14, 14));
	initCheckBox(styleVoid, 600, sf::Color(138, 43, 226));
	initBack();
	helpStyle.push_back(styleClassic);
	helpStyle.push_back(styleWinter);
	helpStyle.push_back(styleHell);
	helpStyle.push_back(styleVoid);
}

void Theme::pollEvents()
{
	while (this->window->pollEvent(this->event)) {
		if (this->event.type == sf::Event::Closed) {
			this->window->close();
		}
		if (this->event.type == sf::Event::KeyPressed) {
			if (themeMenuPos == 0) {
				if (event.key.code == sf::Keyboard::D || event.key.code == sf::Keyboard::Right) {
					checkboxPos += 1;
					if (checkboxPos > 3) {
						checkboxPos = 0;
					}
				}
				if (event.key.code == sf::Keyboard::A || event.key.code == sf::Keyboard::Left) {
					checkboxPos -= 1;
					if (checkboxPos < 0) {
						checkboxPos = 3;
					}
				}
				if (event.key.code == sf::Keyboard::Enter) {
					changeStyle();
				}
			}
			
			if (event.key.code == sf::Keyboard::S || event.key.code == sf::Keyboard::Down) {
				themeMenuPos += 1;
				if (themeMenuPos > 1) {
					themeMenuPos = 0;
				}
			}
			if (event.key.code == sf::Keyboard::W || event.key.code == sf::Keyboard::Up) {
				themeMenuPos -= 1;
				if (themeMenuPos < 0) {
					themeMenuPos = 1;
				}
			}
			if (event.key.code == sf::Keyboard::Enter && themeMenuPos == 1 || event.key.code == sf::Keyboard::Escape) {
				menu->backToMenu();
				themeMenuPos = 0;
				checkboxPos = 0;
			}
		}
	}
}

void Theme::currentCheckBox()
{
	
	if (themeMenuPos == 0) {
		helpStyle[0].setOutlineColor(sf::Color(220, 220, 220));
		helpStyle[1].setOutlineColor(sf::Color(220, 220, 220));
		helpStyle[2].setOutlineColor(sf::Color(220, 220, 220));
		helpStyle[3].setOutlineColor(sf::Color(220, 220, 220));	
		helpStyle[checkboxPos].setOutlineColor(sf::Color::Red);
	}
	if (themeMenuPos == 1) {
		textBack.setFillColor(sf::Color::Red);
		helpStyle[checkboxPos].setOutlineColor(sf::Color(220, 220, 220));
	}
	else {
		textBack.setFillColor(sf::Color::White);
	}
}

void Theme::changeStyle()
{
	switch (checkboxPos) {
	case 0:
		game->setStyle(sf::Color(55, 29, 16), sf::Color(0, 64, 0), sf::Color(85, 172, 238));
		break;
	case 1:
		game->setStyle(sf::Color(20, 13, 7), sf::Color(255, 250, 250), sf::Color(48, 96, 133));
		break;
	case 2:
		game->setStyle(sf::Color(42, 0, 0), sf::Color(125, 14, 14), sf::Color(255, 76, 0));
		break;
	case 3:
		game->setStyle(sf::Color(75, 0, 130), sf::Color(138, 43, 226), sf::Color(0, 0, 0));
		break;
	}
}

void Theme::initCheckBox(sf::RectangleShape& box, int boxXPos, sf::Color boxColor)
{
	box.setFillColor(boxColor);
	box.setOutlineColor(sf::Color(220, 220, 220));
	box.setOutlineThickness(2);
	box.setPosition(boxXPos, 250);
	box.setSize(sf::Vector2f(50, 50));
}

void Theme::initBack()
{
	font.loadFromFile("GAMERIA.ttf");
	textBack.setFont(font);
	textBack.setString("Powrot");
	rect = textBack.getGlobalBounds().getSize();
	textBack.setPosition(400 - rect.x / 2, 350);
}

void Theme::mainStyle()
{
	
	pollEvents();
	window->clear(sf::Color(85, 172, 238));
	currentCheckBox();
	for (auto& e : helpStyle) {
		window->draw(e);
	}
	window->draw(textBack);
	window->display();
}
