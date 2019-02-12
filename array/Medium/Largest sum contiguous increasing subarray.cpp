/*
https://www.geeksforgeeks.org/largest-sum-contiguous-increasing-subarray/
Largest sum contiguous increasing subarray

Given an array of n positive distinct integers. The problem is to find the largest sum of 
contiguous increasing subarray in O(n) time complexity.
Examples :
Input : arr[] = {2, 1, 4, 7, 3, 6}
Output : 12
Contiguous Increasing subarray {1, 4, 7} = 12

Input : arr[] = {38, 7, 8, 10, 12}
Output : 38

*/

/*
Sliding Window technique
*/
#include<iostream>
#include<vector>
using namespace std;

class Solution
{
public:
    int LargestSumOfIncreasingSubarray(vector<int>& nums)
    {
        int sum = nums[0];
        int maxsum = 0;

        for( int i = 1; i<nums.size(); ++i)
        {
            if(nums[i-1]<nums[i])
            {
                sum += nums[i];
            }
            else
            {
                if(maxsum<sum)
                {
                    maxsum = sum;
                }
                sum = nums[i];
            }
        }
        return maxsum;
    }
};

int main()
{
    Solution sol;
    vector<int> nums1{2, 1, 4, 7, 3, 6};
    cout<<sol.LargestSumOfIncreasingSubarray(nums1)<<endl;
    
    vector<int> nums2{38, 7, 8, 10, 12};
    
    cout<<sol.LargestSumOfIncreasingSubarray(nums2)<<endl;

    return 0;

}