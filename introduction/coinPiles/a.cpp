#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
  int t, a, b;
  cin >> t;

  while (t--) {
    cin >> a >> b;
    if (b > a) {
      int tmp = a;
      a = b;
      b = tmp;
    }

    if (a > 2 * b || (a + b) % 3 != 0)
      cout << "NO" << endl;
    else
      cout << "YES" << endl;
  }
  return 0;
}
