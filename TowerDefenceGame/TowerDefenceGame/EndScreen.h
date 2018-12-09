#pragma once
#include "IStateClass.h"

class EndScreen : public IStateClass
{
public:
	EndScreen();
	~EndScreen();

private:
	void update(sf::RenderWindow &window) override;
	void draw(sf::RenderWindow &window) override;
	void handleEvent(sf::RenderWindow &window) override;

};

