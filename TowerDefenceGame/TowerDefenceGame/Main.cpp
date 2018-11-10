#include <iostream>
#include <conio.h>

#include "Application.h"


int main(int argc, char**argv)
{
	/* Instantiate our application (game) */
	Application application("New Window", 400, 400);

	/* Run it */
	application();

	_getch();
	return 0;
}