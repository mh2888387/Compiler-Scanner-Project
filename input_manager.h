
#ifndef INPUT_MANAGER_H
#define INPUT_MANAGER_H

// Reads all lines from the input TINY source file and stores them internally for further processing by the scanner.
// Input Example: File "example.tny" containing:
// if x then
//   y := 4;
// Output: All lines are loaded into the input buffer (internal array or string), ready for character-by-character reading.
void readInput(const char *filename);
// IMPLEMENTATION: Open the file with the given filename, read all lines, store in buffer/structure, and handle file errors.



// Returns the next character from internal storage each time it is called, or EOF when input ends.
// Input: None (called after readInput)
// Output: First call returns 'i', second 'f', third ' ', etc., until end of file then returns EOF (or -1)
char getNextChar(void);
// IMPLEMENTATION: Track current character index; increment after every call. If reached the end, return EOF.



// Resets reading position, so the next getNextChar will return the very first character again.
// Input: None
// Output: Next call to getNextChar() returns first input character again.
void resetInput(void);
// IMPLEMENTATION: Set buffer index to 0, so reading restarts from beginning.

#endif
