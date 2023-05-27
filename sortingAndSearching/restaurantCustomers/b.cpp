#include <bits/stdc++.h>
#include <map>
#define l long

using namespace std;

map<l , int>m;
int n;
l x,y;
int main (int argc, char *argv[]){
    

    
    cin >> n;
    while (n--) { 
        cin >> x >> y;
        m[x]++;
        m[y]--;
    }

    int max = 1;
    int sum = 0;

    for (auto i : m) {
        sum += i.second;
        if (sum > max) max = sum;
    }
    cout << max;

    return 0;
}
