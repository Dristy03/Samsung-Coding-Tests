/*
There is one spaceship. X and Y co-odinate of source of spaceship and destination spaceship is given.
There are N number of warmholes; each warmhole has 5 values. First 2 values are starting co-ordinate
of warmhole and after that value no. 3 and 4 represents ending co-ordinate of warmhole and last 5th 
value is represents cost to pass through this warmhole. Now these warmholes are bi-directional. Now 
the to go from (x1,y1) to (x2,y2) is abs(x1-x2)+abs(y1-y2). The main problem here is to find minimum 
distance to reach spaceship from source to destination co-ordinate using any number of warm-hole. 
It is ok if you wont use any warmhole.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Hole {
    int x1, y1, x2, y2, cost;
};

struct Point {
    int x, y;
};

int calculate(Point src, Point dest) {
    return (abs(src.x - dest.x) + abs(src.y - dest.y));
}

void solve(Point src, Point dest, vector<Hole> holes, int cost, vector<bool>& visited, int& ans) {

    int temp = cost + calculate(src, dest);
    ans = min(ans, temp);

    for (int i = 0; i < holes.size(); i++) {

        if (!visited[i]) {
            visited[i] = true;

            Point temp1 = { holes[i].x1, holes[i].y1 };
            Point temp2 = { holes[i].x2, holes[i].y2 };

            int val = calculate(src, temp1);
            solve(temp2, dest, holes, cost + val + holes[i].cost, visited, ans);

            val = calculate(src, temp2);
            solve(temp1, dest, holes, cost + val + holes[i].cost, visited, ans);

            visited[i] = false;
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        Point src, dest;
        cin >> src.x >> src.y >> dest.x >> dest.y;
        int n;
        cin >> n;
        vector<Hole> holes(n);
        for (int i = 0; i < n; i++)
            cin >> holes[i].x1 >> holes[i].y1 >> holes[i].x2 >> holes[i].y2 >> holes[i].cost;

        int ans = INT_MAX;
        vector<bool> visited(n, false);

        solve(src, dest, holes, 0, visited, ans);
        cout << ans << endl;
    }

    return 0;
}
