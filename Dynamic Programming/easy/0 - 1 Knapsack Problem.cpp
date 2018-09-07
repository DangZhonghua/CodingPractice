/*
https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem/0
https://www.geeksforgeeks.org/0-1-knapsack-problem-dp-10/
https://www.geeksforgeeks.org/space-optimized-dp-solution-0-1-knapsack-problem/

0 - 1 Knapsack Problem

You are given weights and values of N items, put these items in a knapsack of capacity W to get the maximum total value in the knapsack. Note that we have only one quantity of each item, In other words, given two integer arrays val[0..N-1] and wt[0..N-1] which represent values and weights associated with N items respectively. Also given an integer W which represents knapsack capacity, find out the maximum value subset of val[] such that sum of the weights of this subset is smaller than or equal to W. You cannot break an item, either pick the complete item, or don’t pick it (0-1 property).
 

Input:

The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case consists of four lines. The first line consists of N the number of items. The second line consists of W, the maximum capacity of the knapsack. In the next  line are N space separated positive integers denoting the values of the N items and in the fourth line are N space separated positive integers denoting the weights of the corresponding items.
 

Output:

Print the maximum possible value you can get with the given conditions that you can obtain for each test case in a new line.
 

Constraints:

1≤T≤100

1≤N≤100

1≤W≤100

1≤wt[i]≤100

1≤v[i]≤100


Example:

Input:
1
3
4
1 2 3
4 5 1
Output:
3

*/

#include<iostream>
#include<vector>
using namespace std;

int Knapsack(int* v, int*w, int N, int W)
{
    vector<int> cap;
    for(int i = 0; i<=W; ++i)
    {
        cap.push_back(0);
    }
    
    for(int i = 0; i<N; ++i)
    {
        for(int j = W;j>=w[i];--j)
        {
            if(cap[j]<cap[j-w[i]] + v[i])
            {
                cap[j] = cap[j-w[i]] + v[i];
            }
        }
    }
    
    cout<<cap[W]<<endl;
    
    return 0;
}

int main()
 {
    int t = 0;
    int N = 0;
    int W = 0;
    int w[101] = {0};
    int v[101] = {0};
    
    cin>>t;
    
    while(t>0)
    {
        --t;
        cin>>N;
        cin>>W;
        int i = 0;
        while(i<N)
        {
            cin>>v[i];
            ++i;
        }
        i = 0;
        while(i<N)
        {
            cin>>w[i];
            ++i;
        }
        Knapsack(v,w,N,W);
    }


	return 0;
}


// A Dynamic Programming based solution for 0-1 Knapsack problem 
#include<stdio.h> 
  
// A utility function that returns maximum of two integers 
int max(int a, int b) { return (a > b)? a : b; } 
  
// Returns the maximum value that can be put in a knapsack of capacity W 
int knapSack(int W, int wt[], int val[], int n) 
{ 
   int i, w; 
   int K[n+1][W+1]; 
  
   // Build table K[][] in bottom up manner 
   for (i = 0; i <= n; i++) 
   { 
       for (w = 0; w <= W; w++) 
       { 
           if (i==0 || w==0) 
               K[i][w] = 0; 
           else if (wt[i-1] <= w) 
                 K[i][w] = max(val[i-1] + K[i-1][w-wt[i-1]],  K[i-1][w]); 
           else
                 K[i][w] = K[i-1][w]; 
       } 
   } 
  
   return K[n][W]; 
} 
  
int main() 
{ 
    int val[] = {60, 100, 120}; 
    int wt[] = {10, 20, 30}; 
    int  W = 50; 
    int n = sizeof(val)/sizeof(val[0]); 
    printf("%d", knapSack(W, wt, val, n)); 
    return 0; 
} 
