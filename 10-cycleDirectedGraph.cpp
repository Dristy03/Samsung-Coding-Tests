/*
5 5
1 2 2 4 4 5 5 3 3 2                         
*/

#include <iostream>
#include<vector>
#include<set>
using namespace std;


vector< vector< int > > adj(15);
int n, m;
vector< pair< int, vector< int > > > ans;


void dfs(int u, vector< int > v) {

    set< int > s;
    int sum = 0;

    for(auto i: v) {
        s.insert(i);
        sum += i;
    }

    if(s.size() != v.size()) {
        if(v[0] == v.back()) {
            sum -= v.back(); 
            vector< int > aa = v;
            aa.pop_back();
            sort(aa.begin(), aa.end());
            ans.push_back({sum, aa}); 
            return;
        }

        return;
    }

    for(auto ch: adj[u]) {
        v.push_back(ch);
        dfs(ch, v);
        v.pop_back();
    }
}

int main() {

    cin >> n >> m;

    for(int i = 0; i < m; i ++) {
        int u, v; 
        cin >> u >> v;
        adj[u].push_back(v);
    }

    for(int i = 1; i <= n; i ++) {
        vector< int > v; 
        v.push_back(i);
        dfs(i, v);
    }

    sort(ans.begin(), ans.end());

    for(auto b: ans[0].second) {
        cout<< b << ' '; 
    }
    cout<< endl;
}
