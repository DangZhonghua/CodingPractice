/*
https://leetcode-cn.com/problems/string-without-aaa-or-bbb/
String Without AAA or BBB

Given two integers A and B, return any string S such that:
S has length A + B and contains exactly A 'a' letters, and exactly B 'b' letters;
The substring 'aaa' does not occur in S;
The substring 'bbb' does not occur in S.
 
Example 1:
Input: A = 1, B = 2
Output: "abb"
Explanation: "abb", "bab" and "bba" are all correct answers.
Example 2:
Input: A = 4, B = 1
Output: "aabaa"
 
Note:
0 <= A <= 100
0 <= B <= 100
It is guaranteed such an S exists for the given A and B.

*/

#include<string>
using namespace std;

class Solution 
{
public:
    string strWithout3a3b(int A, int B) 
    {
        string s;
        char cl;
        if(A>B)
        {
            cl = 'b';
            while(A>B && A>0 && B>0)
            {
                s += "aab";
                A -= 2;
                B -= 1;
            }
        }
        else if(A<B)
        {
            cl = 'a';
            while(B>A && A>0 && B>0)
            {
                s += "bba";
                B -= 2;
                A -= 1;
            }
        }
        else
        {
            while(A>0)
            {
                s += "ab";
                --A;
                --B;
            }
        }
        
        while(A == B && A>0)
        {
            if( 'b' == cl)
            {
                s += "ba";
            }
            else
            {
                s += "ab";
            }
            --A;
            --B;
            
        }
        while(A>0)
        {
            s.append(A,'a');
            break;
        }
        while(B>0)
        {
            s.append(B,'b');
            break;
        }

        return s;
    }
};