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
    string s;
    cin >> s;
    int oflag = 0, osum = 0;
    for (auto ch : s) {
      if (ch == 'O') osum += ++oflag;
      if (ch == 'X') oflag = 0;
    }
    cout << osum << endl;
  }
  return 0;
}
