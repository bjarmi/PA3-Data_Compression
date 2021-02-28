#ifndef PA3_DATA_COMPRESSION_TREE_BUILDER_H
#define PA3_DATA_COMPRESSION_TREE_BUILDER_H

struct TreeBuilder
{

    std::priority_queue<SaplingNode> heap;

    SaplingNode build();
};

#endif //PA3_DATA_COMPRESSION_TREE_BUILDER_H
