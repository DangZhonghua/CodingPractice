/*
A Simple Fraction
https://practice.geeksforgeeks.org/problems/a-simple-fraction/0
Given a fraction. Convert it into a decimal. So simple :P

eg.
10/2 = 5
3/5 = 0.6

(The Question Begins Now)  :D
If the decimals are repeating recursively, then enclose them inside  ().

eg.
8/3 = 2.(6)

as 8/3 = 2.66666666.......  infinitly.


Input:

The first line of input contains an integer T denoting the number of test cases.
The first line of each test case is an integer N denoting the numerator of fraction.
The second line of each test case is an integer D denoting the denominator of fraction.

Output:

Print decimal of that fraction in separate line for each test case.

Constraints:

1 ≤ T ≤ 100
1 ≤ N,D ≤ 2000

Example:

Input
2
4
2
8
3
Output
2
2.(6)

*/

/*
 
 abc(abc)(abc)

*/

#include<iostream>
#include<unordered_map>
#include<vector>
#include <string>
using namespace std;

int SimpleFraction(int numerator, int Denominator)
{
	vector<int>			vs;
	vector<int>			vb;
	vector<string>		vstr;
	int  base			= 1;
	int  prenumerator	= -1;
	bool bloop			= false;
	unordered_map<int, int>  mnd;
    int start = 0;
    int end = 0;

	while (numerator)
	{
		base = 1;
		if (numerator<Denominator)
		{
			numerator *= 10;
			base = 10;
		}
        auto it = mnd.find(numerator/base);
        if( mnd.end() == it)
        {
            mnd.insert(std::make_pair(numerator/base, vs.size()));
            vs.push_back(numerator / Denominator);
            vb.push_back(base);
            numerator %= Denominator;
        }
        else
        {
            bloop = true;
            start = it->second;
            end  = vs.size()-1;
            break;
        }
	}
	int i = 0;
	if (vb[0] > 1)
	{
		vstr.push_back("0.");
	}
	else
	{
		vstr.push_back(to_string(vs[0]));
		if (vs.size()>1)
		{
			vstr.push_back(".");
		}
		i = 1;
	}

    if(bloop)
    {
        for(i; i<start; ++i)
        {
            vstr.push_back(to_string(vs[i]));
        }
        vstr.push_back("(");
        for(i; i<=end; ++i)
        {
            vstr.push_back(to_string(vs[i]));
        }
        vstr.push_back(")");
    }
    else
    {
        for(i;i<vs.size(); ++i)
        {
            vstr.push_back(to_string(vs[i]));
        }
    }
	
	for (int j = 0; j<vstr.size(); ++j)
	{
		cout << vstr[j];
	}
	cout << endl;

	return 0;
}

int main(int argc, char const *argv[])
{
	int t = 0;
	int numerator = 0;
	int denominator = 1;

	cin >> t;

	while (t--)
	{
		cin >> numerator >> denominator;
		SimpleFraction(numerator, denominator);
	}


	return 0;
}

