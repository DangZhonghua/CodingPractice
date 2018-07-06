/*
Printing Maximum Sum Increasing Subsequence
https://practice.geeksforgeeks.org/problems/printing-maximum-sum-increasing-subsequence/0/?ref=self

The Maximum Sum Increasing Subsequence problem is to find the maximum sum subsequence of a 
given sequence such that all elements of the subsequence are sorted in increasing order.

Input:



The first line of input contains an integer T denoting the number of test cases. 
Then T test cases follow. The first line of each test case contains an integer N denoting 
the size array A representing the set of numbers

The second line of each test case contains N space separated integers denoting elements of the array A[ ].


Output:
Print all the elements of the maximum sum increasing subsequence for each test case in a new line.If there are more than one subsequence print the one with least number of elements.


Constraints:

1<= T <=100
1<= N <=1000
1<= A[ ] <=10000


Example:
Input:

7
1 101 2 3 100 4 5

Output:
1 2 3 100

*/

#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int MaximumSumOfIS(int*a, int N)
{
    vector<int> sum(N,0);
    vector<int> index(N,0);
    int max         = 0;
    int maxindex    = 0;

    for(int i = 0; i<N; ++i)
    {
        sum[i]      = a[i];
        index[i]    = i;
    }

    for(int j = 1; j<N; ++j)
    {
        for(int i = 0; i<j; ++i)
        {
            if(a[j]>a[i]) // make sure increasing subsequence
            {
                if(sum[j]<sum[i] + a[j])
                {
                    sum[j] = sum[i] + a[j];
                    index[j] = i;
                }
            }
        }
        if(max<sum[j])
        {
            max      = sum[j];
            maxindex = j;
        }
    }
    
    stack<int> sis;
    sis.push(maxindex);
    int i = maxindex;
    while(i != index[i])
    {
        i = index[i];
        sis.push(i);
    }
    while( !sis.empty() )
    {
        cout<<a[sis.top()]<<" ";
        sis.pop();
    }
    cout<<endl;
    
    return 0;
}


int main(int argc, char const *argv[])
{
    int t       = 0;
    int a[1001] = {0};
    int N = 0;
    
    cin>>t;

    while(t--)
    {
        cin>>N;
        int i = 0;
        while(i<N)
        {
            cin>>a[i++];
        }
        MaximumSumOfIS(a,N);
    }

    return 0;
}

