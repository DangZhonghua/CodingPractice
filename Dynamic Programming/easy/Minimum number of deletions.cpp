/*
https://practice.geeksforgeeks.org/problems/minimum-number-of-deletions/0/?ref=self

Minimum number of deletions

Given a string 'str' of size ‘n’. The task is to remove or delete minimum number of characters from 
the string so that the resultant string is palindrome.
Note: The order of characters should be maintained.


Input:

The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. 
The first line of each test case contains an integer N denoting the length of string str.
The second line of each test case contains the string str.


Output:
Print the minimum number of characters to be deleted to make the string a palindrome for each testcase in a new line.

Constraints:
1<= T <=100
1<= N <= 1000

Example:

Input:

1
7
aebcbda
Output:
2

*/

/*

length -(longest palindrome subsequence)

                if x[i] == x[j]  lps[i+1][j-1] + 2
lps[i][j] = 
                max{ lps[i+1][j], lps[i][j-1]}

*/


#include<iostream>
#include<vector>
#include<string>
using namespace std;

int MinimumDeletion(const string& x)
{
    int N = x.length();
    vector< vector<int> > lps(N+1, vector<int>(N+1, 1));
    
    for(int l = 2; l<=N; ++l)
    {
        for(int i = 0; i<=N-l; ++i)
        {
            int j = i+l-1;
            if(2 == l)
            {
                lps[i][j] = 1; // This should be assign 1 since length of one char is 1 palindrome
                if(x[i] == x[j])
                {
                    lps[i][j] = 2;
                }
            }
            else
            {
                if(x[i] == x[j])
                {
                    lps[i][j] = lps[i+1][j-1] + 2;
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
    }
    
    cout<< N-lps[0][N-1]<<endl;

    return 0;
}



int main()
{
    int t = 0;
    cin>>t;

    while(t--)
    {
        int N = 0;
        cin>>N;
        string x;
        cin>>x;
        MinimumDeletion(x);
    }
    return 0;
}