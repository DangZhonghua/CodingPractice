/*
Largest rectangular sub-matrix having sum divisible by k
https://www.geeksforgeeks.org/largest-rectangular-sub-matrix-sum-divisible-k/
Given a n x n matrix of integers. The problem is to find the largest area rectangular 
sub-matrix having sum divisible by the given value k.

Examples:

Input : mat[][] = { {1, 2, -1, -4},
                    {-8, -3, 4, 2},
                    {3, 8, 10, 1},
                    {-4, -1, 1, 7} }

        k = 5

Output : Area = 12
(Top, Left): (0, 0)
(Bottom, Right): (2, 3)
The sub-matrix is:
| 1, 2, -1, -4 |
| -8, -3, 4, 2 |
| 3, 8, 10, 1  |

*/

/*

Efficient Approach: Longest subarray having sum divisible by k for 1-D array can be used to 
reduce the time complexity to O(n^3). 
The idea is to fix the left and right columns one by one and find the 
longest sub-array having sum divisible by ‘k’ for contiguous rows for 
every left and right column pair. We basically find top and bottom row numbers 
(which are part of the largest sub-matrix) for every fixed left and right column pair. 
To find the top and bottom row numbers, calculate sum of elements in every row from left to right 
and store these sums in an array say temp[]. 
So temp[i] indicates sum of elements from left to right in row i. 
Now, apply Longest subarray having sum divisible by k 1D algorithm on temp[], 
and get the longest sub-array having sum divisible by ‘k’ of temp[]. 
This length would be the maximum possible length with left and right as boundary columns. 
Set the ‘top’ and ‘bottom’ row indexes for the left right column pair and calculate the area. 
In similar manner get the top, bottom, left, right indexes for other sub-matrices 
having sum divisible by ‘k’ and print the one having maximum area.


*/




#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int  LargestSubarrayDivisableByK(vector<int>& arr,  int& maxlen,int& start, int& end,int K)
{
   unordered_map<int,int> hashmodindex;
   vector<int> arrmode(arr.size(),0);
   int accsum = 0;

   for(int i = 0; i<arr.size(); ++i)
   {
        accsum += arr[i];
        arrmode[i] = ( ( accsum%K + K )%K ); //For negative mode value.
   }
   
   for(int i = 0; i<arr.size(); ++i)
   {
        if(arrmode[i] == 0)
        {
          maxlen        = i+1;
          start         = 0;
          end           = i;
        }
        else
        {
           auto it = hashmodindex.find(arrmode[i]);
          if( hashmodindex.end() != it)
          {
             // modevalue-modevalue = 0 which make it can be divisible.
             int s = it->second + 1;
             int e = i;
             if( maxlen < (e-s+1) )
             {
                maxlen = (e-s+1);
                start  = s;
                end    = e;
             }
          }
          else
          {
             hashmodindex[arrmode[i]] = i;
          }
        }
   }

  return 0;
}

int LargestSubMatrixSumDivisbleByK( vector< vector<int> >& mat,int K)
{
   int maxleft          = 0;
   int maxright         = 0;
   int maxtop           = 0;
   int maxbottom        = 0;
   int maxArea = 0;
  int R = mat.size();
  int C = mat[0].size();
  
  
  for(int leftc = 0; leftc<C; ++leftc)
  {
        vector<int> rowsum(R,0);
        for(int rightc = leftc; rightc<C; ++rightc) // the first two for loop used to form the start/end column
        {
           //Noe let's build row sum.
           for(int i = 0; i<R; ++i)
           {
                rowsum[i] += mat[i][rightc];
           }
           int start    = 0;
           int end      = 0;
           int maxlen   = 0;
           LargestSubarrayDivisableByK(rowsum,maxlen, start,end, K );
           if( maxlen ) // This mean exist the longest subarray.
           {
                if( maxArea < (end-start+1)*(rightc-leftc+1) )
                {
                  maxleft       = leftc;
                  maxright      = rightc;
                  maxtop        = start;
                  maxbottom     = end;
                  maxArea       = (end-start+1)*(rightc-leftc+1);
                }
           }
        }
  }
 
    cout<<maxArea<<endl;
    cout<<maxtop <<" "<<maxleft<<" : "<<maxbottom<<" "<<maxright<<endl;

return 0;
}


int main()
{
int     mat[4][4] = { {1, 2, -1, -4},
                    {-8, -3, 4, 2},
                    {3, 8, 10, 1},
                    {-4, -1, 1, 7} 
                 };

 int R = _countof(mat);
 int C = _countof(mat[0]);
 vector< vector<int> > mv(R, vector<int>(C,0));
 
 for(int r = 0; r< R; ++r)
 {
         for(int c = 0; c<C; ++c)
         {
                 mv[r][c] = mat[r][c];
         }
 }

int K = 5;
LargestSubMatrixSumDivisbleByK(mv,K);

return 0;
}