#ifndef BSTFACT_H
#define BSTFACT_H

#include <iostream>
#include <memory>

#include "Types.h"
#include "BST_Node.h"
#include "TileBag.h"

class BSTFact {
public:

    BSTFact(TileBag* bag);
    ~BSTFact();

    std::shared_ptr<BST_Node> returnRoot();
    
    // clears the BST
    void clear();
    
    // checks if the BST contains a tile or not
    // contract: don't modify the data given
    //           don't modify the BST
    bool contains(const char data) const;

    // finds the count of tiles in the BST
    // contract: don't modify the data given
    //           don't modify the BST    
    int count(const char data, int retNumb)const;

    // adds tiles to the BST
    // contract: don't modify the data given
    void add(const char data);

    // removes tiles from the BST
    // contract: don't modify the data given
    // Geekforgeeks (2020), Binary Search Tree | Set 2 (Delete) (Version 1.0) [Source Code]. https://www.geeksforgeeks.org/binary-search-tree-set-2-delete/
    void remove(const char data);

    std::shared_ptr<BST_Node> returnNode();

    // depth First Search of Binary Tree
    void dfs()const;

    // fills up BST with tiles
    void fillBST();

private:
    std::shared_ptr<BST_Node> root;

    bool contains(std::shared_ptr<BST_Node> node, const char data) const;

    std::shared_ptr<BST_Node> add(std::shared_ptr<BST_Node> node, const char data);

    std::shared_ptr<BST_Node> remove(std::shared_ptr<BST_Node> node, const char data);

    int count(std::shared_ptr<BST_Node> node, const char data, int retCount)const;

    void dfs(std::shared_ptr<BST_Node> node) const;

    TileBag* bag;
};

#endif //BSTFACT_H