/*
Permutations of a given string
https://practice.geeksforgeeks.org/problems/permutations-of-a-given-string/0/?ref=self
https://www.geeksforgeeks.org/find-n-th-lexicographically-permutation-string-set-2/
https://www.geeksforgeeks.org/write-a-c-program-to-print-all-permutations-of-a-given-string/

Given a string, print all permutations of a given string.

Input:
The first line of input contains an integer T, denoting the number of test cases.
Each test case contains a single string S in capital letter.

Output:
For each test case, print all permutations of a given string S with single space and all permutations 
should be in lexicographically increasing order.

Constraints:
1 ≤ T ≤ 10
1 ≤ size of string ≤ 5

Example:
Input:
2
ABC
ABSG
Output:
ABC ACB BAC BCA CAB CBA 
ABGS ABSG AGBS AGSB ASBG ASGB BAGS BASG BGAS BGSA BSAG BSGA GABS GASB GBAS GBSA GSAB GSBA SABG SAGB SBAG SBGA SGAB SGBA 

*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
using namespace std;

void SwapCharP(char*x, char*y)
{
    char c = *x;
    *x = *y;
    *y = c;
}

void PermutationsofString(char* szText, int Len, int index)
{
    if(index == Len)
    {
        cout<<szText<<" ";
    }
    else
    {
        for(int i = index; i<=Len; ++i)
        {
            SwapCharP(szText+index, szText+i);
            PermutationsofString(szText,Len,index+1);
            SwapCharP(szText+index,szText+i);
        }
    }
}

int main()
{
    int t= 0;
    cin>>t;

    while(t--)
    {
        char szText[10];
        cin>>szText;
        std::sort(szText,szText+strlen(szText));
        PermutationsofString(szText,strlen(szText)-1,0);
        cout<<endl;
    }

    return 0;
}