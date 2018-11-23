#include "MainMenu.h"
#include"Enemy.h"

MainMenu::MainMenu()
{
	Button startButton, levelEditorButton, exitButton;

		if (!startButton.getFont().loadFromFile("C:\\Windows\\Fonts\\arial.ttf"))
		{
			exit(1);
		}
	
	startButton.setColour(sf::Color::Red);
	startButton.setFont(startButton.getFont());
	startButton.getText().setString("Play");
	startButton.getText().setPosition(200, 60);
	startButton.setSize(sf::Vector2f(100, 50));
	startButton.setCenterPosition(sf::Vector2f(200, 60));
	menuButtons.push_back(startButton);

	levelEditorButton.setColour(sf::Color::Blue);
	levelEditorButton.setFont(startButton.getFont());
	levelEditorButton.getText().setString("Levels");
	levelEditorButton.setSize(sf::Vector2f(100, 50));
	levelEditorButton.setCenterPosition(sf::Vector2f(200, 160));
	menuButtons.push_back(levelEditorButton);

	exitButton.setColour(sf::Color::Green);
	exitButton.setFont(startButton.getFont());
	exitButton.getText().setString("Exit");
	exitButton.setSize(sf::Vector2f(100, 50));
	exitButton.setCenterPosition(sf::Vector2f(200, 260));
	menuButtons.push_back(exitButton);

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
	for (Button ourButton : menuButtons)
		window.draw(ourButton);

}

void MainMenu::handleEvent(sf::RenderWindow & window)
{
}
