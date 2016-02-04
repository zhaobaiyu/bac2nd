#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;
int main() {
  string s, t;
  while (cin >> s >> t) {
    bool s_match(true);
    string::size_type i(0);
    for (auto chs : s) {
      bool ch_match(false);
      while (i < t.size()) {
        if (chs == t[i++]) {
          ch_match = true;
          break;
        }
      }
      if (!ch_match) {
        s_match = false;
        break;
      }
    }
    if (s_match)
      cout << "Yes" << endl;
    else
      cout << "No" << endl;
  }
  return 0;
}
