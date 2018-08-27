/*
https://practice.geeksforgeeks.org/problems/floor-in-a-sorted-array/0/?ref=self
Floor in a Sorted Array 
Given a sorted array having no duplicates, arr[] and a value, x, find floor of x in given array. 
Floor of x is the largest element in arr[] such that the element is smaller than or equal to x. 
If floor exists, then return index of it, else return -1.

Examples:

Input : arr[] = {1, 2, 8, 10, 11, 12, 19}, x = 5
Output : 1 
1 is index of 2. 2 is the largest element in arr[]
smaller than 5.

Input : arr[] = {1, 2, 8, 10, 11, 12, 19}, x = 20
Output : 6
19 is the largest element in arr[] smaller than 20.

Input : arr[] = {1, 2, 8, 10, 11, 12, 19}, x = 0
Output : -1
Since floor doesn't exist, output is -1.

Input:

The first line of input contains an integer T denoting the number of test cases.
The first line of each test case is N and x, N is the size of array.
The second line of each test case contains N array elements.

Output:

Print index of floor of x if it exists, else print -1

Constraints:

1 ≤ T ≤ 500
1 ≤ N ≤ 1000
0 ≤ X ≤ 1000 
1 ≤ arr[i] ≤ 10000

Example:

Input:
3
7 0
1 2 8 10 11 12 19
7 5
1 2 8 10 11 12 19
7 10
1 2 8 10 11 12 19

Output:
-1
1
3

*/

#include<iostream>
#include<vector>
using namespace std;

int floorFind(vector<int>& a, int t)
{
    int s = 0;
    int e = a.size()-1;
    int m = 0;
    int index = -1;
    
    while(s<=e)
    {
        m = (s+e)/2;
        if(a[m] == t)
        {
            index = m;
            break;
        }
        else if(a[m]>t)
        {
            e = m-1;
        }
        else
        {
            s = m+1;
        }
    }

    if(-1 == index)
    {
        if(s == a.size())
        {
            index = a.size()-1;
        }
        else if(e == -1)
        {
            index = -1;
        }
        else
        {
            index = e;
        }
    }

    cout<<index<<endl;

    return 0;
}

int main()
{
    int t = 0;
    int x = 0;
    int N = 0;
    cin>>t;

    while(t--)
    {
        cin>>N>>x;
        vector<int> a(N,0);
        int i = 0;
        while(i<N)
        {
            int d;
            cin>>d;
            a[i++] = d;
        }
        floorFind(a,x);
    }
    return 0;
}