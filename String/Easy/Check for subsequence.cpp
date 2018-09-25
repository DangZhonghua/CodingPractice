/*
Check for subsequence 
https://practice.geeksforgeeks.org/problems/check-for-subsequence/0/?ref=self

Given two strings a and b, find if a is a subsequence of b

Input: a = "axy", b = "yadxcp"
Output: 0 (a is not a subsequence of b)

Input: a = "gksrek", b = "geeksforgeeks"
Output: 1 (str1 is a subsequence of str2)


Input:
The first line of input contains an integer T denoting the no of test cases. 
Then T test cases follow. Each test case contains two space separated strings a and b.

Output:
For each test case in a new line print 1 if a is sub-sequences of b else print 0.

Constraints:
1<=T<=50
1<=Length of string<=1000

Example:
Input:
2
AXY YADXCP
gksrek geeksforgeeks

Output:
0
1

*/

#include<iostream>
#include<vector>
#include<string>
using namespace std;


int CheckSubsequence(const string& x, const string& y)
{
    bool bSub = false;
    for( int i = 0; i<y.length(); ++i)
    {
        int k = i;
        int j = 0;
        while(k<y.length() && j< x.length)
        {
            if(y[k] == x[j])
            {
                ++k;
                ++j;
            }
            else
            {
                ++k;
            }
        }
        if(j == x.length())
        {
            bSub = true;
            break;
        }
    }

    cout<<(bSub? 1:0)<<endl;

    return 0;
}


int main(int argc, char const *argv[])
{
    int t = 0;
    
    cin>>t;
    
    while(t--)
    {
        string x;
        string y;
        cin>>x>>y;
        CheckSubsequence(x,y);
    }
    
    return 0;
}
