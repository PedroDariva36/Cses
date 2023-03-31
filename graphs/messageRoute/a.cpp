#include <bits/stdc++.h>
#include <bits/types/stack_t.h>
#include <iostream>
#include <vector>
using namespace std;


int main (int argc, char *argv[]){
    
    int n,m,a,b,aux;
    cin >> n >> m;

    vector<int> g[n];
    bool visited[n];
    int father[n];
    queue<int> q;
    stack<int> s;

    
    for (int i = 0; i < n; i++){ 
        visited[i] = false;
        father[i] = -1;
    }

    vector<int> neighbors;
    
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        g[a-1].push_back(b-1);
        g[b-1].push_back(a-1);
    }
    
    q.push(0);
    visited[0] = true;
    while (!q.empty()) {
        aux = q.front();
        neighbors = g[aux];
        q.pop();
        if (aux == n-1) break;


        for (int i = 0; i < neighbors.size(); i++) {
             if (visited[neighbors[i]] == false){
                q.push(neighbors[i]);
                visited[neighbors[i]] = true;
                father[neighbors[i]] = aux;
             }
        }
    }
    
    if (visited[n-1] == false) {
        cout <<"IMPOSSIBLE"<<endl;
        return 0;
    }

    int prev = n-1;
    s.push(n-1);
    while (father[prev] != -1) {
        s.push(father[prev]);
        prev = father[prev];
    }
    
    cout << s.size() << endl;
    while (!s.empty()) {
        cout << s.top() + 1 << " ";
        s.pop();
    }
    cout << endl;
    




    




    return 0;
}
