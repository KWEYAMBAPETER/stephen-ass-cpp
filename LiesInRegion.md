# 2D Bounding Region Geometry Verification Program

This program models an irregular, piece-wise 2D geometric plane bound by custom mathematical functions (linear equations, a parabola, trigonometric sine waves, and a circle arc). It prompts users for coordinate locations and evaluates whether targeted coordinates lie within or outside this defined mathematical region.

---

## OOP Concepts Used

While the analytical execution uses a mathematical function mapping process, the program integrates foundational Object-Oriented Programming (OOP) and Software Architecture principles:

*   **Data Grouping and Structuring:** The program utilizes a data structure `struct Point` to group raw coordinate elements into a single data entity. This serves as an introductory framework for OOP encapsulation by packaging related data primitives (`double x` and `double y`) into a distinct object type.
*   **Abstraction of Complexity:** The mathematical rules, range partitions, and equations governing the irregular boundary region are hidden inside the `isPointInside()` function. The main routine interacts with a high-level abstraction (asking if a point is inside), without needing to manage the complex piece-wise algebraic conditions directly.
*   **Polymorphic Collection Traversal:** The application uses a standard template library container (`std::vector`) to maintain a collection of Point structures. By utilizing an automated ranged-based traversal loop (`for (const auto& p : batchPoints)`), it treats the data collection as an iterable object matrix, mirroring clean object grouping workflows.

---

## Algorithm & Structural Steps

The verification routine maps geographic coordinate values against multi-tiered equations through a clear execution pipeline:




### Main Pipeline Implementation Details:
1.  **Interactive Input Sanitation:** A while loop forces repetitive data collection until a valid X-coordinate sitting within the absolute horizontal structural frame of $[-5.0, 4.5]$ is captured. If alphabetic parsing failures occur, the stream breaks early using code execution failures (`return 1`).
2.  **Piece-wise Lower Domain Extraction:** The `isPointInside` routine assesses the input X coordinate value. If the coordinate rests on the left edge ($x \le -3.0$), it sets a linear barrier threshold. Otherwise, it transitions to a continuous trigonometric sine wave threshold.
3.  **Piece-wise Upper Domain Extraction:** The code steps through a four-tiered conditional cascade to select the active capping function based on the current X axis segment: a parabola, an upper sine wave, a descending linear line, or a geometric circular arc.
4.  **Spatial Intersect Assessment:** The logical engine checks if the target point's Y coordinate falls completely between the calculated lower and upper bounds ($y_{\text{lower}} \le y \le y_{\text{upper}}$).
5.  **Automated Batch Regression Verification:** Once the user-specified point is checked, the program passes an array collection of predetermined test configurations through the calculation model to automatically prove edge stability across multiple region sectors.

---

## Possible Error Points & Edge Cases

When compiling, checking, or modifying this geometrical evaluation application, closely analyze these common vulnerabilities:

*   **Trigonometric Domain Constraints (Radians vs Degrees):**
    The standard library functions `std::sin()` and `std::cos()` operate strictly on **radian measurements**, not angular degrees. Passing an angular configuration based on degrees (e.g., inputting an angle of 90 instead of $\pi/2$) will break your coordinate assessment and lead to inaccurate boundary evaluations.
*   **Square Root Domain Validation Failures (NaN Errors):**
    The upper circular arc equation utilizes `std::sqrt(9.0 - pow(x - 1.0, 2))`. If an evaluation occurs where the inner expression turns negative due to precision tracking variances outside the segment threshold ($x > 4.0$), it triggers a "Not a Number" (NaN) runtime flag, causing all subsequent spatial comparisons to fail.
*   **Floating-Point Boundary Rounding Tolerances:**
    Because variables use the `double` configuration, exact boundary borders are subject to standard binary rounding constraints. A point sitting exactly on an equation line might fluctuate slightly above or below due to floating point inaccuracies, modifying the outcome of tight conditional inequalities ($\le$ or $\ge$).
*   **Input Failure Infinite Loop Traps:**
    If a user types a non-numeric letter (such as 'p') into the coordinate entry prompt, the input channel `std::cin` enters a locked error state. If this occurs inside a standard while loop without code that explicitly clears the error flag and flushes out the incorrect text from the stream buffer, the program will lock up into an infinite processing loop. Your code avoids this by safely executing an early termination exit (`return 1`).