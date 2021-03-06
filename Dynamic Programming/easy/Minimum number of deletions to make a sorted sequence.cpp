/*
Minimum number of deletions to make a sorted sequence
https://practice.geeksforgeeks.org/problems/minimum-number-of-deletions-to-make-a-sorted-sequence/0/?ref=self
Given an array of n integers. The task is to remove or delete minimum number of elements from the array 
so that when the remaining elements are placed in the same sequence order form a sorted sequence.

Input:

The first line of input contains an integer T denoting the number of test cases. 
Then T test cases follow. The first line of each test case contains an integer N denoting the size of array A.

The second line of each test case contains N space separated integers denoting elements of the array A[ ].

Output:
Output the minimum number of deletions to make a sorted sequence. Print the answer in a new line.

Constraints:

1<= T <=100
1<= N <=1000
1<= A[ ] <=1000


Example:
Input:

1
5
5 6 1 7 4

Output:
2
*/

/*

this is LIS variation problem: Minimum Deletion = Len-LIS

*/
#include<iostream>
#include<vector>
using namespace std;


int minimumDeletion(vector<int>&a)
{
    vector<int> lis(a.size(),1);
    int maxlis = 1;
    for(int i = 1; i<a.size();++i)
    {
        for(int j = 0; j<i; ++j)
        {
          if(a[i]>a[j] && lis[i]<lis[j]+1)
          {
              lis[i] = lis[j]+1;
          }
        }
        if(lis[i]>maxlis)
        {
            maxlis = lis[i];
        }
    }

    cout<<(a.size()-maxlis)<<endl;


    return 0;
}

int main(int argc, char const *argv[])
{
    int t = 0;
    cin>>t;
    while(t--)
    {
        int N = 0;
        cin>>N;
        int i =0;
        vector<int> a(N,0);
        while(i<N)
        {
            cin>>a[i];
            ++i;
        }
        minimumDeletion(a);
    }
    return 0;
}
