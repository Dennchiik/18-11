#include <iostream>
#include <fstream>

void encryptCaesarCipher(const std::string& inputFile, const std::string& outputFile, int shift) {
    std::ifstream input(inputFile);
    std::ofstream output(outputFile);

    if (!input.is_open()) {
        std::cerr << "Unable to open input file!" << std::endl;
        return;
    }

    if (!output.is_open()) {
        std::cerr << "Unable to open output file!" << std::endl;
        return;
    }

    char ch;
    while (input.get(ch)) {
        if (isalpha(ch)) { 
            char base = islower(ch) ? 'a' : 'A';
            ch = base + (ch - base + shift) % 26;
        }
        output << ch;
    }

    input.close();
    output.close();

    std::cout << "Encryption completed successfully!" << std::endl;
}

int main() {
    std::string inputFile = "input.txt"; 
    std::string outputFile = "output.txt"; 
    int shift = 3; 

    encryptCaesarCipher(inputFile, outputFile, shift);

    return 0;
}
