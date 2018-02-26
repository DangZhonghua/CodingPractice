//https://practice.geeksforgeeks.org/problems/c-visible-numbers/0/?ref=self

// Given an array of integer having n elements, print the numbers that occur more than n/3 in that array. 

// Input: 
// The first line of input contains integer T denoting the number of test cases.  Each test case has subsequent two lines of input. The first line is an integer N, denoting the size of integer array A. Second line consists of N space separated integers of the array A.

// Output: 
// For each test case, the output is the elements that occur more than n/3 times in increasing order. If no element occurs then return -1.

// Constraints:
// 1<=T<=100
// 1<=N<=100
// 0<=A[i]<=100

// Example:
// Input:
// 2
// 6
// 1 2 1 3 1 2
// 8
// 1 2 2 3 2 3 2 3
// Output:
// 1
// 2 3



#include<iostream>
#include<algorithm>
using namespace std;

int visibleNumbers(int*a, int N);

int main()
 {
    int t = 0;
    int N = 0;
    int a[101] = {0};
    
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
        visibleNumbers(a,N);
        
    }
    
	return 0;
}

int visibleNumbers(int*a, int N)
{
    std::sort(a,a+N);
    
    int oneThirdCount   = N/3;
    int base            = a[0];
    int nBaseCount      = 1;
    bool bFind          = false;
    
    for(int i = 1; i<N; ++i)
    {
        if(a[i] == base)
        {
            ++nBaseCount;
        }
        else
        {
            if(nBaseCount>oneThirdCount)
            {
                cout<<base<<" ";
                bFind = true;
            }
            nBaseCount = 1;
            base = a[i];
        }
    }
    
    if(nBaseCount>oneThirdCount)
    {
        cout<<base<<" ";
        bFind = true;
    }
    if(!bFind)
    {
        cout<<-1;
    }
    cout<<endl;    
    
    return 0;
}