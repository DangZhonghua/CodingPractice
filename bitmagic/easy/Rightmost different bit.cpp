/*
Rightmost different bit
https://practice.geeksforgeeks.org/problems/rightmost-different-bit/0/?ref=self

Given two numbers M and N. Write a program to find the position of rightmost different bit 
in binary representation of numbers.

Input:
First line of input contains a single integer T which denotes the number of test cases. 
T test cases follows. First line of each test case contains two space separated integers M and N.

Output:
For each test case print the position of rightmost different bit in binary representation of numbers. 
If both M and N are same then print -1 in this case.

Constraints:
1<=T<=100
1<=M<=1000
1<=N<=1000

Example:
Input:
2
11 9
52 4
Output:
2
5

*/

#include<iostream>
using namespace std;

int main()
{
    int t = 0;
    cin>>t;
    
    while(t--)
    {
        int M = 0;
        int N = 0;
        cin>>M>>N;
        
        int res = M^N;
        if(0 == res)
        {
            cout<<-1<<endl;
        }
        else
        {
            int num = 1;
            unsigned int d = 1;
            while(1)
            {
                if(d&res)
                {
                    break;
                }
                ++num;
                d <<=1;
            }
            cout<<num<<endl;
        }
    }
    return 0;    
}