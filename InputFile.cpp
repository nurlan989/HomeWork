#include "InputFile.h"
#include <fstream>
#include <iostream>
#include <string>

const int NumberOfLaps = 5;

void WriteToRiderNote()
{
   std::ofstream output("RiderNote.txt", std::ios::app);

   double lapTime{ 0.0 };
   std::string textNote{ "" };

   output << "[ ";
   for (int i = 0; i < NumberOfLaps; ++i) 
   {
      std::cout << "Enter your time "<< i+1 << " lap : ";
      std::cin >> lapTime;

      while (!std::cin.good())
      {
         std::cout << "your input is wrong!" << std::endl;
         std::cout << "input a number please!" << std::endl;

         std::cin.clear();
         std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

         std::cout << "Enter your time "<< i + 1 << " lap : ";
         std::cin >> lapTime;
      }
      output << lapTime << " ";
   }
   output << "]";

   std::cout << "Enter a text note after check-in :\n";
   // std::cin.ignore();   
   // Цитата Дмитрия: Идея на будущее: Можно "сливать" лишний символ перехода на новую строку из потока cin 
   // в специально предназначенный для этого std::ws
   // Разница по отношению к cin.ignore() в следующем: ignore пропустит ЛЮБОЙ следующий символ по дефолту, 
   // а ws - только если там есть какой-то из пробельных (таб, переход на новую строку, пробел, вертикальный таб...)
   std::getline(std::cin >> std::ws, textNote);
   output << " - " << textNote;

   output << std::endl;
}

void ShowRiderNote()
{
   std::ifstream input;
   input.open("RiderNote.txt");

   if (!input.is_open())
   {
      std::cout << "File doesn't exists\n";
   }
   else
   {
      std::string str{ "" };

      while (!input.eof())
      {
            std::getline(input, str);
            std::cout << str << std::endl;
      }
   }
}
