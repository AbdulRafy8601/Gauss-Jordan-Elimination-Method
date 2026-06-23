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
### Case 1: Unique Solution
<img width="622" height="484" alt="Execution Example " src="https://github.com/user-attachments/assets/335d0bf4-a761-479c-afa9-f4430746b341" />

### Case 2: Infinite Many Solution
<img width="684" height="473" alt="Infinite Many Solutions" src="https://github.com/user-attachments/assets/ec79704f-5c40-4b11-8c6e-fb09b58c5e2c" />

### Case 3: Inconsistent System
<img width="505" height="431" alt="image" src="https://github.com/user-attachments/assets/5229b099-9f20-48cf-ba2a-cd58a7881ad6" />

## Example

Given the input shown in the Usage section, the program should output the reduced row-echelon form and the solution vector. If the system has no solution or infinitely many solutions, the program should indicate that.

## Notes

- This implementation is best suited for learning and small matrices. For large systems or high performance requirements, consider numerical libraries (Eigen, Armadillo) and numeric stability techniques (partial pivoting, etc.).
- If your code uses a different filename than `main.cpp`, update the build instructions accordingly.

## Contributing

Contributions, bug reports, and improvements are welcome. Please open issues or submit pull requests with clear descriptions and test cases.

## License

Specify a license for the project (e.g., MIT) by adding a `LICENSE` file. If you want, I can add a suggested license for you.
