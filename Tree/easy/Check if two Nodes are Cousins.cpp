/*
Check if two Nodes are Cousins 
https://practice.geeksforgeeks.org/problems/check-if-two-nodes-are-cousins/1/?ref=self
Given the binary Tree and the two nodes say ‘a’ and ‘b’, determine whether the two node 
values are cousins of each other or not.

Two nodes value are cousins of each other if they are at same level and have different parents.

Note:The Input/Ouput format and Example given are used for system's internal purpose, 
and should be used by a user for Expected Output only. 
As it is a function problem, hence a user should not read any input from stdin/console. 
The task is to complete the function specified, and not to write the full code.

Input:
First line consists of T test cases. First line consists of a integer N denoting number of nodes. 
Second line consists of N triplets consisting of 2 integers and a character. 
Third line consists of 2 integers to check whether they are cousins or not.

Output:
Single line output, print "1" if they are cousins else "0". You don't have to print just return true or false.

Constraints:
1<=T<=100
1<=N<=100

Example:
Input:
2
2
1 2 L 1 3 R
2 3
4
1 2 L 1 3 R 3 4 R 2 5 L
4 5
Output:
0
1

*/


//Complete the function below
//Node is as follows:
struct Node{
  int data;
  Node *left,*right;
};

bool ifCousin(Node *root,Node *a,Node *b)
{
   //add code here.
}