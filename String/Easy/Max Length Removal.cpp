/*
Max Length Removal
https://practice.geeksforgeeks.org/problems/max-length-removal/0/?ref=self

Given a binary string (consists of only 0 and 1). If there is “100” as a sub-string in the string, 
then we can delete this sub-string. 
The task is to find the length of longest sub-string which can be make removed?

Examples:

Input  : str = "1011100000100"
Output : 6
// Sub-strings present in str that can be make removed 
// 101{110000}0{100}. First sub-string 110000-->100-->null,
// length is = 6. Second sub-string 100-->null, length is = 3

Input  : str = "111011"
Output : 0
// There is no sub-string which can be make null

Input:

The first line of input contains a single integer T denoting the number of test cases. 
Then T test cases follow. Each test case consists of one line. The line contains a string of 0's and 1's.

Output:

Length of the longest string that can be removed.

Constraints:

1 ≤ T ≤ 100
1 ≤ string length ≤ 1000

Example:

Input
2
010010
1011110000

Output
3
6
*/

#include<string>
#include<iostream>
using namespace std;

int maxLengthRemoval(char* sztext )
{
    for(int i = 0; sztext[i] != '\0'; ++i)
    {

    }


    return 0;
}

int main()
{
    int t = 0;
    char sztext[1001];
    
    cin>>t;
    
    while(t--)
    {
        cin>>sztext; 
    }


    return 0;
}