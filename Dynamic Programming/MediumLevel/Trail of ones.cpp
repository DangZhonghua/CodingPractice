/*
Trail of ones
https://practice.geeksforgeeks.org/problems/trail-of-ones/0/?ref=self
Given a number N, find the number of binary strings of length N that contains consecutive 1's in them.
 

Input
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. 
The first line of each test case contains a positve integer N, denoting the length of the binary string.


Output
Print out the count of strings having consecutive 1's in them.
 

Constraints
1 <= T <= 200
2 <= N <=30



Examples 

Input
3
2
5
15

Output
1
19
31171


Expaination
In the above first testcase there are 4 strings of length 2, the strings are 00, 01, 10 and 11. 
Only the string 11 has consecutive 1's.
 

Expected Complexity
Time: O(N)


*/

/*

We first calculate the non-consecutive 1's, suppose it is NC.
the the consecutive 1's is: 2^n - NC.

NC[N][0] = NC[N-1][1] + NC[N-1][0] // append 0
NC[N][1] = NC[N-1][0]

total =  NC[N][0] + NC[N][1]

For Input:
2
14
25
Output of Online Judge is:
15397
33358014

*/

#include<iostream>
#include<vector>
using namespace std;

int TrailOnes(int N)
{
    vector<vector<long long> > NC(N+1,vector<long long>(2,0));
    long long count = 0;

    NC[1][0] = 1;  // only one  '0'
    NC[1][1] = 1;  //only one '1'
    
    for(int i =  2; i<=N; ++i)
    {
        NC[i][0] = NC[i-1][0] + NC[i-1][1];
        NC[i][1] = NC[i-1][0];
    }
    count = ( (1<<N) - (NC[N][0]+NC[N][1]) );
    
    cout<< count<<endl;
    
    
    cout<<count<<endl;

    return 0;
}



int main()
{
    int t = 0;
    int N = 0;
    
    cin>>t;

    while(t--)
    {
        cin>>N;
        TrailOnes(N);
    }


    return 0;
}