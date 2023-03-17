#include <iostream>
#include <vector>
using namespace std;


int main(){
	int n;
	vector<int> a;
	vector<int> b;

	cin >> n;

	if ((n + 1) % 4 == 0){
		cout << "YES" << endl;

		a.push_back(1);
		a.push_back(2);
		b.push_back(3);
		
		if (n > 3){
			for(int i = 4; i <= n; i = i + 4){
				a.push_back(i);
				a.push_back(i+3);
				b.push_back(i+1);
				b.push_back(i+2);	
			}
		}
		cout << a.size()<< endl;
		for(int i = 0; i < a.size();i++)
			cout << a[i] <<" ";
		cout << endl;

		cout << b.size()<< endl;
		for(int i = 0; i < b.size();i++)
			cout << b[i] <<" ";
		cout << endl;
	}
	else if(n % 4 == 0){
		for( int i = n; i > 0; i = i - 4){
			a.push_back(i);
			a.push_back(i - 3);
			b.push_back(i - 1);
			b.push_back(i - 2);
		}
		
		cout << "YES"<< endl;
		cout << a.size()<< endl;
	        for(int i = 0; i < a.size();i++)
			 cout << a[i] <<" ";
		cout << endl;

		cout << b.size()<< endl;
		for(int i = 0; i < b.size();i++)
			cout << b[i] <<" ";
		cout << endl;	
	}
	else
		cout << "NO" << endl;
}
