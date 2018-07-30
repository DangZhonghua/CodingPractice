/*
Palindromic Array
https://practice.geeksforgeeks.org/problems/palindromic-array/0
https://www.geeksforgeeks.org/find-minimum-number-of-merge-operations-to-make-an-array-palindrome/

You are given an array A of size N. Your task is to find the minimum number of operations needed 
to convert the given array to 'Palindromic Array'.

Palindromic Array:
[23,15,23] is a ‘Palindromic Array’ but [2,0,1] is not.

The only allowed operation is that you can merge two adjacent elements in the array and replace them with their sum.

Input:
The first line of input contains an integer T denoting the number of test cases.
The first line of each test case is N, where N is the size of array.
The second line of each test case contains N space separated integers which is the input for the array.

Output:
Output the minimum number of operations required to make the given array a palindromic array.

Constraints:
1<=T<=100
1<=N<=100

Example:
Input:
2
5
3 2 3 3 5
4
5 3 3 4
Output:
1
3

Explanation:
For Test Case 1: [3 2 3 3 5] after merging the 1st two elements 3 and 2, 
we get the array as [5 3 3 5] which is a palindrome, hence only 1 operation is needed.


*/

/*

OP[i][j] = min{ OP[i+1][j]+1, OP[i][j-1] + 1 }

*/

#include<iostream>
#include<vector>
using namespace std;

int minimumOpPalindrom(int *a, int N)
{
    int nop = 0;
    int i = 0;
    int j = N-1;
    
    while(i<j)
    {
        if(a[i] == a[j])
        {
            ++i;
            --j;
        }
       else if(a[i]>a[j])
        {
            a[j-1] = a[j-1] + a[j];
            --j;
            ++nop;
        }
        else
        {
            a[i+1] = a[i+1]+a[i];
            ++i;
            ++nop;
        }
    }

    cout<<nop<<endl;

    return 0;
}

int main(int argc, char const *argv[])
{
    int t = 0;
    int N = 0;
    int a[200];
    cin>>t;
    
    while(t--)
    {
        cin>>N;
        int i = 0;
        
        while(i<N)
        {
            cin>>a[i++];
        }
        minimumOpPalindrom(a,N);
    }
    return 0;
}
