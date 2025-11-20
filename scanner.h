#ifndef SCANNER_H
#define SCANNER_H

#include "InputManager.h"
#include <string>
#include <cctype>

using namespace std;

/**
 * Scanner class extracts tokens from the input stream.
 * Groups characters into meaningful lexemes (tokens).
 */
class Scanner {
private:
    InputManager& inputManager;  // Reference to input manager
    
    /**
     * Skips whitespace characters (space, tab, newline).
     */
    void skipWhitespace(){
        char ch;
        while(true){
            ch = inputManager.peekChar();
            if (ch == ' ' || ch == '\t' || ch == '\n' || ch == '\r') {
                inputManager.getNextChar(); // Consume whitespace
            } else {
                break; // Non-whitespace found
            }
        }

    }
    
    /**
     * Skips comments in TINY language.
     * Supports both {multi-line} and single-line // comments.
     */
    void skipComments(){
        char ch = inputManager.peekChar();
        //single line comment 
        if (ch == '/'){
            char next = inputManager.peekNextChar();
            if (next == '/'){
                //consume both slashes
                inputManager.getNextChar();
                inputManager.getNextChar();
                //skip until end of line
                while(true){
                    char curr = inputManager.getNextChar();
                    if (curr == '\n' || curr == -1){
                        break;
                    }
                }
            }
        }
        //multi line 
        else if (ch =='{'){
            while(true){
                char curr = inputManager.getNextChar();
                if (curr == -1 || curr == '}'){
                    break;
                }
            }
        }
    
    }

    
    
public:
    /**
     * Constructor
     * @param im - Reference to InputManager instance
     */
    explicit Scanner(InputManager& im) : inputManager(im) {}
    
    /**
     * Skips all whitespace and comments to reach next token.
     * 
     * Example: "  // comment\nx" moves position to 'x'
     */
    void skipWhitespaceAndComments(){
        while (inputManager.peekChar() == ' ' || 
               inputManager.peekChar() == '\t' || 
               inputManager.peekChar() == '\n' || 
               inputManager.peekChar() == '\r' ||
               inputManager.peekChar() == '/' ||
               inputManager.peekChar() == '{')
               {
                    skipWhitespace();
                    skipComments(); 
               }
    }
    
    /**
     * Extracts the next valid token from input.
     * @param tokenValue - Output parameter for token string
     * @return true if token found, false if EOF reached
     * 
     * Example (for "if x then"):
     *   First call: tokenValue="if"
     *   Second call: tokenValue="x"
     *   Third call: tokenValue="then"
     */
    char scanNextToken(string& tokenValue){
        while (inputManager.hasMoreChars()){
            skipWhitespaceAndComments();

            if (!inputManager.hasMoreChars()) {
                return -1;
            }

            char ch = inputManager.getNextChar();
            if (ch == -1) {
                return -1; // Indicate EOF
            }
            // Check if character starts an identifier/keyword
            if (isalpha(static_cast<unsigned char>(ch))) {
                tokenValue = ch;
                while(inputManager.hasMoreChars()){
                    if(isalnum(static_cast<unsigned char>(inputManager.peekChar()))){
                        tokenValue += inputManager.getNextChar();
                    }
                    else {
                        return 1; // Token found
                    }
                }
                return 1;
            }
            else if (isdigit(static_cast<unsigned char>(ch))){
                tokenValue = ch ;
                while (inputManager.hasMoreChars()){
                    if(isdigit(static_cast<unsigned char>(inputManager.peekChar()))){
                        tokenValue += inputManager.getNextChar();
                    }
                    else {
                        return 1; // Token found
                    }
                }
                return 1;
            }
            else{
                // Handle symbols and operators
                tokenValue = ch;
                // Check for two-character operators like ":="
                if (ch == ':') {
                    if (inputManager.peekChar() == '=') {
                        tokenValue += inputManager.getNextChar(); // consume '='
                    }
                }
                return 1; // Token found

            }

        }
        return -1;
    }
    
    /**
     * Scans an identifier or keyword (alphanumeric starting with letter).
     * @param tokenValue - Output parameter for the identifier
     */
    void scanIdentifier(string& tokenValue);
    
    /**
     * Scans a number (sequence of digits).
     * @param tokenValue - Output parameter for the number
     */
    void scanNumber(string& tokenValue);
    
    /**
     * Scans operators and special symbols (:=, +, -, *, etc.).
     * @param tokenValue - Output parameter for the symbol
     */
    void scanSymbol(string& tokenValue);
};

#endif // SCANNER_H
