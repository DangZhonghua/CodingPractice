/*
https://practice.geeksforgeeks.org/problems/element-appearing-once/0/?ref=self
Element appearing once 

Given an sorted array A[i] of N positive integers having all the numbers occuring exactly twice, except for one number which will occur only once. Find the number occuring only once.

Input
The first line of input contains an integer T denoting the number of test cases. Then T test cases
follow. The first line of each test case contains a positive integer N, denoting the size of the array.
The second line of each test case contains a N positive integers, denoting the elements of the
array.


Output
Print out the singly occuring number.


Constraints
1 <= T  <= 100
0 <   N  <= 100
0 <= A[i] <= 100

Examples 

Input
2
5
1 1 2 5 5
7
2 2 5 5 20 30 30


Output
2
20
 

Expected Complexity

Time : O(N)


*/

/*

use xor method

*/

#include<iostream>
#include<vector>
using namespace std;

int appearOnceElement(vector<int>& a)
{
    int nxor = 0;

    for(int i:a)
    {
        nxor ^= i;
    }
    cout<<nxor<<endl;

    return 0;
}

int main(int argc, char const *argv[])
{
    int t = 0;
    int N = 0;

    cin>>t;

    while(t--)
    {
        cin>>N;
        vector<int> a(N,0);
        int i = 0;
        while(i<N)
        {
            int d = 0;
            cin>>d;
            a[i++] = d;
        }
        appearOnceElement(a);
    }

    return 0;
}
