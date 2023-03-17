#include <bits/stdc++.h>
#include <iostream>
#include <queue>
#include <stack>
#include <tuple>
#include <utility>
#include <vector>
#define pii pair<int,int>
#define ppi pair<pii, pii>

using namespace std;

int main (int argc, char *argv[]){
    queue<ppi> a;
    stack<char> v;
    pii begin, end;
    
    


    int x = 0;
    int y = 0;
    cin >> x >> y;
    
    char lab[x][y];
    int marked[x][y];
    pii father[x][y];
    
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            cin >> lab[i][j];
            if (lab[i][j] == 'A') begin = make_pair(i,j);  
            if (lab[i][j] == 'B') end = make_pair(i,j);
            marked[i][j] = 0;
            father[i][j] = make_pair(-2,-2);
        }
    }

    a.push(make_pair(begin,make_pair(-1, -1)));
    while (!a.empty()) {
        ppi aux = a.front();  
        a.pop();
        int f = aux.first.first;
        int s = aux.first.second;
        father[f][s] = aux.second; 
        marked[f][s] = 1; 

        if (aux.first == end) break;
            if (f-1 >= 0) 
                if (lab[f-1][s] != '#' && marked[f-1][s] == 0) a.push(make_pair(make_pair(f-1, s), aux.first));
       
            if (f+1 <= x-1)
                if (lab[f+1][s] != '#' && marked[f+1][s] == 0) a.push(make_pair(make_pair(f+1, s), aux.first));
            
            if (s-1 >= 0)
                if (lab[f][s-1] != '#' && marked[f][s-1] == 0) a.push(make_pair(make_pair(f, s-1), aux.first));
       
            if (s+1 <= y-1)
                if (lab[f][s+1] != '#' && marked[f][s+1] == 0) a.push(make_pair(make_pair(f, s+1), aux.first));
    }
    
    
    if (marked[end.first][end.second] == 0) cout << "NO" <<endl;
    

    //{1,0,-1,0} f 
    //{0,1,0,-1} s
    // U R D L
    else{
        pii finder = end;
        while (finder.first != -1 && finder.second != -1) {
            int f = finder.first - father[finder.first][finder.second].first;
            int s = finder.second - father[finder.first][finder.second].second;
            
            if (f == 1 && s == 0) v.push('D');
            else if (f == -1 && s == 0) v.push('U');
            else if (f == 0 && s == 1) v.push('R');
            else if (f == 0 && s == -1) v.push('L');
            else {
                cout << "Erro na formatacao!!" << endl;
            }
            
            finder = father[finder.first][finder.second];
        }
        
        cout <<"YES"<<endl;
        cout << v.size() << endl;
        while (!v.empty()) {
            char i = v.top();
            v.pop();
            cout << i;
        }
        cout << endl;

        
        
        for (int i = 0; i < x; i++) {
            for (int j = 0; j < y; j++)
                cout << lab[i][j] << " ";
            cout << endl;
        }

        cout << endl;
    
        for (int i = 0; i < x; i++) {
            for (int j = 0; j < y; j++)
                    cout << marked[i][j] <<" ";
            cout << endl;
        }
    
        cout << endl;

        for (int i = 0; i < x; i++) {
            for (int j = 0; j < y; j++)
                cout << "(" << father[i][j].first << " " << father[i][j].second << ")" << " ";
            cout << endl;
        }
    }
    return 0;
}
