#include <bits/stdc++.h>

using namespace std;
int n,mx,base,k;
int main (int argc, char *argv[]){
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);


    cin >> n;
    int count = 0;
    while(n > 0){
        count++;
        mx = 0;
        k = n;
        base = 10;
        while (k > 0) {
            mx = max((k % base), mx);
            k = (k - (k % base))/10;
        }
        n -= mx;
    }
    cout << count << endl;

    return 0;
}
