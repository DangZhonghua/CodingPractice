/*
https://leetcode-cn.com/problems/maximum-product-subarray/
https://www.geeksforgeeks.org/maximum-product-subarray/
https://www.geeksforgeeks.org/maximum-product-subarray-added-negative-product-case/
Maximum Product Subarray

Given an array that contains both positive and negative integers, find the product of the maximum product subarray. 
Expected Time complexity is O(n) and only O(1) extra space can be used.
Examples:
Input: arr[] = {6, -3, -10, 0, 2}
Output:   180  // The subarray is {6, -3, -10}

Input: arr[] = {-1, -3, -10, 0, 60}
Output:   60  // The subarray is {60}

Input: arr[] = {-2, -3, 0, -2, -40}
Output:   80  // The subarray is {-2, -40}

The following solution assumes that the given input array always has a positive output. 
The solution works for all cases mentioned above. It doesn’t work for arrays like {0, 0, -20, 0}, {0, 0, 0}.. etc. 
The solution can be easily modified to handle this case.
It is similar to Largest Sum Contiguous Subarray problem. 
The only thing to note here is, maximum product can also be obtained by minimum (negative) product ending with 
the previous element multiplied by this element. For example, in array {12, 2, -3, -5, -6, -2}, 
when we are at element -2, the maximum product is multiplication of, minimum product ending with -6 and -2.

*/

class Solution {
public:
    int maxProduct(vector<int>& nums) 
    {
        
    }
};


/* Returns the product of max product subarray.  
   Assumes that the given array always has a subarray 
   with product more than 1 */
int maxSubarrayProduct(int arr[], int n) 
{ 
    // max positive product ending at the current position 
    int max_ending_here = 1; 
  
    // min negative product ending at the current position 
    int min_ending_here = 1; 
  
    // Initialize overall max product 
    int max_so_far = 1; 
  
    /* Traverse through the array. Following values are 
       maintained after the i'th iteration: 
       max_ending_here is always 1 or some positive product 
                       ending with arr[i] 
       min_ending_here is always 1 or some negative product  
                       ending with arr[i] */
    for (int i = 0; i < n; i++) 
    { 
        /* If this element is positive, update max_ending_here.  
           Update min_ending_here only if min_ending_here is  
           negative */
        if (arr[i] > 0) 
        { 
            max_ending_here = max_ending_here*arr[i]; 
            min_ending_here = min (min_ending_here * arr[i], 1); 
        } 
  
        /* If this element is 0, then the maximum product  
           cannot end here, make both max_ending_here and  
           min_ending_here 0 
           Assumption: Output is alway greater than or equal  
                       to 1. */
        else if (arr[i] == 0) 
        { 
            max_ending_here = 1; 
            min_ending_here = 1; 
        } 
  
        /* If element is negative. This is tricky 
           max_ending_here can either be 1 or positive.  
           min_ending_here can either be 1 or negative. 
           next min_ending_here will always be prev.  
           max_ending_here * arr[i] next max_ending_here 
           will be 1 if prev min_ending_here is 1, otherwise  
           next max_ending_here will be prev min_ending_here * 
           arr[i] */
        else
        { 
            int temp = max_ending_here; 
            max_ending_here = max (min_ending_here * arr[i], 1); 
            min_ending_here = temp * arr[i]; 
        } 
  
        // update max_so_far, if needed 
        if (max_so_far <  max_ending_here) 
          max_so_far  =  max_ending_here; 
    } 
  
    return max_so_far; 
} 
  
// Driver Program to test above function 
int main() 
{ 
    int arr[] = {1, -2, -3, 0, 7, -8, -2}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    printf("Maximum Sub array product is %d",  
            maxSubarrayProduct(arr, n)); 
    return 0; 
} 


We have discussed this problem in Maximum Product Subarray, but there is a restriction that result can only be positive. 
For the maximum product to be negative or zero, the values of variable maxval (maximum product up to current element) 
and minval (minimum product up to current element), has to be updated as follows:
When arr[i] is positive : As maxval is maximum possible value, simply multiply 
arr[i] with maxval to obtain new maxval. minval is minimum possible negative product. 
If its previous value is negative then simply multiply it with arr[i]. If its value is 1 keep it as 1.
When arr[i] is 0 : Consider the test case : arr[] = {0, -4, 0, -2}. 
The maximum product is 0 in this case. To account for this case in our algo, 
update maxval with 0 instead of 1 whenever arr[i] is zero. The product of any number with zero is zero. 
Consider another test case, arr[] = {0, 1 ,2}.
If maxval remains zero after current iteration (according to the step described above) and 
the next element is positive then the result will be zero and not the positive element. 
To consider that at the end of each iteration check if maxval is zero or not.
If it is zero set it equal to 1. Update minval with 1 as subarray product 
with zero as element in it will be zero, which results in loss of minimum possible value. 
So exclude this zero from subarray by setting minval to 1, i.e., restarting product calculation.
When arr[i] is negative : new value of maxval is previous minval*arr[i] 
and new value of minval is previous maxval*arr[i]. Before updating maxval, 
store its previous value in prevMax to be used to update minval.
Implementation: 

// C++ program to find maximum subarray product. 
#include <bits/stdc++.h> 
  
using namespace std; 
  
// Function to find maximum subarray product. 
int findMaxProduct(int arr[], int n) 
{ 
    int i; 
  
    // As maximum product can be negative, so 
    // initialize ans with minimum integer value. 
    int ans = INT_MIN; 
  
    // Variable to store maximum product until 
    // current value. 
    int maxval = 1; 
  
    // Variable to store minimum product until 
    // current value. 
    int minval = 1; 
  
    // Variable used during updation of maximum 
    // product and minimum product. 
    int prevMax; 
  
    for (i = 0; i < n; i++) { 
  
        // If current element is positive, update 
        // maxval. Update minval if it is 
        // negative. 
        if (arr[i] > 0) { 
            maxval = maxval * arr[i]; 
            minval = min(1, minval * arr[i]); 
        } 
  
        // If current element is zero, maximum 
        // product cannot end at current element. 
        // Update minval with 1 and maxval with 0. 
        // maxval is updated to 0 as in case all 
        // other elements are negative, then maxval 
        // is 0. 
        else if (arr[i] == 0) { 
            minval = 1; 
            maxval = 0; 
        } 
  
        // If current element is negative, then new 
        // value of maxval is previous minval*arr[i] 
        // and new value of minval is previous 
        // maxval*arr[i]. Before updating maxval, 
        // store its previous value in prevMax to 
        // be used to update minval. 
        else if (arr[i] < 0) { 
            prevMax = maxval; 
            maxval = minval * arr[i]; 
            minval = prevMax * arr[i]; 
        } 
  
        // Update ans if necessary. 
        ans = max(ans, maxval); 
  
        // If maxval is zero, then to calculate 
        // product for next iteration, it should 
        // be set to 1 as maximum product 
        // subarray does not include 0. 
        // The minimum possible value 
        // to be considered in maximum product 
        // subarray is already stored in minval, 
        // so when maxval is negative it is set to 1. 
        if (maxval <= 0) { 
            maxval = 1; 
        } 
    } 
  
    return ans; 
} 
  
int main() 
{ 
    int arr[] = { 0, -4, 0, -2 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    cout << findMaxProduct(arr, n); 
    return 0; 
} 