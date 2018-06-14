/*
Pairs with difference k
https://practice.geeksforgeeks.org/problems/pairs-with-difference-k/0/?ref=self

Given an array of N positive integers  a1, a2 ..... an. 
Find the number of pairs of integers whose difference is equal to a given number K.

Input: 
The first line of the input contains 'T' denoting the total number of testcases.
Then follows the description of testcases. The first line of each testcase contains two space separated positive integers N and K denoting the size of array and the value of K. The second line contains N space separated positive integers denoting the elements of array.

Output:
Output the number of pairs having difference equal to K in a separate line.
Constraints:
1<=T<=100
1<=N<=100
1<=K<=100
1<=Arr[i]<=1000

Example:
Input:
2
5 2
6 4 5 8 7
4 2
1 3 1 8
Output:
3
2


*/

/*

1.Sort the array
2.use slide window to find these pairs
3. pay attention: these elements are not distinct.
*/

#include<iostream>
#include<algorithm>
using namespace std;

int KDiffPairsCount(int*a, int N, int K)
{
    int s = 1;
    int count = 0;

    std::sort(a, a+N);

    for(int i = 0; i<N; ++i)
    {
        bool bSet = false;
        for( int j = s; j<N; ++j)
        {
            if((a[i]+K) == a[j])
            {
                if(!bSet)  //the first element that equal a[i]+K
                {
                    s = j;
                    bSet = true;
                }
                ++count;
            }
            else if( (a[i] + K) < a[j])
            {
                break;
            }
        }
    }

    cout<<count<<endl;
    return 0;
}

int main()
{
    int t = 0;
    int N;
    int K;
    int a[200];

    cin>>t;
    while(t--)
    {
        cin>>N>>K;
        int i = 0;
        while(i<N)
        {
            cin>>a[i++];
        }
        KDiffPairsCount(a,N,K);
    }

    return 0;
}