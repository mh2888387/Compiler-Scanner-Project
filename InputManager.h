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
    void readInput(const std::string& filename){
        this->buffer.clear();
        this->currentPos = 0;
        
        std::ifstream file(filename);
        if (!file.is_open()) {
            throw std::runtime_error("Could not open file: " + filename);
        }
        
        std::string line;
        while (std::getline(file, line)) {
            buffer += line + '\n'; // Preserve newlines
        }
        
        file.close();
    }
    
    /**
     * Returns the next character from the buffer.
     * @return Next character, or EOF (-1) when input ends
     * 
     * Example: First call returns 'i', second 'f', third ' ', etc.
     */
    char getNextChar(){
        if (this->currentPos < this->buffer.size()) {
            return this->buffer[this->currentPos++];
        } else {
            return -1; // Indicate end of input
        }
    }
    
    /**
     * Resets reading position to the beginning of the buffer.
     * Next call to getNextChar() will return the first character again.
     */
    void resetInput(){
        this->currentPos = 0;
    }
    
    /**
     * Checks if there are more characters to read.
     * @return true if more characters available, false otherwise
     */
    bool hasMoreChars() const {
        return this->currentPos < this->buffer.size();
    }
    
    /**
     * Peeks at the next character without advancing position.
     * @return Next character, or EOF if at end
     */
    char peekNextChar() const {
        if (this->currentPos < this->buffer.size()) {
            return this->buffer[this->currentPos];
        } else {
            return -1; // Indicate end of input
        }
    }
};

#endif // INPUT_MANAGER_H
