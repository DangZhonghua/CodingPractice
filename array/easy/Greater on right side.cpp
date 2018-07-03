/*
Greater on right side 
https://practice.geeksforgeeks.org/problems/greater-on-right-side/0/?ref=self
Given an array of integers, replace every element with the next greatest element 
(greatest element on the right side) in the array. Since there is no element next to the last element, replace it with -1.

Input:

The first line of input contains an integer T denoting the number of test cases.
The first line of each test case is N,N is the size of array.
The second line of each test case contains N input A[i].

Output:

Print the modified array.

Constraints:

1 ≤ T ≤ 50
1 ≤ N ≤ 100
1 ≤ A[i] ≤ 1000

Example:

Input:
2
6
16 17 4 3 5 2
4
2 3 1 9

Output:
17 5 5 5 2 -1
9 9 9 -1


*/

/*

Just traverse the array from end to begin. During traversal, update the maximum of the right side.

*/

#include<iostream>
using namespace std;

int replaceWithGeatestOfRightSide(int*a, int N)
{
    int max = -1;
    for(int i = N-1; i>=0; --i)
    {
        int t = a[i];
        a[i] = max;
        if(t>max)
        {
            max = t;
        }
    }
    
    for(int i = 0; i<N; ++i)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
    
    return 0;
}

int main()
{
    int t = 0;
    int N = 0;
    int a[200] = {0};
    
    cin>>t;
    
    while(t--)
    {
        cin>>N;
        int i = 0;
        while(i<N)
        {
            cin>>a[i++];
        }
        replaceWithGeatestOfRightSide(a,N);
    }

    return 0;
}