#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::string;
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    int n, ans = 0;
    cin >> n;
    for (int j = n - 50; j < n; ++j) {
      int sum = j, temp = j;
      while (temp != 0) {
        sum += temp%10;
        temp = temp/10;
      }
      if (sum == n) {
        ans = j;
        break;
      }
    }
    cout << ans << endl;
  }
  return 0;
} 
