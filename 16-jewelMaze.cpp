/*
There is a maze that has one entrance and one exit. Jewels are placed in passages of the maze. 
You want to pick up the jewels after getting into the maze through the entrance and before getting 
out of it through the exit. You want to get as many jewels as possible, but you don’t want to take 
the same passage you used once.

When locations of a maze and jewels are given, find out the greatest number of jewels you can get 
without taking the same passage twice, and the path taken in this case.

Input
There can be more than one test case in the input file. The first line has T, the number of test cases.
Then the totally T test cases are provided in the following lines (T ≤ 10 ).

In each test case, In the first line, the size of the maze N (1 ≤ N ≤ 10) is given. 
The maze is N×N square-shaped. From the second line through N lines, information of the maze is given.
“0” means a passage, “1” means a wall, and “2” means a location of a jewel. The entrance is located 
on the upper-most left passage and the exit is located on the lower-most right passage. 
There is no case where the path from the entrance to the exit doesn’t exist.

Output
From the first line through N lines, mark the path with 3 and output it. In N+1 line, output the 
greatest number of jewels that can be picked up. Each test case must be output separately as a empty.

Input 
2 
5 
0 0 0 2 0 
2 1 0 1 2 
0 0 2 2 0 
0 1 0 1 2 
2 0 0 0 0 
6 
0 1 2 1 0 0 
0 1 0 0 0 1 
0 1 2 1 2 1 
0 2 0 1 0 2 
0 1 0 1 0 1 
2 0 2 1 0 0

Output
Case 1
3 0 3 3 3 
3 1 3 1 3  
3 0 3 2 3  
3 1 3 1 3 
3 3 3 0 3  
6

Case 2
3 1 2 1 0 0  
3 1 3 3 3 1 
3 1 3 1 3 1 
3 2 3 1 3 2 
3 1 3 1 3 1  
3 3 3 1 3 3  
4


*/

#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int n, ans;

bool isValid(int i, int j) {
    return (i >= 0 && i < n && j >= 0 && j < n);
}

int dirX[] = {1, 0, -1, 0};
int dirY[] = {0, 1, 0, -1};

void jewelMaze(vector<vector<int> > maze, int x, int y, int value, vector<vector<int> >& visited, vector<vector<int> >& path) {

    int n = maze.size();
    if (x == n - 1 && y == n - 1) {
        if (value >= ans) {
            ans = value;

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (visited[i][j]) {
                        path[i][j] = 3;
                    } else {
                        path[i][j] = maze[i][j];
                    }
                }
            }
        }
        return;
    }

    for (int i = 0; i < 4; i++) {
        int newX = x + dirX[i];
        int newY = y + dirY[i];

        if (isValid(newX, newY)) {

            if (!visited[newX][newY] && maze[newX][newY] == 0) {
                visited[newX][newY] = 1;
                jewelMaze(maze, newX, newY, value, visited, path);
                visited[newX][newY] = 0;
            }

            if (!visited[newX][newY] && maze[newX][newY] == 2) {
                visited[newX][newY] = 1;
                jewelMaze(maze, newX, newY, value + 1, visited, path);
                visited[newX][newY] = 0;
            }
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
    
        cin >> n;

        vector<vector<int> > maze(n, vector<int>(n, 0));
        vector<vector<int> > visited(n, vector<int>(n, 0));
        vector<vector<int> > path(n, vector<int>(n, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> maze[i][j];
            }
        }
        ans = INT_MIN;
        int sX = 0, sY = 0;
        visited[sX][sY] = 1;

        if (maze[sX][sY] == 2)
            jewelMaze(maze, sX, sY, 1, visited, path);
        else
            jewelMaze(maze, sX, sY, 0, visited, path);


        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout<< path[i][j]<<" ";
            }
            cout<<endl;
        }
        cout <<ans<< endl;
    }
    return 0;
}
