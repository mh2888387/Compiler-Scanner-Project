# C++ TINY Scanner Project

This project implements a lexical scanner for the TINY programming language using modern C++.

## Project Structure

The scanner is divided into four main components, each implemented as a separate class:

### 1. InputManager (`InputManager.h`)
Handles reading and managing input from TINY source files.
- Reads entire file into internal buffer
- Provides character-by-character access via `getNextChar()`
- Supports peeking and position reset functionality

### 2. Scanner (`Scanner.h`)
Extracts tokens from the input stream.
- Groups characters into meaningful lexemes
- Skips whitespace and comments
- Handles identifiers, numbers, and symbols
- Returns tokens one at a time

### 3. TokenClassifier (`TokenClassifier.h`)
Determines the type of each token.
- Classifies tokens as keywords, identifiers, numbers, or operators
- Uses hash set for efficient keyword lookup
- Implements type-safe enumeration for token types

### 4. OutputManager (`OutputManager.h`)
Handles writing tokens to output files.
- Opens and manages output file stream
- Writes tokens in format: "value, type"
- Supports batch writing of token vectors

## Features

✅ **Modern C++ Design**
- Object-oriented architecture with encapsulated classes
- STL containers (string, vector, unordered_set)
- Exception handling for robust error management
- RAII for automatic resource cleanup

✅ **Type Safety**
- Enum classes for token types
- Const correctness throughout
- No raw pointers or manual memory management

✅ **Comprehensive Documentation**
- Detailed comments for all public methods
- Usage examples in header files
- Clear API design

## TINY Language Keywords

The scanner recognizes the following TINY keywords:
- `if`, `then`, `else`, `end`
- `repeat`, `until`
- `read`, `write`

## Building the Project

### Requirements
- C++11 or later compiler (g++, clang++, MSVC)
- Standard C++ library

### Compilation
```bash
g++ -std=c++11 -o scanner main.cpp -I.
```

Or with all warnings enabled:
```bash
g++ -std=c++11 -Wall -Wextra -o scanner main.cpp -I.
```

## Usage

1. Create a TINY source file (e.g., `test.tny`):
```
if x then
  y := 4;
end
```

2. Run the scanner:
```bash
./scanner
```

3. Output will be written to `tokens.txt`:
```
if, Keyword
x, Identifier
then, Keyword
y, Identifier
:=, Assignment Operator
4, Number
;, Semicolon
end, Keyword
```

## Token Types

The scanner recognizes the following token types:
- **KEYWORD**: Reserved words (if, then, else, etc.)
- **IDENTIFIER**: Variable names
- **NUMBER**: Integer literals
- **ASSIGNMENT_OP**: `:=`
- **COMPARISON_OP**: `<`, `=`
- **ARITHMETIC_OP**: `+`, `-`, `*`, `/`
- **SEMICOLON**: `;`
- **LPAREN/RPAREN**: `(`, `)`

## Implementation Notes

### Member Responsibilities (Original C Version)
- **Member 1**: InputManager - File reading and character stream
- **Member 2**: Scanner - Token extraction and grouping
- **Member 3**: TokenClassifier - Token type determination
- **Member 4**: OutputManager - Token output to file

### C++ Improvements Over C Version
1. **Memory Safety**: No buffer overflows, automatic cleanup
2. **Type Safety**: Enum classes instead of string comparisons
3. **Error Handling**: Exceptions instead of error codes
4. **Code Organization**: Classes instead of global functions
5. **STL Usage**: Modern containers instead of C arrays
6. **Resource Management**: RAII pattern for files

## Example Program Flow

```
1. InputManager reads "test.tny" into buffer
2. Scanner calls getNextChar() repeatedly
3. Scanner groups characters into tokens
4. TokenClassifier determines each token's type
5. OutputManager writes tokens to "tokens.txt"
```

## Error Handling

The program handles the following errors:
- File not found (throws runtime_error)
- File read errors (throws runtime_error)
- Invalid output file (throws runtime_error)

All errors are caught in main() and reported to stderr.

## Extending the Scanner

To add new token types:
1. Add enum value to `TokenType` in `TokenClassifier.h`
2. Update `classifyToken()` method
3. Update `tokenTypeToString()` method
4. Add recognition logic in Scanner if needed

To add new keywords:
1. Update `initializeKeywords()` in TokenClassifier implementation

## License

This project is for educational purposes.

## Authors

Converted from C to C++ for improved safety, maintainability, and modern C++ best practices.
