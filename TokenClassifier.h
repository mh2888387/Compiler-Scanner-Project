#ifndef TOKEN_CLASSIFIER_H
#define TOKEN_CLASSIFIER_H

#include <string>
#include <unordered_set>
#include <cctype>

 // Token types enumeration for TINY language.
 
enum class TokenType {
    SEMICOLON,
    IF,
    THEN,
    END,
    REPEAT,
    UNTIL,
    IDENTIFIER,
    ASSIGN,            // :=
    READ,
    WRITE,
    LESSTHAN,          // <
    EQUAL,             // =
    PLUS,              // +
    MINUS,             // -
    MULT,              // *
    DIV,               // /
    OPENBRACKET,       // (
    CLOSEDBRACKET,     // )
    NUMBER,
    UNKNOWN
};
//  Convert TokenType to printable string

inline std::string tokenTypeToString(TokenType t) {
    switch (t) {
        case TokenType::IF: return "Keyword";
        case TokenType::THEN: return "Keyword";
        case TokenType::END: return "Keyword";
        case TokenType::REPEAT: return "Keyword";
        case TokenType::UNTIL: return "Keyword";
        case TokenType::READ: return "Keyword";
        case TokenType::WRITE: return "Keyword";
        case TokenType::SEMICOLON: return "Semicolon";
        case TokenType::ASSIGN: return "Assignment Operator";
        case TokenType::LESSTHAN: return "Comparison Operator";
        case TokenType::EQUAL: return "Comparison Operator";
        case TokenType::PLUS: return "Arithmetic Operator";
        case TokenType::MINUS: return "Arithmetic Operator";
        case TokenType::MULT: return "Arithmetic Operator";
        case TokenType::DIV: return "Arithmetic Operator";
        case TokenType::OPENBRACKET: return "Left Parenthesis";
        case TokenType::CLOSEDBRACKET: return "Right Parenthesis";
        case TokenType::NUMBER: return "Number";
        case TokenType::IDENTIFIER: return "Identifier";
        default: return "Unknown";
    }
}



 // TokenClassifier determines the type of each lexeme.
 // Classifies tokens as keywords, identifiers, numbers, or symbols.
 
class TokenClassifier {
private:
// Map each keyword to its TokenType
    std::unordered_map<std::string, TokenType> keywords;

    void initializeKeywords() {
        keywords["if"] = TokenType::IF;
        keywords["then"] = TokenType::THEN;
        keywords["end"] = TokenType::END;
        keywords["repeat"] = TokenType::REPEAT;
        keywords["until"] = TokenType::UNTIL;
        keywords["read"] = TokenType::READ;
        keywords["write"] = TokenType::WRITE;
    }


    
public:
    TokenClassifier() {
        initializeKeywords();
    }

    // ------------------------------------------------
    // classifyToken() 
    // Input: string lexeme
    // Output: TokenType
    // ------------------------------------------------
    TokenType classifyToken(const std::string& lexeme) const {
        if (lexeme.empty())
            return TokenType::UNKNOWN;

        // ----- Keywords -----
        if (keywords.count(lexeme))
            return keywords.at(lexeme);

        // ----- Single-character tokens -----
        if (lexeme == ";") return TokenType::SEMICOLON;
        if (lexeme == "<") return TokenType::LESSTHAN;
        if (lexeme == "=") return TokenType::EQUAL;
        if (lexeme == "+") return TokenType::PLUS;
        if (lexeme == "-") return TokenType::MINUS;
        if (lexeme == "*") return TokenType::MULT;
        if (lexeme == "/") return TokenType::DIV;
        if (lexeme == "(") return TokenType::OPENBRACKET;
        if (lexeme == ")") return TokenType::CLOSEDBRACKET;

        // ----- Assignment operator -----
        if (lexeme == ":=") return TokenType::ASSIGN;

        // ----- Number detection -----
        bool allDigits = true;
        for (char c : lexeme) {
            if (!std::isdigit(static_cast<unsigned char>(c))) {
                allDigits = false;
                break;
            }
        }
        if (allDigits)
            return TokenType::NUMBER;

        // ----- Identifier detection -----
        if (std::isalpha(static_cast<unsigned char>(lexeme[0]))) {
            for (size_t i = 1; i < lexeme.size(); ++i) {
                if (!std::isalnum(static_cast<unsigned char>(lexeme[i])))
                    return TokenType::UNKNOWN;
            }
            return TokenType::IDENTIFIER;
        }

        return TokenType::UNKNOWN;
    }
   
  
};

#endif // TOKEN_CLASSIFIER_H
