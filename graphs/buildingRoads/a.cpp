#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

void dfs(int s, vector<int>g[], bool visited[]) {
    if (visited[s]) return;
    visited[s] = true;
    for (auto u: g[s]) dfs(u, g, visited);
}


int main (int argc, char *argv[]){
    
    int n,m,a,b;
    cin >> n >> m;
    vector<int> g[n];
    
    bool visited[n];
    for (int i = 0; i < n; i++) visited[i] = false;
    
    vector<int> seed;
    
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        g[a-1].push_back(b-1);
        g[b-1].push_back(a-1);
    }
    
    for (int i = 0; i < n; i++) {
        if (visited[i] == false) {
            seed.push_back(i);
            dfs(i, g, visited);
        }        
    }
    
    
    cout << seed.size()-1 << endl;
    for (int i = 0; i < seed.size()-1; i++) cout << seed[i] + 1 << " " << seed[i+1] + 1 << endl;

    return 0;
}
