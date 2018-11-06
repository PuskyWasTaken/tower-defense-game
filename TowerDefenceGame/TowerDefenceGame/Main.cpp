#include <iostream>
#include <conio.h>

#include "ManagedWindow.h"


int main(int argc, char**argv)
{
	/* Create our window */
	ManagedWindow window("New Window", 400, 400);

	/* Run it */
	window();

	_getch();
	return 0;
}