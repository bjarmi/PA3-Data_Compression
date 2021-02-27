#include <iostream>
#include <queue>
#include <map>
#include <string>

#include "../headers/sapling_node.h"

#ifndef PA3_DATA_COMPRESSION_ENCODER_H
#define PA3_DATA_COMPRESSION_ENCODER_H

class Encoder
{

private:

	std::string _input_file;
	std::string _output_file;

	void encode();

	std::priority_queue<SaplingNode> _build_frequency();

	SaplingNode _build_tree(std::priority_queue<SaplingNode> heap);

    std::map<char, int> count_frequency();

    static void _get_codes(SaplingNode* node, std::string code,
                    std::map<std::string, std::string>* map);


public:

	Encoder(std::string input_file, std::string output_file);

	std::map<std::string, std::string> build_lexicon(SaplingNode* tree);
};

#endif //PA3_DATA_COMPRESSION_ENCODER_H
