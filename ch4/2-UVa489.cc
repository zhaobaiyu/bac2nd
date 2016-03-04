//This program is not optimized.Just accepted, not good.
#include <iostream>
#include <string>
#include <cstring>
using std::cin;
using std::cout;
using std::endl;
using std::string;
int main() {
  int n;
  while (cin >> n && n != -1) {
    string s1, s2;
    cin >> s1 >> s2;
    bool a[26], b[26];
    memset(a, false, sizeof(a));
    memset(b, false, sizeof(b));
    int wrong_num(0);
    for (auto ch1 : s1) {
      a[int(ch1) - 97] = true;
    }
    cout << "Round " << n << endl;
    bool is_cout;
    for (auto ch2 : s2) {
      bool has_guess(false);
      for (int i = 1; i < 26; ++i) 
        if (b[int(ch2) - 97] == true) {
          has_guess = true;
          break;
        }
      if (has_guess)
        continue;
      else
        b[int(ch2) - 97] = true;
      is_cout = false;
      bool find_flag(false);
      for (auto ch1 : s1) 
        if (ch1 == ch2) {
          a[int(ch1) - 97] = false;
          find_flag = true;
          break;
        }
      if (find_flag) {
        bool not_end(false);
        for (int i = 0; i < 26; ++i) {
          if (a[i] == true) not_end = true;
        }
        if (!not_end) {
          cout << "You win." << endl;
          is_cout = true;
          break;
        }
        continue;
      } else {
        if (++wrong_num >= 7) {
          cout << "You lose." << endl;
          is_cout = true;
          break;
        }
      }
    }
    if (!is_cout) cout << "You chickened out." << endl;
  }
  return 0;
}
