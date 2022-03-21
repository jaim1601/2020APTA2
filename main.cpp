#include <iostream>

#include "utils.h"
#include "Types.h"
#include "BSTGame.h"

int main(int argc, char** argv) {  
    // Here lies the test code, unfortunately it had to be omitted cause due to 2 man constraints but oh well.
    if(argv[1] != nullptr /* && argv[2] != nullptr */){
        std::string command(argv[1]); // Parses in the argument
        // std::string savegamename(argv[2]); // Parses in the name of the save game
        // std::ifstream savegame(savegamename);
        if(command == "-t"){
            std::cout << "Testing Mode" << std::endl;
        }else if(command == "-s"){
            printMenu(); // Prints Menu

            char input = '0';

            while (input != '4' && !std::cin.eof()){
                inputMenuOption(&input);

                if(input == '1'){
                    playtheGame(argv[2]);
                }else if(input == '2'){

                }else if(input == '3'){
                    printCredits();
                }else if(input == '4'){
                    
                }
            }
        }
        else{
            std::cout << "Invalid argument" << std::endl;
        }
    }else{
        // Code under here is normal running code

        printMenu(); // Prints Menu
        
        char defaultSeed[] = {'0'};
        char input = '0';

        // Basic Menu function, not much more to be said.
        while (input != '4' && !std::cin.eof()){
            inputMenuOption(&input);

            if(input == '1'){
                playtheGame(defaultSeed);
            }else if(input == '2'){

            }else if(input == '3'){
                printCredits();
            }else if(input == '4'){

            }
        }
    }
    return EXIT_SUCCESS;
}