/*
Company  A  is discarding product numbers that contain few specific digits a specific number of time or 
more than that. You are given a range and you need to find product numbers that are possible.

Example-

Range: 24 to 12943

Numbers that should not come: 1, 3, 5
Number of times these number should not occur: 3 or more

In above case all two digit numbers are valid.

In three digit: 111, 113, 115, 311, 331, 333, 511, 533, 555 are not valid.

In four digit: All the numbers containing above 3 digit numbers are not valid.

Eg: 11223 is not valid, 11222 is valid.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int numberOminous(int a, int b, int k, const vector<int>& delNos) {
    int count = 0;
    for (int i = a; i <= b; i++) {
        int temp = i;
        vector<int> digitArray(10, 0);

        while (temp) {
            digitArray[temp % 10]++;
            temp /= 10;
        }

        int rougeK = 0;
        for (int j = 0; j < delNos.size(); j++) {
            rougeK += digitArray[delNos[j]];
        }

        if (rougeK < k) {
            count++;
        }
    }
    return count;
}

int main() {
    int a, b, k;
    cin >> a >> b >> k;
    int n;
    cin >> n;
    vector<int> delNos(n);
    for (int i = 0; i < n; i++) {
        cin >> delNos[i];
    }

    cout << numberOminous(a, b, k, delNos) << "\n";

    return 0;
}
