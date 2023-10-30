# Japanese-Scanner-And-Parser

This is a C++ program that functions as a simple lexical analyzer. It is designed to read input from a file 
and identify tokens such as words and periods, categorizing them based on specific criteria. The program includes 
deterministic finite automata (DFAs) for recognizing words and periods, a token type enumeration, a map of reserved 
words, a scanner, and a basic driver program to test the scanner.

## Usage

1. **Clone the Repository:**
    ```bash
    git clone https://github.com/your-username/lexical-analyzer.git
    ```

2. **Compile and Run:**
    - Ensure you have a C++ compiler installed (e.g., g++).
    - Navigate to the directory where the code is located.
    - Compile the code using the following command:
        ```bash
        g++ lexical_analyzer.cpp -o lexical_analyzer
        ```
    - Run the program:
        ```bash
        ./lexical_analyzer
        ```
    - The program will prompt you to enter the input file name. Provide the name of the file you want to analyze.

3. **Input File:**
    - Prepare a text file containing words and periods.
    - Ensure the input file is in the same directory as the executable or provide the correct file path when prompted.
