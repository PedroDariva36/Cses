#include <algorithm>
#include <bits/stdc++.h>
#include <deque>
#include <iostream>
#include <vector>

using namespace std;

int binarySearch(deque<int> a, int lower, int upper, int curent, int w){
    if (upperr >= lower) {
        int mid = lower + (upper - lower)/2;
        if (a[mid] == w - curent)
            return mid;

        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);
        return binarySearch(arr, mid + 1, r, x);
    }
 
    return -1;
}

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
    
    //for (auto c : a) cout << c << " ";
    cout <<"done sort " << endl;


    while (a.size() > 1) {
        aux = a[a.size()-1];
        a.pop_back();
        int curent = -1; 
        if (aux + a[0] <= w){ 
               curent = 0;
    
            



            //for (int i = 1; i < a.size(); i++) {
            //    if (aux + a[i] <= w)
            //        curent = i;
            //    else break;
            //}


        }
        if (curent != -1) a.erase(a.begin() + curent);
        counter++;
    
//        for (auto c : a) cout << c << " ";
//        cout << endl;

    }
    
    //for (auto c : a) cout << c << " ";
    //cout << endl;

    counter+=a.size();
    cout << counter << endl;

    return 0;
}


