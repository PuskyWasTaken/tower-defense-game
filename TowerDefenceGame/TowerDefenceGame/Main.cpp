#include <iostream>
#include <conio.h>

#include "Application.h"


int main(int argc, char**argv)
{
	/* Instantiate our application (game) */
	Application application("Tower Defence Game!", 800, 800);

	/* Run it */
	application();

	_getch();
	return 0;
}