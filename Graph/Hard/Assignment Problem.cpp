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
};

struct HunLine
{
    HunPoint s;
    HunPoint e;
    bool row;
};

bool isHorizontalLine(HunLine& line)
{
    if(line.s.r == line.e.r)
    {
        return true;
    }
    return false;
}

int Hungarian_genAssignment(int costm[MAX][MAX],int N, vector<HunLine>& lines, vector<HunPoint>& assignment)
{

    unordered_set<int> hselect;
    unordered_set<int> vselect;
    
    for(int i = 0; i<lines.size(); ++i)
    {
        if(!isHorizontalLine(lines[i]) )
        {
            for(int r = 0; r < N; ++r)
            {
                if( 0 == costm[r][lines[i].s.c])
                {
                    if(hselect.end() == hselect.find(r) && vselect.end() == vselect.find(lines[i].s.c))
                    {
                        hselect.insert(r);
                        vselect.insert(lines[i].s.c);
                        HunPoint point;
                        point.r = r;
                        point.c = lines[i].s.c;
                        assignment.push_back(point);
                        break;
                    }
                }
            }
        }
    }

    for(int i = 0; i<lines.size(); ++i)
    {
        if(isHorizontalLine(lines[i]) )
        {
            for(int c = 0; c<N; ++c)
            {
                if(0 == costm[lines[i].s.r][c])
                {
                    if(hselect.end() == hselect.find(lines[i].s.r) && vselect.end() == vselect.find(c))
                    {
                        hselect.insert(lines[i].s.r);
                        vselect.insert(c);
                        HunPoint point;
                        point.r = lines[i].s.r;
                        point.c = c;
                        assignment.push_back(point);
                        break;
                    }
                }
            }
        }
    }

    return 0;
}

