#include <iostream>
#include <conio.h>

#include "Application.h"


int main(int argc, char**argv)
{
	/* Instantiate our application (game) */
	Application application("Tower Defence Game!", Globals::windowSize.x, Globals::windowSize.y);

	/* Run it */
	application();

	_getch();
	return 0;
}