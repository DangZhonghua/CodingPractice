/*
https://leetcode-cn.com/problems/palindrome-partitioning-ii/
Palindrome Partitioning II
Given a string s, partition s such that every substring of the partition is a palindrome.

Return the minimum cuts needed for a palindrome partitioning of s.

Example:

Input: "aab"
Output: 1
Explanation: The palindrome partitioning ["aa","b"] could be produced using 1 cut.

*/

/*

mc[i][j] = mc[i,k] + mc[k+1][j] + 1

*/


class Solution {
public:
    int minCut(string s) 
    {
        
    }
};