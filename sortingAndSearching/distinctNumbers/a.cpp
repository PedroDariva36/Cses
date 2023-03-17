#include <bits/stdc++.h>

using namespace std;



int main (int argc, char *argv[]){
    

    set<int> a;
    int t,n;
    cin >> t;
    while (t--) {
        cin >> n;
        a.insert(n);
    }

    cout << a.size();
    return 0;
}
