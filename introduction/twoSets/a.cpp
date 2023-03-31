#include <iostream>
#include <vector>
using namespace std;


int main(){
	int n;
	vector<int> a;
	vector<int> b;

	cin >> n;
    int mol = n % 4;
    if (mol == 1 || mol == 2){ 
        cout << "NO" <<endl;
        return 0;
    }
    

    cout << "YES" << endl;
    if (mol) {
        cout << n/2 + 1 << endl << 1 << " " << 2 << " ";
        b.push_back(3);
        for (int i = 4; i <= n; i = i + 4) {
            cout << i <<" " << i+3 << " ";
            b.push_back(i+1);            
            b.push_back(i+2); 
        }
        cout << endl << n/2 << endl;
        for (auto i : b) cout << i << " ";
        cout << endl;
    }
    else {
        cout << n/2  << endl << 1 << " " << 4 << " ";
        b.push_back(2);
        b.push_back(3);
        for (int i = 5; i <= n; i = i + 4) {
            cout << i <<" " << i+3 << " ";
            b.push_back(i+1);            
            b.push_back(i+2); 
        }
        cout << endl << n/2 << endl;
        for (auto i : b) cout << i << " ";
        cout << endl;
    }


   /* 

    if (mol == 0) {
        a.push_back(1);
        b.push_back(2);
        b.push_back(3);
        a.push_back(4);
    }

    if (mol == 3) {
        a.push_back(1);
        a.push_back(2);
        b.push_back(3); 
        i = 4;
    }

    for (; i <= n; i = i + 4) {
        a.push_back(i);
        a.push_back(i+3);
        b.push_back(i+1);            
        b.push_back(i+2); 
    }
    

    cout << "YES" << endl << a.size() << endl;
    for (auto i : a) cout << i <<" ";
    cout << endl << b.size() << endl;
    for (auto i : b) cout << i <<" ";
    cout << endl;
    */
}
