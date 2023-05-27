#include <algorithm>
#include <bits/stdc++.h>
#include <ios>
#include <iostream>
#include <vector>
#define ll long long

using namespace std;
ll n, aux, sum = 0, best;
vector<ll> a;
int main (int argc, char *argv[]){
    ios_base::sync_with_stdio(0);
    cin.tie();
    
    cin >> n;
    while (n--) {
        cin >> aux;
        a.push_back(aux);
    }

    best = a[0];
    for (int i = 0; i < a.size(); i++) {
        sum = max(a[i], (a[i]+sum));
        best = max(best,sum);
    }
    cout << best << endl;

    return 0;
}
