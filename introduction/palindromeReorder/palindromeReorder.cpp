#include <iostream>
#include <iterator>
#include <vector>
#include <map>
#include <string>

using namespace std;

int main(int argc, char *argv[]) {
    char n;
    vector<char> half;
    string a;
    cin >> a; 
    
    if(a.length() == 1){
        cout << a << endl;
        return 0;
    }  

    map<char,int> charMap;
    for(int i = 0; i < a.length(); i++){
        charMap[a[i]]++;
    }
    bool flag = false;     
    map<char,int>::iterator itr; 
    for (itr = charMap.begin(); itr != charMap.end(); itr++) {
        if (itr->second % 2 == 0) for(int i = 0; i < itr->second/2; i++) half.push_back(itr->first);
        else{
            if(flag == true){
                cout <<"NO SOLUTION" << endl;
                return 0;
            }
            else{
                flag = true;
                n = itr->first;
                for(int i = 0; i < itr->second/2; i++) half.push_back(itr->first); 
            }
        }
    }
    for(int i = 0; i < half.size(); i++)cout << half[i];
    if (flag) cout << n;
    for (int i = half.size() - 1; i >= 0; i--) cout << half[i]; 
    cout << endl; 
    return 0;
}
