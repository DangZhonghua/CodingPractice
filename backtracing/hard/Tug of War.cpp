/*
Tug of War
https://www.geeksforgeeks.org/tug-of-war/

Given a set of n integers, divide the set in two subsets of n/2 sizes each such that the difference of the sum of two subsets 
is as minimum as possible. If n is even, then sizes of two subsets must be strictly n/2 and if n is odd, 
then size of one subset must be (n-1)/2 and size of other subset must be (n+1)/2.

For example, let given set be {3, 4, 5, -3, 100, 1, 89, 54, 23, 20}, the size of set is 10.
Output for this set should be {4, 100, 1, 23, 20} and {3, 5, -3, 89, 54}. 
Both output subsets are of size 5 and sum of elements in both subsets is same (148 and 148).

Let us consider another example where n is odd. Let given set be {23, 45, -34, 12, 0, 98, -99, 4, 189, -1, 4}. 
The output subsets should be {45, -34, 12, 98, -1} and {23, 0, -99, 4, 189, 4}. 
The sums of elements in two subsets are 120 and 121 respectively.

The following solution tries every possible subset of half size. 
If one subset of half size is formed, the remaining elements form the other subset. 
We initialize current set as empty and one by one build it. 
There are two possibilities for every element, either it is part of current set, 
or it is part of the remaining elements (other subset). We consider both possibilities for every element. 
When the size of current set becomes n/2, 
we check whether this solutions is better than the best solution available so far. If it is, then we update the best solution.

Following is the implementation for Tug of War problem. It prints the required arrays.


*/


#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int g_sum = 0;

bool JudgeMinimum(int cursum, int& mindsum)
{
	if (INT_MAX == mindsum)
	{
		mindsum = g_sum>cursum ? (g_sum - cursum) : (cursum-g_sum);
		return true;
	}
	else
	{
		int leftCursum = g_sum - cursum;
		int leftCurd = leftCursum > cursum ? (leftCursum - cursum) : (cursum - leftCursum);
	
		if (leftCurd < mindsum)
		{
			mindsum = leftCurd;
			return true;
		}
	}

	return false;
}

int btTugOfWar(vector<int>& a, vector<int>& curset, vector<int>& vr, int start, int cursum, int& mindsum)
{
	if (curset.size() == a.size() / 2)
	{
		if (JudgeMinimum(cursum, mindsum))
		{
			vr = curset;
		}
		return 0;
	}
	for (int i = start; i < a.size(); ++i)
	{
		cursum += a[i];
		curset.push_back(i);
		btTugOfWar(a, curset, vr, i + 1, cursum, mindsum);

		//Backtrack
		cursum -= a[i];
		curset.pop_back();
		btTugOfWar(a, curset, vr, i+1/* should use i+1 since no use i in current set*/, cursum, mindsum);
	}
	return 0;
}

int TugOfWar(vector<int>& a)
{
	int ret = 0;
	int sum = 0;
	for (auto e : a)
	{
		sum += e;
	}
	g_sum = sum;
	int mindsum = INT_MAX;
	vector<int> curset;
	vector<int> vr;
	btTugOfWar(a, curset, vr, 0, 0, mindsum);

	int setsum = 0;
	for (auto index : vr)
	{
		cout << a[index] << " ";
		setsum += a[index];
	}
	cout <<": "<<setsum<<endl;
	return ret;
}

int main(int argc, char const *argv[])
{
	vector<int> a{ 3, 4, 5, -3, 100, 1, 89, 54, 23, 20 };
	vector<int> b{ 23, 45, -34, 12, 0, 98, -99, 4, 189, -1, 4 };
	TugOfWar(a);
	TugOfWar(b);
	return 0;
}
