// Summ_Of_Vector_Alteryx.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

// Simple task to calculate summ of vector
// Alteryx

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <optional>
#include <limits>
#include <climits>
#include <cassert>

using namespace std;

std::optional<int> sumVector(const vector<int>& v)
{
    int res = 0;
    for (auto& n : v)
    {
        // check for overflow
        if ((n > 0 && res > INT_MAX - n) || (n < 0 && res < INT_MIN - n))
        {
            return std::optional<int>();
        }

        res += n;
    }

    return std::optional<int>(res);
}

int main() {

    assert(7 == sumVector({ 1,2,4 }).value());
    assert(!sumVector({ 1,2, INT_MAX }).has_value());
    assert(INT_MIN + 2  == sumVector({ INT_MIN,2 }).value());
    assert(!sumVector({INT_MIN,-2}).has_value());

    std::cout << "Summ of vector. All test cases passed! \n";
}

