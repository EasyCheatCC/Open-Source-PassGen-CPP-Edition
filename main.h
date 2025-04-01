#ifndef MAIN_H
#define MAIN_H
#include <iostream>

extern int ChosenToRes;

void text(std::string text);

void RestartGen();

void CheckInput();

void AskQuestion();

void clearConsole();

std::string generatePassword(int length, bool includeUppercase, bool includeLowercase, bool includeNumbers, bool includeSymbols);

#endif
