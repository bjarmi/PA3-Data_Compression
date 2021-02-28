#include "../headers/sapling_node.h"

SaplingNode::SaplingNode(std::string key, int value,
                         SaplingNode* left_child,
                         SaplingNode* right_child)
{
	_key = std::move(key);
	_value = value;
	_left_child = left_child;
	_right_child = right_child;
}

SaplingNode::SaplingNode(std::string key, int value)
{
	_key = std::move(key);
	_value = value;
	_left_child = nullptr;
	_right_child = nullptr;
}

std::string SaplingNode::get_key()
{
	return _key;
}

int SaplingNode::get_value() const
{
	return _value;
}

SaplingNode* SaplingNode::get_left_child()
{
	return _left_child;
}

SaplingNode* SaplingNode::get_right_child()
{
	return _right_child;
}

bool SaplingNode::operator==(const SaplingNode& other) const
{
	return _value == other._value;
}

bool SaplingNode::operator>=(const SaplingNode& other_node) const
{
	return _value >= other_node._value;
}

bool SaplingNode::operator<=(const SaplingNode& other_node) const
{
	return _value <= other_node._value;
}

bool SaplingNode::operator<(const SaplingNode& other_node) const
{
	return _value < other_node._value;
}

bool SaplingNode::operator>(const SaplingNode& other_node) const
{
	return _value > other_node._value;
}
