#include <cstring>
#include "headers/encoder.h"
#include "headers/decoder.h"

int main(int argc, char** argv)
{
	if (argc == 4)
	{
		if (std::strcmp(argv[1], "-e") == 0)
		{
			Encoder encoder(argv[2], argv[3]);
		}

		if (std::strcmp(argv[1], "-d") == 0)
		{
			Decoder decoder(argv[2], argv[3]);
		}
	}

	return 0;
}
