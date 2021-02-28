#include <iostream>

#ifndef PA3_DATA_COMPRESSION_SAPLING_NODE_H
#define PA3_DATA_COMPRESSION_SAPLING_NODE_H

class SaplingNode {

private:
    std::string _key;
    int _value;
    SaplingNode* _left_child;
    SaplingNode* _right_child;

public:
    SaplingNode(std::string key, int value, SaplingNode* left_child,
                SaplingNode* right_child);

    SaplingNode(std::string key, int value);

    std::string get_key();

    int get_value() const;

    SaplingNode* get_left_child();

    SaplingNode* get_right_child();

    bool operator == (const SaplingNode& other) const;

    bool operator >= (const SaplingNode& other_node) const;

    bool operator <= (const SaplingNode& other_node) const;

};
#endif //PA3_DATA_COMPRESSION_SAPLING_NODE_H
