#ifndef TOKEN_CLASSIFIER_H
#define TOKEN_CLASSIFIER_H

#include <string>
#include <unordered_set>

/**
 * Token types enumeration for TINY language.
 */
enum class TokenType {
    KEYWORD,
    IDENTIFIER,
    NUMBER,
    ASSIGNMENT_OP,    // :=
    COMPARISON_OP,    // <, =
    ARITHMETIC_OP,    // +, -, *, /
    SEMICOLON,
    LPAREN,
    RPAREN,
    END_OF_FILE,
    UNKNOWN
};

/**
 * TokenClassifier determines the type of each lexeme.
 * Classifies tokens as keywords, identifiers, numbers, or symbols.
 */
class TokenClassifier {
private:
    std::unordered_set<std::string> keywords;  // Set of TINY keywords
    
    /**
     * Initializes the keywords set with TINY language reserved words.
     */
    void initializeKeywords();
    
public:
    TokenClassifier();
    
    /**
     * Determines the type of a lexeme.
     * @param lexeme - The token string to classify
     * @return TokenType enum representing the token category
     * 
     * Example: classifyToken("if") returns TokenType::KEYWORD
     *          classifyToken("x") returns TokenType::IDENTIFIER
     *          classifyToken("123") returns TokenType::NUMBER
     */
    TokenType classifyToken(const std::string& lexeme) const;
    
    /**
     * Checks if a lexeme is a TINY keyword.
     * @param lexeme - String to check
     * @return true if keyword, false otherwise
     * 
     * Example: isKeyword("repeat") returns true
     *          isKeyword("xyz") returns false
     */
    bool isKeyword(const std::string& lexeme) const;
    
    /**
     * Checks if a lexeme is a number.
     * @param lexeme - String to check
     * @return true if all characters are digits, false otherwise
     * 
     * Example: isNumber("123") returns true
     *          isNumber("abc") returns false
     */
    bool isNumber(const std::string& lexeme) const;
    
    /**
     * Converts TokenType enum to string representation.
     * @param type - TokenType to convert
     * @return String name of the token type
     */
    static std::string tokenTypeToString(TokenType type);
};

#endif // TOKEN_CLASSIFIER_H
