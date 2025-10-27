
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
    - `scanNextToken(tokenValue)`: Collects characters to make tokens
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

---

## 🔍 Clarification: Scanner (Member 2) vs. Token Classifier (Member 3)

Understanding the separation of responsibilities between these modules is key for teamwork and proper implementation.

**Member 2 – Scanner**
- Scans the input stream character-by-character.
- Groups characters into tokens/words/symbols such as `"if"`, `"x"`, `"123"`, `":="`.
- **Example:** Extracts `"if"` from the input stream, but does **not** decide whether `"if"` is a keyword or identifier.

**Member 3 – Token Classifier**
- Inspects each token string produced by the scanner.
- Decides the type of token: keyword, number, identifier, symbol, etc.
- **Example:** If the scanner hands over `"if"`, the token classifier labels it as a **keyword**. `"x"` is labeled as an **identifier**. `"123"` as a **number**.

**Analogy**
- Scanner: *Splits a sentence into individual words.*
- Token Classifier: *Assigns grammatical roles (noun, verb, etc.) to each word.*

**This separation keeps your project modular and clean. The scanner finds all tokens; the classifier gives each token its proper label—making later processing much easier.**

---


# Data Flow: What Each Member Receives and Outputs

---

## Member 1: Input Manager
**Receives:**
- The file name for the TINY code (e.g., "test.tny").
**Outputs:**
- Provides individual characters, one at a time, from the input file.
**Example:**
Input file:
```
if x then
y := 4;
```
Call sequence:
```
readInput("test.tny") // Loads file
getNextChar()         // returns: 'i', 'f', ' ', 'x', ' ', 't', ... until EOF
```
---

## Member 2: Scanner
**Receives:**
- Access to the characters from Member 1, through getNextChar()
**Outputs:**
- Builds token string (e.g., "if", "x", ":=", "4"), hands to Member 3 for classification.
**Example:**
Input character sequence: 'i','f',' ','x',' ',':','=',...
Output:
```
"if"
"x"
":="
"4"
";"
```
Each token is a C string or char array.
---

## Member 3: Token Classifier
**Receives:**
- Each token string from the scanner
**Outputs:**
- Returns token type as a string (e.g., "Keyword", "Identifier", "AssignmentOperator", "Number")
- (Best practice: Combine as a struct or pair (token_value, token_type))
**Example:**
- Receives "if"  → Classifies as ("if", "Keyword")
- Receives "x"   → Classifies as ("x", "Identifier")
- Receives "4"   → Classifies as ("4", "Number")
- Receives ":="  → Classifies as (":=", "AssignmentOperator")
---

## Member 4: Output Manager
**Receives:**
- Array or list of tokens, or individual pairs of (token_value, token_type). Each pair can be stored in a struct:
```c
struct Token {
  char value[50];
  char type[30];
};
```
Typically receives:
```c
struct Token tokenList[] = {
  {"if", "Keyword"},
  {"x", "Identifier"},
  {":=", "AssignmentOperator"},
  {"4", "Number"},
  {";", "Semicolon"}
};
```
**Outputs:**
- Prints each token and its type (writing to file or stdout):
```
if, Keyword
x, Identifier
:=, AssignmentOperator
4, Number
;, Semicolon
```
**Example usage (loop over array):**
```c
for (int i=0; i<numTokens; i++) {
  writeToken(tokenList[i].value, tokenList[i].type);
}
```
---
