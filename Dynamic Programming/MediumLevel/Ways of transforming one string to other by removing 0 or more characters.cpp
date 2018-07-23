/*
https://www.geeksforgeeks.org/ways-transforming-one-string-removing-0-characters/
Ways of transforming one string to other by removing 0 or more characters

Given two sequences A, B, find out number of unique ways in sequence A, 
to form a subsequence of A that is identical to the sequence B. 
Transformation is meant by converting string A (by removing 0 or more characters) to string B.

Examples:

Input : A = "abcccdf", B = "abccdf"
Output : 3
Explanation : Three ways will be -> "ab.ccdf", 
"abc.cdf" & "abcc.df" .
"." is where character is removed. 

Input : A = "aabba", B = "ab"
Output : 4
Expalnation : Four ways will be -> "a.b..",
 "a..b.", ".ab.." & ".a.b." .
"." is where characters are removed.

Asked in : Google

*/

/*


he idea to solve this problem is using Dynamic Programming. Construct a 2D DP matrix of m*n size, 
where m is size of string B and n is size of string A.
dp[i][j] gives the number of ways of transforming string A[0…j] to B[0…i].

    Case 1 : dp[0][j] = 1, since placing B = “” with any substring of A would have only 1 solution which is to delete all characters in A.
    Case 2 : when i > 0, dp[i][j] can be derived by two cases:
        Case 2.a : if B[i] != A[j], then the solution would be to ignore the character A[j] and align substring B[0..i] 
        with A[0..(j-1)]. Therefore, dp[i][j] = dp[i][j-1].
        Case 2.b : if B[i] == A[j], then first we could have the solution in case a), 
            but also we could match the characters B[i] and A[j] and 
            place the rest of them (i.e. B[0..(i-1)] and A[0..(j-1)]. 
            As a result, dp[i][j] = dp[i][j-1] + dp[i-1][j-1].

*/

/*

           i is the index of A, j is the index of B.

            W[i][0]         //since there is empty y, the only way to convert is: delete all chars in X.

            if x[i] == y[j]  W[i-1][j-1] + W[i-1][j]

W[i][j] =   

            if x[i] != y[j] W[i-1][j]

*/

#include<iostream>
#include<vector>
#include<string>
using namespace std;

int WaysOfTransfroming(const string& x, const string& y)
{
    int R = x.length();
    int C = y.length();

    vector< vector<int> > wt(R+1, vector<int>(C+1,0));
    
    for(int i = 1; i<=R; ++i)
    {
        wt[i][0] = 1;
    }
    
    for(int i = 1; i<=R; ++i)
    {
        for(int j = 1; j<=C; ++j)
        {
            if(x[i-1] == y[j-1])
            {
                wt[i][j] = wt[i-1][j-1] + wt[i-1][j];
            }
            else
            {
                wt[i][j] = wt[i-1][j];
            }
        }
    }
    
    cout<<wt[R][C]<<endl;

    return;
}

int main()
{

    string A = "abcccdf";
    string B = "abccdf";

    WaysOfTransfroming(A,B);

    return 0;
}