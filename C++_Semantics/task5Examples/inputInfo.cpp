/**
 * Duilio Lucio
 * 10/06/2024
 */

#include <iostream>
#include <string>

int main() {
    std::string name;
    int age;

    // User input prompt
    std::cout << "Enter Name: ";
    std::getline(std::cin, name); // reads line of text

    std::cout << "Enter Age: ";
    std::cin >> age; // reads an integer

    // displays the input back to user
    std::cout << "Hello, " << name << "! I am" << age << " years old." << std::endl;

    return 0;
}