#include <algorithm>
#include <bits/stdc++.h>
#include <climits>
#include <cstdlib>
#include <iterator>
#include <limits>
#include <utility>
#include <vector>
#define INF 10e12+7

using namespace std;
 
long long c;
int n,m,a,b,q;


int main (int argc, char *argv[]){

    cin >> n >> m >> q; 
    long long dist[n+1][n+1];

    for (int i = 1; i <= n ; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) dist[i][j] = 0;
            else dist[i][j] = INF;
        }
    }

    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c; 
        if (dist[a][b] < c) continue;
        dist[a][b] = c;
        dist[b][a] = c;
    }

    


    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
            }
        }
    }
   
    
    for (int i = 0; i < q; i++) {
        cin >> a >> b;
        if (dist[a][b] == INF) {cout << -1 <<endl; continue;}
        cout << dist[a][b] << endl;
    }
     
    
    return 0;
}
