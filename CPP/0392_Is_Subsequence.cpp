/*
392. Is Subsequence 

Given two strings s and t, return true if s is a subsequence of t, or false otherwise.

A subsequence of a string is a new string that is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (i.e., "ace" is a subsequence of "abcde" while "aec" is not).
 

Example 1:

Input: s = "abc", t = "ahbgdc"
Output: true

Example 2:

Input: s = "axc", t = "ahbgdc"
Output: false

*/


class Solution {
public:
    bool isSubsequence(string s, string t) {
        
        if(s.empty())
            return true;

        if(!s.empty() && t.empty() )
            return false;

        int i=0, j=0;
        
        for(i=0, j=0; i < s.size() & j < t.size(); )
        {
            if( s[i] != t[j])
            {
                j++;
                continue;
            }

            i++;
            j++;
        }

        if(i < s.size())
        {
            return false;
        }

        return true;
    }
};

