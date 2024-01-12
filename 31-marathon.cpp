/*
Initially you have H amount of energy and D distance to travel. You may travel with any of the given 5 speeds. But you may only travel in units of 1 km. For each km distance traveled, you will spend corresponding amount of energy. e.g. the given speeds are:
Cost of traveling 1 km: [4, 5, 2, 3, 6]
Time taken to travel 1 km: [200, 210, 230, 235, 215]
Find minimum time required to cover total D km with remaining H >= 0
1 <= H <= 4000
1 <= D <= 1000
Input:
1 
10 3 
1 30 2
2 0 3 
0 45 2
0 30 1
1 0 2
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int ans = INT_MAX;
struct Profile {
    int time;
    int energy;
};
int H, D;

void solve(vector<Profile> profiles, int index, int H, int D, int sum) {

    if (H <= 0 || index >= profiles.size() || sum > ans) {
        return;
    }

    if (D <= 0) {
        ans = min(ans, sum);
        return;
    }

    solve(profiles, index, H - profiles[index].energy, D - 1, sum + profiles[index].time);

    solve(profiles, index + 1, H, D, sum);
}

int main() {
    int t;
    cin >> t;

    while (t--) {

        cin >> H >> D;

        vector<Profile> profiles(5);

        for (int i = 0; i < 5; i++) {
            int min, sec;
            cin >> min >> sec >> profiles[i].energy;
            profiles[i].time = 60 * min + sec;
        }

        ans = INT_MAX;
        solve(profiles, 0, H, D, 0);

        cout << ans / 60 << " " << ans % 60 << endl;
    }

    return 0;
}
