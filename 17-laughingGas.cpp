/*
You are busy to promote a newly released film in a movie theater. The title is ‘Biochemical Laughing Bomb’ which is about terror.
Guerrillas drop a biochemical laughing bomb in the middle of a city. Once exposed, you have to laugh all your life. The bomb will 
contaminate four people around it during 1 second, and another four around each of them during another one second. However, you won’t be 
contaminated if you are not in the adjacent four directions. as the below shows the location of the bomb and affected people, and shows 
contamination process in seconds and you can figure out that the whole city is contaminated in 8 seconds.
In order to protect the city from the epidemic, create a program that figures out when the city will be contaminated by the bomb for the last.

Input
2
8 7
0 0 1 1 0 0 0
1 1 1 1 0 1 0 
0 0 1 1 1 1 1
0 1 1 1 1 1 1
0 1 0 0 1 1 0
0 1 1 1 1 0 0
0 0 1 0 1 1 1
0 0 0 0 1 0 0
5 2
10 10
1 1 1 1 0 1 1 0 0 0
0 1 1 1 1 1 0 1 1 0
0 0 1 1 0 1 0 1 1 1
0 1 1 1 1 1 0 0 1 1
0 1 0 1 0 1 1 1 1 0
0 0 0 0 0 1 1 0 0 0
1 0 1 0 1 0 1 1 0 0
0 0 1 1 1 1 1 1 1 1
1 0 1 0 0 1 0 1 1 0
1 1 1 0 0 0 0 1 1 1
2 2

Output
Case #1 
8
Case #2
21
*/


#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct node {
    int x, y, level;
};


 int n, m, r, c;

int mv[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};


bool isValid(int i, int j) {
    return (i >= 0 && i < m && j >= 0 && j < n);
}

int laughingGas(vector<vector<int> > a)
{
     queue<node> q;
      int tmx,tmy,tml;

        q.push({c-1, r-1, 0});
        a[c-1][r-1] = 2;

        while (!q.empty()) {
            node d1 = q.front();
            q.pop();

            for (int k = 0; k < 4; k++) {
                 tmx = d1.x + mv[k][0];
                 tmy = d1.y + mv[k][1];
                 tml = d1.level + 1;

                if (isValid(tmx,tmy) && a[tmx][tmy] == 1) {
                   
                    q.push({tmx, tmy, tml});
                    a[tmx][tmy] = 2;
                }
            }
        }

        return tml;
}

int main() {
    int T;
    cin >> T;

    for (int t = 1; t <= T; t++) {
       
        cin >> n >> m;

        vector<vector<int> > a(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cin >> a[i][j];
            }
        }

        cin >> r >> c;
        int ans = laughingGas(a);

        cout << "Case #" << t << endl;
        cout <<ans<< endl;
    }

    return 0;
}
