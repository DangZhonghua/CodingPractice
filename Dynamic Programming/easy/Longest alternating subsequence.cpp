/*
Longest alternating subsequence 
https://practice.geeksforgeeks.org/problems/longest-alternating-subsequence/0/?ref=self

A sequence {x1, x2, .. xn} is alternating sequence if its elements satisfy one of the following relations :

x1 < x2 > x3 < x4 > x5..... or  x1 >x2 < x3 > x4 < x5.....

Your task is to find the longest such sequence.

 

Input:

The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. 
The first line of each test case contains an integer N denoting the size array A.
The second line of each test case contains N space separated integers denoting elements of the array A[ ].


Output:
Print the length of the longest alternating subsequence for each testcase in a new line.

Constraints:

1<= T <=100
1<= N <=1000
1<= A[ ] <=1000

Example:

Input:

2
3
1 5 4
8
10 22 9 33 49 50 31 60

Output:

3
6
*/

/*

las[i] = max {las[j][smaller] + 1, las[j][larger] + 1}  for j<i

*/



#include<iostream>
#include<vector>
using namespace std;

int las(int*a, int N)
{
    int max = 0;
    vector<int> vl(N,1);
    vector<int> vs(N,1);

    for(int i = 1; i<N; ++i)
    {
        for(int j = 0; j<i; ++j)
        {
            if(a[i]>a[j])
            {
                if(vs[j] + 1 > vl[i])
                {
                    vl[i] = vs[j] + 1;
                }
            }
            else if(a[i]<a[j])
            {
                if(vl[j] + 1 > vs[i])
                {
                    vs[i] = vl[j] + 1;
                }
            }
        }
        if(max<vs[i])
        {
            max = vs[i];
        }
        if(max<vl[i])
        {
            max = vl[i];
        }
        
    }

    cout<<max<<endl;

    return 0;
}

int main()
{
    int t = 0;
    int N = 0;
    int a[1000] = {0};
    
    cin>>t;
    
    while(t--)
    {
        cin>>N;
        int i = 0;
        while(i<N)
        {
            cin>>a[i++];
        }
        las(a,N);
    }

    return 0;
}