#include "utils.h"

// Menu printing Function
void printMenu(){ 
    std::cout << "Welcome to Azul!" << std::endl
              << "-------------------" << std::endl
              << "Menu" << std::endl
              << "----" << std::endl
              << "1. New Game" << std::endl
              << "2. Load Game" << std::endl
              << "3. Credits (Show student information)" << std::endl
              << "4. Quit" << std::endl;
}

// Credits Printing Function
void printCredits(){
    std::cout << "----------------------------------" << std::endl
              << "Name: Daniel Castro" << std::endl
              << "Student ID: s3485519" << std::endl
              << "Email: s3485519@student.rmit.edu.au" << std::endl
              << "----------------------------------" << std::endl
              << "Name: Jaim Zacharia" << std::endl
              << "Student ID: s3855148" << std::endl
              << "Email: s3855148@student.rmit.edu.au" << std::endl
              << "----------------------------------" << std::endl;
}

// Worked perfectly as a simple input function for the player
std::string enterinName(char playerChar){
    std::cout << "Enter a name for player " << playerChar << std::endl << "> ";
    std::string input;
    std::cin >> input;
    return input;
}

// Simple menu input option
char inputMenuOption(char* input){

    std::cout << "Pick a Menu Option: ";
    std::cin >> input;
    
    return *input;
}

// Simple character check function, checks if the character is valid.
bool charCheck(char chartoCheck){
    bool charisCorrect = false;

    if(chartoCheck == RED || chartoCheck == YELLOW || chartoCheck == DARKBLUE || chartoCheck == LIGHTBLUE || chartoCheck == BLACK){
        charisCorrect = true;
    }

    return charisCorrect;
}