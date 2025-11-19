#ifndef OUTPUT_MANAGER_H
#define OUTPUT_MANAGER_H

#include <string>
#include <fstream>
#include <vector>

using namespace std;

/**
 * Token structure to hold token value and type pairs.
 */
struct Token {
    string value;
    string type;

    Token(const string& val, const string& typ)
        : value(val), type(typ) {}
};

/**
 * OutputManager handles writing tokens to output files.
 * Manages file operations for saving token stream.
 */
class OutputManager {
private:
    ofstream outputFile;     // Output file stream
    string filename;          // Output filename
    bool isOpen;                   // File open status
    
public:
    OutputManager();
    ~OutputManager();
    
    /**
     * Opens output file for writing tokens.
     * @param filename - Name of output file
     * @throws runtime_error if file cannot be opened
     * 
     * Example: initOutput("tokens.txt")
     */
    void initOutput(const string& filename);
    
    /**
     * Writes a single token to the output file.
     * @param tokenValue - The token string
     * @param tokenType - The token type
     * 
     * Example: writeToken("x", "Identifier")
     *          Output: "x, Identifier"
     */
    void writeToken(const string& tokenValue, const string& tokenType);
    
    /**
     * Writes multiple tokens from a vector.
     * @param tokens - Vector of Token structs
     */
    void writeTokens(const vector<Token>& tokens);
    
    /**
     * Closes the output file and ensures data is flushed.
     */
    void closeOutput();
    
    /**
     * Checks if output file is currently open.
     * @return true if file is open, false otherwise
     */
    bool isOutputOpen() const;
};

#endif // OUTPUT_MANAGER_H
