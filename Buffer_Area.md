# GIS Buffer Proximity Analysis Program

This program executes a spatial buffer proximity analysis. It sets up a central geographic benchmark point, takes multiple boundary buffer radii, and evaluates a series of independent target coordinates using the Euclidean distance formula to determine which points fall inside each specified buffer zone.

---

##  OOP Concepts Used

While this program uses structured procedural workflows to manage raw data blocks, it implements foundational principles of **Object-Oriented Programming (OOP) logic and architectural design**:

*   **Abstraction:** The computational details of coordinate geometry and vector proximity formulas are completely abstracted away from the user. The interface presents clean, real-world spatial concepts ("Center Point Name", "Buffer Radius") while hiding the underlying library implementation details (`sqrt`, `pow`).
*   **Encapsulation of Data Entities:** The attributes that define a physical point entity (its name string, X-coordinate, and Y-coordinate) are grouped and managed across parallel arrays (`pointNames[]`, `pointX[]`, and `pointY[]`). This mimics an object-like relationship structure by ensuring that individual element indices tightly bind an item's identity to its physical properties.
*   **Separation of Concerns:** The code structure isolates independent operations into distinct, organized logic blocks: Configuration Gathering, Radius Profiling, Target Point Compilation, and Matrix Analysis. This foundational architecture underpins modular object-oriented system design.

---

##  Algorithm & Structural Steps

The calculation engine maps spatial vector relationships by running a nested loop traversal through the following sequential steps:




### Program Step Breakdown:
1.  **Origin Baseline Setup:** The program prompts the user to input a central coordinate anchor node $(X_c, Y_c)$ and assigns it a tracking name.
2.  **Radius Matrix Assembly:** The program captures the total number of buffer thresholds and fills a static floating-point array (`buffers[]`) with distinct geometric radii.
3.  **Target Point Compilation:** The program builds a coordinate collection grid, prompting the user for up to 100 named test points distributed across the vector plane.
4.  **Nested Vector Evaluation:**
    *   The **outer loop** cycles through each buffer boundary size (`currentRadius`).
    *   The **inner loop** calculates the distance from the baseline anchor to the selected point using the Euclidean distance equation:
        $$\text{distance} = \sqrt{(X_p - X_c)^2 + (Y_p - Y_c)^2}$$
    *   If the calculated distance is less than or equal to the active radius parameters ($d \le r$), the program logs the coordinates as sitting inside the zone and increments the count.

---

## Possible Error Points & Edge Cases

When running, testing, or grading this spatial application, watch out for the following critical edge cases and security risks:

*   **Static Memory Buffer Overflow (Critical Vulnerability):**
    The arrays for tracking buffers and coordinates are hardcoded with a rigid structural size boundary of 100 elements (`buffers[100]`, `pointX[100]`, etc.). If a user requests a number of test points or buffers greater than 100 (e.g., `numPoints = 120`), the program will overflow its allocated stack frame, creating severe memory corruption, undefined runtime bugs, or system crashes.
*   **Floating-Point Precision Mismatches:**
    Because coordinates are stored as `double` types, calculations are susceptible to standard binary floating-point rounding limits. A target point lying *exactly* on the outer perimeter boundary line of a buffer zone may occasionally evaluate as invalid or skipped due to tiny, fractional precision variations (e.g., `4.000000000000001 <= 4.0` evaluates to false).
*   **Data Stream Failure Loops:**
    The entry streams lack data type validation wrappers. If a user accidentally enters string text or alphabetic characters when prompted for numerical parameters (such as `centerX` or `numBuffers`), the standard input stream (`cin`) breaks into a failed flag state. This can lock the code into an endless execution loop or auto-populate subsequent inputs with invalid, dangerous garbage values.
*   **Unchecked Negative Radii Entry:**
    The application does not run mathematical sanitization checks on incoming radii. If a user sets a buffer parameter to a negative number (e.g., `-25.0`), the tracking evaluation ($d \le r$) will permanently fail since a square root distance calculation will always return a value greater than or equal to zero.