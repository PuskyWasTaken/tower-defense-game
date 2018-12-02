#pragma once
#include "Panel.h"
#include "Button.h"
class LevelEditorPanel :
	public Panel
{
public:
	LevelEditorPanel();
	~LevelEditorPanel();


public:
	Intersection northIntersection;
	Intersection southIntersection;
	Intersection westIntersection;
	Intersection eastIntersection;
	
	std::vector<Intersection> m_genericIntersections;

	Button northButton;
	Button southButton;
	Button westButton;
	Button eastButton;

	Button instructions;

	std::vector<Button> m_genericButtons;
};

