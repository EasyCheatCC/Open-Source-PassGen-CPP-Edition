#include "CheckInput.h"
#include "main.h"
#include <iostream>
#include <thread>
#include <chrono>

void CheckInput()
{
  if (ChosenToRes == 1)
    {
      clearConsole();
      RestartGen();
    }
    else if (ChosenToRes != 1 && ChosenToRes != 0)
    {
      ChosenToRes = -1;
      text("Invalid Input, Please Enter A Valid Input.\n");
      AskQuestion();
    }
    else
    {
      ChosenToRes = -1;
      text("Ending Program..");
      exit(0);
    }
}
