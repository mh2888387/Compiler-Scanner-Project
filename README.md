
# Scanner Project Life Cycle - README

This README explains the complete life cycle of a TINY language file as it moves through the scanner system, identifying the responsibilities of each team member.

---
## 1. Input Reading (Member 1: Input Manager)
- The process begins when the user provides a text file (e.g., `example.tny`) containing TINY code.
- Member 1 implements:
    - `readInput(filename)`: Opens the file and loads all its lines into an internal buffer for processing.
    - `getNextChar()`: Returns the next character from the buffer each time it's called.
    - `resetInput()`: Resets the character pointer to the start of the buffer.
- **Example:** If the input is:
```
if x then
 y := 4;
```
`getNextChar()` called repeatedly will yield: 'i', 'f', ' ', 'x', etc.

---
## 2. Scanning & Token Building (Member 2: Scanner)
- Member 2 is responsible for grouping characters into meaningful tokens (words, numbers, symbols).
- Implements:
    - `scanNextToken(tokenValue, tokenType)`: Collects characters to make tokens, delegates type detection.
    - `skipWhitespaceAndComments()`: Skips spaces and any comments to reach next relevant token.
- **Example:** For the code `if x then`, `scanNextToken()` produces (`tokenValue='if'`, `tokenType='Keyword'`), then (`tokenValue='x'`, `tokenType='Identifier'`), etc.

---
## 3. Token Classification (Member 3: Token Classifier)
- Member 3 determines and assigns the correct type for each lexeme.
- Implements:
    - `classifyToken(lexeme, tokenType)`: Sets token type (Keyword, Identifier, Number, Symbol).
    - `isKeyword(lexeme)`: Checks if the string is a reserved word in TINY.
    - `isNumber(lexeme)`: Checks if the string represents a number.
- **Example:** `classifyToken('if', type)` => `type='Keyword'`; `isNumber('12')` => `1` (true).

---
## 4. Output Writing (Member 4: Output Manager)
- Member 4 saves all recognized tokens and their types in an output file for later use.
- Implements:
    - `initOutput(filename)`: Opens output file for writing.
    - `writeToken(tokenValue, tokenType)`: Writes the token and its type to the output file.
    - `closeOutput()`: Closes the file securely.
- **Example:** After processing, output file might contain:
```
if, Keyword
x, Identifier
then, Keyword
```

---
## Full Flow Example
1. `input_manager` loads source file and serves up characters.
2. `scanner` consumes characters, builds lexemes, skips irrelevant data.
3. `token_classifier` categorizes lexemes and sets the appropriate type.
4. `output_manager` writes all tokens one by one into the output file.

Each team member focuses on a unique stage. All stages connect together to move from raw code input to a structured token output file, enabling further compilation steps.
