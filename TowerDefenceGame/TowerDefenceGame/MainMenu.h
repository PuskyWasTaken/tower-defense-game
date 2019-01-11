#pragma once
#include "Application.h"
#include "Button.h"
#include "Enemy.h"
#include "Game.h"
#include "LevelEditor.h"
#include <iostream>
#include "../Logging/Logging.h"
#include "LevelSelector.h"
#include"MultiplayerScreen.h"

class MainMenu : public IStateClass
{
public:
	MainMenu();
	~MainMenu();

private:
	Button startButton, multiplayerButton, levelEditorButton, exitButton;
	Button gameName;

public:

	void update(sf::RenderWindow &window);
	void draw(sf::RenderWindow &window);
	void handleEvent(sf::RenderWindow &window);
};

