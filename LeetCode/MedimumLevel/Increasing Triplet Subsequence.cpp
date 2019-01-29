/*
https://leetcode-cn.com/problems/increasing-triplet-subsequence/
Increasing Triplet Subsequence
Given an unsorted array return whether an increasing subsequence of length 3 exists or not in the array.
Formally the function should:

Return true if there exists i, j, k 
such that arr[i] < arr[j] < arr[k] given 0 ≤ i < j < k ≤ n-1 else return false.
Note: Your algorithm should run in O(n) time complexity and O(1) space complexity.
Example 1:
Input: [1,2,3,4,5]
Output: true
Example 2:
Input: [5,4,3,2,1]
Output: false

*/

/*
i  j   k

if(a[i]<a[k]) then find j

if(a[i]>a[k]) //step i

if( a[j]>a[i] && a[j]>a[k]) //step k


let i = 0; j = 1; k=n-1 at first

try to form inequation when traverse the array.

[2,5,3,4,5]

*/


#include<vector>
using namespace std;

class Solution {
public:
    bool increasingTriplet(vector<int>& a) 
    {
        int i = 0;
        int j = 1;
        int k = a.size()-1;
        bool bFind = false;

        while( i<j && j<k)
        {
            if(a[i]<a[j] && a[j]<a[k])
            {
                bFind = true;
                break;
            }
            else if( a[i]<a[j])
            {
                --k;
            }
            else if(a[j]<a[k])
            {
                i = j;
                ++j;
            }
            else if (a[j] > a[k])
            {
                i = j+1;
                j = j+2;
            }
            else
            {
                --k;
            }
        }   
        return bFind; 
    }
};