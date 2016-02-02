#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;
int main() {
  int n, game_order = 1;
  while (cin >> n && n != 0) {
    cout << "Game " << game_order++ << ":" << endl;
    int origin_num[1005], guess_num[1005];
    for (int i = 0; i < n; ++i) cin >> origin_num[i];
    bool end_flag(true);
    while (end_flag) {
      end_flag = false;
      int a_ans = 0, b_ans = 0;
      bool match_origin_num[1005], match_guess_num[1005];
      for (int i = 0; i < n; ++i) {
        match_origin_num[i] = false;
        match_guess_num[i] = false;
      }
      for (int i = 0; i < n; ++i) {
        cin >> guess_num[i];
        end_flag = end_flag || guess_num[i];
        if (guess_num[i] == origin_num[i]) {
          ++a_ans;
          match_origin_num[i] = true;
          match_guess_num[i] = true;
        }
      }
      if (!end_flag) break;
      for (int i = 0; i < n; ++i) {
        if (match_guess_num[i]) continue;
        for (int j = 0; j < n; ++j) {
          if (match_origin_num[j])
            continue;
          else if (guess_num[i] == origin_num[j]) {
            ++b_ans;
            match_origin_num[j] = true;
            break;
          }
        }
      }
      cout << "    (" << a_ans << "," << b_ans << ")" << endl;
    }
  }
  return 0;
}
