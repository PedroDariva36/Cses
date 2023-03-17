#include <algorithm>
#include <bits/stdc++.h>
#include <deque>
#include <iostream>
#include <vector>
 
using namespace std;
 
int main (int argc, char *argv[]){
    int c, w, aux;
    int counter = 0;
    deque<int> a;
    cin >> c >> w;
 
    while (c--) {
       cin >> aux;
       a.push_front(aux); 
    }
    sort(a.begin(),a.end());
    
//    for (auto c : a) cout << c << " ";
//    cout << endl;
 
 
    while (a.size() > 1) {
        if (a[0] + a[a.size()-1] > w) a.pop_back();
            
        else {
            a.pop_front();
            a.pop_back();
        }
        counter++;
    }
    counter += a.size();
    cout << counter << endl;
 
    return 0;
}
 
