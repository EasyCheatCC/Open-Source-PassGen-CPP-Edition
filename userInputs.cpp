#include <iostream>
#include "userInputs.h"
#include "main.h"

int userInputs()
{
  int length;
  bool includeUppercase, includeLowercase, includeNumbers, includeSymbols;

  text("Enter Password Lenth: ");
  //std::cout << "Enter Password Length: ";
  std::cin >> length;

  text("Include Uppercase Letters(1 = Yes | 0 = No): ");
  //std::cout << "Include Uppercase Letters(1 = Yes | 0 = No): ";
  std::cin >> includeUppercase;

  text("Include Lowercase Letters(1 = Yes | 0 = No): ");
  //std::cout << "Include Lowercase Letters(1 = Yes | 0 = No): ";
  std::cin >> includeLowercase;

  text("Include Numbers(1 = Yes | 0 = No): ");
  //std::cout << "Include Numbers(1 = Yes | 0 = No): ";
  std::cin >> includeNumbers;

  text("Include Symbols(1 = Yes | 0 = No): ");
  //std::cout << "Include Symbols(1 = Yes | 0 = No): ";
  std::cin >> includeSymbols;

  std::string password = generatePassword(length, includeUppercase, includeLowercase, includeNumbers, includeSymbols);

  if (password.empty())
  {
    std::cout << "At Least One Character Type Must Be Selected." << std::endl;
  } else
  {
    std::cout << "Generated Password: " << password << std::endl;
    AskQuestion();
  }

  return 0;
}
