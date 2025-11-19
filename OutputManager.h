#ifndef OUTPUT_MANAGER_H
#define OUTPUT_MANAGER_H

#include <iostream>
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
    ofstream initOutput(const string& filename)
    {
        ofstream fileStream(filename);
        if(!fileStream.is_open())
        {
            throw runtime_error("Could not open output file: " + filename);
        }
        cout << "Opened output file:" << filename << "\n";
        return fileStream;
    }

    
    /**
     * Writes a single token to the output file.
     * @param tokenValue - The token string
     * @param tokenType - The token type
     * 
     * Example: writeToken("x", "Identifier")
     *          Output: "x, Identifier"
     */
    void writeToken(ofstream& fileStream, const Token& token)
    {
        if(fileStream.is_open())
        {
            outputFile << token.value << ", " << token.type << "\n";
        }
        else {
            throw runtime_error("Can not write tokens.\n");
        }
    }
    
    /**
     * Writes multiple tokens from a vector.
     * @param tokens - Vector of Token structs
     */
    void writeTokens(ofstream& fileStream, const vector<Token>& tokens)
    {
        if(fileStream.is_open()){
            cout << "Writing Tokens...\n";
            for(const auto& token: tokens)
            {
                fileStream << token.value << ", " << token.type << "\n";
            }
        } else {
            throw runtime_error("Can not write tokens.\n");
        }
    }
    
    /**
     * Closes the output file and ensures data is flushed.
     */
    void closeOutput(ofstream& fileStream)
    {
        if(fileStream.is_open()){
            fileStream.close();
            cout << "Closed output file.\n";
        }
    }
    
    /**
     * Checks if output file is currently open.
     * @return true if file is open, false otherwise
     */
    bool isOutputOpen(const ofstream& fileStream)
    {
        return fileStream.is_open();
    }
};

#endif // OUTPUT_MANAGER_H
