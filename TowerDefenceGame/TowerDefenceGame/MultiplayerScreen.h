#pragma once
#include"IStateClass.h"
#include"Button.h"
#include"Globals.h"
#include "TextBox.h"
#include"..\Logging\Logging.h"

class MultiplayerScreen : public IStateClass
{
private:
	Button m_instructions;
	Button m_defender;
	Button m_attacker;
	TextBox m_textBox;

public:
	MultiplayerScreen();
	~MultiplayerScreen();

public:
	void update(sf::RenderWindow &window) override;
	void draw(sf::RenderWindow &window) override;
	void handleEvent(sf::RenderWindow &window) override;

private:
	bool chosePlayer(const sf::Vector2f& mousePosition);
	void updateTextBoxFocus(sf::RenderWindow &window);
};

