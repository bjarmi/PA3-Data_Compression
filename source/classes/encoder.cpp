#include <iostream>
#include <queue>
#include <utility>
#include <fstream>

#include "../headers/encoder.h"
#include "../headers/sapling_node.h"


/* --- Private --- */
// Counts the frequency of a letter in the input file.
std::map<char, int> Encoder::count_frequency() {
    std::ifstream file_stream(_input_file);
    char character;
    std::map<char, int> map;

    while (file_stream.get(character)) {

        if (map.find(character) == map.end())
            map.insert(std::pair<char, int>(character, 1));

        else
            ++map[character];
    }

    file_stream.close();
    return map;
}

void Encoder::encode() {}

// Builds the frequency_heap as a priority_queue with Sapling nodes
std::priority_queue<SaplingNode> Encoder::_build_frequency() {

    std::priority_queue<SaplingNode> frequency_heap;

    std::map<char, int> frequency_map = count_frequency();

    for (auto & pair : frequency_map)
    {
        std::string str;
        str.push_back(pair.first);
        auto node = SaplingNode(str, pair.second);

        frequency_heap.push(node);
    }
}

SaplingNode Encoder::_build_tree(std::priority_queue<SaplingNode> heap) {}

/* --- Public ---*/
Encoder::Encoder(std::string input_file, std::string output_file) {
    _input_file = std::move(input_file);
    _output_file = std::move(output_file);

    std::priority_queue<SaplingNode> frequency_heap = _build_frequency();
}

std::map<std::string, std::string> build_lexicon(SaplingNode tree) {}





