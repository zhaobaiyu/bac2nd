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
    for (string::size_type j = 1; j <= s.size(); ++j) {
      if (s.size()%j != 0) continue;
      bool flag = false;
      for (string::size_type m = j; m < s.size(); m+=j)
        if (string(s, 0, j) != string(s, m, j)) {
          flag = true;
          break;
        }
      if (!flag) {
        cout << j << endl;
        break;
      }
    }
  }
  return 0;
}
        
