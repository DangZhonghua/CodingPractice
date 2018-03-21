//https://practice.geeksforgeeks.org/problems/find-the-number-of-islands/1

#define MAX 100

int visit[MAX][MAX];


//eight direction search.
int dfsVistit(int A[MAX][MAX],int visit[MAX][MAX], int N, int M, int r, int c)
{
    //The search eight neighbours method is clever: GeeksForGeeks code example.
    // These arrays are used to get row and column numbers of 8 neighbours of a given cell
    static int rowNbr[] = {-1, -1, -1,  0, 0,  1, 1, 1};
    static int colNbr[] = {-1,  0,  1, -1, 1, -1, 0, 1};
 
    // Mark this cell as visited
    visit[r][c] = true;
 
    // Recur for all connected neighbours
    for (int k = 0; k < 8; ++k)
    {   
        int row = r+rowNbr[k];
        int col = c+ colNbr[k];
        if(row>=0 && row<N && col>=0 && col<M && A[row][col] && !visit[row][col] )
        {
            dfsVistit(A,visit,N,M,row,col);
        }
    }

    return 0;
}


int subTreeCountofDFS(int A[MAX][MAX], int N, int M)
{
    int nConnectComponents = 0;

    //Initializ the visit flag.
    for(int r = 0; r<N; ++r)
    {
        for(int c = 0; c<M; ++c)
        {
            visit[r][c] = false;
        }
    }

    for(int r = 0; r<N; ++r)
    {
        for(int c = 0; c<M; ++c)
        {
            if(!visit[r][c])
            {
                ++nConnectComponents;
                dfsVistit(A,visit,N,M,r,c);
            }
        }
    }

    return nConnectComponents;
}


int findIslands(int A[MAX][MAX], int N, int M)
{
//Your code here 
return subTreeCountofDFS(A, N,M);
}