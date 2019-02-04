/*
https://www.geeksforgeeks.org/check-if-a-word-exists-in-a-grid-or-not/
Check if a word exists in a grid or not

Given a 2D grid of characters and a word, the task is to check if that word exists in the grid or not.
 A word can be matched in 4 directions at any point.

The 4 directions are, Horizontally Left and Right, Vertically Up and Down.
Examples:

Input:  grid[][] = {"axmy",
                    "bgdf",
                    "xeet",
                    "raks"};
Output: Yes

a x m y
b g d f
x e e t
r a k s

Input: grid[][] = {"axmy",
                   "brdf",
                   "xeet",
                   "rass"};
Output : No


*/

int main() 
{ 
    char grid[r] = { "axmy", 
                        "bgdf", 
                        "xeet", 
                        "raks" }; 
  
    // Function to check if word exists or not 
    if (checkMatch(grid, "geeks", r, c)) 
        cout << "Yes"; 
    else
        cout << "No"; 
  
 return 0; 
  
} 