/*
https://www.geeksforgeeks.org/maximum-profit-after-buying-and-selling-the-stocks-any-number-of-times/
Maximum profit after buying and selling the stocks
https://www.geeksforgeeks.org/maximum-profit-after-buying-and-selling-the-stocks-any-number-of-times/
Given an array of positive integers containing the price of stocks and transaction fee, 
the task is to find the maximum profit and the difference of days on which you are getting the maximum profit.
Examples:
Input: arr[] = {6, 1, 7, 2, 8, 4}
      transactionFee = 2
Output: 8 1

Input: arr[] = {7, 1, 5, 3, 6, 4}
       transactionFee = 1
Output: 5 1

*/
#include<iostream>
#include<vector>
using namespace std;

class Solution
{
  public:
  int MaximumProfit(vector<int>& nums, int TC)
  {
      vector<int> vMax(nums.size(),0);
      vMax[nums.size()-1] = nums.size()-1;
      for(int i = nums.size()-2; i>=0; --i)
      {
          if(nums[i]>nums[vMax[i+1]])
          {
              vMax[i] = i;
          }
          else
          {
              vMax[i] = vMax[i+1];
          }
      }
      int maxp = 0;
      int p = 0;
      for(int i = 0; i<vMax.size(); ++i)
      {
          if( (nums[vMax[i]]-nums[i])>maxp)
          {
              maxp = (nums[vMax[i]]-nums[i]);
              p = i;
          }
      }
      cout<<vMax[p]<<" "<<p<<endl;

      return 0;
  }
};

int main()
{
    vector<int> nums1{6, 1, 7, 2, 8, 4};
    vector<int> nums2{7, 1, 5, 3, 6, 4};

    Solution sol;

    sol.MaximumProfit(nums1,0);
    sol.MaximumProfit(nums2,0);

    return 0;
}