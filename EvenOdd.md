# Odd or Even Integer Verification Program

This program prompts a user to enter any integer value, performs a mathematical parity check using the modulo operator, and returns a complete, standalone textual analysis declaring whether the input value is odd or even.

---

##  OOP Concepts Used

While this program follows a straightforward procedural structure suited for a fundamental conditional check, it implements essential **Object-Oriented Programming (OOP) and Software Architecture foundations**:

*   **Data Stream Abstraction:** The code abstracts terminal interactions using the C++ standard library object streams (`std::cin` and `std::cout`). Instead of forcing the programmer to write low-level hardware interrupt calls to capture keyboard input or write pixels to the console screen, the program communicates through high-level input/output stream abstractions.
*   **State Flag Encapsulation:** The program evaluates the input stream state directly inside a conditional check (`if (!(cin >> number))`). This utilizes the encapsulation mechanics of the `std::istream` object, which internally tracks error flags (like the `failbit`) and cleanly surfaces them via boolean operators.
*   **Logical Modularization:** The application clearly separates the input validation logic from the computational parity analysis, showcasing foundational single-responsibility design principles.

---

## Algorithm & Structural Steps

The logic follows a linear execution pipeline to calculate and display the number's parity:




### Main Program Steps:
1.  **Stream Allocation:** An integer variable `number` is declared to allocate space in memory.
2.  **Input Filtering:** The user is prompted for an integer. The stream extraction condition checks if the user entered valid numeric data. If an invalid type (such as an alphabetic letter) is detected, the program triggers an early failure exit block (`return 1`).
3.  **Parity Arithmetic Execution:** The code subjects the valid integer to a division operation via the modulo operator (`% 2`). The modulo operator divides the integer by 2 and returns only the remaining fraction value.
4.  **Complete Output Formatting:** 
    *   If the remainder equals `0`, the value divides evenly, and the program executes the `even` string pipeline.
    *   If the remainder is not `0`, the program routes execution to the `else` block to output the `odd` string pipeline.
    *   Both final output scenarios return a standalone, descriptive sentence containing the original value, fully satisfying the requirement to avoid ambiguous "yes/no" results.

---

##  Possible Error Points & Edge Cases

When compiling or testing this parity check program, look out for the following critical edge cases and potential vulnerabilities:

*   **Handling of Negative Integers:**
    In C++, the modulo operator retains the sign of the dividend (the first number). For example, `-5 % 2` evaluates to `-1` (not `1`). Because your implementation checks `if (number % 2 == 0)`, it handles negative even numbers (`-4 % 2 == 0`) and negative odd numbers perfectly. Changing the conditional logic to check `if (number % 2 == 1)` would break the logic for all negative odd integers.
*   **The Zero (0) Case:**
    Mathematically, zero is an even number because `0 / 2 = 0` with a remainder of `0`. The expression `0 % 2 == 0` evaluates to true, correctly categorizing `0` as an even number without throwing any structural arithmetic errors like a divide-by-zero crash.
*   **Input Stream Distortions (Type Mismatch):**
    If a user enters a decimal value (e.g., `4.7`) or text characters (e.g., `abc`), the `cin >> number` operation fails. Because your code contains an explicit validation conditional check (`if (!(cin >> number))`), the stream error is caught securely, preventing the program from running with dangerous, uninitialized garbage values.
*   **Integer Bounds & Buffer Overflow Limits:**
    Standard `int` fields occupy a 32-bit memory window, limiting inputs to values between `-2,147,483,648` and `2,147,483,647`. If a user enters an integer value outside this window (e.g., a 16-digit number), the extraction stream will trigger a failure flag, dropping execution straight into your error-handling routine.