#include "InputManager.h"
#include "scanner.h"
#include "TokenClassifier.h"
#include "OutputManager.h"
#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;
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
        vector<Token> tokenList;
        
        // 1. Read input file
        cout << "Reading input file: test.tny..." << endl;
        inputManager.readInput("test.tny");
        
        // 2. Scan and classify tokens
        cout << "Scanning tokens..." << endl;
        string tokenValue;
        
        while (scanner.scanNextToken(tokenValue) != -1) {
            // Classify the token
            TokenType tokenType = classifier.classifyToken(tokenValue);
            string typeString = classifier.tokenTypeToString(tokenType);
            
            // Check for EOF
            // if (tokenType == TokenType::END_OF_FILE) {
            //     break;
            // }
            
            // Store token
            tokenList.emplace_back(tokenValue, typeString);
            
            // Optional: Print progress
            cout << "Found token: " << tokenValue 
                 << " (" << typeString << ")" << endl;
        }
        
        // 3. Write tokens to output file
        cout << "\nWriting tokens to output file..." << endl;
        ofstream stream = outputManager.initOutput("tokens.txt");
        outputManager.writeTokens(stream,tokenList);
        outputManager.closeOutput(stream);
        
        // Summary
        cout << "\n==================================" << endl;
        cout << "Scanning complete!" << endl;
        cout << "Total tokens scanned: " << tokenList.size() << endl;
        cout << "Output written to: tokens.txt" << endl;
        cout << "==================================" << endl;
        
        return 0;
        
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
        return 1;
    }
}
