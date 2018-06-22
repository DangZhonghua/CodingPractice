/*
Interleaved Strings
https://practice.geeksforgeeks.org/problems/interleaved-strings/1/?ref=self

Given three strings A, B and C your task is to complete the function isInterleave which returns true 
if C is an interleaving of A and B else returns false. 
C is said to be interleaving A and B, if it contains all characters of A and B and 
order of all characters in individual strings is preserved.

Input:
The first line of input contains an input T denoting the no of test cases. Then T test cases follow. Each test case contains three space separated strings A, B, C.

Output:
For each test case output will be 1 if C is interleaving of string A and B else 0.

Constraints:
1<=T<=100
1<=length of A, B, C <=100

Example(To be used only for expected output):
Input:
2
YX  X  XXY
XY X XXY

Output
0
1

Explanation:
1. For first test case XXY is not interleaving of YX and X
2. For the sec test case XXY is interleaving of XY and X.


*/

/*

Dynamic Programming: Optimal sub-structure and overlapped sub-problem.
C[i] can be interlaved by A[j],B[k], then check C[i+1] can be interleaved by A[j+1], B[k]
or A[j],B[k+1]

But what is the formula.

*/

#include<iostream>
#include<string>
#include<vector>
using namespace std;



bool isInterleave(string A, string B, string C)
{
    bool bInterleave = true;
    int na = A.size();
    int nb = B.size();
    int nc = C.size();

    vector<int>  mca(nc,-1);
    vector<int>  mcb(nc,-1);

    for(int i = 0; i<nc; ++i)
    {
    }









    return bInterleave;    
}




int main()
{




    return 0;
}
