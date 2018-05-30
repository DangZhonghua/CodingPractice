/*
https://practice.geeksforgeeks.org/problems/palindromic-patitioning/0

Palindromic patitioning 

Given a string, a partitioning of the string is a palindrome partitioning 
if every sub-string of the partition is a palindrome. 
For example, “aba|b|bbabb|a|b|aba” is a palindrome partitioning of “ababbbabbababa”. 
Determine the fewest cuts needed for palindrome partitioning of a given string. 
For example, minimum 3 cuts are needed for “ababbbabbababa”. 
The three cuts are “a|babbbab|b|ababa”.

Input:
The first line of input contains an integer T, denoting the number of test cases. 
Then T test cases follow. The first line of every Test Case consists of S, denoting a String.

Output:
For each test case in a new line print an integer, denoting the number cuts in the String to make it palindromic.

Constraints:
1<=T<=100
1<=|Length of String|<=1000

Example:
Input:
2
ababbbabbababa
aaabba

Output:
3
1


*/
#include<iostream>
#include<string>
#include<vector>
using namespace std;


//Matrix chain multiply extension.
int PalindromicPartition(string& strtext)
{
    int N = strtext.size();
    vector< vector<int> > psp(N+1,vector<int>(N+1,0));

    for(int i = 0; i<N; ++i)
    {
        psp[i][i] = 1;
    }

    for()


    return 0;
}

int  main()
{
    int t = 0;
    string strtext;
    
    cin>>t;
    
    while(t>0)
    {
        --t;
        cin>>strtext;
        PalindromicPartition(strtext);
    }

    return 0;
}