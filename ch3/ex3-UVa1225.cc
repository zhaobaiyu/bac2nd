#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int m;
    cin >> m;
    int sum[10];
    for (int j = 0; j < 10; ++j) sum[j] = 0;
    for (int j = 1; j <= m; ++j) {
      int temp = j;
      ++sum[temp%10];
      temp = temp/10;
      if (temp > 0) { // >10
        ++sum[temp%10];
        temp = temp/10;
        if (temp > 0) { // >100
          ++sum[temp%10];
          temp = temp/10;
          if (temp > 0) { // >1000
            ++sum[temp%10];
            temp = temp/10;
          }
        }
      }
    }
    bool flag = 0;
    for (int j = 0; j < 10; ++j) {
      if (flag) cout << " ";
      cout << sum[j];
      flag = true;
    }
    cout << endl;
  }
  return 0;
}
