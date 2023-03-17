#include <bits/stdc++.h>
#include <limits>
#include <vector>
#define ll long long 


using namespace std;


const uint64_t Mod =1e9 + 7;
vector <int> coins;
vector <ll> res; 

ll solve(ll x){
    if (x < 0) return 0;
    if (x == 0) return 1;
    if (res[x] != -1) return res[x]; 
    
    ll count = 0;
    for (auto c : coins) {        
        count += solve(x-c);
        count %= Mod;
    }
    
    res[x] = count;
    return count;

}

int main (int argc, char *argv[]){
    

    int n,x,aux;
    cin >> n >> x;
    
    res.push_back(0);
    for (int i = 0; i < x; i++) res.push_back(-1); 
    for (int i = 0; i < n; i++) {
        cin >> aux;
        coins.push_back(aux);
    }
    
    
    cout << solve(x) << endl; 
    return 0;
}
