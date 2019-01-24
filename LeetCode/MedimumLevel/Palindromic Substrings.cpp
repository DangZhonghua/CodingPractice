/*
https://leetcode-cn.com/problems/palindromic-substrings/
Palindromic Substrings

Given a string, your task is to count how many palindromic substrings in this string. 
The substrings with different start indexes or end indexes are counted as different substrings even they consist of same characters. 
Example 1:
Input: "abc"
Output: 3
Explanation: Three palindromic strings: "a", "b", "c".

Example 2:
Input: "aaa"
Output: 6
Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".

Note:
The input string length won't exceed 1000.

*/

#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int countSubstrings(string s) 
    {
        int count = 0;
        int Len = s.length();
        vector< vector<int> > lps(Len+1,vector<int>(Len+1,0));  

        for(int i = 1; i<=Len; ++i)
        {
            lps[i][i] = 1;
            ++count;
        }

        for ( int L = 2; L<=Len; ++L)
        {
            for( int i = 1; i<=Len-L+1; ++i)
            {
                int j = i+L-1;
                if(s[i-1] == s[j-1])
                {
                    if(2 == L)
                    {
                        ++count;
                        lps[i][j] = 2;
                    }
                    else
                    {
                        if(lps[i+1][j-1])
                        {
                            lps[i][j] = lps[i+1][j-1] + 2;
                            ++count;
                        }
                        else
                        {
                            lps[i][j] = 0;
                        }
                    }
                }
                else
                {
                    lps[i][j] = 0;
                }
            }
        }

        return count;
        
    }
};

int main(int argc, char const *argv[])
{
    string s = "abc";
    Solution sol;
    sol.countSubstrings(s);
    return 0;
}
