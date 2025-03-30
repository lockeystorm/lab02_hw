#include <iostream>
#include <string>

int
main()
{
  std::string name;
  std::cout << "What's your name? "; // спрашиваем имя пользователя
  getline(std::cin, name);           // считываем имя пользователя
  std::cout << "Hello world from " << name << std::endl; // приветствие
  return 0;
}
