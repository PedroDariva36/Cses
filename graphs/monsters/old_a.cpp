#include <bits/stdc++.h>
#include <deque>
#include <exception>
#include <iostream>
#include <iterator>
#include <ostream>
#include <queue>
#include <system_error>
#include <utility>

#define mkp make_pair
#define pii pair<int, int>
#define f first
#define s second

using namespace std;

int main (){
    int dx[] = {-1, 1, 0, 0};
    int dy[] = { 0, 0,-1, 1};
    char str[] = {'U', 'D', 'L', 'R' ,'-'};

    char g[1000][1000];
    bool marked[1000][1000];  
    int actions[1000][1000];
    stack<char> p; 
    stack<char> monster;
    queue<pii> queue, qm, eq;
    
    
    for (int i = 0; i < 1000; i++){ 
        for (int j = 0; j < 1000; j++){
            actions[i][j] = 4;
            marked[i][j] = 0;
        }
    }

    int n,m;
    cin >> n >> m;
    
    pii start,end,old,current,aux;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> g[i][j];
            if (g[i][j] == 'A') start = mkp(i,j);
        }
    }
     
    //player search

    queue.push(start);
    marked[start.first][start.second] = true;
    while (!queue.empty()) {
        current = queue.front();  queue.pop();
        if (current.first == 0 || current.first == n-1 || current.second == 0 || current.second == m-1 ){
            end = current;  
            break;
        }

        for (int i = 0; i < 4; i++) {
            aux = mkp(current.first + dx[i], current.second + dy[i]);
            //if (aux.first < 0 || aux.first >= n || aux.second < 0 || aux.second >= m) continue;
            if (marked[aux.first][aux.second]) continue;
            if(g[aux.first][aux.second] != '.') continue;
            marked[aux.first][aux.second] = true;
            actions[aux.first][aux.second] = i;
            queue.push(aux);
        }
    }
        

    // monster search
    
    if (start == end) {
        cout << "YES" << endl;
        cout << "0" << endl;
        return 0;
    }

    if (marked[end.first][end.second] == true){ 
        old = end;
        
         while (end != start) { 
            int action = actions[end.first][end.second];  
            p.push(str[action]);
            end = mkp(end.first - dx[action], end.second - dy[action]); 
        }

        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                marked[i][j] = 0;
                actions[i][j] = 4;
            }
        }

        
        start = old;
        marked[start.f][start.s] = true; 
        qm.push(start);
        end = mkp(-1,-1);
        while (!qm.empty()) {
            current = qm.front(); qm.pop();
            if (g[current.f][current.s] == 'M') {
                end = current;
                break;
            }
            
            for (int i = 0; i < 4; i++) {
                aux = mkp(current.f + dx[i], current.s + dy[i]);
                if (aux.f < 0 || aux.f >= n || aux.s < 0 || aux.s >= m) continue;
                if (marked[aux.f][aux.s]) continue;
                if(g[aux.f][aux.s] == '#') continue;
                actions[aux.first][aux.second] = i;
                marked[aux.f][aux.s] = true;
                qm.push(aux);
            }
        }
        
        if (end.f != -1){
            while (end != start) { 
                int action = actions[end.first][end.second];  
                monster.push(str[action]);
                end = mkp(end.first - dx[action], end.second - dy[action]); 
            }

            if (monster.size() <= p.size()) {
                cout << "NO" << endl;
                return 0;
            }
        }


        cout << "YES" << endl;
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
