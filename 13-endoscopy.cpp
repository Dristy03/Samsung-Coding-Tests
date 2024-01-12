/*
Anurag, a CSE student from MANIT developed an endoscope to explore inner part of ruined water pipes. It is possible explore the inner part of the pipes 
putting the endoscope into a certain part of the pipe. The endoscope can be moved in the pipes only. Meanwhile, when the pipes are connected to each 
other, if the length of the endoscope is long enough to explore, it is able to inspect the connected pipe. However, we cannot observe every pipe 
because the length of the endoscope is limited.

When the map of the ground water pipe, the location where the endoscope to out in, and the length of the endoscope is given, calculate the number of 
pipe which are available to explore. Length of endoscope means the range upto which endoscope can explore. There are seven kind of pipes, and 
description for each pipe are shown below


Fig 1 Shows an example of a map of ground water pipes. In this case, the height of the map is 5, and the width is 6 If a certain point where the 
endoscope to put in is given as (2,1), it means the vertical location will be 2, and the horizontal location will be 1, shown as a red highlighted 
pipe in fig 2. If the length of the endoscope is 1, we can explore only one water pipe which is at the intersection point If the length of the 
endoscope is 2, we can explore 3 water pipes including a blue highlighted pipe and a red marked pipe with the endoscope Fig-3 . If the length of the 
endoscope is 3, we can explore 5 water pipes total Fig-4


INPUT:

In the first line, T, the number of total test cases is given. From the second line, T test cases are given. In the first line of each test case, N, the height of the map of the ground water pipes, M, the width, R, the vertical location of the water pipe where to put in the endoscope, C, the horizontal location of it, and the length of the endoscope L are given. In the following N lines information of the map of ground water pipe is given. Each line has M numbers. Each number (from 1 to 7) means the type of water pipe for that point. 0 means there is no water pipe buried in that place.

OUTPUT:

Print the respective answer for T test cases in total for T lines. The answer is the number of water pipes which is available to observe using the endoscope.

CONSTRAINTS:

1≤ T ≤100

1≤ N, M ≤1000

0≤ X < N

0≤ Y < M

1≤ L ≤ 1000000

Sum of NxM over all the test cases does not exceed 1000000.
*/

#include<iostream>
#include<queue>
using namespace std;

int row, col, X, Y, L;
int map[1000][1000], visited[1000][1000];

struct node {
    int x, y, l;
};

bool valid(int x, int y) {
    return (x >= 0 && x < row && y >= 0 && y < col);
}

bool left(int x, int y) {
    return (map[x][y] == 1 || map[x][y] == 3 || map[x][y] == 6 || map[x][y] == 7);
}

bool right(int x, int y) {
    return (map[x][y] == 1 || map[x][y] == 3 || map[x][y] == 4 || map[x][y] == 5);
}

bool up(int x, int y) {
    return (map[x][y] == 1 || map[x][y] == 2 || map[x][y] == 4 || map[x][y] == 7);
}

bool down(int x, int y) {
    return (map[x][y] == 1 || map[x][y] == 2 || map[x][y] == 6 || map[x][y] == 5);
}

int solve(int x, int y, int l) {
    int ans = 0;
    queue<node> q;
    q.push({x, y, l});
    visited[x][y] = 1;
    while (!q.empty()) {
        node cur = q.front();
        q.pop();
        int x = cur.x;
        int y = cur.y;
        int l = cur.l;
        if (l == 0) continue;
        ans++;
        if (valid(x, y - 1) && left(x, y) && right(x, y - 1) && visited[x][y - 1] == 0) {
            q.push({x, y - 1, l - 1});
            visited[x][y - 1] = 1;
        }
        if (valid(x, y + 1) && right(x, y) && left(x, y + 1) && visited[x][y + 1] == 0) {
            q.push({x, y + 1, l - 1});
            visited[x][y + 1] = 1;
        }
        if (valid(x - 1, y) && up(x, y) && down(x - 1, y) && visited[x - 1][y] == 0) {
            q.push({x - 1, y, l - 1});
            visited[x - 1][y] = 1;
        }
        if (valid(x + 1, y) && down(x, y) && up(x + 1, y) && visited[x + 1][y] == 0) {
            q.push({x + 1, y, l - 1});
            visited[x + 1][y] = 1;
        }
    }
    return ans;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> row >> col >> X >> Y >> L;

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                cin >> map[i][j];
                visited[i][j]=0;
            }
        }
        if (map[X][Y] > 0) {
            cout << solve(X, Y, L) << endl;
        } else cout << 0 << endl;

    }
    return 0;
}
