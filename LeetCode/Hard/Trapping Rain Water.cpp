/*
https://leetcode-cn.com/problems/trapping-rain-water/

https://leetcode.com/articles/trapping-rain-water/#
https://www.geeksforgeeks.org/trapping-rain-water/


42. Trapping Rain Water

Given n non-negative integers representing an elevation map where the width of each bar is 1, 
compute how much water it is able to trap after raining.

The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. 
In this case, 6 units of rain water (blue section) are being trapped. 
Thanks Marcos for contributing this image!
Example:
Input: [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
*/

/*

An Efficient Solution is to prre-compute highest bar on left and right of every bar in O(n) time. 
Then use these pre-computed values to find the amount of water in every array element.


Space Optimization in above solution :
Instead of maintaing two arrays of size n for storing left and right max of each element, 
we will just maintain two variables to store the maximum till that point. 
Since water trapped at any element = min( max_left, max_right) – arr[i] 
we will calculate water trapped on smaller element out of A[lo] and A[hi] first and move the pointers till lo doesn’t cross hi.


最后我们来看一种只需要遍历一次即可的解法，
这个算法需要left和right两个指针分别指向数组的首尾位置，从两边向中间扫描，
在当前两指针确定的范围内，先比较两头找出较小值，如果较小值是left指向的值，
则从左向右扫描，如果较小值是right指向的值，则从右向左扫描，若遇到的值比当较小值小，则将差值存入结果，
如遇到的值大，则重新确定新的窗口范围，以此类推直至left和right指针重合，具体参见代码如下：
class Solution {
public:
    int trap(vector<int>& height) 
    {
        int res = 0, l = 0, r = height.size() - 1;
        while (l < r) 
        {
            int mn = min(height[l], height[r]);
            if (mn == height[l]) 
            {
                ++l;
                while (l < r && height[l] < mn) 
                {
                    res += mn - height[l++];
                }
            } else 
            {
                --r;
                while (l < r && height[r] < mn) 
                {
                    res += mn - height[r--];
                }
            }
        }
        return res;
    }
};

// C++ program to find maximum amount of water that can 
// be trapped within given set of bars. 
// Space Complexity : O(1) 

#include<iostream> 
using namespace std; 

int findWater(int arr[], int n) 
{ 
	// initialize output 
	int result = 0; 
	
	// maximum element on left and right 
	int left_max = 0, right_max = 0; 
	
	// indices to traverse the array 
	int lo = 0, hi = n-1; 
	
	while(lo <= hi) 
	{ 
		if(arr[lo] < arr[hi]) 
		{ 
			if(arr[lo] > left_max) 
			// update max in left 
			left_max = arr[lo]; 
			else
			// water on curr element = max - curr 
			result += left_max - arr[lo]; 
			lo++; 
		} 
		else
		{ 
			if(arr[hi] > right_max) 
			// update right maximum 
			right_max = arr[hi]; 
			else
			result += right_max - arr[hi]; 
			hi--; 
		} 
	} 
	
	return result; 
} 

int main() 
{ 
	int arr[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1}; 
	int n = sizeof(arr)/sizeof(arr[0]); 
	cout << "Maximum water that can be accumulated is "
		<< findWater(arr, n); 
} 

// This code is contributed by Aditi Sharma 



*/

/*

下面这种解法是用stack来做的，博主一开始都没有注意到这道题的tag还有stack，所以以后在总结的时候还是要多多留意一下标签啊。
其实用stack的方法博主感觉更容易理解，我们的做法是，遍历高度，
如果此时栈为空，或者当前高度小于等于栈顶高度，则把当前高度的坐标压入栈，注意我们不直接把高度压入栈，
而是把坐标压入栈，这样方便我们在后来算水平距离。当我们遇到比栈顶高度大的时候，就说明有可能会有坑存在，
可以装雨水。此时我们栈里至少有一个高度，如果只有一个的话，那么不能形成坑，我们直接跳过，
如果多余一个的话，那么此时把栈顶元素取出来当作坑，
新的栈顶元素就是左边界，当前高度是右边界，只要取二者较小的，减去坑的高度，
长度就是右边界坐标减去左边界坐标再减1，二者相乘就是盛水量啦，参见代码如下：

class Solution {
public:
    int trap(vector<int>& height) 
    {
        stack<int> st;
        int i = 0, res = 0, n = height.size();
        while (i < n) 
        {
            if (st.empty() || height[i] <= height[st.top()]) 
            {
                st.push(i++);
            } else 
            {
                int t = st.top(); st.pop();
                if (st.empty()) continue;
                res += (min(height[i], height[st.top()]) - height[t]) * (i - st.top() - 1);
            }
        }
        return res;
    }
};

*/

/* 

we consider every element one by one. NOT find the valley by finding the left and right edge

*/

#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

class Solution 
{
public:
    int trap(vector<int>& height) 
    {
        int N = height.size();
        vector<int> left(N,0);
        vector<int> right(N,0);
        if(N<=1)
        {
            return 0;
        }
        // Calculate the left and right edge for every element
        left[0] = height[0];
        
        for(int i = 1; i<N; ++i)
        {
            left[i] = max(left[i-1], height[i]);
        }
        right[N-1] = height[N-1];
        for(int j = N-2; j>=0; --j)
        {
            right[j] = max(right[j+1],height[j]);
        }
        int ans = 0;
        for(int i = 0; i<N; ++i)
        {
            ans += (min(left[i],right[i])-height[i]);
        }
        return ans;
    }
};