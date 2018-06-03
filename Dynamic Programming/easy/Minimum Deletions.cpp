/*
Minimum Deletions 
https://practice.geeksforgeeks.org/problems/minimum-deletitions/0/?ref=self
Given a string of S as input. Your task is to write a program to remove or delete minimum number of characters from the string so that the resultant string is palindrome.

Note: The order of characters in the string should be maintained.

Input:
First line of input contains a single integer T which denotes the number of test cases. Then T test cases follows. First line of each test case contains a string S.

Output:
For each test case, print the deletions required to make the string palindrome.

Constraints:
1<=T<=100
1<=length(S)<=10000

Example:
Input:
2
aebcbda
geeksforgeeks
Output:
2
8


*/

#include<string>
#include<iostream>
#include<vector>
using namespace std;

int minmiumDeletion(string& strtxt)
{
    int N = strtxt.length();
    vector< vector<int> > lps(N, vector<int>(N, 0));

    for(int i = 0; i<N; ++i)
    {
        lps[i][i] = 1;
    }
    
    for(int l = 2; l<=N; ++l)
    {
        for(int i = 0; i<=N-l; ++i)
        {
            int j = i+l-1;
            if(strtxt[i] == strtxt[j])
            {
                if(2 == l)
                {
                    lps[i][j] = 2;
                }
                else
                {
                    lps[i][j] = lps[i+1][j-1] + 2;
                }
            }
            else
            {
                lps[i][j] = lps[i+1][j];
                if(lps[i][j]<lps[i][j-1])
                {
                    lps[i][j] = lps[i][j-1];
                }
            }
        }
    }
    
    cout<< (N-lps[0][N-1])<<endl;

    return 0;
}


int main(int argc, char const *argv[])
{
    int t = 0;
    string strtxt;
    cin>>t;
    
    while(t--)
    {
        cin>>strtxt;
        minmiumDeletion(strtxt);
    }

    return 0;
}
