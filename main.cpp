#include "input_manager.h"
#include "scanner.h"
#include "token_classifier.h"
#include "output_manager.h"
#include <stdio.h>
#include <string.h>

#define MAX_TOKENS 1000
#define MAX_TOKEN_LEN 50
#define MAX_TYPE_LEN 30

struct Token {
    char value[MAX_TOKEN_LEN];
    char type[MAX_TYPE_LEN];
};

int main() {
    struct Token tokenList[MAX_TOKENS];
    int numTokens = 0;
    char tokenValue[MAX_TOKEN_LEN];
    char tokenType[MAX_TYPE_LEN];

    // 1. Read input file
    readInput("test.tny");

    // 2. Scan tokens and classify them
    while (1) {
        scanNextToken(tokenValue);
        classifyToken(tokenValue, tokenType);
        if (strcmp(tokenType, "EOF") == 0 || numTokens >= MAX_TOKENS)
            break;
        strcpy(tokenList[numTokens].value, tokenValue);
        strcpy(tokenList[numTokens].type, tokenType);
        numTokens++;
    }

    // 3. Write tokens to output
    initOutput("tokens.txt");
    for (int i = 0; i < numTokens; i++) {
        writeToken(tokenList[i].value, tokenList[i].type);
    }
    closeOutput();

    printf("Scanned %d tokens. Tokens are written to tokens.txt\n", numTokens);
    return 0;
}
