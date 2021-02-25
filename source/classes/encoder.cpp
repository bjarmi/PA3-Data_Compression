#include <iostream>
#include <queue>
#include <utility>
#include <fstream>

#include "../headers/encoder.h"
#include "../headers/sapling_node.h"


/* --- Private --- */
int Encoder::count_frequency(char letter) {
    std::ifstream file_stream(_input_file);
    char character;
    int count = 0;

    file_stream.get(character);

    while (!file_stream.fail()) {
        if (std::tolower(character) == letter)
            ++count;
        file_stream.get(character);
    }

    file_stream.close();
    return count;
}

void Encoder::encode(){}

std::priority_queue<SaplingNode> Encoder::_build_frequency() {
    std::priority_queue<SaplingNode, std::vector<SaplingNode>,
            std::greater<SaplingNode>> frequency_heap;

    char letter;
    for (letter = 'a'; letter <= 'z'; letter++){
        int frequency = count_frequency(letter);
        SaplingNode node(letter, frequency);

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





