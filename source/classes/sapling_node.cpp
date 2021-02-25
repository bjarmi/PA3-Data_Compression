#include "../headers/sapling_node.h"

#include <utility>

SaplingNode::SaplingNode(std::string key, int value, SaplingNode* left_child,
                         SaplingNode* right_child) {
    _key = std::move(key);
    _value = value;
    _left_child = left_child;
    _right_child = right_child;
}

std::string SaplingNode::get_key() {
    return _key;
}

int SaplingNode::get_value() const {
    return _value;
}

SaplingNode* SaplingNode::get_left_child() {
    return _left_child;
}

SaplingNode* SaplingNode::get_right_child() {
    return _right_child;
}