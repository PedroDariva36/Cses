#include <iostream>
#include <cmath>
using namespace std;

int main (int argc, char *argv[]){

  int t;
  long long y,x,n;
  cin >> t;

  while(t--){
    cin >> y >> x;
    
    if (x > y) {
      if (x % 2 == 0){
        x--;
        n = x*x + y;
      }

      else n = x*x - y + 1;
    }
    else{
      if (y % 2 == 0){ 
        x--;
        n = y*y - x;  
      }

      else{ 
        y--;  
        n = y*y + x;
      }
    }

    cout << n << endl;
  }
  
  return 0;
}
