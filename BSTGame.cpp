#include "BSTGame.h"

void playtheGame(char* seed){
    Player* player1 = new Player(enterinName('A'),'A'); 
    Player* player2 = new Player(enterinName('B'),'B');
    TileBag* bag = new TileBag();
    NewFact* fact = new NewFact(bag);
    fact->createFactories(seed);
    bool player2Start = false;
    int roundsPlayed = 0;

    std::cout << std::endl << "Let's Play!" << std::endl << std::endl;
    int turns = MAX_TURNS;
    if(*seed != '0'){
        turns = MAX_TURNS + 1;
    }
    // The algorithm here, many eof checks but this is to not bug out when a eof character is inputted.
    while(roundsPlayed < turns && !std::cin.eof()){
        fact->fillAllFactories();
        std::cout << "=== Start Round ===" << std::endl;
        while(fact->isAllFactoriesEmpty() != true && !std::cin.eof()){ // This got slightly more convoluted but the purpose is to make it that player2 Is the first player if Player1 was the last to play in the round.
            if(player2Start != true){
                playerTurn(player1,fact);   
            }
            if(fact->isAllFactoriesEmpty() == true){
                player2Start = true;
            }
            if(fact->isAllFactoriesEmpty() != true && !std::cin.eof()){
                playerTurn(player2,fact);
                player2Start = false;
            }
        }
        if(!std::cin.eof()){
            roundsPlayed++;
            endRoundCheck (player1,fact,seed);
            endRoundCheck (player2,fact,seed);
            if(*seed != '0'){
                isBagEmpty(fact, bag);    
            }
            std::cout << "=== End Round ===" << std::endl << std::endl;
        }
    }
    if(!std::cin.eof()){
        gameEnd(player1,player2,fact);
    }
    if(std::cin.eof()){
        std::cout << "Goodbye" << std::endl;
    }
}

// Function that shows Player mosaic and gets their input
void playerTurn(Player* player,NewFact* fact) {
    std::cout << "TURN FOR PLAYER: " << player->getPlayerChar() << std::endl;    
    factoriesPrint(fact);
    std::cout << std::endl;
    mosaicPrint(player);
    brokenPrint(player);
    // Code for input will go here
    playerInput(player,fact); 
}

// Function that prints out the Mosaic per player.
void mosaicPrint(Player* player){
    std::cout << "Mosaic for " << player->getPlayerChar() << std::endl;
    for(int i = 0;i < PLAYER_MOSAIC_SIZE;i++){   
        player->getStorageMosaic()->printlineStorageMosaic(i);
        std::cout << "||";
        player->getPlayMosaic()->printlinePlayMosaic(i);
        std::cout << std::endl;
    }
}

// Seperated the broken printing, this is mostly for the end of game mosaic screen
void brokenPrint(Player* player){
    std::cout << "Broken: ";
    player->getBrokenMosaic()->printBrokenMosaic();
}

// Function that prints out the current Factories.
void factoriesPrint(NewFact* fact) {
    std::cout << "Factories:" << std::endl;
    fact->printAllFactories();
}

// Gets the players input then parses the input through methods
void playerInput(Player* player,NewFact* fact) {
    int factorySelect = 0;
    char tileSelect = '0';
    int mosaicLineSelect = 0;
    
    bool turnFinished = false;

    while((turnFinished == false) && (!std::cin.eof())){ // Ensures user input that matches input for game to work
        std::cout << "> ";
        std::cin >> factorySelect >> tileSelect >> mosaicLineSelect;

        while (std::cin.fail() && (!std::cin.eof())){
            std::cin.clear();
            std::cin.ignore(100, '\n');
            std::cout << "Please ensure you enter the correct type of input. Try again." << std::endl;
            std::cout << "> ";
            std::cin >> factorySelect >> tileSelect >> mosaicLineSelect;
        }
        std::cout << factorySelect << " " << tileSelect << " " << mosaicLineSelect << std::endl;
        if(std::cin.eof()){ // If the end of file has been Input.
            turnFinished = false; // Mostly symbol, this just ensures that future functions don't print
        }else if(factorySelect > 5 || factorySelect < 0){ // Factory bounds
            std::cout << "Factory Select must be a integer between 0 and 5" << std::endl;
        }else if(charCheck(tileSelect) != true){ // If the character is one of 5 characters
            std::cout << "Tile's must be a single Character Either R, Y, B, L, U" << std::endl; 
        }else if(mosaicLineSelect > 5 || mosaicLineSelect < 1){ // Mosaic bounds
            std::cout << "Must select a valid line" << std::endl;
        }else if(player->getPlayMosaic()->verifyFilledPlayMosaic(mosaicLineSelect - 1,tileSelect) == true){ // Checks to see if you are not inputting the same tile into the mosaic
            std::cout << "Mosaic colour is already filled" << std::endl;
        }else if(fact->tilesExist(factorySelect, tileSelect) != true){ // If there even is tiles in the factory selected.
            std::cout << "The tile you chose does not exist in that factory." << std::endl;
        }else{
            std::cout << "Turn Successful." << std::endl;
            turnFinished = true;
        }
    }
    if(turnFinished == true){ // Only runs if turn the input is properly inputted.
        gameplayFunctions(player, fact, factorySelect, tileSelect, mosaicLineSelect);
    }
}

