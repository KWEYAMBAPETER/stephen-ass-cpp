# Student Multiple-Choice Grading Matrix Program

This program automatically grades multiple-choice exam sheets for a cohort of students. It processes an immutable 2D data matrix containing student responses against a 1D answer key matrix, calculates individual raw success tallies, and outputs descriptive grading notifications.

---

## OOP Concepts Used

While this program uses a linear loop structure, it relies on modern C++ compile-time object patterns and data structuring frameworks that form the foundation of Object-Oriented design:

*   **Encapsulation of Dimensional State:** The program utilizes standard template library array containers (`std::array`). Unlike raw, standard C-style arrays, `std::array` wraps raw data pointers inside a formal class object template. This structure encapsulates both the core collection data and its sizing attributes safely, preventing data decay.
*   **Compile-Time Constant Expressions (`constexpr`):** The code defines dimensional parameters and memory matrices using `constexpr`. This enforces structural immutability, ensuring that internal object states remain completely protected from unauthorized outside modification or accidental memory leakage during runtime execution.
*   **Multidimensional Class Interlocking:** The data matrix `answers` is structured as a nested instance arrangement (`std::array<std::array<char, 10>, 8>`). This demonstrates object nesting, where individual row instances are securely nested within a parent array collection wrapper.

---

## Algorithm & Structural Steps

The grading routine evaluates student responses using a classic nested loop matrix traversal sequence:




### Algorithm Execution Steps:
1.  **Memory Allocation and Matrix Prep:** The application allocates space for a compile-time static 2D grid containing student answer selections alongside a separate array holding the definitive answer sheet baseline.
2.  **Cohort Traversal (Outer Loop):** The outer matrix execution track cycles through each student profile row systematically by index location. At the beginning of each row cycle, an internal counter variable (`correct_count`) is reset to zero.
3.  **Response Comparison (Inner Loop):** The inner processing track steps through every column position within the active student's row. It extracts the student's selected choice and validates it against the character occupying the corresponding index inside the answer key array.
4.  **Count Accumulation:** Every direct equality match detected between the student's choice string and the key increments the local row counter indicator variable.
5.  **Descriptive Report Output:** Once a student row completes its inner column evaluation, the accumulated tally is immediately formatted and pushed to the standard output stream (`std::cout`) before processing the next student profile.

---

## Possible Error Points & Edge Cases

When compiling, evaluating, or scaling this matrix grading program, analyze the following common vulnerabilities:

*   **Matrix Boundary and Index Skew Traps:**
    The outer loop utilizes 0-indexed sizing configurations (`size_t i = 0`). If developers alter the internal parameters manually without updating the central control boundaries (`NUM_STUDENTS` or `NUM_QUESTIONS`), the evaluation checks risk referencing memory outside the allocated framework, triggering out-of-bounds compilation failures or logic errors.
*   **Case Sensitivity Character Discrepancies:**
    The verification step relies on direct character equality comparison (`==`). Because character representations are distinct in ASCII binary encoding, an answer registered in lowercase (e.g., 'a') will evaluate as a mismatch when checked against an uppercase key element ('A'). If input mechanisms become dynamic in future updates, data normalization checks must be integrated.
*   **Hardcoded Sizing Matrix Limitations:**
    Because the structural architecture relies on fixed compile-time dimensional structures, the code cannot dynamically adjust if a professor attempts to grade an exam sheet with a fluctuating number of questions or an arbitrary number of incoming student papers. Adapting to variable sizing demands a structural shift to dynamically allocated heap wrappers like `std::vector`.
*   **Static Data Alignment Asymmetry:**
    If the initialization data rows within the double brace wrapper `{{ ... }}` do not supply a number of character items matching the explicit capacity limits defined by `NUM_QUESTIONS`, the compiler will either reject the program or pad missing entries with blank null termination metrics, causing calculation errors.