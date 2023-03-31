#include <bits/stdc++.h>
#include <exception>
#include <queue>
#include <vector>


using namespace std;



int main (int argc, char *argv[]){
    int n, m, a, b, aux;
    cin >> n >> m;
    queue<int> q;
    vector<int> g[n+1];
    bool visited[n+1];
    int group[n+1];

    for (int i = 0; i < n; i++) {
        visited[i] = false;
        group[i] = -1;
    }
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(b);
    }

    group[0] = 0;
    for (int u = 1; u < n; u++){
        for (auto i : g[u])
            if (group[i] != -1)
                visited[group[i]] = true;
 
        int cr;
        for (cr = 0; cr < n; cr++)
            if (visited[cr] == false)
                break;
 
        group[u] = cr;
 
        for (auto i : g[u])
            if (group[i] != -1)
                visited[group[i]] = false;
    }




    /*
    
    
    
    for (int i = 0 ; i < n; i++) {
        
        if (visited[i] == true) continue;

        group[i] = 0;
        visited[i] = true;
        q.push(i);
        while (!q.empty()) {
            aux = q.front();
            q.pop();

            for (auto j : g[aux]) {

                if (visited[j]) continue;
                group[j] = !group[aux];
                visited[j] = true;
                q.push(j);
            }
        }
    }
    */
    for (int i = 0; i < n; i++) cout << group[i]+1 << " ";
    cout << endl;
    
    return 0;
}
