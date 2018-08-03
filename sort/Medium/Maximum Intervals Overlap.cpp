/*
Maximum Intervals Overlap 
https://practice.geeksforgeeks.org/problems/maximum-intervals-overlap/0/?ref=self
https://www.geeksforgeeks.org/find-the-point-where-maximum-intervals-overlap/

Consider a big party where a log register for guest’s entry and exit times is maintained. 
Find the time at which there are maximum guests in the party. Note that entries in register are not in any order.

Input:
The first line of input contains an integer T denoting the number of test cases. 
Then T test cases follow. Each test case contains an integer n denoting the size of the entry and exit array. 
Then the next two line contains the entry and exit array respectively.

Output:
Print the maximum no of guests and the time at which there are maximum guests in the party.

Constraints:
1<=T<=10^5
1<=N<=10^5
1<=entry[i],exit[i]<=10^5

Example:
Input:
2
5
1 2 10 5 5
4 5 12 9 12
7
13  28 29  14  40 17  3 
107 95 111 105 70 127 74 

Output:
3 5
7 40

*/

/*

Slide window counting: the enter number and leave number are counting 

*/


#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int maximumOverlap(int*in,int*out, int N)
{
    int max = INT_MIN;
    
    for(int i = 0; i<N; ++i)
    {
        if(max<in[i])
        {
            max = in[i];
        }
        if(max<out[i])
        {
            max  = out[i];
        }
    }
    vector<int> wc(max + 2, 0);
    
    for(int i = 0; i< N; ++i)
    {
        wc[in[i]] +=1; // enter party
        wc[out[i] +1 ] -=1; // leave the party
    }
    
    int maxc = INT_MIN;
    int t = 0;
    int time = 0;
    for(int i = 0; i<= max+1; ++i)
    {
        t += wc[i];
        if(t>maxc)
        {
            maxc = t;
            time = i;
        }
    }
    
    cout<<maxc<<" "<<time<<endl;

    return 0;
}

int main()
{
    int t = 0;
    int N = 0;
    int a[100000];
    int b[100000];
    
    cin>>t;
    
    while(t--)
    {
        cin>>N;
        int i = 0;
        while(i<N)
        {
            cin>>a[i++];
        }
        i = 0;
        while(i<N)
        {
            cin>>b[i++];
        }
        maximumOverlap(a,b,N);
    }

    return 0;
}