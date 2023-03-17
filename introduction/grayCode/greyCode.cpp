#include <iostream>

using namespace std;


int main (int argc, char *argv[])
{
    int n,j,aux;

    cin >> n; 
    j = 1 << n;
    
    for (int i = 0; i < j; i++){
        aux = (i^(i>>1));
        for(int k = j/2; k > 0; k = k/2){ 
            cout << aux / k;
            aux = aux % k; 
        }
        cout << endl;
    }
    return 0;
}
