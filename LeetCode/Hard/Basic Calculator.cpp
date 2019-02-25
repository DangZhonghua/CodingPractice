/*
https://leetcode-cn.com/problems/basic-calculator/
Basic Calculator

Implement a basic calculator to evaluate a simple expression string.
The expression string may contain open ( and closing parentheses ), the plus + or minus sign -, non-negative integers and empty spaces .
Example 1:
Input: "1 + 1"
Output: 2
Example 2:
Input: " 2-1 + 2 "
Output: 3
Example 3:
Input: "(1+(4+5+2)-3)+(6+8)"
Output: 23
Note: 
You may assume that the given expression is always valid.
Do not use the eval built-in library function.

*/

#include<iostream>
#include<vector>
#include<string>
#include<stack>
using namespace std;

class Solution 
{
public:
    int calculate(string s) 
    {
        int sum = 0;
        stack<int> cs;
        stack<int> sumStack;
        if(s[0] == '(')
        {
            cs.push(s[0]);
        }

        int i = 1;
        while( !cs.empty() || i< s.length() )
        {
            if(cs.empty())
            {
                int d = 0;
                if( '0'<=s[i] && '9' >= s[i])
                {
                    if(i-1<0)
                    {
                        d = s[i]-'0'; 
                    }
                    else
                    {
                        
                    }   
                }
            }
        }
        
    }
};