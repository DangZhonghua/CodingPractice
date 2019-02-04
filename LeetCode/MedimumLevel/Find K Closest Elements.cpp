/*
https://leetcode-cn.com/problems/find-k-closest-elements/
Find K Closest Elements

 Given a sorted array, two integers k and x, find the k closest elements to x in the array. 
 The result should also be sorted in ascending order. If there is a tie, the smaller elements are always preferred.

Example 1:

Input: [1,2,3,4,5], k=4, x=3
Output: [1,2,3,4]

Example 2:

Input: [1,2,3,4,5], k=4, x=-1
Output: [1,2,3,4]

Note:

    The value k is positive and will always be smaller than the length of the sorted array.
    Length of the given array is positive and will not exceed 10^4
    Absolute value of elements in the array and x will not exceed 10^4

UPDATE (2017/9/19):
The arr parameter had been changed to an array of integers (instead of a list of integers). 
Please reload the code definition to get the latest changes. 

*/

#include<iostream>
#include<vector>
#include<climits>
using namespace std;

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) 
    {
        int i = 0;
        int j = arr.size()-1;
        int index = -1;
        vector<int> vr;
        while(i<=j)
        {
            int m = (i+j)/2;
            if( arr[m] == x)
            {
                index = m;
                break;
            }
            else if(arr[m]<x)
            {
                i = m+1;
            }
            else
            {
                j = m-1;
            }
        }

        if(-1 == index)
        {
            index = i;
        }

        i = index-1;
        j = index;
        int count = 0;
        
        while( count<k )
        {
            int d1 = INT_MAX;
            int d2 = INT_MAX;
            if(i>=0)
            {
                d1 = x-arr[i];
            }
            if(j<arr.size())
            {
                d2 = arr[j]-x;
            }
            if(d1<=d2)
            {
                --i;
            }
            else
            {
                ++j;
            }
            ++count;
        }
        
        int start = i+1;
        int end = j-1;
        while(start<=end)
        {
            vr.push_back(arr[start]);
            ++start;
        }
        return vr;
    }
};