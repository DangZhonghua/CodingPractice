/*
https://leetcode-cn.com/problems/add-strings/
Add Strings

Given two non-negative integers num1 and num2 represented as string, return the sum of num1 and num2.
Note: 
The length of both num1 and num2 is < 5100.
Both num1 and num2 contains only digits 0-9.
Both num1 and num2 does not contain any leading zero.
You must not use any built-in BigInteger library or convert the inputs to integer directly.

*/

#include<string>
#include<deque>
#include<iostream>
using namespace std;

class Solution 
{
public:
    string addStrings(string num1, string num2) 
    {
        deque<char> SQ;
        int i = num1.length()-1;
        int j = num2.length()-1;
        int sum  = 0;
        int s   = 0;

        while(i>=0 && j>=0)
        {
           sum = (s+num1[i]-'0'+num2[j]-'0');
           s   = sum/10;
           sum %=10;
           SQ.push_front('0'+sum);
           --i;
           --j;
        }
        while(i>=0)
        {
            sum = s+num1[i]-'0';
            s = sum/10;
            sum %=10;
            SQ.push_front('0'+sum);
            --i;
        }
        while(j>=0)
        {
            sum = s+num2[j]-'0';
            s = sum/10;
            sum %=10;
            SQ.push_front('0'+sum);
            --j;
        }
        if(s>0)
        {
            SQ.push_front('0'+s);
        }
        string sr;
        
        while(!SQ.empty())
        {
            sr.push_back(SQ.front());
            SQ.pop_front();
        }
        return sr;
    }
};