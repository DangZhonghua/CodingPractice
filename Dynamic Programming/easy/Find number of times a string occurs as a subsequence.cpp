/*
Find number of times a string occurs as a subsequence 
https://practice.geeksforgeeks.org/problems/find-number-of-times-a-string-occurs-as-a-subsequence/0
https://www.geeksforgeeks.org/find-number-times-string-occurs-given-string/

Given two strings S1 and S2, find the number of times the second string occurs in the first string, 
whether continuous or discontinuous.

Input:

The first line of input contains an integer T denoting the number of test cases. 
Then T test cases follow. The first line of each test case contains 
integers N and M denoting the length of the strings S1 and S2 respectively.

The second line of each test case contains the strings S1 and S2.

Output:

Print the number of times S2 appears in S1, whether continuous or discontinuous. 
Print the answer for each test case in a new line.


Constraints:
1<= T <=100
1<= N, M <=1000
Example:


Input:
1
13 3
geeksforgeeks gks

Output: 
4

*/

#include<iostream>
#include<string>
#include<vector>
using namespace std;

int CountStringAsSubsequence(const string& strtext, const string& strsrc)
{
    int R = strtext.length();
    int C = strtext.length();
    vector< vector<int> > lcs(R+1, vector<int>(C+1, 0));

    for(int r = 1; r<=R; ++r)
    {
        for(int c = 1; c<=C; ++c)
        {
            if(strtext[r-1] == strsrc[c-1])
            {
                lcs[r][c] = lcs[r-1][c-1]+1;
            }
            else
            {
                lcs[r][c] = lcs[r-1][c];
                if(lcs[r][c]<lcs[r][c-1])
                {
                    lcs[r][c] = lcs[r][c-1];
                }
            }
        }
    }
    
    int nCount = 0;


    for(int r = 0; r <=R; ++r)
    {
        if(lcs[r][C] == C)
        {
            ++nCount;
        }
    }
    cout<<nCount<<endl;
    


    return 0;
}


int main()
{
    int t = 0;
    int N = 0;
    int M = 0;
    string strtext;
    string strsrc;

    cin>>t;

    while(t--)
    {
        cin>>N>>M;
        cin>>strtext;
        cin>>strsrc;
        CountStringAsSubsequence(strtext,strsrc);
    }
    return 0;
}

