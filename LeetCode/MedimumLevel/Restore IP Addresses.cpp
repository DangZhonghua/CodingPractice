/*
https://leetcode-cn.com/problems/restore-ip-addresses/
Restore IP Addresses

Given a string containing only digits, restore it by returning all possible valid IP address combinations.
Example:
Input: "25525511135"
Output: ["255.255.11.135", "255.255.111.35"]

*/

/*

use backtrack to solve this: valid IP is four part exactly. Every part is in the range [0, 255]. The start point of
each part is NOT started by '0' if the part length is greater than 1
we backtrack by every part.

*/

#include<string>
#include<iostream>
#include<vector>
using namespace std;



class Solution {
public:
	vector<string> restoreIpAddresses(string s)
	{
		vector<string> vips;
		vector<string> ip;
		btGenerateIpAddress(s, vips, ip, 0, 0);

		for (auto a : vips)
		{
			cout << a << endl;
		}
		return vips;
	}
private:
	void btGenerateIpAddress(string& s, vector<string>& vips, vector<string>& ip, int level, int startOfs)
	{
		if (4 == level)
		{
			if (startOfs == s.length())
			{
				string ipc;
				for (int i = 0; i < ip.size() - 1; ++i)
				{
					ipc += (ip[i] + ".");
				}
				ipc += *(ip.rbegin());
				vips.push_back(ipc);
			}
			return;
		}

		for (int i = 0; i < 3; ++i)
		{
            if((startOfs + i+1)>s.length())
            {
                continue;
            }
			string part = s.substr(startOfs, i + 1);
			if (isSafePart(part))
			{
				ip.push_back(part);
				btGenerateIpAddress(s, vips, ip, level + 1, startOfs + i + 1);
				ip.pop_back();
			}
		}
	}

	bool isSafePart(const string& part)
	{
		int partVal = atoi(part.c_str());
		if (partVal > 255 || partVal < 0)
		{
			return false;
		}
		if ('0' == part[0] && part.length() > 1)
		{
			return false;
		}
		return true;
	}
};

int main()
{
	string s = "25525511135";
	Solution sol;
	sol.restoreIpAddresses(s);

	return 0;
}