
#include "headers/encoder.h"

int main(int argc, char** argv)
{
	if (argc == 4)
	{
		if (argv[1] == "-e")
		{
			return 0;
		}

		if (argv[1] == "-d")
			return 0;
	}

	return 0;
}
