#include "NewFact.h"

NewFact::NewFact(TileBag* bag){
    this->bag = bag;
}

NewFact::~NewFact(){
    cntrFactory->clear();
    factory1->clear();
    factory2->clear();
    factory3->clear();
    factory4->clear();
    factory5->clear();

    delete bag;
    delete cntrFactory;
    delete factory1;
    delete factory2;
    delete factory3;
    delete factory4;
    delete factory5;
}

void NewFact::createFactories(char* seed){
    bag->fill_bag(seed);
    BSTFact* cntrFactory = new BSTFact(bag);
    this->cntrFactory = cntrFactory; 
    BSTFact* factory1 = new BSTFact(bag);
    this->factory1 = factory1;
    BSTFact* factory2 = new BSTFact(bag);
    this->factory2 = factory2;
    BSTFact* factory3 = new BSTFact(bag);
    this->factory3 = factory3;
    BSTFact* factory4 = new BSTFact(bag);
    this->factory4 = factory4;
    BSTFact* factory5 = new BSTFact(bag);
    this->factory5 = factory5;
}

void NewFact::fillAllFactories(){
    cntrFactory->add(FIRSTPLAYER);
    factory1->fillBST();
    factory2->fillBST();
    factory3->fillBST();
    factory4->fillBST();
    factory5->fillBST();
}

bool NewFact::isAllFactoriesEmpty(){
    bool isEmpty = false;
    if(cntrFactory->returnRoot() == nullptr && factory1->returnRoot() == nullptr && factory2->returnRoot() == nullptr && factory3->returnRoot() == nullptr && factory4->returnRoot() == nullptr && factory5->returnRoot() == nullptr){
        isEmpty = true;
    }
    return isEmpty;
}

void NewFact::printAllFactories(){
    std::cout << "0: ";
        cntrFactory->dfs();
    std::cout << "1: ";
        factory1->dfs();
    std::cout << "2: ";
        factory2->dfs();
    std::cout << "3: ";
        factory3->dfs();
    std::cout << "4: ";
        factory4->dfs();
    std::cout << "5: ";
        factory5->dfs();
}

bool NewFact::tilesExist(int factory, char colour){
    bool doesExist = false;
    if(factory == 0){
        doesExist = cntrFactory->contains(colour);
    }else if(factory == 1){
        doesExist = factory1->contains(colour);
    }else if(factory == 2){
        doesExist = factory2->contains(colour);
    }else if(factory == 3){
        doesExist = factory3->contains(colour);
    }else if(factory == 4){
        doesExist = factory4->contains(colour);
    }else if(factory == 5){
        doesExist = factory5->contains(colour);
    }

    return doesExist;
}

int NewFact::returnTileCount(int factory, char colour){
    int count = 0;
    if(factory == 0){
        count = cntrFactory->count(colour, count);
    }else if(factory == 1){
        count = factory1->count(colour, count);
    }else if(factory == 2){
        count = factory2->count(colour, count);
    }else if(factory == 3){
        count = factory3->count(colour, count);
    }else if(factory == 4){
        count = factory4->count(colour, count);
    }else if(factory == 5){
        count = factory5->count(colour, count);
    }
    return count;
}

bool NewFact::isFRemoved(){
    bool retValue = true;
    if (cntrFactory->contains(FIRSTPLAYER)){
        retValue = false;
    }
    return retValue;
}

void NewFact::deleteTiles(int factory, char colour){
    if(factory == 0){
        while(cntrFactory->contains(colour)){
            cntrFactory->remove(colour);
        }
        if(cntrFactory->contains(FIRSTPLAYER)){
            cntrFactory->remove (FIRSTPLAYER);
        }
    }else if(factory == 1){
        while(factory1->contains(colour)){
            factory1->remove(colour);
        }
        factory1 = removeFromFactory(factory1, factory);     
        factory1->clear();
    }else if(factory == 2){
        while(factory2->contains(colour)){
            factory2->remove(colour);
        }
        factory2 = removeFromFactory(factory2, factory);
        factory2->clear();
    }else if(factory == 3){
        while(factory3->contains(colour)){
            factory3->remove(colour);
        }
        factory3 = removeFromFactory(factory3, factory);   
        factory3->clear();
    }else if(factory == 4){
        while(factory4->contains(colour)){
            factory4->remove(colour);
        }
        factory4 = removeFromFactory(factory4, factory);
        factory4->clear();
    }else if(factory == 5){
        while(factory5->contains(colour)){
            factory5->remove(colour);
        }
        factory5 = removeFromFactory(factory5, factory);
        factory5->clear();
    }
}

BSTFact* NewFact::removeFromFactory(BSTFact* factory, int numb){
    if(factory->contains(RED)){
        int count = returnTileCount(numb, RED);
        while (count>0){
            cntrFactory->add(RED);
            --count;
        }
    }
    if(factory->contains(LIGHTBLUE)){
        int count = returnTileCount(numb, LIGHTBLUE);
        while (count>0){
            cntrFactory->add(LIGHTBLUE);
            --count;
        }
    }if(factory->contains(DARKBLUE)){
        int count = returnTileCount(numb, DARKBLUE);
        while (count>0){
            cntrFactory->add(DARKBLUE);
            --count;
        }
    }if(factory->contains(YELLOW)){
        int count = returnTileCount(numb, YELLOW);
        while (count>0){
            cntrFactory->add(YELLOW);
            --count;
        }
    }if(factory->contains(BLACK)){
        int count = returnTileCount(numb, BLACK);
        while (count>0){
            cntrFactory->add(BLACK);
            --count;
        }
    }
    return factory; 
}

BSTFact* NewFact::getcntrFact(){
    return cntrFactory;
}

BSTFact* NewFact::getFact1(){
    return factory1;
}

BSTFact* NewFact::getFact2(){
    return factory2;
}

BSTFact* NewFact::getFact3(){
    return factory3;
}

BSTFact* NewFact::getFact4(){
    return factory4;
}

BSTFact* NewFact::getFact5(){
    return factory5;
}

TileBag* NewFact::getBag(){
    return bag;
}
