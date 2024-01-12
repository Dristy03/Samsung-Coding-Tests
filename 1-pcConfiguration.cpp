/*
Given below are the raw materials quantities and their respective selling price(if sold as raw).

D --> No of CPUs
E --> No of memory chips
F --> No of boards
d --> Selling price of CPU
e --> Selling price of Memory chips

We are given N Computer configurations like below : 
Di, Ei, Fi, SPi, which are the CPU, Chips, Boards and one unit selling price for ith computer respectively.
Our task is to maximize the final cost.
Constraints:
1. Can use at Max 3 different Configurations
2. We can use 1 configuration multiple times
3. Remaining Inventories can be sold on its selling price

Input:
T --> Number of test cases.
D E F d e --> Inventories
N --> Total Configuration Count
Di Ei Fi SPi
...
Dn En Fn SPn

1<=T<=10
1<= D, E, F <= 100
1<= d, e <=100000
1<=N<=8

Output:
First Line print the Case #testCaseNumber
Second Line Print Maximum Cost per test case in each line.

Sample Input:
1 --> Total Test Case
10 10 10 2 1 --> D E F d e
1 --> PC Configuration Count
1 2 2 3 --> D1 E1 F1 SP1

Sample Output:
Case #1
30

*/

#include<iostream>
using namespace std;

int D, E, F, d, e, n;
int answer = 0;

struct configuration
{
    int D, E, F, SPi;
};

configuration configs[9];

void solve(int idx, int cnt, int D, int E, int F, int cost)
{
    if (idx == n || cnt == 3)
    {
        cost += D * d + E * e;
        answer = max(answer, cost);
        return;
    }

    solve(idx + 1, cnt, D, E, F, cost);

    int usedCount = min(D / configs[idx].D, min( E / configs[idx].E, F / configs[idx].F));

    for (int i = 1; i <= usedCount; ++i)
    {
        solve(idx + 1, cnt + 1, D - configs[idx].D * i, E - configs[idx].E * i, F - configs[idx].F * i, cost + configs[idx].SPi * i);
    }
}
   
       

int main()
{
    int T,cnt=1;
    cin>>T;
 
    while(T--)
    {
        int i,j,k,s,m,l,res=0,ans=0,a,b;
        answer = 0;
        cin>>D>>E>>F>>d>>e;
        cin>>n;
       

        for (i = 0; i < n; ++i) {
            cin >> configs[i].D >> configs[i].E >> configs[i].F >> configs[i].SPi;
        }

        solve(0, 0, D, E, F, 0);

        cout << "Case #" << cnt++ << endl;
        cout << answer<< endl;
 
    }
 
}