/*

https://practice.geeksforgeeks.org/problems/closest-number/0/?ref=self

Given two integers n and m. The problem is to find the number closest to n and divisible by m. 
If there are more than one such number, then output the one having maximum absolute value. 
If n is completely divisible by m(not equal to 0), then output n only. Time complexity of O(1) is required.

Input:
The first line consists of an integer T i.e number of test cases. The first and only line of each test case contains two space separated integers n and m.

Output:
Print the closest number to n which is also divisible by m.

Constraints: 
1<=T<=100
-1000<=n<=1000

Example:
Input:
2
13 4
-15 6

Output:
12
-18

*/

#include<iostream>
using namespace std;

int ClosestNumber(int n, int m)
{
    int c = 0;
    if(n >0)
    {
        if(n%m)
        {
            c = n;
        }
        else
        {
            int d = n/m;
            if(d == 0)
            {
                c = m;
            }
            else
            {
                if(m>0)
                {
                    c = ((d+1)*m - n)>= (n-d*m)? (d+1)*m:d*m; 
                }
                else
                {
                    c = ((-d+1)*(-m) - n)>= (n-d*m)? (-d+1)*(-m):(-d)*(-m); 
                }
            } 
        }

    }
    else if(n<0)
    {
        if(n%m)
        {
            c = n;
        }
        else
        {
            int d = n/m;
            if(d == 0)
            {
                c = m;
            }
            else
            {
                if(m>0)
                {
                    c = (n-(d-1)*m)  
                }
                else
                {
                    c = m;
                }
            }
        }
    }

    return 0;
}

int main()
{
    int t;
    int m,n;

    cin>>t;

    while(t>0)
    {
        --t;
        cin>>n>>m;
        ClosestNumber(n,m);
    }
    
}