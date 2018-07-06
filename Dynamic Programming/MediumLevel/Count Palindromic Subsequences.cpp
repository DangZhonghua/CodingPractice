/*
Count Palindromic Subsequences

https://practice.geeksforgeeks.org/problems/count-palindromic-subsequences/1/?ref=self

https://www.geeksforgeeks.org/count-palindromic-subsequence-given-string/

Given a string str, your task is to complete the function countPs which takes a string str 
as its only argument and returns an integer denoting the no of palindromic subsequence 
(need not necessarily be distinct) which could be formed from the string str.

Input:
The first line of input contains an integer T, denoting the no of test cases then T test cases follow. 
Each test case contains a string str.

Output:
For each test case output will be an integer denoting the no of palindromic subsequence 
which could be formed from the string str.

Constraints:
1<=T<=100
1<=length of string str <=30

Example(To be used only for expected output):
Input:
2
abcd
aab

Output:
4
4

Explanation:
For the first test case
palindromic subsequence are : "a" ,"b", "c" ,"d"

For second test case
palindromic subsequence are :"a", "a", "b", "aa"

*/

/*
            
ps[i][i] = 1 for i = 0 ...N-1

            ps[i+1][j] + ps[i][j-1] + 1 // 1 for the X[i] == X[j], the two char consist a plaindrome sequence.
ps[i][j] = 
            ps[i+1][j] + ps[i][j-1] -ps[i+1][j-1]


*/



#include<iostream>
#include<vector>
#include<string>
using namespace std;



int countPS(string str)
{
    int count = 0;
    int N = str.length();
    vector< vector<int> > ps(N, vector<int>(N,0));
    
    for(int i = 0; i<N; ++i)
    {
        ps[i][i] = 1;
    }

    for(int l= 2; l<=N; ++l)
    {
        for(int i = 0; i<=N-l; ++i)
        {
            int j = i+l-1;
            if(str[i] == str[j])
            {
                ps[i][j] = ps[i+1][j]+ps[i][j-1]+1;
            }
            else
            {
                ps[i][j] = ps[i+1][j] + ps[i][j-1]-ps[i+1][j-1];
            }
        }
    }

    count = ps[0][N-1];

    return count;
}


int main()
{
    int t;
    string strtxt;

    cin>>t;
    while(t--)
    {
        cin>>strtxt;
        countPS(strtxt);
    }

    return 0;
}

