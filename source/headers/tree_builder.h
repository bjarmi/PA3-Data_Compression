#ifndef PA3_DATA_COMPRESSION_TREE_BUILDER_H
#define PA3_DATA_COMPRESSION_TREE_BUILDER_H

struct TreeBuilder
{

    static std::priority_queue<SaplingNode> heap;

    static SaplingNode build();
};

#endif //PA3_DATA_COMPRESSION_TREE_BUILDER_H
