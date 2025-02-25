/**
 * Duilio Lucio
 * 10/06/2024
 */

#include <iostream>
#include <fstream>
#include <string>

int main() {
    //open text file for reading
    std::ifstream textFile("example.txt");
    if (!textfile) {
        std::cerr << "Text file cant be opened." << std::endl;
        return 1;
    }

    // read text file
    std::string line;
    while (std::getline(textFile, line)) {
        std::cout << line << std::endl;
    }
    textFile.close(); //closes text file

    // open binary file in order to write
    std::ofstream binaryFile("example.bin", std::ios::binary);
    if (!binaryFile) {
        std::cerr << "Binary file cant be opened."
        return 1;
    }

    int data = 12345;
    binaryFile.write(reinterpret_cast<char*>(&data), sizeof(data)); // writes binary data
    binaryFile.close(); // closes the binary file

    return 0;
}