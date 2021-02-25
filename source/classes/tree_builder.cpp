#include <iostream>
#include <queue>
#include "../headers/sapling_node.h"

struct TreeBuilder
{

	static std::priority_queue<SaplingNode> heap;

	static SaplingNode build()
	{
		while (heap.size() > 1)
		{
			auto node_1 = heap.pop();
			auto node_2 = heap.pop();
			auto new_tree = SaplingNode(
					"",
					node_1.get_value() + node_2.value(),
					node_1,
					node_2
			);

			heap.push(new_tree);
			build();
		}

		return heap.pop();
	}
}

