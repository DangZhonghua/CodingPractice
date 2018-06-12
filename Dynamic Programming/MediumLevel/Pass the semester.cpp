/*
Pass the semester
https://practice.geeksforgeeks.org/problems/pass-the-semester/0

Satish wants to prepare for tommorow's exam . He knows the distribution of marks for 
the subject along with time to learn the concepts.
You are given remaining time for the exam along with marks for each topic and passing marks for the subject.
Find the max marks Satish can attain by studing max no of topic in max no hours not excedding (p) .

Input:

The first line of input contains the number of testcases t.
The first line of each testcase contains the no of topics(n) , time remaining for exam(h) in hour and passing marks(p).
Each 'n' lines contain u(time to learn topic) and v(weightage of topic in exam) .

Output:

For each test case print "YES" along with time taken or "NO".  


Constraints:

1<=t<=100

1<=n<=300

1<=h<=150

1<=p<=35

1<=u,v<=25


Example:
Sample Input 0
1
5 40 21 
12 10 
16 10 
20 10 
24 10 
8 3 


Sample Output 0 
YES 36

Explaination :

Marks needed to pass the subject  10 +10 + 3 = 23

Time taken to achieve the 23 marks : 12 + 16 + 8 =36

*/

/*

0-1 knapsack problem. Time stand for capacity and weight. Mark is the value.

*/

#include<iostream>
#include<vector>
using namespace std;


int PassSemester(int N, int leftTime, int* w, int* v, int target)
{
	vector< vector<int> > f(N + 1, vector<int>(leftTime + 1, 0));
	vector< vector<int> > s(N + 1, vector<int>(leftTime+1, 0));

	for (int i = 1; i <= N; ++i)
	{
		for (int l = 1; l <= leftTime; ++l)
		{
			f[i][l] = f[i - 1][l];
			s[i][l] = s[i - 1][l];
			if (l >= w[i] && f[i - 1][l - w[i]] + v[i] > f[i - 1][l])
			{
				f[i][l] = f[i - 1][l - w[i]] + v[i];
				s[i][l] = i;
			}
		}
	}

	int r = N; 
	int c = leftTime;
	vector<int> vSelect;
	while (r > 0 && c > 0)
	{
		if (s[r][c] == r)
		{
			vSelect.push_back(r);
			c = c - w[r];
			r = r-1;
			
		}
		else
		{
			r = r-1;
		}
	}
	int TimeUsage = 0;
	
	for (int i = 0; i < vSelect.size(); ++i)
	{
		TimeUsage += w[vSelect[i]];
	}
	if (f[N][leftTime] >= target)
	{
		cout << "YES" << " "<<TimeUsage<<endl;
	}
	else
	{
		cout << "NO"<<endl;
	}
	return 0;
}


int main()
{
	int t = 0;
	int N = 0;
	int leftTime = 0;
	int target = 0;
	int top[600];
	int m[600];

	cin >> t;

	while (t--)
	{
		cin >> N;
		cin >> leftTime;
		cin >> target;

		int i = 1;

		while (i <= N)
		{
			cin >> top[i];
			cin >> m[i];
			++i;
		}
		PassSemester(N, leftTime, top, m, target);
	}


	return 0;
}