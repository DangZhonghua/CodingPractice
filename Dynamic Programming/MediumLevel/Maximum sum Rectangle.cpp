/*
https://practice.geeksforgeeks.org/problems/maximum-sum-rectangle/0
https://www.geeksforgeeks.org/dynamic-programming-set-27-max-sum-rectangle-in-a-2d-matrix/

Given a 2D array, find the maximum sum subarray in it. 
For example, in the following 2D array, the maximum sum subarray is highlighted 
with blue rectangle and sum of this subarray is 29.

                                                        
Input:
First line of every test case consists of T test case. 
First line of every test case consists of 2 integers R and C , 
denoting number of rows and columns. 
Second line consists of R*C spaced integers denoting number of elements in array.

Output:
Single line output, print the Max sum forming a rectangle in a 2-D matrix

Example:
Input:
1
4 5
1 2 -1 -4 -20 -8 -3 4 2 1 3 8 10 1 3 -4 -1 1 7 -6
Ouptut:
29

*/

/*

Compress the 2D into 1D problem. Use the 1D algorithm to handle this.

Kadane’s algorithm for 1D array can be used to reduce the time complexity to O(n^3). The idea is to fix the left and right columns one by one and find the maximum sum contiguous rows for every left and right column pair. We basically find top and bottom row numbers (which have maximum sum) for every fixed left and right column pair. To find the top and bottom row numbers, calculate sun of elements in every row from left to right and store these sums in an array say temp[]. So temp[i] indicates sum of elements from left to right in row i. If we apply Kadane’s 1D algorithm on temp[], and get the maximum sum subarray of temp, this maximum sum would be the maximum possible sum with left and right as boundary columns. To get the overall maximum sum, we compare this sum with the maximum sum so far.
 
*/

#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int CalcMaximumSubarray(vector<int>& a, int& maxsum, int& start, int& end)
{
    int max_end_current = a[0];
    int max_so_far = a[0];
    int curs = 0;
    int cure = 0;
    start = end = 0;


    for(int i = 1; i<a.size(); ++i)
    {
        cure = i;
        if(max_end_current>0)
        {
            max_end_current += a[i];
        }
        else
        {
            max_end_current = a[i];
            curs = i;
        }
        if(max_so_far<max_end_current)
        {
            max_so_far = max_end_current;
            start = curs;
            end = cure;
        }        
    }

    maxsum = max_so_far;
    
    return 0;
}

int CalcMaximumRectangle(vector< vector<int> >&m, int R, int C)
{
    int max = INT_MIN;

    for(int leftc = 0; leftc<C; ++leftc)
    {
        vector<int> vsum(R, 0);
        for(int rightc = leftc; rightc<C; ++rightc)
        {
            for(int i = 0; i< R; ++i)
            {
                vsum[i] += m[i][rightc];
            }
            int curmax   = 0;
            int curstart = 0;
            int curend   = 0;
           CalcMaximumSubarray(vsum,curmax,curstart,curend);
           if(curmax>max)
           {
               max = curmax;
           }
        }
    }

    cout<<max<<endl;

    return 0;
}

int main()
{
    int t = 0;
    
    cin>>t;
    
    while(t--)
    {
        int R,C;
        cin>>R>>C;
        vector< vector<int> > m(R, vector<int>(C,0));
        int i = 0;
        int j = 0;
        
        while(i<R)
        {
            j = 0;
            while(j<C)
            {
                int a = 0;
                cin>>a;
                m[i][j++] = a;
            }
            ++i;
        }
        CalcMaximumRectangle(m,R,C);
    }


    return 0;
}