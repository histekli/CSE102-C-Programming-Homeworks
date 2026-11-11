# CSE102 - C Programming Homeworks

This repository contains homework assignments for the CSE102 C Programming course.

## Assignments

### **PA1**: Classification Algorithm
A machine learning algorithm that classifies new points into two classes by calculating the average points of the classes.
- **Features**:
  - Takes 10 points for each of two classes in 2D plane
  - Calculates the average points of the classes
  - Creates a separating line
  - Classifies new points and calculates distances
- **Concepts Used**: Mathematical functions, average calculation, slope calculation, distance formula

### **PA2**: N-gram Analysis (2-gram Counter)
Counts 2-grams (consecutive pairs of numbers) in text files and calculates their frequencies.
- **Features**:
  - Reads number pairs from file
  - Detects repeating 2-grams
  - Performs frequency counting
  - Writes results to file
- **Concepts Used**: File operations, array manipulation, fseek usage

### **PA3**: Polynomial Evaluator
Evaluates polynomial expressions for specific values by reading them from files.
- **Features**:
  - Reads expressions from polynomial file
  - Gets variable values from file
  - Parses terms in ax^b format
  - Solves polynomials using string manipulation
- **Concepts Used**: String processing, strtok, sscanf, math.h, file operations

### **PA4**: Word Search Puzzle
Searches for words in a 2D character matrix in horizontal, vertical, and diagonal directions.
- **Features**:
  - Reads character matrix from file
  - Processes word list
  - Searches in three directions (horizontal, vertical, diagonal)
  - Reports positions of found words
- **Concepts Used**: 2D arrays, string comparison, function design

### **PA5**: Nutrition Calculator
Analyzes meal recipes to calculate total calories and macro nutrient values.
- **Features**:
  - Uses recursive functions
  - Nutrition information with struct data structure
  - Calorie calculation (carbohydrate: 4kcal/g, protein: 4kcal/g, fat: 9kcal/g)
  - Percentage ratio calculations
- **Concepts Used**: Struct, recursive functions, string parsing, mathematical operations

### **PA6**: Language Recognition
Predicts which language texts belong to using bi-gram frequency analysis.
- **Features**:
  - Bi-gram (two character) frequency analysis
  - Comparison with 5 different languages
  - Similarity measurement (dissimilarity calculation)
  - Statistical language recognition algorithm
- **Concepts Used**: 2D arrays, statistics, file operations, fabs() function

### **PA7**: Digital Circuit Simulator
Simulates digital circuits composed of logic gates.
- **Features**:
  - Dynamic memory management (malloc/free)
  - Linked data structures
  - AND, OR, NOT, FLIPFLOP gates
  - Recursive evaluation
  - Circuit file and input file processing
- **Concepts Used**: Struct, pointer, malloc/free, recursive evaluation, switch-case

## Setup

A C compiler (GCC) is required to build the assignments.

- **Linux (Debian/Ubuntu)**: `sudo apt install gcc`
- **macOS**: `xcode-select --install` (or `brew install gcc`)

Example compile command:

```bash
gcc -o PA1 hasan_can_istekli_PA1.c -lm
```

Example run:

```bash
./PA1
```

## Compilation

To compile each C file:

```bash
gcc -o PA1 hasan_can_istekli_PA1.c -lm
gcc -o PA2 hasan_can_istekli_PA2.c -lm
gcc -o PA3 hasan_can_istekli_PA3.c -lm
gcc -o PA4 hasan_can_istekli_PA4.c -lm
gcc -o PA5 hasan_can_istekli_PA5.c -lm
gcc -o PA6 hasan_can_istekli_PA6.c -lm
gcc -o PA7 hasan_can_istekli_PA7.c -lm
```

## File Structure

- **Source Code**:
  - `hasan_can_istekli_PA*.c` - C source code files
- **Documentation**:
  - `PA*.pdf` - Assignment instructions and descriptions
  - `README.md` - This documentation file
- **Compiled Files** (in gitignore):
  - `PA*` - Compiled executable files

## C Programming Concepts Used

### Basic Concepts
- **Variables and Data Types**: int, float, double, char
- **Arrays**: 1D and 2D arrays, string manipulation
- **Loops**: for, while, do-while
- **Conditional Statements**: if-else, switch-case
- **Functions**: Parameter passing, return values

### Advanced Topics
- **Struct Structures**: Data organization and manipulation
- **Pointer Usage**: Memory addressing and reference passing
- **Dynamic Memory Management**: malloc, free
- **Recursive Functions**: Self-calling functions
- **File Operations**: fopen, fclose, fscanf, fprintf, fgets, fseek

### Libraries Used
- **stdio.h**: Standard input/output operations
- **string.h**: String manipulation functions
- **math.h**: Mathematical functions (pow, sqrt, fabs)
- **stdlib.h**: Dynamic memory management and utility functions

## Notes

- All programs use the math library (`-lm` flag)
- Files have been tested with GCC compiler
- Programs are designed to work on Linux/Unix systems
- Each assignment demonstrates different programming concepts and problem-solving techniques