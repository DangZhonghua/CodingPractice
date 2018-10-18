/*
https://practice.geeksforgeeks.org/problems/generate-ip-addresses/1/?ref=self
Generate IP Addresses

Given a string s containing only digits, Your task is to complete the function genIp
which returns a vector containing all possible combination of valid IPv4 ip address
and takes only a string s as its only argument .
Note : Order doesn't matter

For string 11211 the ip address possible are
1.1.2.11
1.1.21.1
1.12.1.1
11.2.1.1

Input:
The first line of input will contain no of test cases T. Then T test cases follow . Each test case will contains a string s .

Output:
The output in the expected output will be 1 if successfully all the combinations
were obtained in the returned vector else it will be 0.

Constraints:
1<=T<=100
1<=str<=16

Example(To be used only for expected output):
Input
1
1111

Output
1

*/

/*

Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.

You are required to complete this method

vector<string> genIp(string s)
{
//Your code here
}

*/

#include<iostream>
#include<vector>
#include<string>
using namespace std;


int ConvertStr2Int(const char* str)
{
	return atoi(str);
}

bool isSafeDigital(const string& strdig)
{
	int d = ConvertStr2Int(strdig.c_str());
	if (d >= 0 && d <= 255)
	{
		return true;
	}
	return false;
}

bool isSafePart(const string& strPart)
{
    if( !isSafeDigital(strPart))
    {
        return false;
    }
    if(strPart[0] == '0' && strPart.length()>1)
    {
        return false;
    }
    return true;
}

bool btGenIp(string& s, int step, int level, vector<string>& vstrip, string& strip)
{
	if (4 == level)
	{
		if (step == s.length())
		{
			string s = strip;
			s.pop_back();
			vstrip.push_back(s);
			return true;
		}
		else
		{
			return false;
		}
	}
	if (4 > level && step >= s.length())
	{
		return false;
	}

	bool bIp = false;
	for (int i = 0; i<3; ++i)
	{
		string strDigital = s.substr(step, i + 1);
		if (isSafePart(strDigital))
		{
			strip += strDigital;
			strip += ".";
			bIp = (btGenIp(s, step + i + 1, level + 1, vstrip, strip) | bIp);
			for (int j = 0; j <= strDigital.length(); ++j)
			{
				strip.pop_back();
			}
		}
	}
	return bIp;
}


int    generateIpString(string& s, vector<string>& vstrip)
{
	string strip;
	btGenIp(s, 0, 0, vstrip, strip);
	return 0;
}

vector<string> genIp(string s)
{
	vector<string> vstrIp;
	generateIpString(s, vstrIp);
	for (auto str : vstrIp)
	{
		cout << str << endl;
	}

	return vstrIp;
}


int main(int argc, char const *argv[])
{
	int t = 0;
	cin >> t;

	while (t--)
	{
		string strtext;
		cin >> strtext;
		genIp(strtext);
	}
	return 0;
}







