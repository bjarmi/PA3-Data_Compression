#include <iostream>
#include <queue>
#include <map>
#include <string>

#ifndef PA3_DATA_COMPRESSION_ENCODER_H
#define PA3_DATA_COMPRESSION_ENCODER_H

class Encoder
{

private:

	string _input_file;
	string _output_file;

	void encode();

	std::priority_queue<SaplingNode> _build_frequency(std::string filename);

	SaplingNode _build_tree(std::priority_queue<SaplingNode> heap);


public:

	Encoder(string input_file, string output_file);

	std::map<std::string, std::string> build_lexicon(SaplingNode tree);

};

#endif //PA3_DATA_COMPRESSION_ENCODER_H
