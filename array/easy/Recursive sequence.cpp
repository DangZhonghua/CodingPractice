/*
Recursive sequence 
https://practice.geeksforgeeks.org/problems/recursive-sequence/0/?ref=self

A function f is defined as follows F(n)= (1) +(2*3) + (4*5*6) ... n. Given an integer n the task is to print the F(n)th term.

Input:
The first line of input contains an integer T denoting the number of test cases. 
Then T test cases follow. Each test contains an integer n.

Output:
For each test case print the nth term of the sequence. .

Constraints:
1<=T<=100
1<=N<=10

Example:
Input:
2
5
7

Output:
365527
6006997207

*/

#include<iostream>
#include<vector>
using namespace std;

int RecursiveSequence(int N)
{
    unsigned long long RS[2] = {1,0};
    int next = 2;

    for(int i = 2; i<=N; ++i)
    {
        unsigned long long p = 1;
        for(int j = 0; j<i; ++j)
        {
            p *= next;
            ++next;
        }
        if(0 == i%2)
        {
            RS[1] = RS[0] + p;
        }
        else
        {
            RS[0] = RS[1] + p;
        }
    }

    if(N%2)
    {
        cout<<RS[0]<<endl;
    }
    else
    {
        cout<<RS[1]<<endl;
    }

    return 0;
}

int main(int argc, char const *argv[])
{
    int t = 0;
    int N = 0;
    
    cin>>t;
    
    while(t--)
    {
        cin>>N;
        RecursiveSequence(N);
    }

    return 0;
}
