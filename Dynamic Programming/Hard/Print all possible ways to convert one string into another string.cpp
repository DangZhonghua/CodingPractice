/*
Print all possible ways to convert one string into another string
https://www.geeksforgeeks.org/print-all-possible-ways-to-convert-one-string-into-another-string-edit-distance/


Print all possible ways to convert one string into another string | Edit-Distance

Prerequisite: Dynamic Programming | Set 5 (Edit Distance)
Given two strings str1 and str2, the task is to print the all possible ways to convert ‘str1’ into ‘str2’.
Below are the operations that can be performed on “str1”:

Insert
Remove
Replace

All of the above operations are of equal cost.
The task is to print all the various ways to convert ‘str1’ into ‘str2’
using the minimum number of edits (operations) required, where a “way”
comprises of the series of all such operations required.

Examples:

Input: str1 = “abcdef”, str2 = “axcdfdh”
Output:
Method 1:
Add h
Change f to d
Change e to f
Change b to x

Method 2:
Change f to h
Add d
Change e to f
Change b to x

Method 3:
Change f to h
Change e to d
Add f
Change b to x


*/

/*

ed[i-1][j-1]  if x[i] == y[j]

ed[i][j] =  min     if x[i] != y[j]
{
ed[i-1][j-1] + 1 //replace
ed[i-1][j] + 1 // remove
ed[i][j-1] + 1 // for insert
}

*/

/*

after computing the minicost of transforming. We store the parent pointer to
figure out the possible way.

*/

#include<iostream>
#include<vector>
#include<string>
#include<stack>
using namespace std;

enum opcode
{
	op_invaild,
	op_insert,
	op_remove,
	op_replace,
	op_equal
};


struct edop
{
	vector<opcode>  code;
	int ed = INT_MAX;
	int i = 0;
	int j = 0;
	int index = 0;
};

struct edt
{
	opcode code;
	int i = 0;
	int j = 0;
};

char szopt[1024] = { 0 };

int output(vector<string>& vm)
{
	for (auto m : vm)
	{
		cout << m << endl;
	}
	cout << "************"<<endl;
	return 0;
}

int CalcTransform(const string& x, const string& y, vector< vector<edop> >& ed, int i, int j, vector<string>& vm)
{
	if (0 == j || 0 == i)
	{
		output(vm);
		return 0;
	}
	for (int index = ed[i][j].index; index < ed[i][j].code.size(); ++index)
	{
		if (op_equal == ed[i][j].code[index])
		{
			CalcTransform(x, y, ed, i - 1, j - 1, vm);
		}
		if (op_insert == ed[i][j].code[index])
		{
			sprintf_s(szopt,1024, "add %c\n", y[j-1]);
			vm.push_back(szopt);
			CalcTransform(x, y, ed, i, j - 1, vm);
			vm.pop_back();
		}
		if (op_remove == ed[i][j].code[index])
		{
			sprintf_s(szopt, 1024, "remove %c\n", x[i-1]);
			vm.push_back(szopt);
			CalcTransform(x, y, ed, i - 1, j, vm);
			vm.pop_back();
		}
		if (op_replace == ed[i][j].code[index])
		{
			sprintf_s(szopt, 1024, "change %c to %c\n", x[i-1], y[j-1]);
			vm.push_back(szopt);
			CalcTransform(x, y, ed, i - 1, j - 1, vm);
			vm.pop_back();
		}
	}


	return 0;
}

int editDistance(const string& x, const string& y)
{
	int R = x.length();
	int C = y.length();
	vector< vector<edop> > ed(R + 1, vector<edop>(C + 1, edop()));

	//if y is empty.
	for (int i = 0; i <= R; ++i)
	{
		ed[i][0].ed = i; //just removing
		ed[i][0].code.push_back(op_remove);
		ed[i][0].i = i;
		ed[i][0].j = 0;
	}
	//if x is empty
	for (int i = 0; i <= C; ++i)
	{
		ed[0][i].ed = i; //just insert
		ed[0][i].code.push_back(op_insert);
		ed[0][i].i = 0;
		ed[0][i].j = i;
	}

	for (int i = 1; i <= R; ++i)
	{
		for (int j = 1; j <= C; ++j)
		{
			ed[i][j].i = i;
			ed[i][j].j = j;
			if (x[i - 1] == y[j - 1])
			{
				ed[i][j].ed = ed[i - 1][j - 1].ed;
				ed[i][j].code.push_back(op_equal);
			}
			else
			{

				if (ed[i - 1][j].ed + 1<ed[i][j].ed) //for remove
				{
					ed[i][j].ed = ed[i - 1][j].ed + 1;
					ed[i][j].code.clear();
					ed[i][j].code.push_back(op_remove);
				}

				if (ed[i - 1][j - 1].ed + 1 < ed[i][j].ed) // for replace
				{
					ed[i][j].ed = ed[i - 1][j - 1].ed + 1;
					ed[i][j].code.clear();
					ed[i][j].code.push_back(op_replace);

				}
				else if (ed[i - 1][j - 1].ed + 1 == ed[i][j].ed)
				{
					ed[i][j].code.push_back(op_replace);
				}
				if (ed[i][j - 1].ed + 1 < ed[i][j].ed) // for insert
				{
					ed[i][j].ed = ed[i][j - 1].ed + 1;
					ed[i][j].code.clear();
					ed[i][j].code.push_back(op_insert);
				}
				else if (ed[i][j - 1].ed + 1 == ed[i][j].ed)
				{
					ed[i][j].code.push_back(op_insert);
				}
			}
		}
	}
	vector<string> vm;
	CalcTransform(x, y, ed, x.length(), y.length(), vm);
	//cout<<ed[R][C].ed<<endl;

	return 0;
}


int main()
{
	int t;
	int M = 0;
	int N = 0;
	string x, y;


	cin >> t;

	while (t--)
	{
		cin >> x >> y;
		editDistance(x, y);
	}

	return 0;
}