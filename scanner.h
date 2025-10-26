
#ifndef SCANNER_H
#define SCANNER_H
#include "input_manager.h"

// Extracts the next valid token (lexeme) from input, writing its value and type to provided arrays.
// Input: Call after initializing input and optionally skipping white/comment.
// Output Example (for input: "if x then"):
// First call: tokenValue="if", tokenType="Keyword"
// Second call: tokenValue="x", tokenType="Identifier"
// Third call: tokenValue="then", tokenType="Keyword"
void scanNextToken(char *tokenValue, char *tokenType);
// IMPLEMENTATION: Read next non-whitespace chars, group as token. Use classifyToken to decide type.

// Skips whitespace (spaces, tabs, newlines) and comments (if TINY supports // or { } for comments)
// Input Example: "  // this is a comment\nx"
// Output: Scanner moves to position of 'x' (next significant char)
void skipWhitespaceAndComments(void);
// IMPLEMENTATION: Loop reading chars using getNextChar() until find non-whitespace and non-comment char to stop at next token.

#endif
