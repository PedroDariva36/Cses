#include <bits/stdc++.h>
#include <cmath>
#include <iostream>
#define ull unsigned long long


using namespace std;

int main (int argc, char *argv[])
{
    int n;
    cin >> n;
    ull x;
    cout << 0 << endl;
    if (n > 1) {
        for (int i = 2; i <= n; i++) {
            x = (pow(i,4) - 9*pow(i,2) + 24*i -16)/2;
            cout << x << endl;
        }
    }


    return 0;
}
