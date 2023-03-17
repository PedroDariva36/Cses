#include <bits/stdc++.h>
#include <deque>
#include <utility>
#include <vector>
#define pii pair<int,int>

using namespace std;

int main (int argc, char *argv[]){
    
    int count = 0;
    int x,y;
    deque<pii> a;
    cin >> x >> y;

    
    char t[x][y];
    for (int i = 0; i < x; i++)
        for (int j = 0; j < y; j++)
                cin >> t[i][j];
    


    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++){
            if (t[i][j] == '.') {
                
                //cout << endl;
                //cout << "t["<<i<<"]["<<j<<"]"<< endl;
                count++;
                a.push_back(make_pair(i, j));
                while (!a.empty()) {
                    pii p = a.front();
                    a.pop_front();
                    t[p.first][p.second] = '#';
                    
                    if (p.first > 0 && t[p.first-1][p.second] == '.') a.push_back(make_pair(p.first-1, p.second));
                    if (p.first < x-1 && t[p.first+1][p.second] == '.') a.push_back(make_pair(p.first+1, p.second));
                    if (p.second > 0 && t[p.first][p.second-1] == '.') a.push_back(make_pair(p.first, p.second-1));
                    if (p.second < y-1 && t[p.first][p.second+1] == '.') a.push_back(make_pair(p.first, p.second+1));
                }
            }
        }
    }
    /*
    for (int i = 0; i < x; i++){
        for (int j = 0; j < y; j++)
            cout << t[i][j];
        cout << endl;
    } 
   */ 

    cout << count<<endl;

    return 0;
}


