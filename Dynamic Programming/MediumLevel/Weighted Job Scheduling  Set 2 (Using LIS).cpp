/*
Weighted Job Scheduling | Set 2 (Using LIS)
https://www.geeksforgeeks.org/weighted-job-scheduling-set-2-using-lis/
Given N jobs where every job is represented by following three elements of it.

1. Start Time
2. Finish Time
3. Profit or Value Associated

Find the maximum profit subset of jobs such that no two jobs in the subset overlap.

Examples:

Input:  
Number of Jobs n = 4
Job Details {Start Time, Finish Time, Profit}
Job 1: {1, 2, 50}
Job 2: {3, 5, 20}
Job 3: {6, 19, 100}
Job 4: {2, 100, 200}

Output:  
Job 1: {1, 2, 50}
Job 4: {2, 100, 200}

Explaination: We can get the maximum profit by 
scheduling jobs 1 and 4 and maximum profit is 250.

*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct job_t
{
	int start;
	int end;
	int weight;
};

struct jobcompare
{
	bool operator ()(const job_t& lhs, const job_t& rhs) const{
		return lhs.end<rhs.end;
	}
};


int WeightedJobSchedule(vector<job_t>& jobs)
{
	int max = 0;
	vector<int> vw(jobs.size(), 0);
	std::sort(jobs.begin(), jobs.end(), jobcompare());

	for (int i = 1; i< jobs.size(); ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			if (jobs[j].end <= jobs[i].start)
			{
				if (vw[i]<vw[j] + jobs[i].weight)
				{
					vw[i] = vw[j] + jobs[i].weight;
				}
			}
		}
		if (max<vw[i])
		{
			max = vw[i];
		}
	}

	cout << max << endl;
	return 0;
}

int main()
{
	vector<job_t> jobs{ { 0, 0, 0 }, { 1, 2, 50 }, { 3, 5, 20 }, { 6, 19, 100 }, { 2, 100, 200 } };
	WeightedJobSchedule(jobs);


	return 0;

}
