#include <iostream>
#include <array>

int main() {
    // Problem Constants
    constexpr size_t NUM_STUDENTS = 8;
    constexpr size_t NUM_QUESTIONS = 10;

    // 2D Matrix storing student answers
    constexpr std::array<std::array<char, NUM_QUESTIONS>, NUM_STUDENTS> answers = {{
        {'A', 'B', 'A', 'C', 'C', 'D', 'E', 'E', 'A', 'D'},
        {'D', 'B', 'A', 'B', 'C', 'A', 'E', 'E', 'A', 'D'},
        {'E', 'D', 'D', 'A', 'C', 'B', 'E', 'E', 'A', 'D'},
        {'C', 'B', 'A', 'E', 'D', 'C', 'E', 'E', 'A', 'D'},
        {'A', 'B', 'D', 'C', 'C', 'D', 'E', 'E', 'A', 'D'},
        {'B', 'B', 'E', 'C', 'C', 'D', 'E', 'E', 'A', 'D'},
        {'B', 'B', 'A', 'C', 'C', 'D', 'E', 'E', 'A', 'D'},
        {'E', 'B', 'E', 'C', 'C', 'D', 'E', 'E', 'A', 'D'}
    }};

    // 1D Answer Key
    constexpr std::array<char, NUM_QUESTIONS> key = {
        'D', 'B', 'D', 'C', 'C', 'D', 'A', 'E', 'A', 'D'
    };

    // Grade processing and output
    for (size_t i = 0; i < NUM_STUDENTS; ++i) {
        int correct_count = 0;

        for (size_t j = 0; j < NUM_QUESTIONS; ++j) {
            if (answers[i][j] == key[j]) {
                ++correct_count;
            }
        }

        std::cout << "Student " << i << "'s correct count is " << correct_count << '\n';
    }

    return 0;
}