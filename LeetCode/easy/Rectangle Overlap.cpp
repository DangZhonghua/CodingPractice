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
            if(rec2[0]<rec1[2] && rec2[1]<rec1[3])
            {
                bOverlapped = true;
                break;
            }

            if(rec2[0]<rec1[2] && rec2[3]>rec1[1])
            {
                bOverlapped = true;
                break;
            }

            if(rec2[2]>rec1[0] && rec2[3]>rec1[1])
            {
                bOverlapped = true;
                break;
            }

            if( rec1[0]<rec2[2] && rec1[3] > rec2[1] )
            {
                bOverlapped = true;
                break;
            }

            if(rec1[0]<=rec2[0] && rec1[1]<=rec2[1] && rec1[2]>=rec2[2] && rec1[3]>=rec2[3])
            {
                bOverlapped = true;
                break;
            }
            if(rec1[0]>=rec2[0] && rec1[1]>=rec2[1] && rec1[2]<=rec2[2] && rec1[3]<=rec2[3])
            {
                bOverlapped = true;
                break;
            }
        }while(0);
        
        return bOverlapped;
    }
};


int main()
{
    vector<int> rec1{0,0,1,1};
    vector<int> rec2{1,0,2,1};
    Solution sol;

    sol.isRectangleOverlap(rec1,rec2);

    return 0;
}