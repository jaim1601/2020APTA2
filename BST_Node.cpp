
#include <iostream>
#include <memory>

#include "Types.h"
#include "BST_Node.h"

BST_Node::BST_Node(char value):
    value(value),
    left(nullptr),
    right(nullptr)
{
    //std::cout << "BST_Node Create: " << value << std::endl;
}

BST_Node::BST_Node(const BST_Node& other):
    value(other.value),
    left(other.left),
    right(other.right)
{
    //std::cout << "BST_Node Copy: " << value << std::endl;
}

BST_Node::~BST_Node(){
    //std::cout << "BST_Node Deconstructor: " << value << std::endl;
    left = nullptr;
    right = nullptr;
}
