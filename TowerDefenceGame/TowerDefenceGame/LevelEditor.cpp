#include "LevelEditor.h"
#include "Application.h"




LevelEditor::LevelEditor()
{
}


LevelEditor::~LevelEditor()
{
}

void LevelEditor::update(sf::RenderWindow &window)
{
	handleEvent(window);
}

void LevelEditor::draw(sf::RenderWindow & window)
{
}

void LevelEditor::handleEvent(sf::RenderWindow &window)
{
	if (sf::Mouse::isButtonPressed)
		sf::Mouse::getPosition(window);
}



