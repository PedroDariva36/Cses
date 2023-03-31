#include <bits/stdc++.h>
#include <deque>
#include <exception>
#include <iostream>
#include <queue>
#include <utility>

#define mkp make_pair
#define pii pair<int, int>

using namespace std;

int main (){
    int dx[] = {-1, 1, 0, 0};
    int dy[] = { 0, 0,-1, 1};
    char str[] = {'U', 'D', 'L', 'R' ,'-'};

    char g[1000][1000];
    bool marked[1000][1000]; 
    int actions[1000][1000];
    stack<char> p;
    queue<pii> queue;
    
    
    for (int i = 0; i < 1000; i++) 
        for (int j = 0; j < 1000; j++)
            actions[i][j] = 4;
    
    
    int n,m;
    cin >> n >> m;
    
    pii start,end,current,aux;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> g[i][j];
            if (g[i][j] == 'A') start = mkp(i,j);
        }
    }
     
    queue.push(start);
    marked[start.first][start.second] = true;
    while (!queue.empty()) {
        current = queue.front(); 
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
        
        queue.pop();
    }
        
    if (marked[end.first][end.second] == true){
        cout << "YES" << endl;
    
        while (end != start) { 
            int action = actions[end.first][end.second];  
            p.push(str[action]);
            end = mkp(end.first - dx[action], end.second - dy[action]); 
        }
        
        cout << p.size()<<endl;
        while (!p.empty()) {
            cout << p.top();
            p.pop();
        }
        cout << endl;
    }

    else cout << "NO" <<endl;


    /*
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << str[actions[i][j]]<<" ";
        }
        cout << endl;
    }
    */
    return 0;
}
