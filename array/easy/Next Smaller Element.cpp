/*
Next Smaller Element
https://www.geeksforgeeks.org/next-smaller-element/

Given an array, print the Next Smaller Element (NSE) for every element.
The Smaller smaller Element for an element x is the first smaller element on
the right side of x in array. Elements for which no smaller element exist (on right side), consider next smaller element as -1.

Examples:
a) For any array, rightmost element always has next smaller element as -1.
b) For an array which is sorted in increasing order, all elements have next smaller element as -1.
c) For the input array {4, 8, 5, 2, 25}, the next smaller elements for each element are as follows.

Element       NSE
4      -->   2
8      -->   5
5      -->   2
2      -->   -1
25     -->   -1

d) For the input array {13, 7, 6, 12}, the next smaller elements for each element are as follows.

Element        NSE
13      -->    7
7       -->    6
6       -->    -1
12     -->     -1

*/

/*

scan the array from right to left, there are three case:

a[i-1] > a[i]   NSE[i-1] = i
a[i-1] == a[i]  NSE[i-1] = NSE[i]
a[i-1]<a[i]    find according to NSE[i] until a[i-1]>a[NSE[j]] or -1

*/

#include<iostream>
#include<vector>
using namespace std;

int NextSmallerElement(vector<int>&a)
{
	int ret = 0;
	vector<int> nse(a.size(), -1);

	for (int i = a.size() - 2; i >= 0; --i)
	{
		if (a[i]>a[i + 1])
		{
			nse[i] = i + 1;
		}
		else if (a[i] == a[i + 1])
		{
			nse[i] = nse[i + 1];
		}
		else
		{
			int j = i + 1;
			while (-1 != j )
			{
				if (a[i]>a[j])
				{
					nse[i] = j;
					break;
				}
				else
				{
					j = nse[j];
				}
			}
		}
	}

	for (int i = 0; i<a.size(); ++i)
	{
		if (-1 != nse[i])
		{
			cout << a[nse[i]] << " ";
		}
		else
		{
			cout << nse[i] << " ";
		}
	}
	cout << endl;

	return ret;
}


int main(int argc, char const *argv[])
{
	/* code */

	vector<int> a{ 4, 8, 5, 2, 25 };
	vector<int> b{ 13, 7, 6, 12 };
	NextSmallerElement(a);
	NextSmallerElement(b);

	return 0;
}
