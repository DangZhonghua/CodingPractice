/*
Excel Sheet | Part - 1
https://practice.geeksforgeeks.org/problems/excel-sheet/0/?ref=self

Given a positive integer, return its corresponding column title as appear in an Excel sheet.

For example:

    1 -> A
    2 -> B
    3 -> C
    ...
    26 -> Z
    27 -> AA
    28 -> AB 

NOTE: The alphabets are all in uppercase.

 

Input:

The first line contains an integer T, depicting total number of test cases. Then following T lines contains an integer N.


Output:

Print the string corrosponding to the column number.


Constraints:

1 ≤ T ≤ 100
1 ≤ N ≤ 10000000

Example:
Input
1
51
Output
AY

*/

/*

This is 26 进制模拟

*/


#include<iostream>
#include<stack>
#include<string>
using namespace std;

int ColumnNo2ColumnName(int N)
{
    stack<char> scolumn;
    int rem = 0;

    while(N>0)
    {
        rem = N%26;
        if(0 == rem)
        {
            scolumn.push('Z');
            N = (N/26)-1;
        }
        else
        {
            N = (N/26);
            scolumn.push(rem+'A'-1);
        }
    }
    string strcol;
    
    while(!scolumn.empty())
    {
        strcol += scolumn.top();
        scolumn.pop();
    }
    cout<<strcol<<endl;

    return 0;
}

int main()
{
    int t = 0;
    int N = 0;
    
    cin>>t;
    
    while(t--)
    {
        cin>>N;
        ColumnNo2ColumnName(N);
    }

    return 0;
}