#include <algorithm>
#include <bits/stdc++.h>
#include <ios>
#include <vector>
#define ll long long
#define pll pair<ll,ll>
#define s second
#define f first



using namespace std;

ll x,y;
int n;
int main (int argc, char *argv[]){
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    ll a[n], b[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }    
    sort(a, a+n);
    sort(b,b+n);


    x = 0;
    y = 0;

    ll max = 1;
    ll time = 1;
    ll counter = 0;
    while (x < n && y < n) {
        if(a[x] == time){
            x++;
            counter++;
        }

        if(b[y] == time){
            y++;
            counter--;
        }


        if (counter > max) max = counter;
        time++;
    }
    
    cout << max << endl;
    return 0;
}
