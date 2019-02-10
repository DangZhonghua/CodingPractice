/*
https://www.geeksforgeeks.org/sliding-window-maximum-maximum-of-all-subarrays-of-size-k/
Sliding Window Maximum (Maximum of all subarrays of size k)

Given an array and an integer k, find the maximum for each and every contiguous subarray of size k.

Examples :

Input :
arr[] = {1, 2, 3, 1, 4, 5, 2, 3, 6}
k = 3 
Output :
3 3 4 5 5 5 6

Input :
arr[] = {8, 5, 10, 7, 9, 4, 15, 12, 90, 13}
k = 4 
Output :
10 10 10 15 15 90 90
*/
/*
Method 3 (A O(n) method: use Deque)
We create a Deque, Qi of capacity k, that stores only useful elements of current window of k elements. 
An element is useful if it is in current window and is greater than all other elements on left side 
of it in current window. We process all array elements one by one and maintain Qi to contain useful 
elements of current window and these useful elements are maintained in sorted order. 
The element at front of the Qi is the largest and element at rear of Qi is the smallest of current window. 
Thanks to Aashish for suggesting this method.

Following is the implementation of this method.


#include <iostream> 
#include <deque> 
  
using namespace std; 
  
// A Dequeue (Double ended queue) based method for printing maixmum element of 
// all subarrays of size k 
void printKMax(int arr[], int n, int k) 
{ 
    // Create a Double Ended Queue, Qi that will store indexes of array elements 
    // The queue will store indexes of useful elements in every window and it will 
    // maintain decreasing order of values from front to rear in Qi, i.e.,  
    // arr[Qi.front[]] to arr[Qi.rear()] are sorted in decreasing order 
    std::deque<int>  Qi(k); 
  
    /* Process first k (or first window) elements of array */
    int i; 
    for (i = 0; i < k; ++i) 
    { 
        // For every element, the previous smaller elements are useless so 
        // remove them from Qi 
        while ( (!Qi.empty()) && arr[i] >= arr[Qi.back()]) 
            Qi.pop_back();  // Remove from rear 
  
        // Add new element at rear of queue 
        Qi.push_back(i); 
    } 
  
    // Process rest of the elements, i.e., from arr[k] to arr[n-1] 
    for ( ; i < n; ++i) 
    { 
        // The element at the front of the queue is the largest element of 
        // previous window, so print it 
        cout << arr[Qi.front()] << " "; 
  
        // Remove the elements which are out of this window 
        while ( (!Qi.empty()) && Qi.front() <= i - k) 
            Qi.pop_front();  // Remove from front of queue 
  
        // Remove all elements smaller than the currently 
        // being added element (remove useless elements) 
        while ( (!Qi.empty()) && arr[i] >= arr[Qi.back()]) 
            Qi.pop_back(); 
  
         // Add current element at the rear of Qi 
        Qi.push_back(i); 
    } 
  
    // Print the maximum element of last window 
    cout << arr[Qi.front()]; 
} 
  
// Driver program to test above functions 
int main() 
{ 
    int arr[] = {12, 1, 78, 90, 57, 89, 56}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    int k = 3; 
    printKMax(arr, n, k); 
    return 0; 
} 

Output:

78 90 90 90 89

Time Complexity: O(n). It seems more than O(n) at first look. If we take a closer look, we can observe that every element of array is added and removed at most once. So there are total 2n operations.
Auxiliary Space: O(k)

Below is an extension of this problem.
Sum of minimum and maximum elements of all subarrays of size k.

*/

#include<iostream>
#include<vector>
#include<deque>
using namespace std;

class Solution
{
public:
	vector<int>  LargestOfWindowInArray(vector<int>& arr, int wk)
	{
		vector<int> vw;
		deque<int>  mq(wk); //use to record the window info. It is decreasing order according to the element position.
							//this queue is used to store the array index RATHER THAN the element itself.

		for (int i = 0; i < wk && i < arr.size(); ++i)
		{
			while (!mq.empty())
			{
				if (arr[i] >= arr[mq.back()]) //the current is larger than previous, so remove the previous
				{
					mq.pop_back();
				}
				else
				{
					break;
				}
			}
			mq.push_back(i); //store the index
		}

		for (int i = wk; i < arr.size(); ++i)
		{
			vw.push_back(arr[mq.front()]);
			//update the largest since the window has been changed
			while (!mq.empty() && mq.front() <= (i - wk)) // the removed are that of out of range
			{
				mq.pop_front();
			}
			//the current should be into queue since the window has been started.
			while (!mq.empty() && arr[i] >= arr[mq.back()])
			{
				mq.pop_back();
			}
			mq.push_back(i);
		}
		vw.push_back(arr[mq.front()]);

		for (auto m : vw)
		{
			cout << m << " ";
		}
		cout << endl;

		return vw;
	}
};

int main()
{
	vector<int> arr{ 12, 1, 78, 90, 57, 89, 56 };
	int K = 3;
	Solution sol;

	sol.LargestOfWindowInArray(arr, K);


	return 0;
}