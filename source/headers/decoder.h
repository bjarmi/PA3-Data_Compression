#include <iostream>
#include <string>
#include <map>

#ifndef PA3_DATA_COMPRESSION_DECODER_H
#define PA3_DATA_COMPRESSION_DECODER_H

class Decoder
{

private:

	std::string _input_file;
	std::string _output_file;
	std::map<std::string, std::string> _lexicon;

	std::map<std::string, std::string> _get_lexicon();

	void _decode();

	void _write_lexicon();

	void _parse_encoding();

	void _write(const std::string& code);

	int _get_code_start_index();

	void _parse(std::ifstream& in_file, std::string& buffer);

public:

	Decoder(std::map<std::string, std::string> lexicon,
	        std::string input_file,
	        std::string output_file);

	Decoder(std::string input_file, std::string output_file);

};

#endif //PA3_DATA_COMPRESSION_DECODER_H
