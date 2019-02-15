/*
Remove Invalid Parentheses
https://www.geeksforgeeks.org/remove-invalid-parentheses/

An expression will be given which can contain open and close parentheses and optionally some characters,
No other operator will be there in string. We need to remove minimum number of parentheses to make the input string valid.
If more than one valid output are possible removing same number of parentheses then print all such output.
Examples:

Input  : str = “()())()” -
Output : ()()() (())()
There are two possible solutions
"()()()" and "(())()"

Input  : str = (v)())()
Output : (v)()()  (v())()

*/

/*
Are there: optimal substructure and overlapped problems?
Seems there are no substructure: from prefix or postfix  or range

What is the difference between DP and BT

*/

/*
As we need to generate all possible output we will backtrack among all states by removing one opening or closing bracket and
check whether they are valid.
If invalid then add the removed bracket back and go for next state.
We will use BFS for moving through states, use of BFS will assure removal of minimal number of brackets
because we traverse into states level by level and each level corresponds to one extra bracket removal.
Other than this BFS involve no recursion so overhead of passing parameters is also saved.
Below code has a method isValidString to check validity of string,
it counts open and closed parenthesis at each index ignoring non-parenthesis character.
If at any instant count of close parenthesis becomes more than open then we return false else we keep update the count variable.

*/

#include <stack>
#include <string>
#include <set>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;


bool isParentheses(char c)
{
	return ('(' == c || ')' == c);
}

bool isValidString(const string& str)
{
	int cnt = 0;
	for (char c : str)
	{
		if ('(' == c)
		{
			++cnt;
		}
		else if (')' == c)
		{
			--cnt;
		}
		if (cnt < 0)
		{
			break;
		}
	}
	return (cnt == 0);
}


int RemoveMinimumParenthesis(string& str)
{
	int ret = 0;

	set<string>     visitedString;
	queue<string>   q;
	vector<string>  qualifiedString;

	q.push(str);
	visitedString.insert(str);
	bool bFindValid = false;

	while (!q.empty())
	{
		if (isValidString(q.front()))
		{
			qualifiedString.push_back(q.front());
			bFindValid = true;
		}
		string strTemp;
		if (bFindValid)
		{
			q.pop();
			continue; // skip the removal since we have find minimal removal.
		}
		else
		{
			strTemp = q.front();
		}
		q.pop();

		for (int i = 0; i < strTemp.length(); ++i)
		{
			if (!isParentheses(strTemp[i]))
			{
				continue;
			}
			string strRemoval = strTemp.substr(0, i) + strTemp.substr(i + 1);
			if (visitedString.find(strRemoval) == visitedString.end())
			{
				visitedString.insert(strRemoval);
				q.push(strRemoval);
			}
		}
	}

	for (const string& str : qualifiedString)
	{
		cout << str << endl;
	}
	return ret;
}

int main(int argc, char const *argv[])
{

	string str = "()())()";
	RemoveMinimumParenthesis(str);
	return 0;
}
