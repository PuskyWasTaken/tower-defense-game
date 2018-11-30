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
};

