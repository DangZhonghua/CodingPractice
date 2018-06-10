/*
Sorted subsequence of size 3 
https://practice.geeksforgeeks.org/problems/sorted-subsequence-of-size-3/1/?ref=self

Given an array A of N integers, Your task is to complete the function find3Numbers 
which finds any 3 elements in it such that A[i] < A[j] < A[k] and i < j < k. 
You need to return them as a vector, if no such element is present then return the empty vector of size 0.

Input:
The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. 
The first line of each test case contains an integer N denoting the size of the array A in the next line are N space separated values of the array A.

Output:
For each test case in a new line output will be 1 
if the sub-sequence returned by the function is present in array A else 0.

Constraints:
1<=T<=100
1<=N<=100
1<=A[ ] <=1000

Example:
Input:
2
5
1 2 1 1 3
3
1 1 3
Output:
1
0

Explanation:
There are 2 test cases
For first test case
a sub-sequence 1 2 3 exist 
For second test case
no such sub-sequence exist


*/

#include<vector>
#include<iostream>
using namespace std;


vector<int> find3Numbers(vector<int> a, int N)
{
    vector<int > vt;
    vector<int> vsmall(N, -1);
    vector<int> vgreat(N,-1);
    int min = 0;
    for(int i = 1; i<N; ++i)
    {
        if(a[i]<a[min])
        {
            min = i;
        }
        else
        {
            vsmall[i] = min; 
        }
    }

    int max = N-1;
    for(int i=N-2; i>=0; --i)
    {
        if(a[i]>a[max])
        {
            max = i;
        }
        else
        {
            vgreat[i] = max;
        }
    }

    for(int i = 0; i<N; ++i)
    {
        if(vsmall[i] != -1 && vgreat[i] != -1)
        {
            vt.push_back(a[vsmall[i]]);
            vt.push_back(a[i]);
            vt.push_back(a[vgreat[i]]);
            break;
        }
    }
    return vt;    
}

int main()
{
    int t = 0;
    int N = 0;
   // int A[101];
    vector<int> A;

    cin>>t;
    
    while(t--)
    {
        cin>>N;
        int i = 0;
        while(i<N)
        {
            int a;
            cin>>a;
           A.push_back(a);
           ++i;
        }
        find3Numbers(A,N);
    }


return 0;
}