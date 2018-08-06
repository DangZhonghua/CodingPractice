/*
Wildcard Pattern Matching
https://practice.geeksforgeeks.org/problems/wildcard-pattern-matching/1
https://www.geeksforgeeks.org/dynamic-programming-wildcard-pattern-matching-linear-time-constant-space/
https://www.geeksforgeeks.org/dynamic-programming-wildcard-pattern-matching-linear-time-constant-space/
https://www.geeksforgeeks.org/wildcard-pattern-matching/


Given a text 'str' and a wildcard pattern 'pattern',
your task is to complete the function wildcard that returns '1' 
if the  wildcard pattern is matched with text 
else returns '0'.The function takes two strings as arguments 'str' and 'pattern'.

The wildcard pattern can include the characters ‘?’ and ‘*’
‘?’ – matches any single character
‘*’ – Matches any sequence of characters (including the empty sequence)

For example,

Text = "baaabab",
Pattern = “*****ba*****ab", output : true
Pattern = "baaa?ab", output : true
Pattern = "ba*a?", output : true
Pattern = "a*ab", output : false 

Note: The matching should cover the entire text (not partial text).

Input
The first line of input will contain no of test cases T . 
Then T test cases follow . Each test case contains 2 lines. 
The first line of each test case represent a string pat denoting the pattern 
and the next line contains string str .

Output
Output will be 1 if the string follows the pattern else it will be 0.

Constraints:
1<=T<=50
1<=length of(str,pat) <=50

Example
Input
2
a*a
aa
a?a
aa

Output
1
0
*/


/*

like LCS problem, the prefixs of text and pattern string as the base of the sub-problems.

*/


/*
 
 // both text and pattern are null
T[0][0] = true; 

// pattern is null
T[i][0] = false; 

// text is null
T[0][j] = T[0][j - 1] if pattern[j – 1] is '*' 


DP relation :

// If current characters match, result is same as 
// result for lengths minus one. Characters match
// in two cases:
// a) If pattern character is '?' then it matches  
//    with any character of text. 
// b) If current characters in both match
if ( pattern[j – 1] == ‘?’) || 
     (pattern[j – 1] == text[i - 1])
    T[i][j] = T[i-1][j-1]   
 
// If we encounter ‘*’, two choices are possible-
// a) We ignore ‘*’ character and move to next character in the pattern, i.e., ‘*’ indicates an empty sequence.
// b) '*' character matches with ith character in input text. i.e., '*' can match any sequence.
else if (pattern[j – 1] == ‘*’)
    T[i][j] = T[i][j-1] || T[i-1][j]  

else // if (pattern[j – 1] != text[i - 1])
    T[i][j]  = false 
 

uxnspusgdhiixqmbfjxjcvudjsuyibyebmwsiqyoygyxymzevypzvjegebeocfuftsxdixtigsieehkch
w*l*s*d?u?u?m?q?d?u*e*o*y?h*a?h?d?m*x*d*y*l*n?q*u*w?g?l?j?u?w?i?x*b?m?n?e?a?d*m*d?a?x*o*h?q?m*h*v*h?o*v?u?o?p?y?l?e?m?o?e*z*i*c?s*p?g?b?i*z*r*u*x?m?u*f*k?r?o?z?i?o?b?p*e*l?p?a*j*a*q*d*n?w*t*j*m*p?p*a*

*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;


int wildcard(const string& p, const string& x)
{
    int R = x.length();
    int C = p.length();
    vector< vector<bool> > wp(R+1, vector<bool>(C+1, false));
    wp[0][0] = true;
    
    //This is initialization part

    //the pattern is empty.
    for(int i = 1; i<=R; ++i)
    {
        wp[i][0] = false;
    }
    //the text is empty
    for(int i = 1; i<=C; ++i)
    {
        wp[0][i] = false;
        if( '*' == p[i-1])  // like this *****
        {
            wp[0][i] = wp[0][i-1]; 
        }
    }
    
    for(int i = 1; i<=R; ++i)
    {
        for(int j = 1; j<=C; ++j)
        {
            if(x[i-1] == p[j-1] || '?' == p[j-1])
            {
                wp[i][j] = wp[i-1][j-1];
            }
            else if('*' == p[j-1])
            {
                wp[i][j] = (wp[i][j-1] /* move pattern*/ || wp[i-1][j]/* move text case*/);
            }
            else
            {
                wp[i][j] = false;
            }
        }
    }


    return wp[R][C];
}


int main()
{
    int t = 0;

    
    cin>>t;
    
    while(t--)
    {
        string p;
        string x;
        cin>>p>>x;
        wildcard(p,x);
        
    }


return 0;
}