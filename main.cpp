#include <iostream>
#include <random>
#include <string>
#include <algorithm>
#include <thread>
#include <chrono>
#include <cstdlib>
#include "main.h"
#include "userInputs.h"
#include "CheckInput.h"

int ChosenToRes = -1;


void text(std::string text)
{
  std::cout << text;
}

void clearConsole()
{
  std::cout << "\033[2J\033[1;1H";
}


void Loading()
{
  text("Loading Password Generator..\n");
  std::this_thread::sleep_for(std::chrono::seconds(5));
  clearConsole();
  text("Online Open Source C++ PassGen By Clxcks/Cypher\n");
}

void RestartGen()
{
  ChosenToRes = -1;
  clearConsole();
  userInputs();
}

void AskQuestion()
{
  std::cout <<"Generate New Password? (1 = Yes | 0 = No): ";
  std::cin >> ChosenToRes;
  CheckInput();
  
}

std::string generatePassword(int length, bool includeUppercase, bool includeLowercase, bool includeNumbers, bool includeSymbols) {
    const std::string uppercaseChars = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const std::string lowercaseChars = "abcdefghijklmnopqrstuvwxyz";
    const std::string numberChars = "0123456789";
    const std::string symbolChars = "!@#$%^&*()-+";

    std::string allowedChars = "";
    if (includeUppercase) allowedChars += uppercaseChars;
    if (includeLowercase) allowedChars += lowercaseChars;
    if (includeNumbers) allowedChars += numberChars;
    if (includeSymbols) allowedChars += symbolChars;

    if (allowedChars.empty()) {
        return "";
    }

    std::random_device randomDevice;
    std::mt19937 generator(randomDevice());
    std::uniform_int_distribution<> distribution(0, allowedChars.size() - 1);

    std::string password = "";
    for (int i = 0; i < length; ++i) {
        password += allowedChars[distribution(generator)];
    }
    std::shuffle(password.begin(), password.end(), generator);
    return password;
}



int main() 
{
  Loading();
  userInputs();
}
