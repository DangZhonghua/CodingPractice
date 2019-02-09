/*
https://leetcode-cn.com/problems/largest-rectangle-in-histogram/
Largest Rectangle in Histogram

Given n non-negative integers representing 
the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.
*/

/*

keep the stack is increasing.
https://www.geeksforgeeks.org/largest-rectangle-under-histogram/

*/


#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Solution {
public:
	int largestRectangleArea(vector<int>& heights)
	{
		stack<int> s;
		int len = heights.size();
		int max_area = 0;
		int cur_area = 0;
		int i = 0;
		while (i < len)
		{
			if (s.empty() || heights[s.top()] <= heights[i]) //  this is the condition of pushing stack
			{												 // which the stack is increasing.
				s.push(i);
				++i;
			}
			else 
			{
				//find the right smaller element, then try to find the left smaller index
				// since this is increasing stack, so every stack top should be used to calculate the area.
				int tp = s.top(); // heights[tp] is used to calculated the area.
				s.pop();
				// after pop, the difference between s.top() and i  *   heights[tp]
				
				cur_area = heights[tp]*(s.empty()?i:i-s.top()-1);
				if( cur_area>max_area)
				{
					max_area = cur_area;
				}
			}
		}

		while (!s.empty()) // the remaining are increasing elements on the stack.
		{
			int tp = s.top();
			s.pop();
			cur_area = heights[tp] * (s.empty() ? i : i - s.top() - 1);
			if (cur_area > max_area)
			{
				max_area = cur_area;
			}
		}

		return max_area;
	}
};


// The main function to find the maximum rectangular  
// area under given histogram with n bars 
int getMaxArea(vector<int> hist, int n)
{
	// Create an empty stack. The stack holds indexes  
	// of hist[] array. The bars stored in stack are  
	// always in increasing order of their heights. 
	stack<int> s;

	int max_area = 0; // Initalize max area 
	int tp;  // To store top of stack 
	int area_with_top; // To store area with top bar 
					   // as the smallest bar 

	// Run through all bars of given histogram 
	int i = 0;
	while (i < n)
	{
		// If this bar is higher than the bar on top  
		// stack, push it to stack 
		if (s.empty() || hist[s.top()] <= hist[i])
			s.push(i++);

		// If this bar is lower than top of stack,  
		// then calculate area of rectangle with stack  
		// top as the smallest (or minimum height) bar.  
		// 'i' is 'right index' for the top and element  
		// before top in stack is 'left index' 
		else
		{
			tp = s.top();  // store the top index 
			s.pop();  // pop the top 

			// Calculate the area with hist[tp] stack  
			// as smallest bar 
			area_with_top = hist[tp] * (s.empty() ? i :
				i - s.top() - 1);

			// update max area, if needed 
			if (max_area < area_with_top)
				max_area = area_with_top;
		}
	}

	// Now pop the remaining bars from stack and calculate 
	// area with every popped bar as the smallest bar 
	while (s.empty() == false)
	{
		tp = s.top();
		s.pop();
		area_with_top = hist[tp] * (s.empty() ? i :
			i - s.top() - 1);

		if (max_area < area_with_top)
			max_area = area_with_top;
	}

	return max_area;
}

int main()
{

	vector<int> h1{ 2,1,0,2 };
	Solution sol;
	vector<int> h2{ 3, 6, 5, 7, 4, 8, 1, 0 };

	cout << sol.largestRectangleArea(h2) << endl;
	//getMaxArea(h2,h2.size());


	return 0;
}