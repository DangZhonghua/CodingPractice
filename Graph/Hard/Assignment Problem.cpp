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

19 22 22 79 31 2 77 47 8 28 9 57 54 81 18 8 2 61 78 98 51 47 63 55 7 93 27 59 49 24 56 27 4 22 70 68 93 75 68 35 68 13 27 80 29 87 9 72 36 87 60 76 5 98 5 37 50 29 52 73 18 17 77 95 87 68 9 9 29 94 93 28 25 65 62 50 73 77 22 92 1 71 94 71 71 36 36 20 66 88 95 76 23 39 84 73 96 28 19 50 54 81 31 67 50 2 34 65 22 77 16 51 100 24 30 17 27 45 54 60 14 43 29 6 50 66 80 43 43 93 23 52 13 54 7 87 95 18 70 100 40 77 40 30 53 16 60 68 19 48 88 37 73 86 69 10 13 74 26 84 88 9 14 18 51 38 44 52 27 34 39 40 95 6 66 35 97 29 49 16 57 3 17 96 37 29 37 81 94 42 73 33 75 34 31 65 44 25 20 19 68 21 48 19 83 96 57 37 78 72 41 63 19 40 50 44 81 4 61 22 8 55 98 88 29 52 51 87 4 78 35 75 49 73 50 44 69 14 66 33 33 37 11 95 80 88 82 46 97 62 14 13 67 33 97 47


*/

/*
Solution: This is optimal bipartite graph matching problem which can be solved by 'Hungarian Method'

Refer to:
https://en.wikipedia.org/wiki/Hungarian_algorithm
https://en.wikipedia.org/wiki/Bipartite_graph#Matching

*/

/***** Hungarian method description *****/


/*



The Hungarian algorithm
The Hungarian algorithm consists of the four steps below. The first two steps are executed once, while Steps 3 and 4 are repeated until an optimal assignment is found. The input of the algorithm is an n by n square matrix with only nonnegative elements.

Step 1: Subtract row minima

For each row, find the lowest element and subtract it from each element in that row.

Step 2: Subtract column minima

Similarly, for each column, find the lowest element and subtract it from each element in that column.

Step 3: Cover all zeros with a minimum number of lines

Cover all zeros in the resulting matrix using a minimum number of horizontal and vertical lines.
If n lines are required, an optimal assignment exists among the zeros. The algorithm stops.
If less than n lines are required, continue with Step 4.


Step 4: Create additional zeros

Find the smallest element (call it k) that is not covered by a line in Step 3.
Subtract k from all uncovered elements, and add k to all elements that are covered twice
(elements @intersection of two lines).



*/



#include<iostream>
#include<climits>
#include<vector>
#include<unordered_set>
#include<unordered_map>
#include<map>
#include<functional>
using namespace std;


static const int MAX = 31;


struct HunPoint
{
	int r;
	int c;
	HunPoint(int a = 0, int b = 0)
	{
		r = a;
		c = b;
	}
};

struct HunLine
{
	HunPoint s;
	HunPoint e;
	bool row;
};

bool isHorizontalLine(HunLine& line)
{
	if (line.s.r == line.e.r)
	{
		return true;
	}
	return false;
}
struct zeroprop
{
	int nZeros;
	bool bRow;
	zeroprop(int n, bool b)
	{
		nZeros = n;
		bRow = b;
	}
};

