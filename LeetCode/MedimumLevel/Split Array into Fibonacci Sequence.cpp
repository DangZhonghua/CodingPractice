/*
https://leetcode-cn.com/problems/split-array-into-fibonacci-sequence/

Split Array into Fibonacci Sequence
Given a string S of digits, such as S = "123456579", we can split it into a Fibonacci-like sequence [123, 456, 579].

Formally, a Fibonacci-like sequence is a list F of non-negative integers such that:

    0 <= F[i] <= 2^31 - 1, (that is, each integer fits a 32-bit signed integer type);
    F.length >= 3;
    and F[i] + F[i+1] = F[i+2] for all 0 <= i < F.length - 2.

Also, note that when splitting the string into pieces, each piece must not have extra leading zeroes, 
except if the piece is the number 0 itself.

Return any Fibonacci-like sequence split from S, or return [] if it cannot be done.

Example 1:

Input: "123456579"
Output: [123,456,579]

Example 2:

Input: "11235813"
Output: [1,1,2,3,5,8,13]

Example 3:

Input: "112358130"
Output: []
Explanation: The task is impossible.

Example 4:

Input: "0123"
Output: []
Explanation: Leading zeroes are not allowed, so "01", "2", "3" is not valid.

Example 5:

Input: "1101111"
Output: [110, 1, 111]
Explanation: The output [11, 0, 11, 11] would also be accepted.

Note:

    1 <= S.length <= 200
    S contains only digits.


*/

#include<string>
#include<vector>
#include<deque>
#include<iostream>
using namespace std;


class Solution 
{
    /*
     Still need figure out the first three elements. But PLEASE, PAY ATTENTION TO leading zero
    */

public:
    vector<int> splitIntoFibonacci(string s) 
    {
		bool bFibonacci = false;
		int N = s.length();
        vector<int> vr;
        vector<int> vindex;
	
		
		for(int len = 1; len<=10 && !bFibonacci; ++len)
		{
			string strop1 =  s.substr(0,len);
			vindex.push_back(atoi(strop1.c_str()) );
			for(int len2 = 1; len2<=N-len&&len2<=10; ++len2)
			{
				string strop2 = s.substr(len, len2);
				if( '0' == strop2.at(0) && strop2.length() > 1)
				{
					break;
				}
				vindex.push_back(atoi(strop2.c_str()));	
				if( btCheckFibonacciSeq(s,strop1,strop2,vindex, len+len2) )
				{
					bFibonacci = true;
					break;
				}
				vindex.pop_back();
			}
			if(bFibonacci)
			{
				break;
			}
			vindex.pop_back();
        }
        
        return vindex;
    }

private:
	bool btCheckFibonacciSeq(const string& s, const string& op1, const string& op2, vector<int>& vindex, int nIndexSum) //nIndexSum means sum start index
	{
		string strsum = addStrings(op1,op2);
        if(strsum.length() == 10 && strsum.compare("2147483647")>0) // pay attention to: the element scope.
        {
            return false;
        }
		if( ( nIndexSum+strsum.length() ) <= s.length())
		{
			string subsum = s.substr(nIndexSum, strsum.length());
			if(subsum.compare(strsum))
			{
				return false;
			}
			else
			{
				vindex.push_back(atoi(strsum.c_str()));
				if( ( nIndexSum+strsum.length() ) == s.length() )
				{
					return true;
				}
				else
				{
					if( !btCheckFibonacciSeq(s, op2,subsum,vindex, nIndexSum+subsum.length()) )
					{
						vindex.pop_back();
						return false;
					}
					return true;
				}
			}
		}
		//since there is no enough letter.
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