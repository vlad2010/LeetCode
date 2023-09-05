// atoi_with_dec_hex_oct_support.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

int customAtoi(const std::string& str) {
    int result = 0;
    int sign = 1;
    int base = 10;  // Default base is decimal

    size_t i = 0;

    // Skip leading whitespaces
    while (i < str.length() && isspace(str[i])) {
        i++;
    }

    // Check for optional sign
    if (i < str.length() && (str[i] == '-' || str[i] == '+')) {
        sign = (str[i] == '-') ? -1 : 1;
        i++;
    }

    // Check for base indicator for hexadecimal and octal
    if (i + 1 < str.length() && str[i] == '0') {
        if (str[i + 1] == 'x' || str[i + 1] == 'X') {
            base = 16;  // Hexadecimal
            i += 2;
        }
        else {
            base = 8;  // Octal
            i++;
        }
    }

    while (i < str.length()) {
        char c = str[i];
        int digit;

        if (base == 16) {
            if (isdigit(c)) {
                digit = c - '0';
            }
            else if (isxdigit(c)) {
                digit = std::tolower(c) - 'a' + 10;
            }
            else {
                break;
            }
        }
        else if (base == 8) {
            if (c >= '0' && c <= '7') {
                digit = c - '0';
            }
            else {
                break;
            }
        }
        else {
            if (!isdigit(c)) {
                break;
            }
            digit = c - '0';
        }

        // Check for overflow
        if (result > (INT_MAX - digit) / base) {
            return (sign == 1) ? INT_MAX : INT_MIN;
        }

        result = result * base + digit;
        i++;
    }

    return result * sign;
}

int main() {

    while (1)
    {
        std::string input;
        std::cout << "Enter a string: ";
        std::cin >> input;

        int result = customAtoi(input);
        std::cout << "Converted integer: " << result << std::endl;
    }

    return 0;
}
