/*
https://www.geeksforgeeks.org/partition-into-two-subarrays-of-lengths-k-and-n-k-such-that-the-difference-of-sums-is-maximum/
Partition into two subarrays of lengths k and (N – k) such that the difference of sums is maximum

Given an array of non-negative integers of length N and an integer k.
 Partition the given array into two subarrays of length K and N – k 
 so that the difference between the sum of both subarray is maximum.

Examples :

Input : arr[] = {8, 4, 5, 2, 10}
        k = 2
Output : 17
Explanation :
Here, we can make first subarray of length k = {4, 2}
and second subarray of length N - k = {8, 5, 10}. Then,
the max_difference = (8 + 5 + 10) - (4 + 2) = 17.

Input : arr[] = {1, 1, 1, 1, 1, 1, 1, 1}
        k = 3
Output : 2
Explanation :
Here, subarrays would be {1, 1, 1, 1, 1} and {1, 1, 1}.
So, max_difference would be 2.

*/

/*

Besides, the method mentioned in the webpage, another method can use order-statisticals.

*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution
{
public:
    int MaximumDifference(vector<int>& a, int K)
    {
        
    };

private:
   int OS_Select(vector<int>& a, int s, int e, int K)
   {
       
   };

}