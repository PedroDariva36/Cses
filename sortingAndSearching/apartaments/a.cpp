#include <algorithm>
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#define vi vector<int>
 
using namespace std;

int main (int argc, char *argv[]){
    
    int n, m, k, temp;
    cin >> n >> m >> k;
    
    vi ap;
    vi renter;
    

    for (int i = 0; i < n; i++) {
        cin >> temp;                
        renter.push_back(temp);        
    }

    for (int i = 0; i < m; i++) {
        cin >> temp;                
        ap.push_back(temp);        
    }
    
    sort(ap.begin(), ap.end());
    sort(renter.begin(), renter.end());

    int total = 0;
    int apc = 0;
    int rtc = 0;
    
    //for (int a: renter) cout << a << " ";
//    cout << endl;

    

    while (apc != m && rtc != n) {
        if (renter[rtc]-k <= ap[apc] && ap[apc] <= renter[rtc]+k) { 
 //           cout << "apartamento: " << ap[apc] << " renter: " << renter[rtc] << endl; 
            apc++;
            rtc++;
            total++;
            continue;
        }

        if (ap[apc] < renter[rtc]-k) apc++;
        else rtc++;
    }
    
    cout << total << endl;

    return 0;
}
