/*
Longest Arithmetic Progression
https://practice.geeksforgeeks.org/problems/longest-arithmetic-progression/0
https://www.geeksforgeeks.org/length-of-the-longest-arithmatic-progression-in-a-sorted-array/

Given an array of sorted numbers having no duplicates , 
write a program to find the length of the Longest Arithmetic Progression (LLAP) in it.

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. 
Each test case consists of two lines.
The first line of each test case contains an integer N , where  N is the size of array.
The second line of each test case contains N space separated integers denoting array input A[i].

Output:
 Print the length of the Longest Arithmetic Progression ​

Constraints:
1 <=T<= 200
1 <= N <= 1000
1 <= arr[i] <= 10000

Example:

Input:
2
6
1  7 10  13  14  19
5
2 4  6 8 10

Output:
4
5

Explanation:
For test case 1:
set[] = {1, 7, 10, 13, 14, 19}
output = 4
The longest arithmetic progression is {1, 7, 13, 19}
For test case 2:
set[] = {2, 4, 6, 8, 10}
output = 5 
The whole set is in AP

*/


/*

Dynamic Programming:
The required output of original problem is Length of the Longest Arithmetic Progression (LLAP) which is an integer value. 
If the given set has two or more elements, then the value of LLAP is at least 2 (Why?).
The idea is to create a 2D table L[n][n]. An entry L[i][j] in this table stores LLAP with 
set[i] and set[j] as first two elements of AP and j > i. The last column of the table is always 2 
(Why – see the meaning of L[i][j]). Rest of the table is filled from bottom right to top left. 
To fill rest of the table, j (second element in AP) is first fixed. i and k are searched for a fixed j. 
If i and k are found such that i, j, k form an AP, then the value of L[i][j] is set as L[j][k] + 1. 
Note that the value of L[j][k] must have been filled before as the loop traverses from right to left columns.

*/

#include<iostream>
#include<vector>
using namespace std;

int LongestArithmeticProgression(int*a, int N)
{
    if(N<2)
    {
        cout<< N<<endl;
        return 0;
    }
    vector< vector<int> > lap(N+1,vector<int>(N+1,0) );
    int llap = 2;

    // Special is: Calculate bottom-right to top-left.
    for(int i = 0; i<N; ++i)
    {
        lap[i][N-1] = 2;
    }

    for(int j = N-2; j>=1; --j)
    {
        //j is the middle element of AP of three elements.
        int i = j-1;
        int k = j+1;
        while(i>=0 && k<=N-1)
        {
            int sum = (a[i]+a[k]);

            if( sum == 2*a[j] )
            {
                // Found i and k for j, LLAP with i and j as first two
               // elements is equal to LLAP with j and k as first two
               // elements plus 1. L[j][k] must have been filled
               // before as we run the loop from right side
                lap[i][j] = lap[j][k]+1; //1 for a[i] is added.
                if(llap<lap[i][j])
                {
                    llap = lap[i][j];
                }
                --i;
                ++k;
            }
            else if(sum<2*a[j])
            {
                ++k;
            }
            else
            {
                lap[i][j] = 2;
                --i;
            }
        }
        
        //if No k is found
        while(i>=0)
        {
            lap[i][j] = 2;
            --i;
        }
    }

    cout<<llap<<endl;

    return 0;
}



int main()
{
    int t = 0;
    int a[1001];
    int N = 0;
    
    cin>>t;
    
    while(t--)
    {
        cin>>N;
        int i = 0;
        while(i<N)
        {
            cin>>a[i++];
        }
        LongestArithmeticProgression(a,N);
    }

    return 0;
}