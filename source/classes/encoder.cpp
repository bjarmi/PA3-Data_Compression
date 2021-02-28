#include <iostream>
#include <queue>
#include <fstream>
#include <utility>

#include "../headers/encoder.h"
#include "../headers/decoder.h"
#include "../headers/sapling_node.h"
#include "../headers/tree_builder.h"


/* --- Private --- */
// Counts the frequency of a letter in the input file.
std::map<char, int> Encoder::count_frequency()
{
	char character;
	std::map<char, int> map;

	std::ifstream file_stream(_input_file);

	while (file_stream.get(character))
	{

		if (map.find(character) == map.end())
			map.insert(std::pair<char, int>(character, 1));

		else
			++map[character];
	}

	file_stream.close();
	return map;
}

// I encoded the file boss.
void Encoder::encode(std::map<std::string, std::string> lexicon)
{
	Decoder decoder(std::move(lexicon), _input_file, _output_file);
}

// Builds the frequency_heap as a priority_queue with Sapling nodes
std::priority_queue<SaplingNode> Encoder::_build_frequency()
{

	std::priority_queue<SaplingNode> frequency_heap;

	std::map<char, int> frequency_map = count_frequency();

	for (auto& pair : frequency_map)
	{
		std::string str;
		str.push_back(pair.first);
		auto node = SaplingNode(str, (-1) * pair.second);

		frequency_heap.push(node);
	}
}

// Builds huffman tree.
SaplingNode Encoder::_build_tree(std::priority_queue<SaplingNode> heap)
{
	TreeBuilder::heap = std::move(heap);
	return TreeBuilder::build();
}

// Recursively finds code for each letter in a tree and inserts them to lexicon
void
Encoder::_assign_codes_to_letters(SaplingNode* node, const std::string& code,
                                  std::map<std::string,
		                                  std::string>* lexicon
)
{
	if (node->get_left_child())
		_assign_codes_to_letters(node->get_left_child(),
		                         (code + "0"),
		                         lexicon);

	if (node->get_right_child())
		_assign_codes_to_letters(node->get_right_child(),
		                         (code + "1"),
		                         lexicon);

	if (!node->get_left_child() && !node->get_right_child())
		(*lexicon)[node->get_key()] = code;
}

/* --- Public ---*/
Encoder::Encoder(std::string input_file, std::string output_file)
{

	_input_file = std::move(input_file);
	_output_file = std::move(output_file);

	std::priority_queue<SaplingNode> frequency_heap = _build_frequency();

	SaplingNode tree = _build_tree(frequency_heap);

	std::map<std::string, std::string> lexicon = build_lexicon(&tree);

	encode(lexicon);
}

// Builds lexicon from a given tree.
std::map<std::string, std::string> Encoder::build_lexicon(SaplingNode* tree)
{

	std::map<std::string, std::string> lexicon;

	_assign_codes_to_letters(tree, "", &lexicon);

	return lexicon;
}
