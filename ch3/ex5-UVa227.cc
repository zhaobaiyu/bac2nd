#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;
int main() {
  int label_num = 0;
  string a[5], b, b_temp;
  getline(cin, a[0]);
  while (a[0][0] != 'Z') {
    for (int i = 1; i <= 4; ++i) getline(cin, a[i]);
    getline(cin, b);
    while (b[b.size() - 1] != '0') {
      getline(cin, b_temp);
      b = b + b_temp;
    }
    if(label_num) {
      cout << endl;
    }
    string::size_type x = 0;
    int y = 0;
    cout << "Puzzle #" << ++label_num << ":" << endl;
    for (int i = 0; i <= 4; ++i)
      for (string::size_type j = 0; j < a[i].size(); ++j)
        if (a[i][j] == ' ') {
          x = j;
          y = i;
        }
    bool error_flag(false);
    for (auto ch : b) {
      if (ch == 'A' && y == 0) {
        error_flag = true;
        break;
      }
      if (ch == 'A' && y != 0) {
        a[y][x] = a[y - 1][x];
        a[y - 1][x] = ' ';
        y = y - 1;
      }
      if (ch == 'B' && y == 4) {
        error_flag = true;
        break;
      }
      if (ch == 'B' && y != 4) {
        a[y][x] = a[y + 1][x];
        a[y + 1][x] = ' ';
        y = y + 1;
      }
      if (ch == 'R' && x == a[y].size() - 1) {
        error_flag = true;
        break;
      }
      if (ch == 'R' && x != a[y].size() - 1) {
        a[y][x] = a[y][x + 1];
        a[y][x + 1] = ' ';
        x = x + 1;
      }
      if (ch == 'L' && x == 0) {
        error_flag = true;
        break;
      }
      if (ch == 'L' && x != 0) {
        a[y][x] = a[y][x - 1];
        a[y][x - 1] = ' ';
        x = x - 1;
      }
    }
    if(error_flag) {
      cout << "This puzzle has no final configuration." << endl;
    } else {
      for (int i = 0; i <= 4; ++i) {
        for (int j = 0; j <= 3; ++j) {
          cout << a[i][j] << ' ';
        }
        cout << a[i][4] << endl;
      }
    }
    getline(cin, a[0]);
  }
  return 0;
}
