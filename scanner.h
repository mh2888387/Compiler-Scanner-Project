#ifndef SCANNER_H
#define SCANNER_H

#include "InputManager.h"
#include <string>

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
    void skipWhitespace();
    
    /**
     * Skips comments in TINY language.
     * Supports both {multi-line} and single-line // comments.
     */
    void skipComments();
    
public:
    /**
     * Constructor
     * @param im - Reference to InputManager instance
     */
    explicit Scanner(InputManager& im);
    
    /**
     * Skips all whitespace and comments to reach next token.
     * 
     * Example: "  // comment\nx" moves position to 'x'
     */
    void skipWhitespaceAndComments();
    
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
    bool scanNextToken(std::string& tokenValue);
    
    /**
     * Scans an identifier or keyword (alphanumeric starting with letter).
     * @param tokenValue - Output parameter for the identifier
     */
    void scanIdentifier(std::string& tokenValue);
    
    /**
     * Scans a number (sequence of digits).
     * @param tokenValue - Output parameter for the number
     */
    void scanNumber(std::string& tokenValue);
    
    /**
     * Scans operators and special symbols (:=, +, -, *, etc.).
     * @param tokenValue - Output parameter for the symbol
     */
    void scanSymbol(std::string& tokenValue);
};

#endif // SCANNER_H
