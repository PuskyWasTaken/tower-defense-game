#pragma once
#include"IStateClass.h"
#include"Button.h"
#include"Globals.h"
#include"..\Logging\Logging.h"

class MultiplayerScreen : public IStateClass
{
private:
	Button m_instructions;
	Button m_defender;
	Button m_attacker;
	void chosePlayer(const sf::Vector2f& mousePosition);

public:
	MultiplayerScreen();
	~MultiplayerScreen();

public:
	void update(sf::RenderWindow &window) override;
	void draw(sf::RenderWindow &window) override;
	void handleEvent(sf::RenderWindow &window) override;
};

