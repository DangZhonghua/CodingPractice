/*
https://www.cnblogs.com/grandyang/p/5235086.html
3Sum Smaller

Given an array of n integers nums and a target, find the number of index triplets i, j, k 
with 0 <= i < j < k < n that satisfy the condition nums[i] + nums[j] + nums[k] < target.
For example, given nums = [-2, 0, 1, 3], and target = 2.
Return 2. Because there are two triplets which sums are less than 2:
[-2, 0, 1]
[-2, 0, 3]

Follow up:
Could you solve it in O(n2) runtime?

*/

#include<algorithm>
#include<vector>
using namespace std;


class Solution 
{
public:
    int threeSumSmaller(vector<int>& nums, int target) 
    {
        int count = 0;
        int N = nums.size();
        std::sort(nums.begin(), nums.end());

        for(int i = 0; i<N-2; ++i)
        {
            int left  = i+1;
            int right = N-1;
            
            while(left < right)
            {
                int sum = nums[i] + nums[left] + nums[right];
                
                if(sum < target)
                {
                    count += (right-left); // all element left side of the "right" are satisfied.
                    ++left;
                }
                else
                {
                    --right;
                }
            }
        }
        return count;
    }
};
int main()
{
    Solution sol;
    int target = 2;
    vector<int> n1{-2, 0, 1, 3};

    sol.threeSumSmaller(n1,target);

    return 0;
}