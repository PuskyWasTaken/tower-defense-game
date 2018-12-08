#include "stdafx.h"
#include "CppUnitTest.h"
#include"SFML/Graphics.hpp"
#include"../TowerDefenceGame/Button.h"
#include"../TowerDefenceGame/Globals.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Tests
{
	TEST_CLASS(ButtonTest)
	{
	public:

		TEST_METHOD(DefaultConstructor)
		{
			Button button(sf::Vector2f(10, 10), sf::Vector2f(250, 100));
			Assert::IsTrue(button.getHitbox().getSize() == Globals::mainMenuButtonSize);
		}
	};
}
