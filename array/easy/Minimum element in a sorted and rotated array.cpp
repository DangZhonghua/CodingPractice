/*
Minimum element in a sorted and rotated array 
https://practice.geeksforgeeks.org/problems/minimum-element-in-a-sorted-and-rotated-array/0/?ref=self

A sorted array A[ ] with distinct elements is rotated at some unknown point, 
the task is to find the minimum element in it.

Expected Time Complexity: O(Log n)

Input:

The first line of input contains a single integer T denoting the number of test cases. Then T test cases follow. Each test case consist of two lines. The first line of each test case consists of an integer N, where N is the size of array.
The second line of each test case contains N space separated integers denoting array elements.

Output:
Corresponding to each test case, in a new line, print the minimum element in the array.

Constraints:

1 ≤ T ≤ 200
1 ≤ N ≤ 500
1 ≤ A[i] ≤ 1000

Example:

Input
1
5
4 5 1 2 3

Output
1

*/


#include<iostream>
using namespace std;



int FindMinInSortedRotatedArr(int*a, int N)
{
    int s = 0;
    int e = N-1;
    int m = 0;
    while(s<e)
    {
        m = (s+e)/2;
        if(a[m]>a[e])
        {
            s = m+1;
        }
        else
        {
            e = m;
        }
    }
    cout<<a[s]<<endl;

    return 0;
}


int main(int argc, char const *argv[])
{
    int t = 0;
    int N = 0;
    int a[501] = {0};

    cin>>t;
    
    while(t--)
    {
        cin>>N;
        int i = 0;
        while(i<N)
        {
            cin>>a[i++];
        }
        FindMinInSortedRotatedArr(a, N);
    }


    return 0;
}