class zeropropComp
{
public:
	zeropropComp(){};
	~zeropropComp(){};
public:
	bool operator () (const zeroprop& lhs, const zeroprop& rhs) const
	{
		if (lhs.nZeros > rhs.nZeros)
		{
			return true;
		}
		else if (lhs.nZeros == rhs.nZeros)
		{
			if (lhs.bRow&&!rhs.bRow)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		return false;
	}
};

struct  lineprop
{
	bool  isRow;
	int   number;
	lineprop(bool b, int num)
	{
		isRow = b;
		number = num;
	};
	lineprop(const lineprop& rhs)
	{
		isRow = rhs.isRow;
		number = rhs.number;
	};
	lineprop& operator =(const lineprop& rhs)
	{
		isRow = rhs.isRow;
		number = rhs.number;
		return *this;
	};
};

int Hungarian_OutputMatrix(int costm[MAX][MAX], int N)
{
	cout << "###############################\n";
	for (int r = 0; r < N; ++r)
	{
		printf("%4d:", r);
		for (int c = 0; c < N; ++c)
		{
			printf("%4d", costm[r][c]);
		}
		cout << endl;
	}
	cout << endl;

	cout << "###############################\n";



	return 0;
}

int Hungarian_DFS(int costm[MAX][MAX], vector<int> &rvisited, vector<int>& cvisited, int N, int u, int v, vector<HunPoint>& assignment)
{
	HunPoint point;
	point.r = u;
	point.c = v;
	assignment.push_back(point);
	if (assignment.size() == N)
	{
		return 0;
	}
	rvisited[u] = 1;
	cvisited[v] = 1;

	for (int r = 0; r < N; ++r)
	{
		if (v + 1 < N && !rvisited[r] && !cvisited[v + 1] && 0 == costm[r][v + 1])
		{
			Hungarian_DFS(costm, rvisited, cvisited, N, r, v + 1, assignment);
			if (assignment.size() == N)
			{
				break;
			}
			else
			{
				assignment.pop_back();
			}
		}

	}

	rvisited[u] = 0;
	cvisited[v] = 0;

	return 0;
}

int Hungarian_genAssignment(int costm[MAX][MAX], int N, vector<HunPoint>& assignment)
{
	vector<int> rowvisted;
	vector<int> colvisted;
	for (int i = 0; i < N; ++i)
	{
		rowvisted.push_back(0);
	}
	colvisted = rowvisted;

	for (int r = 0; r < N; ++r)
	{
		if (0 == costm[r][0])
		{
			Hungarian_DFS(costm, rowvisted, colvisted, N, r, 0, assignment);
			if (assignment.size() == N)
			{
				break;
			}
			assignment.clear();
		}

	}

	return 0;
}

int Hungarian_AdjustCost(int costm[MAX][MAX], int N, vector<HunLine>& lines)
{
	unordered_set<int> rowlines;
	unordered_set<int> collines;
	for (int i = 0; i < lines.size(); ++i)
	{
		if (isHorizontalLine(lines[i]))
		{
			rowlines.insert(lines[i].s.r);
		}
		else
		{
			collines.insert(lines[i].s.c);
		}
	}
	//select the minimum value which is not covered by any lines.
	int min = INT_MAX;

	for (int r = 0; r < N; ++r)
	{
		if (rowlines.end() != rowlines.find(r))
		{
			continue;
		}
		for (int c = 0; c<N; ++c)
		{
			if (collines.end() != collines.find(c))
			{
				continue;
			}
			if (min > costm[r][c])
			{
				min = costm[r][c];
			}
		}
	}
	//subtract this minimum value from every uncovered rows.
	for (int r = 0; r < N; ++r)
	{
		if (rowlines.end() != rowlines.find(r))
		{
			continue;
		}
		for (int c = 0; c < N; ++c)
		{
			if (collines.end() != collines.find(c))
			{
				continue;
			}
			costm[r][c] -= min;
		}
	}
	//add this minimum value to these covered columns.

	for (int c = 0; c < N; ++c)
	{
		if (collines.end() == collines.find(c))
		{
			continue;
		}
		for (int r = 0; r < N; ++r)
		{
			if (rowlines.end() == rowlines.find(r))
			{
				continue;
			}
			costm[r][c] += min;
		}
	}
	cout << "adjust: the minimum value is: " << min << " the length is:" << lines.size() << endl;
	return 0;
}

int Hungarian_DFSLines(int costm[MAX][MAX], int N, vector<HunPoint>&  maxAssignment, vector<HunPoint>& assignment,
	vector<int>& rowvisted, vector<int>& colvisted, int r, int c)
{
	assignment.push_back(HunPoint(r, c));

	if (maxAssignment.size() < assignment.size())
	{
		maxAssignment = assignment;
	}
	if (maxAssignment.size() == N)
	{
		return 0;
	}
	rowvisted[r] = 1;
	colvisted[c] = 1;

	bool bExistZero = false;
	int col = c;
	while (!bExistZero && col + 1 < N)
	{
		for (int row = 0; row < N; ++row)
		{
			if (0 == rowvisted[row] && 0 == colvisted[col + 1] && 0 == costm[row][col + 1])
			{
				bExistZero = true;
				Hungarian_DFSLines(costm, N, maxAssignment, assignment, rowvisted, colvisted, row, col + 1);
				assignment.pop_back();
				if (maxAssignment.size() == N)
				{
					break;
				}
			}
		}
		++col;
	}
	rowvisted[r] = 0;
	colvisted[c] = 0;
	return 0;
}

int Hungarian_genlinesV4(int costm[MAX][MAX], int N, vector<HunPoint>&  maxAssignment, vector<HunLine>& lines)
{
	vector<int> rowzero;
	vector<int> colzero;
	vector<int> rowsline;
	vector<int> colsline;
	vector<int> markrow;
	vector<int> markcol;
	for (int i = 0; i < N; ++i)
	{
		rowzero.push_back(0);
	}
	colzero		= rowzero;
	rowsline	= rowzero;
	colsline	= rowzero;
	markrow		= rowzero;
	markcol		= rowzero;

	for (int r = 0; r < N; ++r)
	{
		for (int c = 0; c < N; ++c)
		{
			if (0 == costm[r][c])
			{
				rowzero[r] += 1;
				colzero[c] += 1;
			}
		}
	}
	
	for (int i = 0; i < maxAssignment.size(); ++i)
	{
		rowsline[maxAssignment[i].r] = 1;
		//colsline[maxAssignment[i].c] = 1;
	}
	for (int c = 0; c < N; ++c)
	{
		bool bNotCovered = false;
		for (int r = 0; r < N; ++r)
		{
			if (0 == costm[r][c])
			{
				if (0 == rowsline[r])
				{
					bNotCovered = true;
					break;
				}
			}
		}
		if (bNotCovered)
		{
			colsline[c] = 1;
			for (int row = 0; row < N; ++row)
			{
				if (0 == costm[row][c])
				{
					rowzero[row] -= 1;
					if (0 == rowzero[row])
					{
						rowsline[row] = 0;
					}
				}
			}
		}
	}
	
	for (int i = 0; i < N; ++i)
	{
		if (rowsline[i])
		{
			HunLine l;
			l.row = true;
			l.s.c = 0;
			l.s.r = i;
			
			l.e.c = N - 1;
			l.e.r = i;
			lines.push_back(l);
		}
		if (colsline[i])
		{
			HunLine l;
			l.row = false;
			l.s.r = 0;
			l.s.c = i;
			l.e.r = N - 1;
			l.e.c = i;
			lines.push_back(l);
		}
	}

	return 0;
}

int Hungarian_drawlinesV4(int costm[MAX][MAX], int N, vector<HunLine>& lines)
{
	vector<HunPoint>  maxAssignment;
	vector<HunPoint> assignment;


	vector<int> rowvisted;
	vector<int> colvisted;
	for (int i = 0; i < N; ++i)
	{
		rowvisted.push_back(0);
	}
	colvisted = rowvisted;

	bool bExistZero = false;
	int col = 0;
	while (!bExistZero &&  col < N)
	{
		for (int r = 0; r < N; ++r)
		{
			if (0 == costm[r][col])
			{
				bExistZero = true;
				Hungarian_DFSLines(costm, N, maxAssignment, assignment, rowvisted, colvisted, r,col);
			}
			if (maxAssignment.size() == N)
			{
				break;
			}
			assignment.clear();
		}
		++col;
	}
	cout << maxAssignment.size() << endl;
	Hungarian_genlinesV4(costm, N, maxAssignment, lines);
	//if (maxAssignment.size() == N)
	{
		for (int i = 0; i < maxAssignment.size(); ++i)
		{
			cout << maxAssignment[i].r << " " << maxAssignment[i].c << endl;
		}

	}

	return 0;
}

int outputlines(vector<HunLine>& lines)
{
	for (int i = 0; i < lines.size(); ++i)
	{
		cout << (lines[i].row ? "H" : "V") << " [ " << lines[i].s.r << " : " << lines[i].s.c << " ] # [ " << lines[i].e.r << " : " << lines[i].e.c << " ]." << endl;
	}

	cout << endl;

	return 0;
}


int Hungarian_lines(int costm[MAX][MAX], int N, vector<HunLine>& lines)
{
	while (1)
	{
		lines.clear();
		Hungarian_OutputMatrix(costm, N);
		Hungarian_drawlinesV4(costm, N, lines);
		outputlines(lines);
		if (lines.size() < N)
		{
			Hungarian_AdjustCost(costm, N, lines);
		}
		else
		{
			//outputlines(lines);
			break;
		}
	}


	return 0;
}


int Hungarian_InitCostMatrix(int costm[MAX][MAX], int N)
{
	//operate rows of cost matrix.
	for (int r = 0; r < N; ++r)
	{
		int min = INT_MAX;
		for (int c = 0; c<N; ++c)
		{
			if (min>costm[r][c])
			{
				min = costm[r][c];
			}
		}

		for (int c = 0; c < N; ++c)
		{
			costm[r][c] -= min;
		}
	}

	//operate columns of cost matrix
	for (int c = 0; c < N; ++c)
	{
		int min = INT_MAX;
		for (int r = 0; r< N; ++r)
		{
			if (min>costm[r][c])
			{
				min = costm[r][c];
			}
		}

		for (int r = 0; r < N; ++r)
		{
			costm[r][c] -= min;
		}
	}

	return 0;
}

int Hungarian_genCost(int cost[MAX][MAX], int N, vector<HunPoint>& assignment)
{
	int minicost = 0;

	for (int i = 0; i < assignment.size(); ++i)
	{
		//cout << assignment[i].r << ":" << assignment[i].c << endl;
		minicost += cost[assignment[i].r][assignment[i].c];
	}


	return minicost;
}

int Hungarian_algorithm(int costm[MAX][MAX], int N)
{
	int cost[MAX][MAX];
	//Keep copy
	for (int r = 0; r < N; ++r)
	{
		for (int c = 0; c < N; ++c)
		{
			cost[r][c] = costm[r][c];
		}
	}

	//Init cost matrix
	Hungarian_InitCostMatrix(costm, N);
	//Draw least number of lines
	vector<HunLine> lines;
	Hungarian_lines(costm, N, lines);
	vector<HunPoint> assignment;
	Hungarian_genAssignment(costm, N, assignment);
	outputlines(lines);
	//Hungarian_OutputMatrix(costm, N);
	int miniCost = Hungarian_genCost(cost, N, assignment);

	cout << miniCost << endl;
	return 0;
}


int main()
{
	// int costm[4][4] = {
	//                 {90, 75, 75, 80},
	//                 {35, 85, 55, 65},
	//                 {125, 95, 90, 105},
	//                 {45, 110, 95, 115}
	//             };

	// int cost[MAX][MAX] = {
	//                 {90, 75, 75, 80},
	//                 {35, 85, 55, 65},
	//                 {125, 95, 90, 105},
	//                 {45, 110, 95, 115}
	//             };


	int t = 0;
	int N = 0;
	int cost[MAX][MAX];

	cin >> t;

	while (t--)
	{
		cin >> N;
		for (int r = 0; r < N; ++r)
		{
			for (int c = 0; c < N; ++c)
			{
				cin >> cost[r][c];
			}
		}
		Hungarian_algorithm(cost, N);
	}



	return 0;
}

/*

http://www.hungarianalgorithm.com/solve.php?c=43-52-67-7-81-20-77-22--78-19-91-86-20-48-67-36--52-46-44-77-75-65-30-11--68-87-5-53-20-12-90-5--13-75-67-57-38-75-99-94--77-49-80-28-19-83-96-41--69-78-52-89-5-67-71-88--72-33-99-49-14-7-10-33&random=1

http://www.hungarianalgorithm.com/solve.php?c=33-43-88-78-36-35-36-84--1-49-29-54-59-13-23-74--40-34-37-4-29-67-46-79--18-58-67-1-98-37-48-94--83-92-18-69-38-10-28-35--30-39-30-24-93-2-73-90--94-66-64-49-81-98-27-73--33-1-22-34-77-62-6-3&random=1
*/