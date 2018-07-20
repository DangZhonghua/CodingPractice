/*
Get Minimum Squares
https://practice.geeksforgeeks.org/problems/get-minimum-squares/0/?ref=self
https://www.geeksforgeeks.org/minimum-number-of-squares-whose-sum-equals-to-given-number-n/

Given a number N. You need to write a program to print the minimum number of squares of this number that sums to N. 
For Example: If N = 100 , N can be expressed as (10*10) and also as (5*5 + 5*5 + 5*5 + 5*5) 
but the output will be 1 as minimum number of square is 1 , i.e (10*10).

Input:
First line of input contains a single integer T, which denotes the number of test cases. 
Then T test cases follows. First line of each test case contains a single integer N.
Output:
For each test case print the minimum number of squares that sums to N.

Constraints:
1<=T<=100
1<=N<=10^4

Example:
Input:
3
100
6
25
Output:
1
3
1
 
*/

#include<iostream>
#include<vector>
using namespace std;

  vector<int> MS(10001,10001);
  int gN = 0;
int MinimumSquares(int N)
{
    if(gN>=N)
    {
        cout<<MS[N]<<endl;
        return 0;
    }
    else
    {
            
        int i = 1;
        for(int i = gN+1; i<=N; ++i)
        {
            for(int j = 1; j<i; ++j)
            {
                int tmp = j*j;
                if(j*j > i)
                {
                    break;
                }
                if(1+MS[i-tmp] < MS[i])
                {
                    MS[i] = 1+MS[i-tmp];
                }

            }
        }

        cout<<MS[N]<<endl;
    }


    return 0;
}


int main()
{
    int t = 0;
    MS[0] = 0;
    MS[1] = 1;
    MS[2] = 2;
    MS[3] = 3;
    
    gN = 3;
    cin>>t;
    while(t--)
    {
        int N = 0;
        cin>>N;
        MinimumSquares(N);
    }
    
    return 0;
}