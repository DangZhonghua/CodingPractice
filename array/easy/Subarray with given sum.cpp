/*
Subarray with given sum 
https://practice.geeksforgeeks.org/problems/subarray-with-given-sum/0

Given an unsorted array of non-negative integers, find a continuous sub-array which adds to a given number.

Input:

The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case consists of two lines. The first line of each test case is N and S, where N is the size of array and S is the sum. The second line of each test case contains N space separated integers denoting the array elements.

Output:

Corresponding to each test case, in a new line, print the starting and ending positions of first such occuring subarray if sum equals to subarray, else print -1.

Note: Position of 1st element of the array should be considered as 1.

Expected Time Complexity: O(n)

Constraints:
1 ≤ T ≤ 100
1 ≤ N ≤ 100
1 ≤ an array element ≤ 200

Example:

Input:
2
5 12
1 2 3 7 5
10 15
1 2 3 4 5 6 7 8 9 10

Output:
2 4
1 5

Explanation :
In first test case, sum of elements from 2nd position to 4th position is 12
In second test case, sum of elements from 1st position to 5th position is 15



*/

#include<iostream>
using namespace std;

void givenSumSubArray(int*a, int N, int S);


int main()
 {
    int t = 0;
    int N = 0;
    int S = 0;
    int a[101] = {0};
    
    cin>>t;
    
    while(t>0)
    {
        --t;
        cin>>N;
        cin>>S;
        int i = 1;
        while(i<=N)
        {
            cin>>a[i];
            ++i;
        }
        givenSumSubArray(a,N,S);
    }

	return 0;
}

//When larger than target, subtract a[i] increase i
//When smaller then target, increase j, add a[j]
void givenSumSubArray(int*a, int N, int S)
{
    
 int sum = 0;
 sum = a[1];
 int i = 1;
 int j = 1;
 bool bsum = false;
 
 while(i<=N&&j<=N)
 {
     if(sum == S)
     {
         bsum = true;
         break;
     }
     if(sum>S)
     {
         sum -= a[i];
         ++i;
         if(i>j)
         {
             j = i;
         }
     }
     else
     {
         ++j;
         if(j>N) break;
         sum += a[j];
     }
 }
 if(bsum)
 {
     cout<<i<<" "<<j<<endl;
 }
 else
 {
     cout<<-1<<endl;
 }
    
}