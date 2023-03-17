#include <bits/stdc++.h>
using namespace std;

int main (int argc, char *argv[]){

    cout << 1000 << " " << 1000 << endl;
    for (int i = 0; i < 1000; i++) {
        cout << "#";
        for (int j = 0; j < 998; j++) {
            if (i % 2 == 0)
                cout << "#";
            else
             cout << ".";
        }
        cout<<"#"<<endl;
    }
    return 0;
}
