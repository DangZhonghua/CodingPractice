/*
Single Number
https://practice.geeksforgeeks.org/problems/single-number/0/?ref=self

Given an array of integers, every element appears twice except for one. 
Find that single one.
Note: There can be an element appearing odd number of times. 
That element needs to be counted as single number. 
In case of odd number of copies, the even ones get cancelled out 
from each other rendering just one element in the end.

Input:

First line will consist  a number T, the number of test cases.
Each test case will then consist of an Integer N depicting the size of array.
Next line will consist of N space separated integers ,the value of array.

Output:

Print the element that appears once in the array in a separate line.


Constraints:

1<=T<=30
1<=N<=100
0<=A[i]<=50

Example:

Input:
2
3
1 1 2
7
8 8 7 7 6 6 1 

Output:
2
1

*/
#include<iostream>
#include<vector>
using namespace std;

int singleNumber(vector<int>& a)
{
    int xorv = 0;
    
    for(int i = 0; i<a.size(); ++i)
    {
        xorv ^= a[i];
    }
    
    cout<<xorv<<endl;

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
        vector<int> a(N,0);
        int i = 0;
        while(i<N)
        {
            int d = 0;
            cin>>d;
            a[i++] = d;
        }
        singleNumber(a);
    }
    

    return 0;
}
