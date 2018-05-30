/*
Longest Palindromic Subsequence
https://practice.geeksforgeeks.org/problems/longest-palindromic-subsequence/0

Given a String, find the longest palindromic subsequence

Input:
The first line of input contains an integer T, denoting no of test cases. 
The only line of each test case consists of a string S(only lowercase)

Output:
Print the Maximum length possible for palindromic subsequence.

Constraints:
1<=T<=100
1<=|Length of String|<=1000
 

Examples:
Input:
2
bbabcbcab
abbaab
Output:
7
4


*/

#include<iostream>
#include<vector>
#include<string>
using namespace std;

int longestPalindromeString(const char* szText, int N)
{
    vector< vector<int> > lps(N+1, vector<int>(N+1, 0));
    
    for(int i = 0; i<N; ++i)
    {
        lps[i][i] = 1; //one letter is the palindrome
    }

    for(int l = 2; l<=N; ++l)
    {
        for(int i = 0; i<= N-l; ++i)
        {
            int j = i+l-1;
            if(szText[i] == szText[j])
            {
                if(i+1<= j-1)
                {
                    lps[i][j] = (lps[i+1][j-1] + 2 );
                }
                else
                {
                    lps[i][j] = 2;
                }
            }
            else
            {
                lps[i][j] = lps[i-1][j];
                if(lps[i][j]<lps[i][j-1])
                {
                    lps[i][j] = lps[i][j-1];
                }
            }
        }
    }
    
    cout<<lps[0][N-1]<<endl;

    return 0;
}


int main()
{
    int t = 0;
    string strText;
    
    cin>>t;
    while(t)
    {
        --t;
        cin>>strText;
        longestPalindromeString(strText.c_str(), strText.size());
        strText.clear();
    }

    return 0;
}
