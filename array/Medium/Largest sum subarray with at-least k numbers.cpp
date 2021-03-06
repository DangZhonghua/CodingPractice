/*
https://www.geeksforgeeks.org/largest-sum-subarray-least-k-numbers/
https://practice.geeksforgeeks.org/problems/largest-sum-subarray-of-size-at-least-k/0

https://practice.geeksforgeeks.org/problems/maximum-rectangular-area-in-a-histogram/0
Largest sum subarray with at-least k numbers

Given an array, find the subarray (containing at least k numbers) which has the largest sum.

Examples:

Input : arr[] = {-4, -2, 1, -3} 
            k = 2
Output : -1
The sub array is {-2, 1}

Input : arr[] = {1, 1, 1, 1, 1, 1} 
            k = 2
Output : 6 
The sub array is {1, 1, 1, 1, 1, 1}

*/

/*
This problem is an extension of Largest Sum Subarray Problem.

1) We first compute maximum sum till every index and store it in an array maxSum[].
2) After filling the array, we use the sliding window concept of size k. Keep track of sum of current k elements. 
To compute sum of current window, remove first element of previous window and add current element. After getting the sum of current window, we add the maxSum of the previous window, if it is greater than current max, then update it else not.
*/


// C++ program to find largest subarray sum with 
// at-least k elements in it. 
#include<bits/stdc++.h> 
using namespace std; 
  
// Returns maximum sum of a subarray with at-least 
// k elements. 
int maxSumWithK(int a[], int n, int k) 
{ 
    // maxSum[i] is going to store maximum sum 
    // till index i such that a[i] is part of the 
    // sum. 
    int maxSum[n]; 
    maxSum[0] = a[0]; 
  
    // We use Kadane's algorithm to fill maxSum[] 
    // Below code is taken from method 3 of 
    // https://www.geeksforgeeks.org/largest-sum-contiguous-subarray/ 
    int curr_max = a[0]; 
    for (int i = 1; i < n; i++) 
    { 
        curr_max = max(a[i], curr_max+a[i]); 
        maxSum[i] = curr_max; 
    } 
  
    // Sum of first k elements 
    int sum = 0; 
    for (int i = 0; i < k; i++) 
        sum += a[i]; 
  
    // Use the concept of sliding window 
    int result = sum; 
    for (int i = k; i < n; i++) 
    { 
        // Compute sum of k elements ending 
        // with a[i]. 
        sum = sum + a[i] - a[i-k]; 
  
        // Update result if required 
        result = max(result, sum); 
  
        // Include maximum sum till [i-k] also 
        // if it increases overall max. 
        result = max(result, sum + maxSum[i-k]); 
    } 
    return result; 
} 
  
// Driver code 
int main() 
{ 
    int a[] = {1, 2, 3, -10, -3}; 
    int k = 4; 
    int n = sizeof(a)/sizeof(a[0]); 
    cout << maxSumWithK(a, n, k); 
    return 0; 
} 



