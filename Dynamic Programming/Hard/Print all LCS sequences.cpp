/*
Print all LCS sequences
https://practice.geeksforgeeks.org/problems/print-all-lcs-sequences/0
https://www.geeksforgeeks.org/print-longest-common-sub-sequences-lexicographical-order/
You are given two strings a and b. Now your task is to print all longest common sub-sequences in lexicographical order.

Input:
The first line of input contains an integer denoting the no of test cases T. Then T test case follow each test case contains 2 space separated strings a and b.

Output:
For each test case in a new line  print the space separated sequences.

Constraints:
1<=T<=100
1<=length of strings a and b<=100

Example:
Input:
2
abaaa baabaca
aaa a
Output:
aaaa abaa baaa
a

*/


/*                1+LCS[i-1, j-1] if szx[i] == szy[j]

    LCS[i,j] =    max{LCS[i-1,j], LCS[i,j-1]} if(sz[i] ! = sz[j])

                  0 if i = 0 or j = 0;


*/


#include<iostream>
#include<vector>
using namespace std;


int printLCS(char* szx, char* szy)
{
    int m = strlen(szx+1);
    int n = strlen(szy+1);





    //1. Calculate the LCS first.
    

    return 0;
}

int LCS(char* szx, char* szy)
{
    

    return 0;
}




int main()
{
    int t = 0;
    char szx[200];
    char szy[200];
    
    cin>>t;
    
    while(t--)
    {
        cin>>szx+1;
        cin>>szy+1;
        printLCS(szx,szy);
    }

    return 0;
}
