#include "TileBag.h"

TileBag::TileBag(){
    head = nullptr;
}

TileBag::~TileBag(){
    while(head != nullptr) {
        remove_front();
    }
}

int TileBag::bagSize(){
    int count = 0;
    Node* current = head;
    while (current != nullptr){
        ++count;
        current = current->next;
    }
    return count;
}

char TileBag::get_front(){
    char retTile;
    Node* current = head;
    
    retTile = current->colour;

    return retTile;
}

void TileBag::add_back(char tile){
    Node* toAdd = new Node();

    toAdd->colour = tile;
    if (head == nullptr){
        head = toAdd;
    } else{
        Node* current = head;
        while (current->next != nullptr){
            current = current->next;
        }
    current->next = toAdd;    
    }
}

void TileBag::remove_front(){
    if (head != nullptr){
        Node* current = head->next;
        delete head;
        head = current;
    }
}

void TileBag::fill_bag(char* input_seed){
    Tiles* newTile = new Tiles();
    
    if (*input_seed == '0'){
        seed = 10;
    }else{
        seed = atoi(input_seed);
    }
    std::default_random_engine engine(seed);  
    std::uniform_int_distribution<int> uniform_dist(1, TYPES_OF_TILES);
    int count = 0;
    while (count<MAX_TILES_IN_TILEBAG){
        int randIndex = uniform_dist(engine);
        char tile = newTile->addTile(randIndex);
        Node* toAdd = new Node();
        toAdd->colour = tile;
        toAdd->next = nullptr;
        if (head == nullptr){
            head = toAdd;
        } else{
            Node* current = head;
            while (current->next != nullptr){
                current = current->next;
                }
        current->next = toAdd;
        }
        ++count;  
    }
}

int TileBag::boxSize(){
    return length;
}

void TileBag::addToBoxLid(char tile){
    BoxLid[length] = tile;
    ++length;
}

void TileBag::refillBag(){
    int count = 0;
    while (count<length){
        char tile = BoxLid[count];
        Node* toAdd = new Node();
        toAdd->colour = tile;
        toAdd->next = nullptr;
        if (head == nullptr){
            head = toAdd;
        } else{
            Node* current = head;
            while (current->next != nullptr){
                current = current->next;
                }
        current->next = toAdd;
        }
        ++count;  
    }
}

void TileBag::shuffle(int n){  
    std::shuffle(BoxLid, BoxLid + n, std::default_random_engine(seed)); 
}