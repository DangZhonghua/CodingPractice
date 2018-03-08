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
    
    for(int e = 1; e<=eggs; ++e)
    {
        for(int f = 1; f<=floors; ++f)
        {
            int min = 0;
            int max = INT_MAX;
            for(int k = 1; k<=f; ++k)
            {
                min = M[e-1][k-1]> M[e][f-k]?  M[e-1][k-1]:M[e][f-k]
                if(min<max)
                {
                    max = min;
                }
            }
            edp[e][f] = 1+max;
        }
    }

    cout<<edpM[eggs][floors]<<endl;


    return 0;
}