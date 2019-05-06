/*
https://leetcode-cn.com/problems/median-of-two-sorted-arrays/
https://leetcode.com/problems/median-of-two-sorted-arrays/discuss/2471/very-concise-ologminmn-iterative-solution-with-detailed-explanation
https://www.youtube.com/watch?v=LPFhl65R7ww

Median of Two Sorted Arrays

There are two sorted arrays nums1 and nums2 of size m and n respectively.
Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
You may assume nums1 and nums2 cannot be both empty.
Example 1:
nums1 = [1, 3]
nums2 = [2]

The median is 2.0
Example 2:
nums1 = [1, 2]
nums2 = [3, 4]

The median is (2 + 3)/2 = 2.5

*/

/*

the basic idea: binary segment the median K = (ArrLen1+ArrLen2)/2. Not the array itself.


*/

#include<vector>
#include<algorithm>
using namespace std;

class Solution 
{
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
    {
        int m       = nums1.size();
        int n       = nums2.size();
        int left    = (m+n+1)/2;
        int right   = (m+n+2)/2;

        return(findKthElement(nums1,0,nums2,0,left) + findKthElement(nums1,0,nums2,0,right))/2.0;
    }
private:
    int findKthElement(vector<int>& nums1, int start1, vector<int>& nums2, int start2, int K )
    {
        if(start1>=nums1.size()) return nums2[start2 + K - 1];
        if(start2>=nums2.size()) return nums1[start1 + K - 1];
        if(1 == K) return min(nums1[start1], nums2[start2]);
        
        int minv1 = (start1+K/2 - 1) < nums1.size()? nums1[start1+K/2 - 1]:INT_MAX;
        int minv2 = (start2+K/2 - 1) < nums2.size()? nums2[start2+K/2 - 1]:INT_MAX;
        if(minv1<minv2)
        {
           return findKthElement(nums1,start1+K/2,nums2,start2,K-K/2);
        }
        else
        {
            return findKthElement(nums1,start1,nums2,start2+K/2,K-K/2);
        }
    }
};