#ifndef UTILS_H
#define UTILS_H

#include <exception>
#include <iostream>

#include "Types.h"

void printMenu();
void printCredits();
std::string enterinName(char playerChar);
char inputMenuOption(char* input);
bool charCheck(char charToCheck);

#endif // UTILS_H