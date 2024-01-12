/*
https://www.careercup.com/question?id=14989765
http://ideone.com/oXdBaF

Given a 2 D matrix where 1 represent the places where the frog can jump and 0 represent the empty spaces,
the frog can move freely in horizontal direction (on 1’s only) without incurring any cost (jump). 
A vertical jump from a given point of the matrix to other point on the matrix can be taken (on 1’s only) 
with cost as the number of jumps taken.
Given a source and destination, the frog has to reach the destination minimizing the cost (jump).

5
0 1 1 0 1
1 0 0 1 0
1 0 0 0 1
0 1 0 1 1
1 0 1 1 1
4 4 2 4

*/

#include <iostream>
#include <queue>
using namespace std;

struct Point {
    int x, y;
};

const int MAX_N = 105;
int n, sX, sY, tX, tY;
int mat[MAX_N][MAX_N], dis[MAX_N][MAX_N];
bool vis[MAX_N][MAX_N];

int dirX[] = {1, 0, -1, 0};
int dirY[] = {0, 1, 0, -1};

bool isValid(int i, int j) {
    return (i >= 0 && i < n && j >= 0 && j < n);
}

int calculateFrogJump() {
    queue<Point> q;
    q.push({sX, sY});
    vis[sX][sY] = true;
    dis[sX][sY] = 0;

    while (!q.empty()) {
        Point current = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int newX = current.x + dirX[i];
            int newY = current.y + dirY[i];

            if (isValid(newX, newY) && mat[newX][newY] == 1 && !vis[newX][newY]) {
                dis[newX][newY] = (i == 0 || i == 2) ? dis[current.x][current.y] : 1 + dis[current.x][current.y];
                vis[newX][newY] = true;
                q.push({newX, newY});
            }
        }
    }

    return dis[tX][tY];
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> mat[i][j];
            vis[i][j] = false;
            dis[i][j] = 0;
        }
    }

    cin >> sX >> sY >> tX >> tY;

    int ans = calculateFrogJump();
    cout<<ans<<endl;
    return 0;
}
