#include <algorithm>
#include <bits/stdc++.h>
#include <climits>
#include <iterator>
#include <map>
#include <queue>
#include <unordered_map>
#include <vector>
#define ll long long

using namespace std;

int n, m;
ll aux, last;

multiset<ll> a;
queue<ll> q;
int main (int argc, char *argv[]){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> aux;
        a.insert(aux);
    }

    for (int i = 0; i < m; i++) {
        cin >> aux;
        q.push(aux);
    }

    while (!q.empty()) {
        aux = q.front(); q.pop(); 
        auto x = a.upper_bound(aux);
        
        if (x == a.begin()) {
            cout << -1 << endl;
            continue;
        } 
        --x; 
        cout << *x << endl;
        a.erase(x);
    }

    
        return 0;
}