// This undergoes the gameplay functions and is the underlying algorithm for playing the game
void gameplayFunctions(Player* player,NewFact* fact, int factorySelect, char tileSelect, int mosaicLineSelect){
    int tilesRemaining = player->getStorageMosaic()->setStorageMosaic(tileSelect,mosaicLineSelect, fact->returnTileCount(factorySelect, tileSelect)); // Finds the tiles remaining off the factory and saves the integer to be used to push onto the Storage
    player->getBrokenMosaic()->excessTilesInput(tilesRemaining, tileSelect); // Excess tiles are then pushed to the broken Mosaic
    if((fact->isFRemoved() == false) && (factorySelect == 0)){ // This checks if the F token is there or not so F can be included in calculates
        player->getBrokenMosaic()->pushFirstPlayer();
    }
    fact->deleteTiles(factorySelect, tileSelect); //The factory tiles are then deleted
}

// This is the end of round functions to set up for the next row
void endRoundCheck(Player* player, NewFact* fact, char* gameCheck){
    for(int rowIndex = 0; rowIndex < PLAYER_MOSAIC_SIZE;rowIndex++){ // Checks each row
        if(player->getStorageMosaic()->filledLineCheck(rowIndex) == true){ // If the row is full then
            char getChar = player->getStorageMosaic()->getPartMosaic(MOSAIC_ARRAY_LIMIT - rowIndex,rowIndex); // Gets the character of the final row
            int colIndex =  player->getPlayMosaic()->mosaicInput(rowIndex, getChar); // Gets the column from inputting into the play Mosaic
            addToTileBag(rowIndex-1, fact->getBag(), getChar, gameCheck); // Adds tiles that were pushed off into the tile bag or boxlid
            addToTileBagBroken(player, fact->getBag(), gameCheck); // Adds tiles that are in the broken back into the tile bag or boxlid
            scoreCheck(player,colIndex,rowIndex); // Does a scoring check of the tile that was just pushed to the mosaic
            player->getBrokenMosaic()->clear(); // Broken is cleared out
            player->getStorageMosaic()->clearLineMosaic(rowIndex); //The line is then cleared for the next round to begin
        }
    }
}

// This is the score check function, stops the score from going below 0 and handles 
void scoreCheck(Player* player,int colIndex,int rowIndex){
    player->incrementPlayerScore(player->getPlayMosaic()->findNearbyTiles(colIndex,rowIndex));
    player->incrementPlayerScore(player->getBrokenMosaic()->reduceBrokenScore()); // negative score from broken is taken away
    if(player->getPlayerScore() < 0){
        player->minimumScore();
    }
}

// This is the game ending function, this gets the scores from each player and tells us the winner!
void gameEnd(Player* player1, Player* player2,NewFact* fact){

    std::cout << "=== GAME OVER ===" << std::endl 
    << std::endl
    << "Final Mosaics:" << std::endl;
    mosaicPrint(player1);
    std::cout << std::endl;
    mosaicPrint(player2);
    std::cout << std::endl
    << "Final Scores:" << std::endl
    << "Player " << player1->getPlayerChar() << ": " << player1->getPlayerScore() << std::endl
    << "Player " << player2->getPlayerChar() << ": " << player2->getPlayerScore() << std::endl;
    if(player1->getPlayerScore() > player2->getPlayerScore()){
        std::cout << "Player " << player1->getPlayerChar() << " wins!" << std::endl;
    }else if(player2->getPlayerScore() > player1->getPlayerScore()){
        std::cout << "Player " << player2->getPlayerChar() << " wins!" << std::endl;
    }else{
        std::cout << "It was a Draw!" << std::endl;
    }

    // Deletes and cleans up memory
    delete player1;
    delete player2;
    delete fact;
}

void addToTileBag(int count, TileBag* bag, char tile, char* gameCheck){
    while(count>=0){
        if (*gameCheck == '0'){
            bag->add_back(tile);
            --count;
        }else{
            bag->addToBoxLid(tile);
            --count;
        }
    }
}

void addToTileBagBroken(Player* player, TileBag* bag, char* gameCheck){
    for (int i=0; i!=player->getBrokenMosaic()->returnSize(); ++i){
        if(player->getBrokenMosaic()->returnTile(i) != FIRSTPLAYER){
            if(*gameCheck == '0'){
                bag->add_back(player->getBrokenMosaic()->returnTile(i));
            }else{
               bag->addToBoxLid(player->getBrokenMosaic()->returnTile(i)); 
            }
        }
    }
}

void isBagEmpty(NewFact* fact, TileBag* bag){
    if (bag->bagSize() == 0){
        bag->shuffle(bag->boxSize());
        bag->refillBag();
    }
}