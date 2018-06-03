/*
https://practice.geeksforgeeks.org/problems/find-first-repeated-character/0/?ref=self

https://practice.geeksforgeeks.org/problems/zero-sum-subarrays/0/?ref=self

*/

#include<iostream>
#include<unordered_map>
#include<string>
#include<climits>
using namespace std;


int firstRepeatChar(const string& strText)
{
	unordered_map<char, pair<int, int>> repmap;
    int min = INT_MAX;

	for (int i = 0; i<strText.size(); ++i)
	{
		auto it = repmap.find(strText[i]);
		if (it != repmap.end())
		{
			it->second.second += 1;
            min = it->second.first;
            break;
		}
		else
		{
			repmap[strText[i]] = pair<int, int>(i, 1);
		}
	}


	if (min == INT_MAX)
	{
		cout << -1 << endl;
	}
	else
	{
		cout << strText[min] << endl;
	}



	return 0;
}

int main()
{
	int t = 0;
	string strText;

	cin >> t;

	while (t--)
	{
		cin >> strText;
		firstRepeatChar(strText);
	}


	return 0;
}