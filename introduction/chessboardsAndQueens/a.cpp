#include <algorithm>
#include <bits/stdc++.h>

using namespace std;
int n = 8;
int column[64];
int diag1[64];
int diag2[64];
char invalid[8][8];
int g = 0;

void search(int y) {
    if (y == n) {
        g++;
        return;
    }
    for (int x = 0; x < n; x++) {
        if (column[x] || diag1[x+y] || diag2[x-y+n-1] || invalid[x][y] == '*') continue;
        column[x] = diag1[x+y] = diag2[x-y+n-1] = 1;
        search(y+1);
        column[x] = diag1[x+y] = diag2[x-y+n-1] = 0;
    }
}


int main (int argc, char *argv[]){
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> invalid[i][j];
        }
    }
    
    search(0);
    cout << g << endl;

    return 0;
}
