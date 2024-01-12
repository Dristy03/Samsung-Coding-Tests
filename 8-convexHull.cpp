/*
Given random points in a 2-D plane, construct a convex polygon with minimum area of covering and 
which encompasses all the given points.

1
7
0 3
2 2
1 1
2 1
3 0
0 0
3 3
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Point {
    int x, y;
};

int orientation(Point p, Point q, Point r) {
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    return (val == 0) ? 0 : ((val > 0) ? 1 : 2);
}

bool comparePoints(Point& a, Point& b) {
    return (a.x == b.x) ? (a.y < b.y) : (a.x < b.x);
}

void convexHull(Point points[], int n) {
    if (n < 3) {
        cout << "-1";
        return;
    }

    vector<Point> hull;

    int p = 0, q;
    
    while (true) {
        hull.push_back(points[p]);
        q = (p + 1) % n;
        for (int i = 0; i < n; i++) {
            if (orientation(points[p], points[i], points[q]) == 2)
                q = i;
    }

   
    p = q;

    if (p == 0) {
        break;
    }
}

   for (int i = 0; i < hull.size(); ++i) {
    cout << hull[i].x << " " << hull[i].y<<endl;
   
}

}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        Point* points = new Point[n];
        for (int i = 0; i < n; ++i) {
            cin >> points[i].x >> points[i].y;
        }

        convexHull(points, n);
        cout << "\n";
    }

    return 0;
}
