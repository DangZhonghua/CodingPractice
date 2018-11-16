/*
Find pair of rows in a binary matrix that has maximum bit difference
https://www.geeksforgeeks.org/find-pair-rows-binary-matrix-maximum-bit-difference/

Given a Binary Matrix. The task is to find the pair of row in the Binary matrix that has maximum bit difference

Examples:

Input: mat[][] = {{1, 1, 1, 1},
                 {1, 1, 0, 1},
                 {0, 0, 0, 0}};
Output : (1, 3)
Bit difference between row numbers 1 and 3
is maximum with value 4. Bit difference 
between 1 and 2 is 1 and between 2 and 3
is 3.

Input: mat[][] = {{1 ,1 ,1 ,1 }
                  {1 ,0, 1 ,1 }
                  {0 ,1 ,0 ,0 }
                  {0, 0 ,0 ,0 }} 
Output : (2, 3)
Bit difference between rows 2 and 3 is 
maximum which is 4.

Input: mat[][] = {{1 ,0 ,1 ,1 }
                  {1 ,1 ,1 ,1 }
                  {0 ,1 ,0 ,1 }
                  {1, 0 ,0 ,0 }} 
Output : (1, 3) or (2  ,4 ) or (3 ,4 ) 
They all are having  maximum bit difference
that is 3




*/