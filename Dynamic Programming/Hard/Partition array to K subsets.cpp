//https://practice.geeksforgeeks.org/problems/partition-array-to-k-subsets/1

/*

Given an integer array A[] of N elements, the task is to complete the function which returns true if the array A[] could be divided into K non-empty subsets such that the sum of elements in every subset is same.

Note: All elements of this array should be part of exactly one partition.

Examples:
Input : A[] = [2, 1, 4, 5, 6], K = 3
Output : 1, as we can divide above array into 3 parts with equal sum as (2, 4), (1, 5), (6)
 

Input : A[] = [2, 1, 5, 5, 6], K = 3 
Output : 0, as it is not possible to divide above array into 3 parts with equal sum


Input:
The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. Each test case contains 3 lines. The first line of each test case contains an integer denoting the size of the array. In the next line are N space separated values of the array A[ ]. In the next line is an integer K.

Output:
The output for each test case will be 1 if the array could be divided into k subsets else 0 .

Constraints:
1<=T<=100
1<=N,K<=100
1<=A[ ] <=100

Example(To be used only for expected output):
Input:
2
5
2 1 4 5 6
3
5
2 1 5 5 6
3
Output:
1
0
*/

/*

Suppose, There are multiple bags with same capacity. For Every bag, we use 0-1 knapsnack algorithm to slove it.



*/

#include <vector>
#include <climits>
using namespace std; 

int  ZeroOnePack(int a[], int N, int C, vector<int>& selectedIndex)
{
    vector< vector<int> > m;
    for(int r = 0; r<=N;  ++r)
    {
        m.push_back( vector<int>() );
        for(int c = 0; c<=C; ++c)
        {
            if(0 == c)
            {
                m[r].push_back(0);
            }
            else
            {
                m[r].push_back(INT_MIN);
            }     
        }
    }




    return 0;
}


bool isKPartitionPossible(int A[], int N, int K)
{
     //Your code here
     int sum    = 0;
     int group  = 0;

     for(int i = 0; i<N; ++i)
     {
         sum += A[i];
     }
     if(sum % K )//Can't be diviable, so it is not partitioned
     {
         return false;
     }
     sum /=  K;
    
    while(group != K)
    {

    }



}