#include "BSTFact.h"

#include <iostream>
#include <string>

BSTFact::BSTFact(TileBag* bag){
    root = nullptr;
    this->bag = bag;
}

BSTFact::~BSTFact(){
}

std::shared_ptr<BST_Node> BSTFact::returnRoot(){
    return root;
}

void BSTFact::clear(){
    root = nullptr;
}

bool BSTFact::contains(const char data) const{
    return contains(root, data);
}

bool BSTFact::contains(std::shared_ptr<BST_Node> node, const char data)const{
    bool retValue = false;

    if (node == nullptr){
        retValue = false;
    }else if (data == node->value){
        retValue = true;
    }else{
        // recursive step
        if (data < node->value){
            // go left
            retValue = contains(node->left, data);
        }else{
            // go right
            retValue = contains(node->right, data);
        }
    }
    return retValue;
}

void BSTFact::add(const char data){
    root = add(root, data);
}

std::shared_ptr<BST_Node> BSTFact::add(std::shared_ptr<BST_Node> node, const char data){
    std::shared_ptr<BST_Node> returnNode;

    if (node == nullptr){
        // base case
        //std::cout << "Make new new node: " << data << std::endl;
        returnNode = std::make_shared<BST_Node>(data);
    }else{
        // recursive step
        //std::cout << "*Insert: " << data << "*" << std::endl;
        if (data < node->value){
            // go left
            //std::cout << "\tInsert " << data << " left of: " << node->value << std::endl;
            std::shared_ptr<BST_Node> subtree = add(node->left, data);
            node->left = subtree;
            returnNode = node;
        }else{
            // go right
            //std::cout << "\tInsert " << data << " right of: " << node->value << std::endl;
            std::shared_ptr<BST_Node> subtree = add(node->right, data);
            node->right = subtree;
            returnNode = node;
        }
    }
    return returnNode;
}

int BSTFact::count(const char data, int retNumb)const{
    return count(root, data, retNumb);
}

int BSTFact::count(std::shared_ptr<BST_Node> node, const char data, int retCount)const{
    if(node!=nullptr){
        if (data == node->value){
            ++retCount;
        }
        if (data < node->value){
            retCount = count(node->left, data, retCount);
        }else{
            retCount = count(node->right, data, retCount);
        }
    }
    return retCount;
}

void BSTFact::remove(const char data){
    root = remove(root, data);
}

std::shared_ptr<BST_Node> BSTFact::remove(std::shared_ptr<BST_Node> node, const char data){
    std::shared_ptr<BST_Node> returnNode;

    if(node == nullptr){
        returnNode = node;
    }
    if(data < node->value){
        node->left = remove(node->left, data);
        returnNode = node;
    }else if(data > node->value){
        node->right = remove(node->right, data);
        returnNode = node;
    }else{
        if(node->left == nullptr){
            std::shared_ptr<BST_Node> temp = node->right;
            node = nullptr;
            returnNode = temp;
        }else if(node->right == nullptr){
            std::shared_ptr<BST_Node> temp = node->left;
            node = nullptr;
            returnNode = temp;
        }
        else{
            std::shared_ptr<BST_Node> succParent = node;

            std::shared_ptr<BST_Node> succ = node->right;
            while(succ->left != nullptr){
                succParent = succ; 
                succ = succ->left;
            }

            if (succParent != node){
                succParent->left = succ->right;
            }else{
                succParent->right = succ->right;
            }

            node->value = succ->value;

            succ = nullptr;
            returnNode = node;
        }
    }
    return returnNode;
}

void BSTFact::dfs()const{
    dfs(root);
    std::cout << std::endl;
}

void BSTFact::dfs(std::shared_ptr<BST_Node> node) const{
    // print out all the nodes

    if (node != nullptr){
        // go left
        dfs(node->left);

        // do me
        std::cout << node->value << " ";

        // go right
        dfs(node->right);
    }
}

void BSTFact::fillBST(){
    int count = 0;
    while (count < MAX_TILES_IN_FACTORY){
        char tile = bag->get_front();
        add(tile);
        bag->remove_front();
        ++count;
    }
}
