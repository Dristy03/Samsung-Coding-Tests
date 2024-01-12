/*
Mr. Kim has to deliver refrigerators to N customers. From the office, he is going to visit all the customers and then return to his home. 
Each location of the office, his home, and the customers is given in the form of integer coordinates (x,y) (0≤x≤100, 0≤y≤100) . 
The distance between two arbitrary locations (x1, y1) and (x2, y2) is computed by |x1-x2| + |y1-y2|, where |x| denotes the absolute value 
of x; for instance, |3|=|-3|=3. The locations of the office, his home, and the customers are all distinct. You should plan an optimal way 
to visit all the N customers and return to his among all the possibilities.
You are given the locations of the office, Mr. Kim’s home, and the customers; the number of the customers is in the range of 5 to 10. 
Write a program that, starting at the office, finds a (the) shortest path visiting all the customers and returning to his home. 
Your program only have to report the distance of a (the) shortest path.

Constraints

5≤N≤10. Each location (x,y) is in a bounded grid, 0≤x≤100, 0≤y≤100, and x, y are integers.

3
5
0 0 100 100 70 40 30 10 10 5 90 70 50 20
6
88 81 85 80 19 22 31 15 27 29 30 10 20 26 5 14
10
39 9 97 61 35 93 62 64 96 39 36 36 9 59 59 96 61 7 64 43 43 58 1 36

#1 200

#2 304

#3 366

*/


#include<iostream>
#include<climits>
#include<algorithm>
#include<vector>
using namespace std;

int n, ans;
vector<int> x, y;

int dist(int i, int j) {
    return (abs(x[i] - x[j]) + abs(y[i] - y[j]));
}

void optimalPath(int current, vector<bool>& visited, int nodes, int value) {
    if (nodes == n) {
        ans = min(ans, value + dist(current, n + 1));
        return;
    }

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            visited[i] = true;
            optimalPath(i, visited, nodes + 1, value + dist(current, i));
            visited[i] = false;
        }
    }
}

int main() {
    int tCases;
    cin >> tCases;

    for (int i = 0; i < tCases; i++) {
        ans = INT_MAX;
        cin >> n;
        x.resize(n + 2);
        y.resize(n + 2);

        cin >> x[n + 1] >> y[n + 1] >> x[0] >> y[0];

        for (int i = 1; i <= n; i++) {
            cin >> x[i] >> y[i];
        }

        vector<bool> visited(n + 2, false);
        optimalPath(0, visited, 0, 0);

        cout << "#" << i + 1 << " " << ans << endl;
    }

    return 0;
}
