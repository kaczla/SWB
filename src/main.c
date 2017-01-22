#include <stdio.h>
#include "update.h"
#include "print.h"

int main (int argc, char **argv)
{
	init(argc, argv);
	print();
	while (runned)
	{
		update();
		if (refresh)
		{
			print();
		}
	}
	clean();
	return 0;
}
