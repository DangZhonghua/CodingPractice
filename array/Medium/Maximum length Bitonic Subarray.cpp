/*
Maximum length Bitonic Subarray 
https://practice.geeksforgeeks.org/problems/maximum-length-bitonic-subarray/0/?ref=self

Given an array A[0 … n-1] containing n positive integers, a subarray A[i … j] is bitonic 
if there is a k with i < k < j such that A[i] < A[i + 1] ... < A[k] > A[k + 1] > .. A[j – 1] >  A[j]. 
Write a program that returns the length of the maximum length bitonic subarray.

For Example: In array {20, 4, 1, 2, 3, 4, 2, 10} the maximum length bitonic subarray is 
{1, 2, 3, 4, 2} which is of length 5.

Note: A[k] can be first or last element. Ex:-  10 20 30 , 30 20 10 and 1 2 3 4 3 2 1 these all are bitonic array.

Input:

The first line of input contains an integer T denoting the number of test cases.
The first line of each test case is N,N is the size of array.
The second line of each test case contains N input A[i].

Output:

Print the maximum length of bitonic subarray.

Constraints:

1 ≤ T ≤ 200
1 ≤ N ≤ 200
1 ≤ A[i] ≤ 1000

Example:

Input:
2
6
12 4 78 90 45 23
4
10 20 30 40

Output:
5
4

*/

/*
 Increase then Decrease

先升后降
先降后升
 
*/


#include<iostream>
using namespace std;

int longestBitonicSubarray(int*a, int N)
{
    bool bIncreased = false; //Current subarray trend.
    int  maxlen = 1;
    int  s      = 0;
    int  e      = 0;
    int  i      = 0;
    // i is the subarray begin index
    // j is the beyond of end index of subarray.
    for(int j = 1; j<N; ++j)
    {
        if(a[j]>a[j-1])
        {
            if(!bIncreased)
            {
                if( j-1-i+1 > maxlen)
                {
                    maxlen = j-i;
                    s = i;
                    e = j-1;
                }
                i = j-1; //Update subarray begin index.
                bIncreased = true; //update subarray trend.
            }
            else
            {
                if(maxlen<j-i+1)
                {
                    maxlen = j-i+1;
                    e = j;
                }
            }
        }
        // First solution, the euqal case is not handled.
        else if(a[j] == a[j-1]) //the equal case is the segment point
        {
            i = j; //Set subarray start point.
            bIncreased = false;
        }
        else //a[j]<a[j-1]:decrease
        {
            bIncreased = false;
            if(maxlen<j-i+1)
            {
                maxlen = j-i+1;
                e = j;
            }   
        }
    }
    
    cout<<maxlen<<endl;

    return 0;
}


int main()
{
    int t = 0;
    int N = 0;
    int a[1000];

    cin>>t;
    
    while(t--)
    {
        cin>>N;
        int i = 0;
        while(i<N)
        {
            cin>>a[i++];
        }
        longestBitonicSubarray(a, N);
    }

    return 0;
}