int Hungarian_AdjustCost(int costm[MAX][MAX],int N, vector<HunLine>& lines)
{
    unordered_set<int> rowlines;
    unordered_set<int> collines;
    for(int i= 0; i<lines.size(); ++i)
    {
        if(isHorizontalLine(lines[i]))
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
    
    for(int r = 0; r<N; ++r)
    {
        if(rowlines.end() != rowlines.find(r))
        {
            continue;
        }
        for(int c = 0; c<N;++c)
        {
            if(collines.end() != collines.find(c))
            {
                continue;
            }
            if(min > costm[r][c])
            {
                min = costm[r][c];
            }
        }
    }
    //subtract this minimum value from every uncovered rows.
    for(int r = 0; r<N; ++r)
    {
        if(rowlines.end() != rowlines.find(r))
        {
            continue;
        }
        for(int c = 0; c<N; ++c)
        {
            costm[r][c] -= min;
        }
    }
    //add this minimum value to these covered columns.
    
    for(int c = 0; c<N; ++c)
    {
        if(collines.end() == collines.find(c))
        {
            continue;
        }
        for(int r = 0; r<N; ++r)
        {
            costm[r][c] += min;
        }
    }

    return 0;
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
        if(lhs.nZeros>rhs.nZeros)
        {
            return true;
        }
        else if(lhs.nZeros == rhs.nZeros)
        {
            if(lhs.bRow)
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


//Draw virtual mininum number lines to cover all zeros in cost matrix
int Hungarian_drawlines(int costm[MAX][MAX], int N, vector<HunLine>& lines)
{
    
    //Use Geedy idea:let one line cover as many as zero.
    int zeros = 0;
    unordered_map<int, int> rowzeromap;
    unordered_map<int, int> columnzeromap;
    unordered_set<int>      rowlineSet;
    unordered_set<int>      columnlineSet;
  


    
    struct  lineprop
    {
        bool  isRow;
        int   number;
        lineprop(bool b, int num)
        {
            isRow = b;
            number   = num;
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



    multimap<zeroprop, lineprop, zeropropComp >      mapzerosCount2Direct;


    lines.clear();
    for(int r = 0; r< N; ++r)
    {
        for(int c = 0; c<N; ++c)
        {
            if(0 == costm[r][c])
            {
                auto itrow = rowzeromap.find(r);
                if(itrow != rowzeromap.end())
                {
                    itrow->second += 1;
                }
                else
                {
                    rowzeromap.insert(std::make_pair(r,1));
                }
               
                auto itcol = columnzeromap.find(c);
                if(itcol != columnzeromap.end())
                {
                    itcol->second += 1;
                }
                else
                {
                    columnzeromap.insert(std::make_pair(c,1));
                }

                ++zeros;
            }
        }
    }

    do
    {
        if(0 == zeros)
        {
            break;
        }
        
       for(auto itrow = rowzeromap.begin(); itrow != rowzeromap.end(); ++itrow)
       {
         mapzerosCount2Direct.insert( {zeroprop(itrow->second,true),lineprop(true,itrow->first)} );
       }

       for(auto itcol = columnzeromap.begin(); itcol != columnzeromap.end(); ++itcol)
       {
         mapzerosCount2Direct.insert( {zeroprop(itcol->second,false),lineprop(false,itcol->first)} );
       }
      

      int nlinesZero = 0;
      for(auto it = mapzerosCount2Direct.begin(); nlinesZero <= zeros && it != mapzerosCount2Direct.end(); ++it)
      {
          bool bFind = false;
          if(it->second.isRow)
          {
              
              for(int c = 0; c<N; ++c)
              {
                  if(0 == costm[it->second.number][c])
                  {
                      if(columnlineSet.end() == columnlineSet.find(c))
                      {
                          bFind = true;
                          ++nlinesZero;
                      }
                  }
              }
              if(bFind)
              {
                rowlineSet.insert(it->second.number);
                HunLine oneline;
                oneline.s.r = it->second.number;
                oneline.s.c = 0;

                oneline.e.r = it->second.number;
                oneline.e.c = N-1;
                oneline.row = true;
                lines.push_back(oneline);
              }

          }
          else
          {
            
            for(int r = 0; r<N; ++r)
            {
                if(0 == costm[r][it->second.number])
                {
                    if(rowlineSet.end() == rowlineSet.find(r))
                    {
                        bFind = true;
                        ++nlinesZero;
                    }
                }
            }
            if(bFind)
            {
              columnlineSet.insert(it->second.number); 
              HunLine oneline;
              oneline.s.r = 0;
              oneline.s.c = it->second.number;

              oneline.e.r = N-1;
              oneline.e.c = it->second.number;
              oneline.row = false;
              lines.push_back(oneline);
            }

          }    
      }


    }while(false);




    return 0;
}


int outputlines(vector<HunLine>& lines)
{
    for(int i = 0; i<lines.size(); ++i)
    {
        cout<<(lines[i].row?"H":"V")<<" [ "<<lines[i].s.r<<" : "<<lines[i].s.c<<" ] # [ "<<lines[i].e.r<<" : "<<lines[i].e.c<<" ]."<<endl;
    }
    
    cout<<endl;

    return 0;
}


int Hungarian_lines(int costm[MAX][MAX], int N,  vector<HunLine>& lines)
{
    while(1)
    {
        lines.clear();
        Hungarian_drawlines(costm,N,lines);
        outputlines(lines);
        if(lines.size()<N)
        {
            Hungarian_AdjustCost(costm,N,lines);
        }
        else
        {
            break;    
        }
    }


    return 0;
}


int Hungarian_InitCostMatrix(int costm[MAX][MAX], int N)
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
            if(min>costm[r][c])
            {
                min = costm[r][c];
            }
        }

        for(int r = 0; r<N; ++r)
        {
            costm[r][c] -= min;
        }
    }

    return 0;
}

int Hungarian_genCost(int cost[MAX][MAX],int N, vector<HunPoint>& assignment)
{
    int minicost  = 0;
    
    for(int i = 0; i<assignment.size(); ++i)
    {
        cout<<assignment[i].r<<":"<<assignment[i].c<<endl;
        minicost += cost[assignment[i].r][assignment[i].c];
    }
    

    return minicost;
}

int Hungarian_algorithm(int costm[MAX][MAX], int N)
{
    int cost[MAX][MAX];
    //Keep copy
    for(int r = 0; r<N; ++r)
    {
        for(int c = 0; c<N; ++c)
        {
            cost[r][c] = costm[r][c];
        }
    }

    //Init cost matrix
    Hungarian_InitCostMatrix(costm, N);
    //Draw least number of lines
    vector<HunLine> lines;
    Hungarian_lines(costm,N,lines);
    vector<HunPoint> assignment;
    Hungarian_genAssignment(costm, N, lines, assignment);
    
   int miniCost = Hungarian_genCost(cost,N, assignment);

    cout<<miniCost<<endl;
    return 0;
}


int main()
{
int costm[4][4] = {
                {90, 75, 75, 80},
                {35, 85, 55, 65},
                {125, 95, 90, 105},
                {45, 110, 95, 115}
            };

int cost[MAX][MAX] = {
                {90, 75, 75, 80},
                {35, 85, 55, 65},
                {125, 95, 90, 105},
                {45, 110, 95, 115}
            };


Hungarian_algorithm(cost, 4);

    return 0;
}