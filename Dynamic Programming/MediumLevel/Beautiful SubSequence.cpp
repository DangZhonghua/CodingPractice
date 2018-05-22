/*
Beautiful SubSequence
https://practice.geeksforgeeks.org/problems/beautiful-subsequence/0

Nowadays Babul is solving problems on sub-sequence. 
He is struck with a problem in which he has to find 
the longest sub-sequence in an array A of size  N such that for all (i,j) where i!=j either A[i] divides A[j] or vice versa. 
If no such sub-sequence exists then print -1. Help him to accomplish this task.

Constraints : 
1<=T<=100
2<=N<=1000
1<=A[i]<=1000

Input:
The First line contains T no. of test cases.
Each Test case is of two lines. 
The First line contains N size of the array.
Next line contains N-Space separated integers, denoting elements of an array.

Output:
For each T print the size of the longest sub-sequence satisfying the above criteria.

Example:
Input:
2
5
5 3 1 4 7
6
2 4 6 1 3 11

Output:
2
3

Explanation:
First Test Case :
Longest Sub Sequence are {5,1} , {4,1}, {3,1} etc. so size is 2.

Second Test Case :
Longest Sub Sequence are {1, 2, 6}, {1, 3, 6} so size is 3.


*/

/*
Pre-process the array before DP: sort the array.

*/

#include<iostream>
#include<algorithm>
using namespace std;

int longestPerfectSubsequence(int*a, int*b, int N)
{
    int maxset = 1;
    for(int i = 0; i<N; ++i)
    {
        b[i] = 1;
    }
    std::sort(a,a+N);

    for(int i = 1; i<N; ++i)
    {
        for(int j = 0; j<i; ++j)
        {
            if(0 ==  (a[i]%a[j]) && b[i]<b[j]+1  )
            {
                b[i] = b[j] + 1;
            }
        }
        if(b[i]>maxset)
        {
            maxset = b[i];
        }
    }
    
    if(1== maxset)
    {
        cout<<-1<<endl;
    }
    else
    {
         cout<<maxset<<endl;
    }


    return 0;
}


int main()
{
    int t = 0;
    int N = 0;
    int a[1001] = {0};
    int b[1001] = {0};

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
        longestPerfectSubsequence(a,b,N);
    }


    return 0;
}