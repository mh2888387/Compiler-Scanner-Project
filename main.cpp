#include "InputManager.h"
#include "Scanner.h"
#include "TokenClassifier.h"
#include "OutputManager.h"
#include <iostream>
#include <vector>
#include <stdexcept>

/**
 * Main function orchestrating the scanning process.
 * Coordinates input reading, token scanning, classification, and output.
 */
int main() {
    try {
        // Create instances of all components
        InputManager inputManager;
        Scanner scanner(inputManager);
        TokenClassifier classifier;
        OutputManager outputManager;
        
        // Vector to store all tokens
        std::vector<Token> tokenList;
        
        // 1. Read input file
        std::cout << "Reading input file: test.tny..." << std::endl;
        inputManager.readInput("test.tny");
        
        // 2. Scan and classify tokens
        std::cout << "Scanning tokens..." << std::endl;
        std::string tokenValue;
        
        while (scanner.scanNextToken(tokenValue)) {
            // Classify the token
            TokenType tokenType = classifier.classifyToken(tokenValue);
            std::string typeString = TokenClassifier::tokenTypeToString(tokenType);
            
            // Check for EOF
            if (tokenType == TokenType::END_OF_FILE) {
                break;
            }
            
            // Store token
            tokenList.emplace_back(tokenValue, typeString);
            
            // Optional: Print progress
            std::cout << "Found token: " << tokenValue 
                      << " (" << typeString << ")" << std::endl;
        }
        
        // 3. Write tokens to output file
        std::cout << "\nWriting tokens to output file..." << std::endl;
        outputManager.initOutput("tokens.txt");
        outputManager.writeTokens(tokenList);
        outputManager.closeOutput();
        
        // Summary
        std::cout << "\n==================================" << std::endl;
        std::cout << "Scanning complete!" << std::endl;
        std::cout << "Total tokens scanned: " << tokenList.size() << std::endl;
        std::cout << "Output written to: tokens.txt" << std::endl;
        std::cout << "==================================" << std::endl;
        
        return 0;
        
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
}
