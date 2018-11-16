#pragma once
#include "IStateClass.h"

#include <SFML\Graphics.hpp>


class LevelEditor :
	public IStateClass
{
public:
	LevelEditor();
	~LevelEditor();

	//TODO implement VertexArray sprites

private:
	sf::VertexArray sprites();  //TODO: to look after when sprite class is done
	sf::RenderTexture tiles();  //Tiles-> to pe converted in pgn



};

