#include "MainMenu.h"
#include"Enemy.h"

MainMenu::MainMenu()
{	
	startButton.setColour(sf::Color::Red);

	/* What the ... is this? */
	//startButton.setFont(startButton.getFont());

	/* TIP: Don't try to use std::Vector if you don't know how it works. */

	startButton.setText("Start");
	startButton.setSize(sf::Vector2f(100, 50));
	startButton.setCenterPosition(sf::Vector2f(200, 60));
	startButton.text.setPosition(startButton.getPosition());
	startButton.text.move(sf::Vector2f(0, startButton.getHeight() / 4));

	levelEditorButton.setText("Level Editor");
	levelEditorButton.setSize(sf::Vector2f(100, 50));
	levelEditorButton.setCenterPosition(sf::Vector2f(200, 160));
	levelEditorButton.text.setPosition(levelEditorButton.getPosition());

	exitButton.setText("Exit");
	exitButton.setSize(sf::Vector2f(100, 50));
	exitButton.setCenterPosition(sf::Vector2f(200, 260));
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
}
