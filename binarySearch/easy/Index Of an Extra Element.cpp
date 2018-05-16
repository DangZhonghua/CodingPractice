 /*
Index Of an Extra Element 
https://practice.geeksforgeeks.org/problems/index-of-an-extra-element/1/?ref=self

Given two sorted arrays. There is only 1 difference between the arrays. First array has one element extra added in between. 
Find the index of the extra element.

Input:
The first line of input contains an integer T, denoting the no of test cases. 
Then T test cases follow. The first line of each test case contains an integer N, 
denoting the number of elements in array. 
The second line of each test case contains N space separated values of the array A[]. 
The Third line of each test case contains N-1 space separated values of the array B[].

Output:
Return the index of the corresponding extra element in array A[].(starting index 0).

Constraints:
1<=T<=100
1<=N<=100
1<=Ai<=1000

Example:
Input:
2
7
2 4 6 8 9 10 12
2 4 6 8 10 12
6
3 5 7 9 11 13
3 5 7 11 13
Output:
4
3

 */


/*

Solution: since these array are sorted, inituively, this should be slove by binary* method.
Seatch the middle of b in the array a, then judge the index
*/

#include<iostream>
using namespace std;


int binarySearch(int*a, int s, int e, int t)
{
    int index = -1;
    while(s<=e)
    {
        int m = (s+e)/2;
        if(a[m] == t)
        {
            index = m;
            break;
        }
        else if(a[m]>t)
        {
            e -= 1;
        }
        else
        {
            s += 1;
        }
    }
 
    return index;
}


int findExtra(int a[], int b[], int N)
{
    int sa = 0;
    int ea = 0;
    int sb = 0;
    int eb = 0;
    int index = 0;
     sa = 0;
     ea = N-1;
     sb = 0;
     eb = N-2;
     int t = 0;

     while(sb<=eb)
     {
        int mb = (sb+eb)/2;
        index = binarySearch(a,sa,ea,b[mb]);
        if(index-sa == mb-sb) // the extra element should be in the second half.
        {
            sb = mb + 1;
            sa = index +1;
            t =  sa;
        }
        else //the extra element should be in the first half.
        {
            eb = mb-1;
            ea = index-1;
            t = ea;           
        }
     }
   cout<<t<<endl;
    return t;
}


int main()
{
    int t;
    int a[101];
    int b[101];
    int N = 0;

    cin>>t;

    while(t>0)
    {
        --t;
        cin>>N;
        int i = 0;
        while(i<N)
        {
            cin>>a[i++];
        }
        i = 0;
        while(i<N-1)
        {
            cin>>b[i++];
        }
        findExtra(a,b,N);
    
    }

    return 0;
}