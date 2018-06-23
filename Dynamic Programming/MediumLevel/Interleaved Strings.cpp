/*
Interleaved Strings
https://practice.geeksforgeeks.org/problems/interleaved-strings/1/?ref=self
https://www.geeksforgeeks.org/check-whether-a-given-string-is-an-interleaving-of-two-other-given-strings-set-2/

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

a) If first character of C matches with first character of A, we move one character ahead in A and C and recursively check.

b) If first character of C matches with first character of B, we move one character ahead in B and C and recursively check.

If any of the above two cases is true, we return true, else false. Following is simple recursive implementation of this approach

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
    
    vector<vector<bool> > IS(na+1, vector<bool>(nb+1,false));
    IS[0][0] = true; // for empty string can be considered as interleaved.
    
    if(nc != (na+nb))
    {
        return false;
    }
    
    for(int i = 0; i<=na; ++i)
    {
        for(int j = 0; j<=nb; ++j)
        {
            if(0 ==i && 0 == j)
            {
                IS[0][0] = true;
                continue;
            }

            if(0 == i && C[j-1] == B[j-1])  //when A is zero length substring
            {
                IS[i][j] = IS[i][j-1];
            }
            else if (0 == j && C[i-1] == A[i-1])
            {
                IS[i][j] = IS[i-1][j];
            }
            else if(A[i-1] == C[i+j-1] && B[j-1] != C[i+j-1])
            {
                IS[i][j] = IS[i-1][j];
            }
            else if( B[j-1] == C[i+j-1] && A[i-1] != C[i+j-1])
            {
                IS[i][j] = IS[i][j-1];
            }
            else if(B[j-1] == C[i+j-1] && A[i-1] == C[i+j-1] )
            {
                IS[i][j] = (IS[i][j-1] | IS[i-1][j]);
            }
        }
    }

    bInterleave = IS[na][nb];

    return bInterleave;    
}




int main()
{




    return 0;
}
