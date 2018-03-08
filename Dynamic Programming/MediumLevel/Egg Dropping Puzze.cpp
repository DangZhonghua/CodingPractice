#include <iostream>
#include <climits>
using namespace std;

 const int M = 50;

int edp[M][M];

int minCount2JudgeFloors(int eggs, int floors);


int main(int argc, char* argv[])
{
    int t       = 0;
    int eggs    = 0;
    int floors  = 0;
    
    cin>>t;

    while(t>0)
    {
        --t;
        cin>>eggs;
        cin>>floors;
        minCount2JudgeFloors(eggs, floors);
    }

    return 0;
}

int minCount2JudgeFloors(int eggs, int floors)
{
    for(int i = 0; i < M; ++i)
    {
        for(int j = 0; j< M; ++j)
        {
            edp[i][j] = 0;
        }
    }

    for(int f = 0; f<= floors; ++f)
    {
        edp[1][f] = f;
    }
    for(int e = 1; e<=eggs; ++e)
    {
        edp[e][1] = 1;
    }
    
    for(int e = 2; e<=eggs; ++e)
    {
        for(int f = 2; f<=floors; ++f) //Select the minimum trial count for certain floor
        {
            int min = INT_MAX;
            int maxpart = 0;
            for(int k = 1; k<=f; ++k)//From kth floor to try: which is the master, select the minimum among these maximum
            {
                maxpart = edp[e-1][k-1]> edp[e][f-k]?  edp[e-1][k-1]:edp[e][f-k]; 
                if(min>maxpart)
                {
                    min = maxpart;
                }
            }
            edp[e][f] = 1+min;
        }
    }

    cout<<edp[eggs][floors]<<endl;


    return 0;
}