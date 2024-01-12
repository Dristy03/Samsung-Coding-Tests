#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>
using namespace std;

int n, m, o;
vector<int> working, operations;
unordered_map<int, unordered_map<int, int> > memo;

int eval(int prev, int curr, int op) {
    if (op == 1) return prev + curr;
    if (op == 2) return prev - curr;
    if (op == 3) return prev * curr;
    if (op == 4) return (curr == 0) ? -1 : prev / curr;
    return -1;
}

bool isDone(int prev, int curr, int Operation, int target) {
    if (Operation == 4 && curr == 0) return false;
    return (eval(prev, curr, Operation) == target);
}

int findMinTouch(int prev, int curr, int ooperation, int tou, int t) {
    if (memo.count(curr) && memo[curr].count(ooperation))
        return memo[curr][ooperation];

    if (ooperation != -1 && curr != -10000000) {
        bool k = isDone(prev, curr, ooperation, t);
        if (k && tou < o) {
            memo[curr][ooperation] = min(memo[curr][ooperation], tou + 1);
            return memo[curr][ooperation];
        }
    }
    if (prev == t && tou < o && ooperation != -1 && curr == -10000000) {
        memo[curr][ooperation] = min(memo[curr][ooperation], tou);
        return memo[curr][ooperation];
    }
    if (ooperation == -1 && curr == t && tou < o) {
        memo[curr][ooperation] = min(memo[curr][ooperation], tou);
        return memo[curr][ooperation];
    }
    if (tou > o) return INT_MAX;

    int result = INT_MAX;

    for (int i = 0; i < m; i++) {
        if (curr == -10000000) break;
        if (curr == 0 && ooperation == 4) continue;
        int val = eval(prev, curr, ooperation);
        result = min(result, findMinTouch(val, -10000000, operations[i], tou + 1, t));
    }

    for (int i = 0; i < n; i++) {
        if (curr == -10000000) {
            result = min(result, findMinTouch(prev, working[i], ooperation, tou + 1, t));
        } else {
            int val = abs(curr);
            val = val * 10 + working[i];
            if (curr < 0) {
                val *= -1;
            }
            result = min(result, findMinTouch(prev, val, ooperation, tou + 1, t));
        }
    }

    memo[curr][ooperation] = result;
    return result;
}

int main() {
    int t;
    cin >> t;
    int count = 0;
    while (t--) {
        memo.clear();
        cin >> n >> m >> o;
        
        working.resize(n);
        for (int i = 0; i < n; i++) {
            cin >> working[i];
        }

        operations.resize(m);
        for (int i = 0; i < m; i++) {
            cin >> operations[i];
        }

        int target;
        cin >> target;

        int answer = findMinTouch(-10000000, -10000000, -1, 0, target);
        count++;
        cout << "#" << count << ": " << (answer == INT_MAX ? -1 : answer) << endl;
    }

    return 0;
}
