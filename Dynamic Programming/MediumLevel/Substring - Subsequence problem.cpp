/*
Substring - Subsequence problem
https://practice.geeksforgeeks.org/problems/substring-subsequence-problem/0/?ref=self

Manoj, Vinoj and Jegan are the famous coders of TCE. One fine day Vinoj and Jegan challenge Manoj to solve a puzzle. 
That is Vinoj will select one string A. Similarly Jegan will choose one string B with the same size. 
You need to help Manoj to find the longest subsequence X of a string A which is a substring Y of a string B. 

Example
A : ABCD
B : BACDBDCD
The answer would be 3 as because 'ACD' is the longest subsequence of A which is also a substring of B.


Input:
The first line of input contains an integer T. Then T test cases follow. Each test case contains two space separated strings A and B.

Output:
For each test case in a new line print the required output.

Constraints:
1<=T<=12
1<=Length of strings <=100

Example:
Input:
2
ABCD BACDBDCD
A A
Output:
3
1


*/

/*
                LCS[i-1][j-1] + 1 if x[i] == y[j]
LCS[i][j] =     LCS[i-1][j]  //Since j need to be a string, so it can't be j-1
                0 if 0 == i or 0 == j
*/

#include<iostream>
#include<string>
#include<vector>
using namespace std;


int CalcLenOfLcs(string&x, string&y)
{
    int ret = 0;
    vector< vector<int> > lcs(x.length()+1, vector<int>(y.length()+1,0));

    for(int i = 0; i<x.length(); ++i)
    {
        for(int j = 0; j<y.length(); ++j)
        {
            if(x[i] == y[j])
            {
                lcs[i+1][j+1] = lcs[i][j] + 1;
            }
            else
            {
                lcs[i+1][j+1] = lcs[i][j+1];
            }
        }
    }

    cout<<lcs[x.length()][y.length()]<<endl;

    return ret;
}


int main(int argc, char const *argv[])
{
    int t = 0;
    
    cin>>t;
    
    while(t--)
    {
        string x,y;
        cin>>x>>y;
        CalcLenOfLcs(x,y);
    }

    return 0;
}




