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

int 