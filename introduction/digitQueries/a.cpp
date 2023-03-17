#include <iostream>
#include <cmath>
#include <string>
#define ull unsigned long long
using namespace std;


ull eq(ull i){ 
    return 9 * i * pow(10,i - 1);
}

ull power(ull k){
    ull l = 1;
    while(k > eq(l)) l++;
    return l;
}

int main (int argc, char *argv[]){
    
    int t, powerOf10;
    unsigned long long k, q, baseNumber, digit;
    cin >> t;
    while (t--) {
        
        cin >> k;
        digit = 0;
        powerOf10 = power(k);
        
        for (int i = 1; i < powerOf10; i++) digit += eq(i);
        k -= digit; 
        q = k/powerOf10;
        digit += q;
        k -= q * powerOf10;        
        if(k == 0){ 
            cout << digit % 10 << endl;
        }

        else {
            string a = to_string(digit+1);
            cout << a[k-1] << endl;
        }

        //cout << k << endl;
    }
    return 0;
}

