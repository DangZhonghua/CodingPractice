/*
Maximum Index
https://practice.geeksforgeeks.org/problems/maximum-index/0

Given an array A of integers, find the maximum of j - i subjected to the constraint of A[i] <= A[j].

Example :

A : [3 5 4 2]

Output : 2 
for the pair (3, 4)

 

Input:

The first line contains an integer T, depicting total number of test cases. 
Then following T lines contains an integer N depicting the size of array and next line followed by the value of array.


Output:

Print the maximum difference of the indexes i and j in a separtate line.


Constraints:

1 ≤ T ≤ 100
1 ≤ N ≤ 1000
0 ≤ A[i] ≤ 100


Example:

Input
1
2
1 10
Output
1

*/


#include<iostream>
using namespace std;


int maximumIndex(int*a, int N);


int main()
 {
    int t = 0;
    int N = 0;
    int a[1000] = {0};
    
    cin>>t;
    
    while(t>0)
    {
        --t;
        cin >>N;
        int i = 0;
        while(i<N)
        {
            cin>>a[i];
            ++i;
        }
        maximumIndex(a,N);
    }
    
	return 0;
}

int maximumIndex(int*a, int N)
{
    int i = 0;
    int j = 0;
    int d = 0;
    int k = -1;
    
    int base = 0;

    for(i = 0; i<N;++i)
    {
        if(a[base]<=a[i])
        {
            k = i;
        }
    }
    d = k-base;
    
    for(i = base+1; i<N; ++i)
    {
        if(a[base] > a[i])
        {
            int l = k;
            for(j = k; j<N;++j)
            {
                if(a[j]>=a[i])
                {
                    l = j;
                }
            }
            if(d<l-i)
            {
                d = l-i;
                base = i;
                k = l;
            }
            
        }
    }
    
    
    
    cout<<d<<endl;
    
    return 0;
}
