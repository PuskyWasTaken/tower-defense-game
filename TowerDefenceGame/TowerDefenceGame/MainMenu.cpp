#include "MainMenu.h"
#include"Enemy.h"
#include<iostream> //to test mouse-button collision

MainMenu::MainMenu()
{	
	startButton.setColour(sf::Color::Red);

	/* What the ... is this? */
	//startButton.setFont(startButton.getFont());

	/* TIP: Don't try to use std::Vector if you don't know how it works. */

	startButton.setText("Start");
	startButton.setSize(Globals::mainMenuButtonSize);
	startButton.setCenterPosition(sf::Vector2f(Globals::windowSize.x / 2, Globals::windowSize.y/2 - Globals::mainMenuButtonSize.y*4 ));
	startButton.text.setPosition(startButton.getPosition());

	levelEditorButton.setText("Level Editor");
	levelEditorButton.setSize(Globals::mainMenuButtonSize);
	levelEditorButton.setCenterPosition(sf::Vector2f(startButton.getCenter().x, startButton.getCenter().y + Globals::mainMenuButtonSize.y * 1.5));
	levelEditorButton.text.setPosition(levelEditorButton.getPosition());

	exitButton.setText("Exit");
	exitButton.setSize(Globals::mainMenuButtonSize);
	exitButton.setCenterPosition(sf::Vector2f(levelEditorButton.getCenter().x, levelEditorButton.getCenter().y + Globals::mainMenuButtonSize.y * 1.5));
	exitButton.text.setPosition(exitButton.getPosition());


}

MainMenu::~MainMenu()
{
}

void MainMenu::update(sf::RenderWindow & window)
{
	handleEvent(window);
}

void MainMenu::draw(sf::RenderWindow & window)
{
	window.draw(startButton);
	window.draw(levelEditorButton);
	window.draw(exitButton);

}

void MainMenu::handleEvent(sf::RenderWindow & window)
{
	sf::RectangleShape mouseRect;
	sf::Vector2f mousePositionOnWindow = mouseRect.getPosition();
	mousePositionOnWindow = static_cast<sf::Vector2f>(sf::Mouse::getPosition(window));
	mouseRect.setPosition(mousePositionOnWindow);



		if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
		{
			if (startButton.isCollisonWithPoint(sf::Vector2f(sf::Mouse::getPosition(window))))
			{
				Application::getInstance()->setState(std::make_unique<Game>());
			}
			if (levelEditorButton.isCollisonWithPoint(sf::Vector2f(sf::Mouse::getPosition(window))))
			{
				Application::getInstance()->setState(std::make_unique<LevelEditor>());
			}
			if (exitButton.isCollisonWithPoint(sf::Vector2f(sf::Mouse::getPosition(window))))
			{
				std::cout << "Sorry, ran out of money for documentation on how to do this\n";
			}
		}
}
