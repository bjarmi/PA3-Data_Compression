#include <iostream>
#include <queue>
#include "headers/sapling_node.h"

static struct TreeBuilder{

public:
    std::priority_queue<SaplingNode> heap;

    SaplingNode build();
};

