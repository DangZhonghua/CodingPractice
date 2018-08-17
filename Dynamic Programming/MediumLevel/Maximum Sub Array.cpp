/*
https://practice.geeksforgeeks.org/problems/maximum-sub-array/0
Maximum Sub Array 

Find out the maximum sub-array of non negative numbers from an array.
The sub-array should be continuous. That is, a sub-array created 
by choosing the second and fourth element and skipping the third element is invalid.

Maximum sub-array is defined in terms of the sum of the elements in the sub-array. 
Sub-array A is greater than sub-array B if sum(A) > sum(B).

Example:

A : [1, 2, 5, -7, 2, 3]
The two sub-arrays are [1, 2, 5] [2, 3].
The answer is [1, 2, 5] as its sum is larger than [2, 3]

NOTE 1: If there is a tie, then compare with segment's length and return segment which has maximum length
NOTE 2: If there is still a tie, then return the segment with minimum starting index

 

Input:

The first line contains an integer T, depicting total number of test cases. 
Then following T lines contains an integer N depicting the size of array and next line followed by the value of array.



Output:

Print the Sub-array with maximum sum.


Constraints:


1 ≤ T ≤ 40
1 ≤ N ≤ 100
-100 ≤ A[i] ≤ 100


Example:
Input
2
3
1 2 3
2
-1  2
Output
1 2 3
2
*/

/*

if(a[i]>0) then
    case 1:  sum < 0  sum=a[i]
    case 2:  sum>=0   sum += a[i];
else
 sum = a[i];

*/


#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int maximumSubArray(vector<int>&a)
{
	int max   = a[0];
	int start = a.size();
	int end   = a.size();


	int sum = 0;
	int s   = 0;
	int e   = 0;
	sum = a[0];

	for (int i = 1; i<a.size(); ++i)
	{
		if (a[i] >= 0)
		{
			if (sum < 0)
			{
				sum = a[i];
				s = i;
			}
			else
			{
				sum += a[i];
			}
			
			e = i;
		}
		else
		{
			if (sum > max)
			{
				max = sum;
				start = s;
				end = e;
			}
			else if (sum == max)
			{
				if (end - start == e - s)
				{
					if (s<start)
					{
						start = s;
						end = e;
					}
				}
				else if (end - start < e - s)
				{
					start = s;
					end = e;
				}
			}
			sum = a[i];
			s = i; //from next element
			e = s;
		}
	}

	if (sum > max)
	{
		max = sum;
		start = s;
		end = e;
	}
	else if (sum == max)
	{
		if (end - start == e - s)
		{
			if (s<start)
			{
				start = s;
				end = e;
			}
		}
		else if (end - start < e - s)
		{
			start = s;
			end = e;
		}
	}

	for (int i = start; i <= end; ++i)
	{
		cout << a[i] << " ";
	}
	cout << endl;




	return 0;
}



int main(int argc, char const *argv[])
{
	int  t = 0;
	int N = 0;

	cin >> t;

	while (t--)
	{
		cin >> N;
		vector<int> a(N, 0);

		int i = 0;
		while (i<N)
		{
			int d = 0;
			cin >> d;
			a[i++] = d;
		}
		maximumSubArray(a);
	}

	return 0;
}
