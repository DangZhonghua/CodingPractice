/*
Counting elements in two arrays

https://practice.geeksforgeeks.org/problems/counting-elements-in-two-arrays/1


Given two unsorted arrays arr1[] and arr2[]. They may contain duplicates. 
For each element in arr1[] count elements less than or equal to it in array arr2[].

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case contains two integers m and n denoting the size of the two arrays. The following two lines will contain both the arrays respectively.

Output:
Print the count of elements less than or equal to it in arr2 for each element in arr1.

Constraints:
1<=T<=10^5
1<=m,n<=10^5
1<=arr1[i],arr2[j]<=10^5

Example:
Input:
2
6 6
1 2 3 4 7 9
0 1 2 1 1 4
5 7
4 8 7 5 1
4 48 3 0 1 1 5

Output:
4 5 5 6 6 6 
5 6 6 6 3
*/

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

// function to count for each element in 1st array,
// elements less than or equal to it in 2nd array

#include<iostream>
#include <algorithm>
using namespace std;

int FindLastIndex(int *a, int N, int t)
{
    int index = -1;
    int s = 0;
    int e = N - 1;

    while (s <= e)
    {
        int m = (s + e) / 2;

        if (a[m] == t)
        {
            index = m;
            s = m+1;
        }
        else if (a[m] > t)
        {
            e = m-1;
        }
        else
        {
            s = m+1;
        }
    }

    return e;
}

void countEleLessThanOrEqual(int arr1[], int arr2[], int m, int n)
{
    std::sort(arr2, arr2 + n);
    
    for(int i = 0; i< m; ++i)
    {
        int index = FindLastIndex(arr2,n,arr1[i]);
        if(-1 != index)
        {
            cout<<index+1<<" ";
        }
        else
        {
            cout<<0<<" ";
        }
    }
}

int main()
{
    int t = 0;
    int a[100000];
    int b[100000];
    int m,n;

    cin>>t;
    
    while(t>0)
    {
        --t;
        cin>>m>>n;
        
        int i = 0;
        while(i<m)
        {
            cin>>a[i++];
        }
        i = 0;
        while(i<n)
        {
            cin>>b[i++];
        }
        countEleLessThanOrEqual(a,b,m,n);
    }


    return 0;
}