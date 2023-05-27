#include <bits/stdc++.h>
#define ll long long 
#define pli pair<ll, int>
#define f first
#define s second
using namespace std;


int n, t; 
ll aux,num;
 vector<pli> a;

int main (int argc, char *argv[]){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> num;
    for (int i = 0; i < n; i++) {
        cin >> aux;
        a.push_back({aux,i});
    }
     
    sort(a.begin(),a.end());
    int x = 0;
    int y = a.size()-1;


    ll s;
    while (x < y){
        s = (a[x].f + a[y].f);
//        cout << a[x].f << " " << a[y].f << endl;
        if (s > num) 
            y--;
        if (s < num) 
            x++;
        if (s == num) 
            break;
    }
    
    if (a[x].f + a[y].f != num || x == y) 
        cout << "IMPOSSIBLE" <<endl;
    else
        cout << a[x].s+1 << " " << a[y].s+1 << endl;
        
    return 0;
}
