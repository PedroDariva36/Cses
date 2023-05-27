#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
#define ll long long 
#define pll pair<ll,ll>
#define s second
#define f first
using namespace std;

vector<pll> a;
int n;
ll x, y;

int main (int argc, char *argv[]){
    cin >> n;
    while (n--) {
        cin >> x >> y;
        a.push_back({x,y});
    }
    sort(a.begin(),a.end());
    int counter = 1;
    pll start = a[0]; 
    pll last = start;
    
    for (int i = 1; i < a.size(); i++) {
        if (a[i].s < start.s) {
            if (start == last) last = a[i]; 
            start = a[i];
            continue;
        }

        if (a[i].s < last.s) {
            last = a[i];
            continue;
        }

        if (last.s <= a[i].f) {
            counter++;
            last = a[i];
        }
    }

    cout << counter << endl;

    return 0;
}
