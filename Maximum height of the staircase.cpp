//https://practice.geeksforgeeks.org/problems/maximum-height-of-the-staircase/0/?ref=self

// You have given an N number of squire blocks. Height of each squire Block is 1. your task is to create a  max height of the staircase that can be made from these blocks.

// Note: The first stair would require one block, the second stair (height 2) would require two blocks and so on.

// Input:

// The first line of the input contains T i.e number of test cases. Each line of the test case contains a number  N i.e number of blocks. 

// Output:

// Each new line of the output contains only one single integer i.e Maximum height of staircase.

// Constraints:

// 1<=T<=100

// 1<=N<=10^8

// Example:

// Input:

// 3
// 10
// 12
// 16

// Output:

// 4
// 4
// 5

// Explanation:

// Test Case 1: the max height of the staircase that can be made from  12  blocks is 4  . (A staircase of height 4 means sequence of 1,2,3,4 blocks to create a valid staircase.


#include<iostream>
using namespace std;


int maxStairsHeight(int N);

int main()
 {
    int t = 0;
    int N = 0;
    
    cin>>t;
    
    while(t>0)
    {
        --t;
        cin>>N;
        
        maxStairsHeight(N);
    }


	return 0;
}

int maxStairsHeight(int N)
{
    int nBlockCount = 0;
    int nIncr       = 1;
    int h           = 0;
    
    while(nBlockCount+nIncr<=N)
    {
        ++h;
        nBlockCount += nIncr;
        ++nIncr;
    }
    cout<<h<<endl;
    
    return 0;
}