#include <queue>
#include "../headers/sapling_node.h"
#include "../headers/tree_builder.h"


SaplingNode TreeBuilder::build()
{

    while (heap.size() > 1)
    {
        auto node_1 = heap.top();
        heap.pop();

        auto node_2 = heap.top();
        heap.pop();

        auto new_tree = SaplingNode(
                "",
                node_1.get_value() + node_2.get_value(),
                &node_1,
                &node_2
        );

        heap.push(new_tree);
    }
    return heap.top();
}


