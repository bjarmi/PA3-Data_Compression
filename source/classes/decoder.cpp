#include <string>
#include <map>
#include <fstream>
#include <sstream>
#include <iostream>
#include "../headers/decoder.h"

Decoder::Decoder(std::map<std::string, std::string>& lexicon,
                 std::string& input_file, std::string& output_file)
{
	_lexicon = lexicon;
	_input_file = input_file;
	_output_file = output_file;
	_decode();

}

Decoder::Decoder(std::string& input_file, std::string& output_file)
{
	_input_file = input_file;
	_output_file = output_file;
	_get_lexicon();
	_parse_encoding();
}

// Initiate decoding instructions.
void Decoder::_decode()
{
	_write_lexicon();
	_parse_encoding();
}

// Todo: Remove Try/Catch -> Use "if (file.is_open()) else throw <error>".
// Read lexicon from file header.
std::map<std::string, std::string> Decoder::_get_lexicon()
{

	std::map<std::string, std::string> payload;
	std::string key, value;

	try
	{
		std::ifstream file(_input_file);

		while (file >> key >> value)
			payload[key] = value;

		file.close();
		return payload;
	}

	catch (std::ifstream::failure& error)
	{
		throw error;
	}

}

// Decode from input_file to output_file with the lexicon.
void Decoder::_parse_encoding()
{
	try
	{
		std::ifstream in_file(_input_file);
		std::string buffer;
		int start_index = _get_code_start_index();

		// Todo: Read from start_index to end of file.

		_parse(in_file, buffer);
	}

	catch (std::ifstream::failure& error)
	{
		throw error;
	}
}

// Attempt to parse an encoded symbol.
void Decoder::_parse(std::ifstream& in_file, std::string& buffer)
{
	char symbol;

	while (in_file >> symbol)
	{
		buffer.append(reinterpret_cast<const char*>(symbol));

		if (_lexicon.count(buffer))
		{
			_write(buffer);
			buffer.clear();
		}
	}
}

// Write lexicon to file.
void Decoder::_write_lexicon()
{
	std::ostringstream payload;

	for (auto const& pair : _lexicon)
		payload << pair.first << " " << pair.second << "\n";

	payload << "\\\n";
	_write(payload.str());

}

// Write code to file.
void Decoder::_write(const std::string& text)
{
	std::ofstream file(_input_file, std::ios::app);

	if (file.is_open())
	{
		file << text;
		file.close();
	}

}

// Todo: Returns the index that marks where the code in the input file starts.
int Decoder::_get_code_start_index()
{
	// Todo: Read until encountering 'backslash + newline'.
	// Todo: Return next index after that encounter.
	return 0;
}
