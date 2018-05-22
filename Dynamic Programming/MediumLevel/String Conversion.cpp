/*
String Conversion
https://practice.geeksforgeeks.org/problems/string-conversion/0

Given two strings X and Y (call letters in uppercase). Check if it is possible to convert X to Y by performing following operations.

 Make some lowercase letters uppercase.
 Delete all the lowercase letters.

Input:
First line of the input contains no of test cases  T,the T test cases follow.
Each test case consist of 2 space separated integers A and B denoting the size of string X and Y respectively
The next two lines contain the 2 string X and Y.


Output:
For each test case print the "Yes" if it's  possible to convert X to Y by performing following operations else "No".


Constraints:
1<=T<=200
1<=size(X),size(Y)<=100
'a'<=X[i]<='z'
'A'<=X[i] , Y[i]<='Z'
Example:
Input :

2
5 3
daBcd ABC 
4 3
ABcd BCD 

Output :
Yes
No
Explanation :

Test Case 1:  daBcd -> dABCd -> ABC Covert a and b at index 1 and 3 to upper case, delete the rest those are lowercase. 
We get the string Y so the output is: Yes.

*/


/*

this is a variable of LCS: LCS(X,Y) = |Y| insensitive case.
WOW, DP again!


                LCS[i-1][j-1] + 1;
LCS[i][j] = 
                max{LCS[i-1][j], LCS[i][j-1]}


*/

#include<iostream>
#include<string>
using namespace std;

int StringConversion(const char* strx,  const char* stry, int n, int m)
{
    int LCS[101][101];


    return 0;
}


int main()
{
    int t;
    int n = 0;
    int m = 0;
    char szX[101] = {0};
    char szY[101] = {0};
    
    cin>>t;
    
    while(t>0)
    {
        cin>>n>>m;
        cin>>szX>>szY;

        StringConversion(szX,szY,n,m);
    }


    return 0;
}