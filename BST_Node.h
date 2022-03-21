#ifndef BST_NODE_H
#define BST_NODE_H

#include <iostream>
#include <memory>

#include "Types.h"
#include "TileBag.h"

class BST_Node {
public:

    BST_Node(char value);
    BST_Node(const BST_Node& other);
    ~BST_Node();

    char value;

    std::shared_ptr<BST_Node> left;
    std::shared_ptr<BST_Node> right;

private:

};

#endif //BST_NODE_H