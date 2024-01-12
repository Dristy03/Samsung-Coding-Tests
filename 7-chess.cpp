/*
There is a mobile piece and a stationary piece on the N×M chessboard. 
The available moves of the mobile piece are the same as set out in the image below. 
You need to capture the stationary piece by moving the mobile piece with the minimum amount of moves.

Write a program to find out the minimum number moves to catch a piece. 

[Input]
Several test cases can be included in the inputs. T, the number of cases is given in the first row of the
inputs. After that, the test cases as many as T (T ≤ 20) are given in a row. 
N, the numbers of the rows and M, the number of columns of the chessboard are given in the first row of
each test case. 
R & C is the location information of the attacking piece and S & K is the location of the defending pieces 
and are given in the row at the second line. However, the location of the uppermost end of the left end 
is (1, 1)

[Output]
For each test case, you should print "Case #T" in the first line where T means the case number.

For each test case, you should output the minimum number of movements to catch a defending piece at the 
first line of each test case. If not moveable, output equals ‘-1’. 

[I/O Example]

Input 
2
9 9
3 5 2 8
20 20
2 3 7 9

Output
Case #1
2
Case #2
5 
*/

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

struct Position {
    int x, y, level;
};

const int moves[8][2] = {{-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}};

bool isValid(int x, int y, int n, int m, vector<vector<int> >& chessboard) {
    return (x >= 1 && x <= n && y >= 1 && y <= m && chessboard[x][y] == 0);
}

int main() {
    int T;
    cin >> T;

    for (int t = 1; t <= T; t++) {
        int n, m, r1, c1, r2, c2;
        cin >> n >> m >> r1 >> c1 >> r2 >> c2;

        vector<vector<int> > chessboard(n + 1, vector<int>(m + 1, 0));
        queue<Position> q;

        Position start = {r1, c1, 0};
        q.push(start);
        chessboard[start.x][start.y] = 1;

        int steps = -1;

        while (!q.empty()) {
            Position current = q.front();
            q.pop();

            for (int k = 0; k < 8; k++) {
                int nextX = current.x + moves[k][0];
                int nextY = current.y + moves[k][1];
                int nextLevel = current.level + 1;

                if (isValid(nextX, nextY, n, m, chessboard)) {
                    if (nextX == r2 && nextY == c2) {
                        steps = nextLevel;
                        break;
                    }

                    Position nextPosition = {nextX, nextY, nextLevel};
                    q.push(nextPosition);
                    chessboard[nextX][nextY] = 1;
                }
            }

            if (steps != -1) {
                break;
            }
        }

        cout << "Case #" << t << endl;
        cout << steps << endl;
    }

    return 0;
}
