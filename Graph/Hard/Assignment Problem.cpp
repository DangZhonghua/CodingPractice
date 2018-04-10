/*

https://practice.geeksforgeeks.org/problems/assignment-problem/0
You are the head of a firm and you have to assign jobs to people.
You have N persons working under you and you have N jobs that are to be done by these persons.
Each person has to do exactly one job and each job has to be done by exactly one person.
Each person has his own capability (in terms of time taken) to do any particular job.
Your task is to assign the jobs to the persons in such a way that the total time taken is minimum.
A job can be assigned to only one person and a person can do only one job.

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow.
The first line of each test case contains an integer N, where N is the number of jobs and the number of persons under you. The next line contains N2 positive integers. The first N of these integers denote the time taken by the first person to do the N jobs, the next N integers denote the time taken by the second person to do the N jobs and so on till the Nth person.

Output:
For each test case in a new line, print the time taken in the best possible assignment that you can do.  

Constrains:
1<=T<=100
1<=N<=30
1<=Time taken to do a job <=100
 

Example:
Input:
2
2
3 5 10 1
3
2 1 2 9 8 1 1 1 1

Output:
4
3

Explanation: 
The first person takes times 3 and 5 for jobs 1 and 2 respectively. 
The second person takes times 10 and 1 for jobs 1 and 2 respectively. 
We can see that the optimal assignment will be to give job 1 to person 1 and job 2 to person 2 for a total for 3 + 1 = 4.

*/

/*
Solution: This is optimal bipartite graph matching problem which can be sloved by 'Hungarian Method'

Refer to:
https://en.wikipedia.org/wiki/Hungarian_algorithm
https://en.wikipedia.org/wiki/Bipartite_graph#Matching

*/

#include<iostream>
#include<climits>
#include<vector>
using namespace std;


static const int max = 31;


struct HunPoint
{
    int r;
    int c;
};

struct HunLine
{
    HunPoint s;
    HunPoint e;
};



int Hungarian_AdjustCost(int costm[max][max],int N, vector<HunLine>& lines)
{


    return 0;
}


int Hungarian_lines(int costm[max][max], int N, int& lineNum)
{



    return 0;
}

int Hungarian_drawlines(int costm[max][max], int N)
{

    int nlines = 0;
    while(1)
    {
        nlines = 0;
       Hungarian_lines(costm,N,nlines);
        if(nlines<N)
        {
            
        }
        else
        {
         break;    
        }
    }

    return 0;
}

int Hungarian_InitCostMatrix(int costm[max][max], int N)
{
    //operate rows of cost matrix.
    for(int r = 0; r<N; ++r)
    {
        int min = INT_MAX;
        for(int c = 0; c<N; ++c)
        {
            if(min>costm[r][c])
            {
                min = costm[r][c];
            }
        }

        for(int c = 0; c<N; ++c)
        {
            costm[r][c] -= min;
        }
    }

    //operate columns of cost matrix
    for(int c = 0; c<N; ++c)
    {
        int min = INT_MAX;
        for(int r = 0; r< N; ++r)
        {
            if(min>costm[c][r])
            {
                min = costm[c][r];
            }
        }

        for(int r = 0; r<N; ++r)
        {
            costm[c][r] -= min;
        }
    }

    return 0;
}

int Hungarian_algorithm(int costm[max][max], int N)
{
    //Init cost matrix
    Hungarian_InitCostMatrix(costm, N);


    //Draw least number of lines    
    Hungarian_drawlines(costm,N);



    return 0;
}


int main()
{


    return 0;
}