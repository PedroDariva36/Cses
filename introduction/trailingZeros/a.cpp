#include<iostream>

using namespace std;


int main(){
	int n,a,x;
	cin >> n;
	
  if (n == 5){
    cout << 1 << endl;
    return 0;
  }


  x = 5;
	while(n > x){
		a = a + n/x;
		x = x * 5;
	}
	
	cout << a << endl;
	return 0;
}
