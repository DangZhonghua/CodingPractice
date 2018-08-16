/*
Smallest sum contiguous subarray
https://www.geeksforgeeks.org/smallest-sum-contiguous-subarray/

Given an array containing n integers. The problem is to find the sum of the elements 
of the contiguous subarray having the smallest(minimum) sum.

Examples:

Input : arr[] = {3, -4, 2, -3, -1, 7, -5}
Output : -6
Subarray is {-4, 2, -3, -1} = -6

Input : arr = {2, 6, 8, 1, 4}
Output : 1

*/

/*

Kadane's Algorithm

*/

#include<iostream>
#include<vector>
using namespace std;

int SmallestSumSubarray(vector<int>& va)
{
    int min_so_far      = va[0];
    int min_end_current = va[0];

    for(int i = 1; i<va.size(); ++i)
    {
        if(min_end_current<0)
        {
            min_end_current += va[i];
        }
        else
        {
            min_end_current = va[i];
        }

        if(min_so_far>min_end_current)
        {
            min_so_far = min_end_current;
        }
    }

    cout<<min_so_far<<endl;

    return 0;
}


int main(int argc, char const *argv[])
{
    vector<int> va{3, -4, 2, -3, -1, 7, -5};
    vector<int> vb{2, 6, 8, 1, 4};
    SmallestSumSubarray(va);
    SmallestSumSubarray(vb);
    
    return 0;
}

