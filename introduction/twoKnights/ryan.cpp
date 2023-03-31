#include <bits/stdc++.h>
#include <cmath>
#define ull unsigned long long

int dx[] = {1,-1,1,-1,2,-2,2,-2};
int dy[] = {2,-2,2,-2,1,1,-1,-1};


using namespace std;


int main(){
    int k; 
    ull x,y,p;
    cin >> k; 
    
    cout << 0 << endl;
    for(ull n = 2; n <= k; n++){
        ull n2 = pow(n,2);
        ull count = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                p = 1; //valid_pos(i,j,N);
                for (int z = 0; z < 8; z++) {
                    x = i + dx[i];
                    y = j + dy[i];
                    if (x < 0 || x >= n || y < 0 || y >= n) continue;
                    p += 1;
                }
                count += n2 - p;
            }
        }
        cout << (count >> 1) << endl;
    }

    return 0;
}

