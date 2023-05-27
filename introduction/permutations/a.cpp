#include<bits/stdc++.h>


using namespace std;
 
 
vector<int> odd;
int main(int argc, char const *argv[]){

    int n;
    cin >> n;
 
    if (n == 1) cout << 1;
    
    else if (n == 4) cout << "2 4 1 3";

    else if (n > 4){ 
        for (int i = 5; i < n+1; i++){
            if (i % 2 == 0) cout << i << " ";
            else odd.push_back(i);
        }
        cout << "2 4 1 3 ";
        for (auto i : odd) cout << i << " ";
        
    }
    
    else cout << "NO SOLUTION";
    return 0;
}
