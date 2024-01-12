/*
There is an island surrounded by oil mines. You will be given n companies and m oil mines having values.
You have to distribute the mines to "n" companies in fair manner. Remember the companies can have oil 
mines adjacent to each other and not in between of each others.After distributing them compute the 
difference of oil mines from the company getting highest and company getting lowest. This number 
should be minimum.(then only the distribution can be termed as fair).

Input 
2 
2 4 
6 13 10 2 
2 4 
6 10 13 2 

output 
5 
1
*/

#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>
using namespace std;

int companies, mines, ans;

void calculateOilMines(int i, vector<int>& oilMines, vector<bool>& visited, int minV, int maxV, int sum,
                        int nodes, int &ans) {

    if (visited[i]) {
        int newMin = min(sum, minV);
        int newMax = max(sum, maxV);

        if (nodes == companies - 1) {
            ans = min(ans, newMax - newMin);
        }
        return;
    }

    visited[i] = true;
    int j = (i + 1) % mines;

    calculateOilMines(j, oilMines, visited, minV, maxV, sum + oilMines[i], nodes, ans);

    int newMin = min(sum, minV);
    int newMax = max(sum, maxV);

    calculateOilMines(j, oilMines, visited, newMin, newMax, oilMines[i], nodes + 1, ans);

    visited[i] = false;
    return;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> companies >> mines;

        vector<int> oilMines(mines);
        vector<bool> visited(mines, false);

        for (int i = 0; i < mines; i++) {
            cin >> oilMines[i];
        }

        ans = INT_MAX;
        for (int i = 0; i < mines; i++)
            calculateOilMines(i, oilMines, visited, INT_MAX, INT_MIN, 0, 0, ans);

        cout << ans << endl;
    }
    return 0;
}
