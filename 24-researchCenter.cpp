/*
A Research team want to establish a research center in a region where they found some rare-elements.
They want to make it closest to all the rare-elements as close as possible so that they can reduce
overall cost of research over there. It is given that all the rare-element’s location is connected
by roads. It is also given that Research Center can only be build on road. Team decided to assign
this task to a coder. If you feel you have that much potential.

Here is the Task :- Find the shortest of the longest distance of research center from given locations
of rare-elements.

Locations are given in the matrix cell form where 1 represents roads and 0 no road. 
Number of rare-element and their location was also given(number<=5) and order of square matrix
was less than equal to (20).

Input - 
1
5 2
4 3
3 4
1 1 0 0 0
1 1 0 0 0
1 1 1 1 1
1 1 1 0 1
1 1 1 1 1

Output - 
1
*/



#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

struct node {
    int x, y, level;
};

vector<vector<int> > a;
vector<vector<int> > vis;

int n, c;

bool isValid(int r, int c) {
    return (r >= 0 && r < n && c >= 0 && c < n);
}

int mv[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int bfs(int sx, int sy, int dx, int dy) {
    queue<node> q;
    q.push({sx, sy, 0});
    vis[sx][sy] = 1;

    while (!q.empty()) {
        node temp = q.front();
        q.pop();

        if (temp.x == dx && temp.y == dy)
            return temp.level;

        for (int k = 0; k < 4; k++) {
            int valx = temp.x + mv[k][0];
            int valy = temp.y + mv[k][1];
            int lvl = temp.level + 1;

            if (isValid(valx, valy) && a[valx][valy] == 1 && vis[valx][valy] == 0) {
                q.push({valx, valy, lvl});
                vis[valx][valy] = 1;
            }
        }
    }

    return INT_MAX;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> c;

        a.assign(n, vector<int>(n));
        vis.assign(n, vector<int>(n, 0));

        vector<vector<int> > rare(c, vector<int>(2));

        for (int i = 0; i < c; i++) {
            cin >> rare[i][0] >> rare[i][1];
            rare[i][0]--;  
            rare[i][1]--;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> a[i][j];
            }
        }

        int ans = INT_MAX;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (a[i][j] == 1) {
                    int temp = 0;
                    for (int k = 0; k < c; k++) {
                        vis.assign(n, vector<int>(n, 0));
                        int res = bfs(i, j, rare[k][0], rare[k][1]);
                        temp = max(res, temp);
                    }

                    ans = min(ans, temp);
                }
            }
        }

        cout << ans << endl;
    }

    return 0;
}
