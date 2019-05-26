/*

https://www.cnblogs.com/grandyang/p/4814506.html
https://leetcode-cn.com/problems/expression-add-operators/
Expression Add Operators

Given a string that contains only digits 0-9 and a target value,
return all possibilities to add binary operators (not unary) +, -, or * 
between the digits so they evaluate to the target value.

Example 1:

Input: num = "123", target = 6
Output: ["1+2+3", "1*2*3"]

Example 2:

Input: num = "232", target = 8
Output: ["2*3+2", "2+3*2"]

Example 3:

Input: num = "105", target = 5
Output: ["1*0+5","10-5"]

Example 4:

Input: num = "00", target = 0
Output: ["0+0", "0-0", "0*0"]

Example 5:

Input: num = "3456237490", target = 9191
Output: []


*/

/*

this can be solved by backtracking technique.

*/


#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<deque>
#include <set>
using namespace std;

class Solution
{

	struct btDesc
	{
		int m_Start;
		int m_Len;
		int m_end;
		int m_OP;
		bool m_bLast;
		btDesc() { m_Start = 0; m_Len = 1; m_end = 0; m_OP = 0; m_bLast = false; }
		btDesc(int s, int l, int e, int o, bool bLast)
		{
			m_Start = s;
			m_Len = l;
			m_end = e;
			m_OP = o;
			m_bLast = bLast;
		}
	};

public:
	vector<string> addOperators(string num, int target)
	{
		//char* szNum = num.c_str();
		if (num.empty())
		{
			return vector<string>();
		}

		stack<btDesc>   btStack;  //use to backtracking
		deque<btDesc>   btQ;      // use to calculate the expression
		vector<string>  vExp;
		string  strExp;
		btDesc btd;

		btd.m_end = btd.m_Start + btd.m_Len - 1;
		if ((btd.m_Start + btd.m_Len) == num.length())
		{
			btd.m_bLast = true;
		}
		btStack.push(btd);
		btQ.push_back(btd);

		//#1:Keep the sub-string length unchanged, chang the operator
		//#2: change the operator, if all operator have been tried, increase the length go to the step 1.

		while (!btStack.empty())
		{
			btDesc& tp = btStack.top();
			if (tp.m_bLast)
			{
				CalculateExpress(btQ, num, vExp, target);
				btStack.pop();
				btQ.pop_back();
				if (!btStack.empty())
				{
					btQ.pop_back();

					bool bLast = false;
					btDesc& ntp = btStack.top();

					btDesc btQNext;
					ntp.m_OP++;
					if (ntp.m_OP > 2)
					{
						//has try all operator with the same length, now we try to change the length.
						btQNext.m_Len = (ntp.m_Len + 1);
						btQNext.m_Start = ntp.m_Start;
						btQNext.m_OP = 0;
						btQNext.m_end = btQNext.m_Start + btQNext.m_Len - 1;
					}
					else
					{
						btQNext.m_Len = ntp.m_Len;
						btQNext.m_Start = ntp.m_Start;
						btQNext.m_OP = ntp.m_OP;
						btQNext.m_end = btQNext.m_Start + btQNext.m_Len - 1;

					}
					btStack.pop();
					if (btQNext.m_end == num.length() - 1)
					{
						bLast = true;
					}
					btQNext.m_bLast = bLast;

					btQ.push_back(btQNext);
					btStack.push(btQNext);
				}
			}
			else
			{
				btDesc btQNext;
				btQNext.m_Start = (tp.m_end + 1);
				btQNext.m_end = btQNext.m_Start + btQNext.m_Len - 1;

				bool bLast = false;
				if (btQNext.m_end == num.length() - 1)
				{
					bLast = true;
				}
				btQNext.m_bLast = bLast;
				btQ.push_back(btQNext);
				btStack.push(btQNext);
			}
		}

		// for (string& exp : vExp)
		// {
		// 	cout << exp << endl;
		// }

		return vExp;
	}
private:
	int CalculateExpress(deque<btDesc>& Q, string& num, vector<string>& vExp, int target)
	{

		long long nProduct = 1;
		long long sum = 0;
		int i = 0;
		long long bPositive = 1;
		string  strExp;
		bool bVaild = true;

		while (i < Q.size())
		{

			if (!Q[i].m_bLast)
			{
				long long d = GetNumber(Q[i], num, strExp, bVaild);
				if (0 == Q[i].m_OP) // '*' case
				{
					nProduct = 1;
					nProduct *= (d*bPositive);
					int j = i + 1;
					while (j < Q.size() && 0 == Q[j].m_OP && bVaild)
					{
						d = GetNumber(Q[j], num, strExp, bVaild);
						nProduct *= d;
						++j;
					}
					if (j < Q.size() && bVaild)
					{
						d = GetNumber(Q[j], num, strExp, bVaild);
						nProduct *= d;
						sum += nProduct;
						if (1 == Q[j].m_OP)
						{
							bPositive = -1;
						}
						else
						{
							bPositive = 1;
						}
					}
					else
					{
						sum += nProduct;
					}
					i = (j + 1);
				}
				else
				{
					sum += (bPositive)*d;
					bPositive = 1;
					if (1 == Q[i].m_OP)
					{
						bPositive = -1;
					}
					++i;
				}
			}
			else
			{
				sum += (bPositive)*GetNumber(Q[i], num, strExp, bVaild);
				++i;
			}
		}

		//if (!strExp.compare("1+23*4+5-6-7*8+9"))
		//{
		//	cout << "find"<<endl;
		//}

		if (sum == target && bVaild)
		{
			//auto it = m_Dict.find(strExp);
			//if (it == m_Dict.end())
			{
			//	m_Dict.insert(strExp);
				vExp.push_back(strExp);
			}
			//cout << strExp << endl;
 			
		}
		return 0;
	}

	long long GetNumber(btDesc& e, string& num, string& strExp, bool& bVaild)
	{
		if ('0' == num[e.m_Start] && e.m_Len > 1)
		{
			bVaild = false;
			return 0;
		}
		char c = num[e.m_end + 1];
		num[e.m_end + 1] = '\0';
		long long d = atol(num.c_str() + e.m_Start);

		strExp += (num.c_str() + e.m_Start);
		if (!e.m_bLast)
		{
			if (2 == e.m_OP)
			{
				strExp += "+";
			}
			else if (1 == e.m_OP)
			{
				strExp += "-";
			}
			else
			{
				strExp += "*";
			}
		}
		num[e.m_end + 1] = c;
		return d;
	}

private:
	//char arOP[3] = { '+', '-', '*' };
	//char arOP[3] = { '*', '-', '+' };

	set<string> m_Dict;
};

int main()
{
	Solution sol;
	int target = 6;
	string num = "123";

	//sol.addOperators(num, target);

	num = "232";
	target = 8;
	//sol.addOperators(num, target);

	//num = "105";
	//target = 5;
	//sol.addOperators(num, target);


	//num = "00";
	//target = 0;
	//sol.addOperators(num, target);

	num = "3456237490";
	target = 9191;

	sol.addOperators(num, target);


	//num = "123456789";
	//target = 45;

	//sol.addOperators(num,target);

	return 0;
}