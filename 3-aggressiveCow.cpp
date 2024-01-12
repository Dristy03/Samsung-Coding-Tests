/*
You are given an array of integers which represents positions available and an integer c(cows).
Now you have to choose c positions such that minimum difference between cows is maximized.

input
5 3
1 3 5 8 10


Output:
4
1 5 10
*/


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool canPlaceCows(const vector<int>& positions, int c, int minDistance) {
    int cowsPlaced = 1;
    int lastPosition = positions[0];

    for (int i = 1; i < positions.size(); ++i) {
        if (positions[i] - lastPosition >= minDistance) {
            lastPosition = positions[i];
            ++cowsPlaced;

            if (cowsPlaced == c)
                return true;
        }
    }

    return false;
}

int maximizeMinDistance(const vector<int>& positions, int c) {
    int low = 1; 
    int high = positions.back() - positions.front(); 
    int result = 0;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (canPlaceCows(positions, c, mid)) {
            result = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return result;
}

int main() {
    int n, c;
    cin >> n >> c;

    vector<int> positions(n);
    for (int i = 0; i < n; ++i) {
        cin >> positions[i];
    }

    sort(positions.begin(), positions.end());

    int maxMinDistance = maximizeMinDistance(positions, c);

    cout << maxMinDistance << endl;

    int cowsPlaced = 1;
    int lastPosition = positions[0];

    cout << lastPosition << " ";

    for (int i = 1; i < n; ++i) {
        if (positions[i] - lastPosition >= maxMinDistance) {
            lastPosition = positions[i];
            cout << lastPosition << " ";
            ++cowsPlaced;

            if (cowsPlaced == c)
                break;
        }
    }

    return 0;
}
