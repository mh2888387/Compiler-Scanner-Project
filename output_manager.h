
#ifndef OUTPUT_MANAGER_H
#define OUTPUT_MANAGER_H

// Prepares the output file to which tokens (tokenValue, tokenType) will be written.
// Input: filename="tokens.txt"
// Output: tokens.txt file ready for writing.
void initOutput(const char *filename);
// IMPLEMENTATION: Open file for writing, store file pointer globally

// Writes a token value and its type to the output file, each on a new line.
// Input: writeToken("x", "Identifier");
// Output: File will contain line: x, Identifier
void writeToken(const char *tokenValue, const char *tokenType);
// IMPLEMENTATION: Write formatted string to file. Each token on a new line: e.g. "if, Keyword\n"

// Closes the output file, ensuring data is saved.
// Input: None
// Output: File is closed, further writeToken calls don't work.
void closeOutput(void);
// IMPLEMENTATION: Close the file, clean up any resources.

#endif
