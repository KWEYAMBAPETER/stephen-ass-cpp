#include <iostream>
#include <string>

using namespace std;
 
bool isValid(long long number);
int sumOfDoubleEvenPlace(long long number);
int getDigit(int number);
int sumOfOddPlace(long long number);
bool prefixMatched(long long number, int d);
int getSize(long long d);
long long getPrefix(long long number, int k);

int main() {
    long long cardNumber;
    
    // Prompt the user for input
    cout << "Enter a credit card number as an integer: ";
    cin >> cardNumber;

    // Display the final verification result
    if (isValid(cardNumber)) {
        cout << cardNumber << " is valid" << endl;
    } else {
        cout << cardNumber << " is invalid" << endl;
    }

    return 0;
}

// Return true if the card number passes all validity checks
bool isValid(long long number) {
    int totalDigits = getSize(number);
    
    // Check 1: Card must have between 13 and 16 digits
    if (totalDigits < 13 || totalDigits > 16) {
        return false;
    }

    // Check 2: Card must start with a valid prefix (4, 5, 37, or 6)
    if (!prefixMatched(number, 4) &&   // Visa
        !prefixMatched(number, 5) &&   // MasterCard
        !prefixMatched(number, 37) &&  // American Express
        !prefixMatched(number, 6)) {   // Discover
        return false;
    }

    // Check 3: Run the complete Mod 10 / Luhn mathematical verification
    int finalSum = sumOfDoubleEvenPlace(number) + sumOfOddPlace(number);
    
    // Valid only if the final sum is completely divisible by 10
    return (finalSum % 10 == 0);
}

// Get the total sum for Step 2 (Double every second digit from right to left)
int sumOfDoubleEvenPlace(long long number) {
    int sum = 0;
    
    // Shift right once to skip the first odd position digit and land on the first even position
    number /= 10; 
    
    while (number > 0) {
        int lastDigit = number % 10;          // Extract the current even-position digit
        sum += getDigit(lastDigit * 2);       // Double it and pass it to getDigit()
        number /= 100;                        // Move left by 2 positions to skip the next odd position
    }
    return sum;
}

// Return this number if it is a single digit, otherwise, return the sum of the two digits
int getDigit(int number) {
    // If doubling results in a single digit (0-9), keep it as is
    if (number < 10) {
        return number;
    }
    // If it's a two-digit number, split them (e.g., 16 becomes 1 + 6 = 7)
    return (number / 10) + (number % 10);
}

// Return sum of odd place digits in number (Step 3)
int sumOfOddPlace(long long number) {
    int sum = 0;
    while (number > 0) {
        sum += number % 10;     // Extract the current odd-position digit
        number /= 100;          // Move left by 2 positions to skip the next even position
    }
    return sum;
}

// Return true if the digit d matches the starting prefix of the card number
bool prefixMatched(long long number, int d) {
    int dSize = getSize(d);
    // Compare the leading digits of the card with the target prefix value
    return getPrefix(number, dSize) == d;
}

// Return the total number of digits contained within long long input d
int getSize(long long d) {
    int count = 0;
    if (d == 0) return 1;
    
    // Strip digits away one-by-one to count length
    while (d > 0) {
        count++;
        d /= 10;
    }
    return count;
}

// Return the first k number of digits from number. 
// If the number of digits in number is less than k, return number.
long long getPrefix(long long number, int k) {
    int size = getSize(number);
    if (size <= k) {
        return number;
    }
    
    // Truncate trailing digits off the right side until only k digits remain on the left
    int positionsToDrop = size - k;
    for (int i = 0; i < positionsToDrop; i++) {
        number /= 10;
    }
    return number;
}
