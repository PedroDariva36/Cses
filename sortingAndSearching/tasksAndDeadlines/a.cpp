#include <algorithm>
#include <bits/stdc++.h>
#include <ctime>
#define pii pair<int,int>

using namespace std;

int main (int argc, char *argv[]){
    int n, a, b;
    long long r = 0;
    vector<pii> v;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        v.push_back({a,b});
    }
    
    sort(v.begin(),v.end());
    
    long long time = 0;
    for (auto i : v) {
        time += i.first;
        r+= i.second - time;
    }
    
    cout << r << endl;


    return 0;
}
