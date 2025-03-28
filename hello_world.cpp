#include <iostream>
#include <string>

int main() {    
    std::string name;
    std::cout << "What's your name? "; // ask user for his name
    getline(std::cin, name); // accept user's name
    std::cout << "Hello world from " << name << std::endl; // greeting
    return 0;
}
