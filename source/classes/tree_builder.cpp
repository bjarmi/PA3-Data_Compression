#include <iostream>
#include <queue>
#include "../headers/sapling_node.h"

struct TreeBuilder
{

	static std::priority_queue<SaplingNode> heap;

	static SaplingNode build()
	{
		while (heap.size() != 1)
		{
			break;
		}

		return heap.pop();
	}
};

