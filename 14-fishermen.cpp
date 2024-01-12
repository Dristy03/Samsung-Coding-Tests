/*
There are N fishing spots and 3 gates. At each gate there are some fishermen waiting to reach the nearest unoccupied fishing spot. (Total no of fisherman <=N) 
Distance between consecutive spots = distance between gate and nearest spot = 1 m 
Only 1 gate can be opened at a time and all fishermen of that gate must occupy the spots before the next gate is opened. 
Distance is calculated as gate to nearest spot + nearest spot to closest vacant spot. 
Find the total sum of minimum distances need to walk for all the fishermen.
Inputs to be taken: 
Number of fishing spots 
Position of the gates 
Number of fishermen at each gates 


1 
10
4 5
6 2
10 2
*/

#include <iostream>
#include <climits>
using namespace std;

struct Gate {
    int position, fishermen;
};

Gate gates[4];
int n, ans;
bool visited[100];

int findLeft(int index) {
    for (int i = index; i > 0; i--) {
        if (!visited[i]) return i;
    }
    return INT_MAX;
}

int findRight(int index) {
    for (int i = index + 1; i <= n; i++) {
        if (!visited[i]) return i;
    }
    return INT_MAX;
}



void exploreGate(int x, int y, int z, int distance, int currentGate) {
    if (distance > ans) return;

    if (gates[currentGate].fishermen == 0) {
        if (currentGate == x) currentGate = y;
        else if (currentGate == y) currentGate = z;
        else {
            ans = min(ans, distance);
            return;
        }
    }

    int leftVacantSpot = findLeft(gates[currentGate].position);
    int rightVacantSpot = findRight(gates[currentGate].position);

    int costLeft = abs(gates[currentGate].position - leftVacantSpot) + 1;
    int costRight = abs(gates[currentGate].position - rightVacantSpot) + 1;

    if (costLeft <= costRight && !visited[leftVacantSpot]) {
        visited[leftVacantSpot] = true;
        gates[currentGate].fishermen--;
        exploreGate(x, y, z, distance + costLeft, currentGate);
        visited[leftVacantSpot] = false;
        gates[currentGate].fishermen++;
    }

    if (costRight <= costLeft && !visited[rightVacantSpot]) {
        visited[rightVacantSpot] = true;
        gates[currentGate].fishermen--;
        exploreGate(x, y, z, distance + costRight, currentGate);
        visited[rightVacantSpot] = false;
        gates[currentGate].fishermen++;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n;

        
        for (int i = 1; i <= 3; i++)
            cin >> gates[i].position >> gates[i].fishermen;

        for (int i = 0; i < 100; i++)
            visited[i] = false;

        ans = INT_MAX;
        exploreGate(1, 2, 3, 0, 1);
        exploreGate(1, 3, 2, 0, 1);
        exploreGate(2, 1, 3, 0, 2);
        exploreGate(2, 3, 1, 0, 2);
        exploreGate(3, 1, 2, 0, 3);
        exploreGate(3, 2, 1, 0, 3);

        cout << ans << endl;
    }
    return 0;
}
