#ifndef INPUT_MANAGER_H
#define INPUT_MANAGER_H

#include <string>
#include <vector>

/**
 * InputManager class handles reading and managing input from TINY source files.
 * Provides character-by-character access to the input stream.
 */
class InputManager {
private:
    std::string buffer;        // Stores entire file content
    size_t currentPos;         // Current reading position
    
public:
    InputManager();
    
    /**
     * Reads all lines from the input TINY source file and stores them internally.
     * @param filename - Path to the TINY source file
     * @throws std::runtime_error if file cannot be opened
     * 
     * Example: readInput("example.tny") loads entire file into buffer
     */
    void readInput(const std::string& filename);
    
    /**
     * Returns the next character from the buffer.
     * @return Next character, or EOF (-1) when input ends
     * 
     * Example: First call returns 'i', second 'f', third ' ', etc.
     */
    char getNextChar();
    
    /**
     * Resets reading position to the beginning of the buffer.
     * Next call to getNextChar() will return the first character again.
     */
    void resetInput();
    
    /**
     * Checks if there are more characters to read.
     * @return true if more characters available, false otherwise
     */
    bool hasMoreChars() const;
    
    /**
     * Peeks at the next character without advancing position.
     * @return Next character, or EOF if at end
     */
    char peekNextChar() const;
};

#endif // INPUT_MANAGER_H
