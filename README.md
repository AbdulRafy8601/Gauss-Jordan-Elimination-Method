# Gauss-Jordan Elimination Method

Mathematics assistance to solve systems of linear equations using the Gauss–Jordan elimination method.

This repository contains a C++ implementation to reduce augmented matrices to reduced row-echelon form (RREF) and extract solutions for linear systems. The program is intended for educational use and small-to-medium sized systems.

## Features

- Perform Gauss–Jordan elimination on augmented matrices
- Return the reduced row-echelon form (RREF)
- Detect unique solutions, no solution (inconsistent), or infinitely many solutions
- Simple, easy-to-read C++ implementation suitable for learning and extension

## Requirements

- A C++ compiler that supports C++11 or later (e.g., g++, clang++)

## Build

Compile the main C++ source file (replace `main.cpp` with the actual filename if different):

```bash
g++ -std=c++11 -O2 main.cpp -o gauss
```

## Run / Usage

Run the compiled program and provide the augmented matrix via standard input. The expected input format is an integer n (number of rows / equations) followed by m columns per row where m = n+1 for an augmented matrix (variables plus RHS).

Example for a 3x4 augmented matrix (3 equations, 3 variables plus right-hand side):

```text
3 4
2 1 -1 8
-3 -1 2 -11
-2 1 2 -3
```

For the matrix above the solution is:

x = 2, y = 3, z = -1

If your program uses a different input format (for example separate `n` and `m` lines or prompts), adjust the command above accordingly.

## Example

Given the input shown in the Usage section, the program should output the reduced row-echelon form and the solution vector. If the system has no solution or infinitely many solutions, the program should indicate that.

## Notes

- This implementation is best suited for learning and small matrices. For large systems or high performance requirements, consider numerical libraries (Eigen, Armadillo) and numeric stability techniques (partial pivoting, etc.).
- If your code uses a different filename than `main.cpp`, update the build instructions accordingly.

## Contributing

Contributions, bug reports, and improvements are welcome. Please open issues or submit pull requests with clear descriptions and test cases.

## License

Specify a license for the project (e.g., MIT) by adding a `LICENSE` file. If you want, I can add a suggested license for you.
