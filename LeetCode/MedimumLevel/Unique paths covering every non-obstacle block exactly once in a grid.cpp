/*
https://www.geeksforgeeks.org/unique-paths-covering-every-non-obstacle-block-exactly-once-in-a-grid/
Unique paths covering every non-obstacle block exactly once in a grid

Unique paths covering every non-obstacle block exactly once in a grid

Given a grid grid[][] with 4 types of blocks:

    1 represents the starting block. There is exactly one starting block.
    2 represents the ending block. There is exactly one ending block.
    0 represents empty block we can walk over.
    -1 represents obstacles that we cannot walk over.

The task is to count the number of paths from the starting block to the ending block such that every non-obstacle block is covered exactly once.

Examples:

Input: grid[][] = 
    {
        {1, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 2, -1} 
    }
    Output: 2
    Following are the only paths covering all the non-obstacle blocks:

Input: grid[][] = 
{
    {1, 0, 0, 0},
    {0, 0, 0, 0},
    {0, 0, 0, 2} 
}
Output: 4 

*/