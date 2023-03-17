#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main (int argc, char *argv[])
{
    unsigned long int n = 100001;        
    vector<char> a;
    a.push_back('a');


    for (unsigned long int i = 1; i < n; i++){ 
        string q = to_string(i);
        for(int j = 0; j < q.length(); i++){
            a.push_back(q[i]);
        }
    }

    for (int i = 1; i < a.size();i++) cout<< i << " - " << a[i] << endl;
        
    return 0;
}
