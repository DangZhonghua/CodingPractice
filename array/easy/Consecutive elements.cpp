/*
Consecutive elements
https://practice.geeksforgeeks.org/problems/consecutive-elements/0/?ref=self

For a given string delete the elements which are appearing more than once consecutively. All letters are of lowercase.

Input:
The first line contains an integer 'T' denoting the total number of test cases. In each test cases,  a string will be inserted.


Output:
In each seperate line the modified string should be output.


Constraints:
1<=T<=31
1<=length(string)<=100


Example:
Input:
1
aababbccd

Output:
ababcd


*/


#include <iostream>
#include<string>
#include<vector>
using namespace std;

int ConsecutiveElements(const string& strtext)
{
	char a[101] = { 0 };
	strncpy(a, strtext.c_str(), sizeof(a) / sizeof(a[0]));

	int j = 1;
	int i = 0;

	while (a[j] != '\0')
	{
		if (a[i] != a[j])
		{
			++i;
			a[i] = a[j];
		}
		++j;
	}
	++i;
	a[i] = '\0';
	cout << a << endl;

	return 0;
}


int main()
{
	int  t = 0;
	string  sztext;

	cin >> t;

	while (t--)
	{
		cin >> sztext;
		ConsecutiveElements(sztext);
	}


	return 0;
}