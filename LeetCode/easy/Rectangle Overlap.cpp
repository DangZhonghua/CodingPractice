/*
https://leetcode-cn.com/problems/rectangle-overlap/
Rectangle Overlap

A rectangle is represented as a list [x1, y1, x2, y2], where (x1, y1) are
the coordinates of its bottom-left corner, and (x2, y2) are the coordinates of its top-right corner.

Two rectangles overlap if the area of their intersection is positive.
To be clear, two rectangles that only touch at the corner or edges do not overlap.

Given two (axis-aligned) rectangles, return whether they overlap.

Example 1:

Input: rec1 = [0,0,2,2], rec2 = [1,1,3,3]
Output: true

Example 2:

Input: rec1 = [0,0,1,1], rec2 = [1,0,2,1]
Output: false

Notes:

	Both rectangles rec1 and rec2 are lists of 4 integers.
	All coordinates in rectangles will be between -10^9 and 10^9.


*/

/*

b___a
|	|
|___|
c   d

Check the edges whether cross the rectangle.
*/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2)
	{
		bool bOverlapped = false;

		//let us "move" rec2
		// bottom left top right
		// 0       1    2   3

		do
		{
			if( )

		} while (0);

		return bOverlapped;
	}
};


int main()
{
	vector<int> rec1{ 7,8,13,15 };
	vector<int> rec2{ 10,8,12,20 };
	Solution sol;

	cout << sol.isRectangleOverlap(rec1, rec2) << endl;

	return 0;
}