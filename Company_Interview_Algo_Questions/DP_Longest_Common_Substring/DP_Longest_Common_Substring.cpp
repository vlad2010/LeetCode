// DP_Longest_Common_Substring.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include <cassert>

using namespace std;

// Dynamic programming task from "Grokking algorithms" book

string longestCommonSubstring(const string &s1, const string &s2)
{
    int sz1 = s1.size();
    int sz2 = s2.size();

    // dynamic programming matrix
    vector<vector<int>> dp(sz1, vector<int>(sz2, 0));

    // fill DP matrix
    for (int i = 0; i < sz1; i++)
    {
        for (int j = 0; j < sz2; j++)
        {
            if (s1[i] == s2[j])
            {
                int prev = 0;
                if (i - 1 >= 0 && j - 1 >= 0)
                {
                    prev = dp[i - 1][j - 1];
                }

                dp[i][j] = prev + 1;
            }
            else
            {
                dp[i][j] = 0;
            }
        }
    }

    int max = -1;
    int mi = -1, mj = -1;

    // get max value from DP matrix
    for (int i = 0; i < sz1; i++)
    {
        for (int j = 0; j < sz2; j++)
        {
            if (dp[i][j] > max)
            {
                max = dp[i][j];
                mi = i, mj = j;
            }
        }
    }

    // and return correct substring
    if (mi >= 0 && mj >= 0 && max > 0)
    {
        string res = s1.substr(mi-(max-1), max);
        return res;
    }

    return "";
}


int main()
{
    assert(longestCommonSubstring("a", "ab") == string("a"));
    assert(longestCommonSubstring("hish", "fish") == string("ish"));
    assert(longestCommonSubstring("fosh", "fish") == string("sh"));
    assert(longestCommonSubstring("blue", "clues") == string("lue"));

    std::cout << "All tests passed \n";
}


