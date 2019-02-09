/*
https://leetcode-cn.com/problems/maximal-rectangle/
Maximal Rectangle
Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

Example:

Input:
[
  ["1","0","1","0","0"],
  ["1","0","1","1","1"],
  ["1","1","1","1","1"],
  ["1","0","0","1","0"]
]
Output: 6

*/

#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Solution 
{
public:
    int maximalRectangle(vector<vector<char>>& matrix) 
    {
      if(matrix.empty() || matrix[0].empty())
      {
        return 0;
      }
      int R = matrix.size();
      int C = matrix[0].size();
      vector< vector<int> > m(R,vector<int>(C,0));
      for(int r = 0; r<R; ++r)
      {
        for(int c = 0; c<C; ++c)
        {
          if(matrix[r][c] == '1')
          {
            m[r][c] = 1;
          }
        }
      }
      
      int maxRect = largestRectangleArea(m[0]);
      
      for(int r = 1; r<R; ++r)
      {
        for(int c = 0; c<C; ++c)
        {
          if(m[r][c])
          {
            m[r][c] += m[r-1][c];
          }
        }
        int curRect = largestRectangleArea(m[r]);
        if(maxRect<curRect)
        {
          maxRect = curRect;
        }
      }
      return maxRect;
    }

private:
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