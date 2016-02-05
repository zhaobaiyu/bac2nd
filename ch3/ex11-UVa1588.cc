#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;
int main() {
  string b_str, t_str;
  while (cin >> b_str >> t_str) {
    int ans_a = 300, ans_b = 300;
    string::size_type i = 0, j;
    bool end_flag = false;
    while (i < b_str.size()) {
      j = 0;
      bool next_ch(false);
      while (j < t_str.size()) {
        if (t_str[j] == '2' && b_str[i+j] == '2') {
          next_ch = true;
          break;
        }
        if (i + j == b_str.size() - 1) {
          ans_a = i + t_str.size(); //b_str.size() + t_str.size() - j - 1
          end_flag = true;
          break;
        }
        ++j;
      }
      if (end_flag) break;
      if (next_ch) {
        ++i;
      } else {
        ans_a = b_str.size();
        break;
      }
      if (i == b_str.size() - 1) ans_a = b_str.size() + t_str.size();
    }
    i = 0;
    end_flag = false;
    while (i < t_str.size()) {
      j = 0;
      bool next_ch(false);
      while (j < b_str.size()) {
        if (t_str[i+j] == '2' && b_str[j] == '2') {
          next_ch = true;
          break;
        }
        if (i + j == t_str.size() - 1) {
          ans_b = i + b_str.size(); //t_str.size() + b_str.size() - j - 1
          end_flag = true;
          break;
        }
        ++j;
      }
      if (end_flag) break;
      if (next_ch) {
        ++i;
      } else {
        ans_b = t_str.size();
        break;
      }
      if (i == t_str.size() - 1) ans_b = b_str.size() + t_str.size();
    }
    if (ans_a > ans_b) ans_a = ans_b;
    cout << ans_a << endl;
  }
  return 0;
}
