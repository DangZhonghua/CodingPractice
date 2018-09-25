/*

Perfect Sum Problem 
https://practice.geeksforgeeks.org/problems/perfect-sum-problem/0/?ref=self

Given an array of integers and a sum, the task is to count all subsets of given array with sum equal to given sum.

Input:
The first line of input contains an integer T denoting the number of test cases. 
Then T test cases follow. Each test case contains an nteger n denoting the size of the array. 
The next line contains n space separated integers forming the array. The last line contains the sum.

Output:
Count all the subsets of given array with sum equal to given sum.

Constraints:
1<=T<=10^5
1<=n<=10^5
1<=a[i]<=10^5
1<=sum<=10^5

Example:
Input:
2
6
2 3 5 6 8 10
10
5
1 2 3 4 5
10

Output:
3
3

*/


#include<iostream>
#include<vector>
using namespace std;

int PerfectSum(vector<int>& a, int sum)
{
    vector<int> vw(sum+1, 0);
    vw[0] = 1; 

    for(int i = 0; i<a.size(); ++i)
    {
        for(int v = sum; v>=a[i]; --v)
        {
            if(vw[v-a[i]])
            {
                vw[v] += vw[v-a[i]];
            }
        }
    }   
    
    cout<<vw[sum]<<endl;

    
    return 0;
}


int main(int argc, char const *argv[])
{
    int t = 0;
    
    cin>>t;

    while(t--)
    {
        int N,M;
        cin>>N;
        vector<int> a(N,0);

        int i = 0;
        while(i<N)
        {
            cin>>a[i];
            ++i;
        }
        cin>>M;
        PerfectSum(a,M);
    }
    return 0;
}
