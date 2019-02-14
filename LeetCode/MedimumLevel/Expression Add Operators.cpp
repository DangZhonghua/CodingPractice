/*
https://leetcode-cn.com/problems/expression-add-operators/
Expression Add Operators

Given a string that contains only digits 0-9 and a target value,
return all possibilities to add binary operators (not unary) +, -, or * between the digits so they evaluate to the target value.

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

this can be solved by backtrcking technique.

*/


#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<deque>
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

		if ((btd.m_Start + btd.m_Len) == num.length())
		{
			btd.m_bLast = true;
		}
		btStack.push(btd);
		btQ.push_back(btd);

		//#1: Keep the operator unchanged, change the digital length
		//#2: change the operator, then step 1

		while (!btStack.empty())
		{
			btDesc& tp = btStack.top();
			if (tp.m_bLast)
			{
				CalculateExpress(btQ, num, target);
				btStack.pop();
				btQ.pop_back();
				
				if (!btStack.empty())
				{
					btDesc& tp = btStack.top();
					tp.m_Len += 1;
					
				}
			}
			else
			{
				tp.m_Len += 1;
				
			}
		}
	}
private:
	int CalculateExpress(deque<btDesc>& Q, string& num, int target)
	{
		int nProduct = 1;
		int sum = 0;
		int i = 0;
		int bPositive = 1;
		string  strExp;

		while (i < Q.size())
		{
			if (!Q[i].m_bLast)
			{
				int d = GetNumber(Q[i], num, strExp);
				if (2 == Q[i].m_OP) // '*' case
				{
					nProduct *= d;
					int j = i + 1;
					while (2 == Q[j].m_OP && j < Q.size())
					{
						d = GetNumber(Q[j], num, strExp);
						nProduct *= d;
						++j;
					}
					if (j < Q.size())
					{
						d = GetNumber(Q[j], num, strExp);
						nProduct *= d;
						sum += (bPositive)*nProduct;
						if (1 == Q[j].m_OP)
						{
							nProduct = -1;
						}
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
				sum += (bPositive)*GetNumber(Q[i], num, strExp);
				++i;
			}
		}

		if (sum == target)
		{
			cout << strExp << endl;
		}
		return 0;
	}

	int GetNumber(btDesc& e, string& num, string& strExp)
	{
		char c = num[e.m_end + 1];
		num[e.m_end + 1] = '\0';
		int d = atoi(num.c_str() + e.m_Start);

		strExp += (num.c_str() + e.m_Start);
		if (!e.m_bLast)
		{
			if (0 == e.m_OP)
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
};

int main()
{
	Solution sol;
	int target = 6;
	string num = "123";

	sol.addOperators(num, target);

	return 0;
}