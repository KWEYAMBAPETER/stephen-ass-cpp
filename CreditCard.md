# Credit Card Validation Program (Luhn Algorithm)

This program prompts a user to input a credit card number as an integer and determines its structural validity using length checks, prefix matching, and the **Luhn Algorithm (Mod 10 Check)**.


##  OOP Concepts Used

While the core functionality of this program relies on modular procedural execution to strictly match the requested function signatures, it applies essential **Object-Oriented Programming (OOP) and Software Engineering foundational concepts**:

*   **Abstraction & Modularization:** The internal complexities of the mathematical Luhn check, prefix matching, and digit processing are completely hidden from the `main()` function. `main()` interacts only with a simplified high-level interface (`isValid()`), isolating distinct tasks into autonomous, reusable code units.
*   **Encapsulation of Logic:** Data transformation logic is securely bound within targeted operations. For instance, `getDigit()` encapsulates the exact rule for splitting and summing double-digit numbers without exposing that structural logic to the master loop.
*   **Strong Typing and Data Management:** To handle 13-to-16 digit identifiers safely without suffering from memory truncation or signed overflow behaviors, the program leverages the 64-bit primitive data space (`long long`), acting as a clean wrapper for raw data processing.

## 🧬 Algorithm & Structural Steps

The verification workflow runs through the following systematic execution pipeline:






### Main Function Processing Steps:
1.  **Input Collection:** The application queries the system input streams for a `long long` integer representation of the card sequence.
2.  **Size and Validation Filtering:** `getSize()` maps out the literal magnitude of the buffer. If it falls outside the range of $[13, 16]$, execution drops out early as `false`.
3.  **Prefix Identification:** `getPrefix()` and `prefixMatched()` isolate the initial characters of the number to confirm alignment with authoritative issuer benchmarks ($4$, $5$, $37$, or $6$).
4.  **Mathematical Traversal:** 
    *   The code steps backward through the number using modulo arithmetic (`% 10`) to extract individual digits.
    *   It scales position pointers by a factor of 100 (`number /= 100`) to intentionally bounce over alternating digit slots, satisfying independent calculations for both odd and even tracks cleanly.
5.  **Divisibility Resolution:** The algorithm combines the final tallies from both processing tracks. If the combined sum outputs a remainder of zero when divided by 10, the card passes.

---

##  Possible Error Points & Edge Cases

When implementing, executing, or grading this program, look out for the following critical edge cases and implementation risks:

*   **Standard Integer Overflow (Critical Mistake):** 
    Using a standard 32-bit `int` or `long` data type will cause immediate integer overflow errors because they can only store numbers up to roughly 2.14 billion ($2 \times 10^9$). A 16-digit credit card number requires a 64-bit container. **Resolution:** The code strictly uses `long long` to allocate enough memory footprint space.
*   **Leading Zero Handling:** 
    If a user inputs a numeric sequence beginning with a leading zero (e.g., `04388...`), mathematical streams discard leading zeros from numerical types automatically. This alters both the total structural length check (`getSize`) and shifts the odd/even positioning calculations out of alignment.
*   **Malformed Non-Numeric Characters:** 
    Entering spaces, hyphens, or alphabet characters (e.g., `4388-5760-...`) into a `cin >> long long` numeric extraction stream breaks the input buffer completely, forcing the program into an infinite loop or producing a garbage variable state of `0`.
*   **Array/String Index Shifting Traps:** 
    The Luhn algorithm natively reads positions starting from **right to left** (where the rightmost check digit is index position 1, an odd place). If an implementation incorrectly converts the number to a string and loops from left to right using 0-indexed values without adjusting for length parity, the odd/even tracks flip entirely, reversing the logic and invalidating valid entries.