#include <algorithm>
#include <bits/stdc++.h>
#include <climits>
#include <cstdlib>
#include <iterator>
#include <limits>
#include <utility>
#include <vector>
#define ll long long 
#define pli pair<ll , int>
using namespace std;
 
 
int n,m,a,b,c;
ll x;
 
int main (int argc, char *argv[]){
    
    cin >> n >> m; 
    
    ll dist[n+1];
    bool marked[n+1];
    vector<pair<int, long>> g[n+1];
    priority_queue<pli> q;
 
 
 
    for (int i = 0; i < n+1; i++) {
        dist[i] = -9223372036854775807;
        marked[i] = false;
    }
 
    
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c; 
        g[a].push_back({b,c});
    }
    
   
    dist[1] = 0;
    for (int i = 2; i < n+1 ; i++) {
        q.push({dist[i],i});
    }
    
    q.push({0,1});
    while (!q.empty()) {
        int a = q.top().second; q.pop();
        if (marked[a]) continue;
        marked[a] = true;
        for (auto u : g[a]) {
            ll b = u.first, w = u.second;
            if (dist[a]+w > dist[b]) {
                dist[b] = dist[a]+w;
                q.push({dist[b],b});
            }
        }
    }
 
 
    cout << dist[n] << endl;
 
    return 0;
}
