/*
https://leetcode-cn.com/problems/additive-number/
Additive Number

Additive number is a string whose digits can form additive sequence.
A valid additive sequence should contain at least three numbers. Except for the first two numbers, 
each subsequent number in the sequence must be the sum of the preceding two.
Given a string containing only digits '0'-'9', write a function to determine if it's an additive number.
Note: Numbers in the additive sequence cannot have leading zeros, so sequence 1, 2, 03 or 1, 02, 3 is invalid.
Example 1:
Input: "112358"
Output: true 
Explanation: The digits can form an additive sequence: 1, 1, 2, 3, 5, 8. 
             1 + 1 = 2, 1 + 2 = 3, 2 + 3 = 5, 3 + 5 = 8
Example 2:
Input: "199100199"
Output: true 
Explanation: The additive sequence is: 1, 99, 100, 199. 
             1 + 99 = 100, 99 + 100 = 199
Follow up:
How would you handle overflow for very large input integers?  use the string add NOT the number add

*/

#include<string>
#include<deque>
#include<iostream>
using namespace std;

/*

we only need find the first three elements to decide the whole string.
Pay attention to leading zero

*/
class Solution
{
public:
	bool isAdditiveNumber(string num)
	{
		bool bAdditive = false;
		int N = num.length();

		for (int len = 1; len <= N && !bAdditive; ++len)
		{
			string strop1 = num.substr(0, len);
			for (int j = 1; j <= N - len; ++j)
			{
				string strop2 = num.substr(len, j);
				if ( (strop1.length()>1&& '0' == strop1.at(0) )|| (strop2.length()>1 && '0' == strop2.at(0)))
				{
					continue;
				}
				string rs = addStrings(strop1, strop2);
				if (rs.length() > (num.length() - len - j))
				{
					continue;
				}
				string res = num.substr(len + j, rs.length());
				if ( ( res.length()>1 && '0' == res.at(0) ) || rs.compare(res))
				{
					continue;
				}
				bAdditive = BackTrackAddNumber(num, strop2, res, len + j + res.length());
			}
		}

		return bAdditive;
	}

private:
	bool BackTrackAddNumber(string & num, string & strop1, string & strop2, int startsum) // {start,len} describe the first operator.
	{
		if (startsum == num.length())
		{
			return true;
		}
		string rs = addStrings(strop1, strop2);
		if ((startsum + rs.length()) <= num.length())
		{
			string strsum = num.substr(startsum, rs.length());
			if (strsum.length()>1 && '0' == strsum.at(0))
			{
				return false;
			}
			if (rs.compare(strsum))
			{
				return false;
			}
			else
			{
				return BackTrackAddNumber(num, strop2, strsum, startsum + strsum.length());
			}
		}
		return false;
	}

private:
	string addStrings(const string & num1, const string & num2)
	{
		deque<char> SQ;
		int i = num1.length() - 1;
		int j = num2.length() - 1;
		int sum = 0;
		int s = 0;

		while (i >= 0 && j >= 0)
		{
			sum = (s + num1[i] - '0' + num2[j] - '0');
			s = sum / 10;
			sum %= 10;
			SQ.push_front('0' + sum);
			--i;
			--j;
		}
		while (i >= 0)
		{
			sum = s + num1[i] - '0';
			s = sum / 10;
			sum %= 10;
			SQ.push_front('0' + sum);
			--i;
		}
		while (j >= 0)
		{
			sum = s + num2[j] - '0';
			s = sum / 10;
			sum %= 10;
			SQ.push_front('0' + sum);
			--j;
		}
		if (s > 0)
		{
			SQ.push_front('0' + s);
		}
		string sr;

		while (!SQ.empty())
		{
			sr.push_back(SQ.front());
			SQ.pop_front();
		}
		return sr;
	}
};

int main()
{
    Solution sol;
    string num = "112358";
    
    cout<< sol.isAdditiveNumber(num)<<endl;

    return 0;
}