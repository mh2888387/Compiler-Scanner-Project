
#ifndef TOKEN_CLASSIFIER_H
#define TOKEN_CLASSIFIER_H

// Determines the type of a string lexeme: Keyword, Identifier, Number, or Symbol.
// Input: lexeme = "if"
// Output: tokenType = "Keyword"
// Example: classifyToken("x", tokenType) => tokenType = "Identifier"
void classifyToken(const char *lexeme, char *tokenType);
// IMPLEMENTATION: Compare lexeme to known keywords, check if number, otherwise identifier or symbol

// Checks if input is a valid TINY keyword (e.g., if, then, read, write...)
// Input: "repeat" -> returns 1; "xyz" -> returns 0
int isKeyword(const char *lexeme);
// IMPLEMENTATION: Return 1 if keyword, 0 if not (check in keywords table).

// Checks if input string is an integer number
// Input: "123" -> returns 1; "abc" -> returns 0
int isNumber(const char *lexeme);
// IMPLEMENTATION: Return 1 if all chars are digits, 0 otherwise.

#endif
