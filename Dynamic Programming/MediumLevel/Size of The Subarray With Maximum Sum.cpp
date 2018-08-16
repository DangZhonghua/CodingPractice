/*
https://www.geeksforgeeks.org/size-subarray-maximum-sum/


Size of The Subarray With Maximum Sum

An array is given, find length of the subarray having maximum sum.

Examples :

Input :  a[] = {1, -2, 1, 1, -2, 1}
Output : Length of the subarray is 2
Explanation: Subarray with consecutive elements
and maximum sum will be {1, 1}. So length is 2

Input : ar[] = { -2, -3, 4, -1, -2, 1, 5, -3 }
Output : Length of the subarray is 5
Explanation: Subarray with consecutive elements
and maximum sum will be {4, -1, -2, 1, 5}.

*/

/*
Kadane's Algorithm
*/

#include<iostream>
#include<vector>
using namespace std;

int CalcLengthofSubarrayofMaximumSum(vector<int>& va)
{
	int start = 0;
	int end = 0;
	int max_end_current = va[0];
	int max_so_far = va[0];
	int curs = 0;
	int cure = 0;

	for (int i = 1; i< va.size(); ++i)
	{
		cure = i;
		if (max_end_current>0)
		{
			max_end_current += va[i];
		}
		else
		{
			max_end_current = va[i];
			curs = i;
		}

		if (max_end_current>max_so_far)
		{
			start = curs;
			end = cure;
			max_so_far = max_end_current;
		}
	}
	cout << "[ " << start << ":" << end <<"]"<<endl;
	for (int i = start; i <= end; ++i)
	{
		cout << va[i] << " ";
	}
	cout << endl;

	return 0;
}

int main(int argc, char const *argv[])
{
	// int t = 0;
	// int N = 0;

	// cin>>t;

	// while(t--)
	// {
	//     cin>>N;
	//     vector<int> va;
	//     int i = 0;
	//     while(i<N)
	//     {
	//         int a = 0;
	//         cin>>a;
	//         va[i++] = a;
	//     }
	//     CalcLengthofSubarrayofMaximumSum(va);
	// }
	vector<int> va{ -2, -3, 4, -1, -2, 1, 5, -3 };
	CalcLengthofSubarrayofMaximumSum(va);
	return 0;
}
