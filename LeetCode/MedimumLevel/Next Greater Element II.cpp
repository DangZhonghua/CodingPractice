/*
https://leetcode-cn.com/problems/next-greater-element-ii/
Next Greater Element II

Given a circular array (the next element of the last element is the first element of the array), 
print the Next Greater Number for every element. 
The Next Greater Number of a number x is the first greater number to 
its traversing-order next in the array, 
which means you could search circularly to find its next greater number. 
If it doesn't exist, output -1 for this number. 
Example 1:
Input: [1,2,1]
Output: [2,-1,2]
Explanation: The first 1's next greater number is 2; 
The number 2 can't find next greater number; 
The second 1's next greater number needs to search circularly, which is also 2.

Note: The length of given array won't exceed 10000. 

*/


#include<vector>
#include<stack>
using namespace std;

/*

数组是一个循环数组，就是说某一个元素的下一个较大值可以在其前面，那么对于循环数组的遍历，
为了使下标不超过数组的长度，我们需要对n取余，下面先来看暴力破解的方法，遍历每一个数字，
然后对于每一个遍历到的数字，遍历所有其他数字，注意不是遍历到数组末尾，
而是通过循环数组遍历其前一个数字，遇到较大值则存入结果res中，并break，再进行下一个数字的遍历

*/


class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int> res(n, -1);
        for (int i = 0; i < n; ++i) 
        {
            for (int j = i + 1; j < i + n; ++j) 
            {
                if (nums[j % n] > nums[i]) 
                {
                    res[i] = nums[j % n];
                    break;
                }
            }
        }
        return res;
    }
};

/*

我们可以使用栈来进行优化上面的算法，我们遍历两倍的数组，然后还是坐标i对n取余，取出数字，
如果此时栈不为空，且栈顶元素小于当前数字，说明当前数字就是栈顶元素的右边第一个较大数，
那么建立二者的映射，并且去除当前栈顶元素，
最后如果i小于n，则把i压入栈。因为res的长度必须是n，
超过n的部分我们只是为了给之前栈中的数字找较大值，所以不能压入栈

*/

class Solution 
{
public:
    vector<int> nextGreaterElements(vector<int>& nums) 
    {
        int N = nums.size();
        vector<int> res(N, -1);
        stack<int> ls;
        for(int i = 0; i<2*N; ++i)
        {
            int j = i%N;
            while(!ls.empty() && nums[ls.top()] < nums[j])
            {
                //for the left to right side, it is the "nearest" larger element.
                //End for circular, it is the "farest" larger element since the left-most is on the stack top
                res[ls.top()] = nums[j];
                ls.pop();
            }
            if(i<N)
            {
                ls.push(i);
            }
        }
        
        return res; 
    }
};