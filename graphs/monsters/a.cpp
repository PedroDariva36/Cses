#include <bits/stdc++.h>
#include <deque>
#include <exception>
#include <iostream>
#include <queue>
#include <utility>

#define mkp make_pair
#define pii pair<int, int>
#define MAX 10e6
#define f first
#define s second


using namespace std;


int dx[] = {-1, 1, 0, 0};
int dy[] = { 0, 0,-1, 1};
char str[] = {'U', 'D', 'L', 'R' ,'-'};
int marked[1000][1000];
char g[1000][1000];
int dist[1000][1000];
int n,m, auxDist;

int main (){
    

    int actions[1000][1000];
    for (int i = 0; i < 1000; i++){ 
        for (int j = 0; j < 1000; j++){
            actions[i][j] = 4;
            dist[i][j] = MAX;
            marked[i][j] = -1;
        }
    }
    
    stack<char> p;
    queue<pii> mq, q;
    pii start,end = make_pair(-1, -1),current,aux;
    cin >> n >> m; 

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> g[i][j];
            if (g[i][j] == 'A') start = mkp(i,j);
            if (g[i][j] == 'M') {
                mq.push(mkp(i,j)); 
                dist[i][j] = 0;
            }
        }
    }
    
    //monster search
    while (!mq.empty()) {
        current = mq.front(); mq.pop(); 
        auxDist = dist[current.f][current.s] + 1;
        for (int i = 0; i < 4; i++) {
            aux = mkp(current.f + dx[i], current.s + dy[i]);
            if (aux.f < 0 || aux.f >= n || aux.s < 0 || aux.s >= m) continue;
            if (dist[aux.f][aux.s] <= auxDist) continue;
            if (g[aux.f][aux.s] == '#') continue;
            dist[aux.f][aux.s] = auxDist; 
            mq.push(aux);
        }
    }
           
    q.push(start);
    marked[start.f][start.s] = 0;
    while (!q.empty()) {
        current = q.front(); q.pop();
        
        if (current.f == 0 || current.s == 0 || current.first == n-1 || current.second == m-1) {
            end = current;
            break;
        }

        auxDist = marked[current.f][current.s] + 1;
        for (int i = 0; i < 4; i++) {
            aux = mkp(current.f + dx[i], current.s + dy[i]);
            if (aux.f < 0 || aux.f >= n || aux.s < 0 || aux.s >= m) continue;
            if (dist[aux.f][aux.s] <= auxDist || marked[aux.f][aux.s] != -1) continue;
            if (g[aux.f][aux.s] == '#') continue;
            actions[aux.f][aux.s] = i;
            marked[aux.f][aux.s] = auxDist; 
            q.push(aux);
        }
    }

    if (end.f > -1){
        cout << "YES" << endl;
    
        while (end != start) { 
            int action = actions[end.first][end.second];  
            p.push(str[action]);
            end = mkp(end.f - dx[action], end.s - dy[action]); 
        }
        
        cout << p.size()<<endl;
        while (!p.empty()) {
            cout << p.top();
            p.pop();
        }
        cout << endl;
    }

    else cout << "NO" <<endl;

    return 0;
}
