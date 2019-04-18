/*
https://leetcode-cn.com/problems/find-the-closest-palindrome/
564. Find the Closest Palindrome

Given an integer n, find the closest integer (not including itself), which is a palindrome. 
The 'closest' is defined as absolute difference minimized between two integers.
Example 1:
Input: "123"
Output: "121"

Note:
The input n is a positive integer represented by string, whose length will not exceed 18.
If there is a tie, return the smaller one as answer.
*/

/*

10-->9


*/

#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    string nearestPalindromic(string n) 
    {
        string s = n;
        int N = s.length();
        int i = 0;
        int j = N-1;
        bool bChange = false;
        while(i<j)
        {
            if(s[i] != s[j])
            {
                s[j] = s[i];
                bChange = true;
            }
            ++i;
            --j;
        }
        if(!bChange)
        {
            int m = N/2;
            if('0' == s[m])
            {
                s[m] = '1';
            }
            else
            {
                s[m] -=1;
            }
        }
        return s;
    }
};