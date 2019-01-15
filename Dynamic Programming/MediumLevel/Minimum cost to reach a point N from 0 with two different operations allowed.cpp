/*

https://www.geeksforgeeks.org/minimum-cost-to-reach-a-point-n-from-0-with-two-different-operations-allowed/

Minimum cost to reach a point N from 0 with two different operations allowed
Given integers N, P and Q where N denotes the destination position. 
The task is to move from position 0 to position N with minimum cost possible and print the calculated cost. 
All valid movements are:

    From position X you can go to position X + 1 with a cost of P
    Or, you can go to the position 2 * X with a cost of Q

Examples:

    Input: N = 1, P = 3, Q = 4
    Output: 3
    Move from position 0 to 1st position with cost = 3.

    Input: N = 9, P = 5, Q = 1
    Output: 13
    Move from position 0 to 1st position with cost = 5,
    then 1st to 2nd with cost = 1,
    then 2nd to 4th with cost = 1,
    then 4th to 8th with cost = 1,
    finally 8th to 9th with cost = 5.
    Total cost = 5 + 1 + 1 + 1 + 5 = 13. 

*/