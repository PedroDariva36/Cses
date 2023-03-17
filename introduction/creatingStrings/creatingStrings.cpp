#include <iostream>
#include <iterator>
#include <vector> 
#include <string>
#include <set>


#define mci map<char,int>
using namespace std;



//set<string> str;

void solve(vector<char> perm, bool *chosen,  int n){
    if (perm.size() == n){ //str.insert(perm.begin(), perm.end());
        for (int i = 0; perm.size(); i++) cout << perm[i];
        cout << endl;
    }
    else{
        for (int i = 1; i < n; i++) {
            if (chosen[i]) continue;
            
            chosen[i] = true;
            perm.push_back(perm[i]);
            solve(perm, chosen, n);
            chosen[i] = false;
            perm.pop_back();
        }
    }
}


int main (int argc, char *argv[])
{
    string s;
    vector<char> perm;

    cin >> s;
    
    for (int i = 0; i < s.size(); i++) {
        perm.push_back(s[i]);       
    }

    bool chosen [s.size()+1];

    solve(perm, chosen, s.size());
    
    //set<string>::iterator itr;

    //for(itr = str.begin(); itr != str.end(); itr++){
    //    cout << *itr << endl;
    //}





/*    
    mci charMap; 
    for (int i = 0; i < s.length(); i++) charMap[s[i]]++;
         
    mci::iterator itr;
    for (itr = charMap.begin(); itr != charMap.end(); itr++) {
        cout << itr->first <<" " << itr->second << endl;
    }
*/

    return 0;
}
