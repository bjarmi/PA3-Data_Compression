#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <sstream>
#include "../headers/decoder.h"

Decoder::Decoder(std::map<std::string, std::string> lexicon,
                 std::string input_file, std::string output_file)
{
	_lexicon = lexicon;
	_input_file = input_file;
	_output_file = output_file;
	_write_lexicon();
	_parse_encoding();
}

Decoder::Decoder(std::string input_file, std::string output_file)
{
	_input_file = input_file;
	_output_file = output_file;
	_get_lexicon();
	_parse_encoding();
}

// Initiate decoding instructions.
void Decoder::_decode()
{

}

// Read lexicon from file header.
std::map<std::string, std::string> Decoder::_get_lexicon()
{
	return std::map<std::string, std::string>();
}

// Parse code from input_file to output file with the lexicon.
void Decoder::_parse_encoding()
{

}

// Write lexicon from file header to file.
void Decoder::_write_lexicon()
{
	std::string payload;
	std::ifstream file(_input_file);

	if (file.is_open())
	{
		for (std::string line; getline(file, line);)
		{
			if (line == "\\")
				break;

			payload.append(line);
		}

		_write(payload);
	}
}

// Write code to file.
void Decoder::_write(const std::string& code)
{
	std::ofstream file(_input_file, std::ios::app);

	if (file.is_open())
	{
		file << code;
		file.close();
	}

}

