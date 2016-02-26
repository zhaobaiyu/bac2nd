#include <iostream>
#include <string>
#include <iomanip>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::setw;
int main() {
  int r, label_num(0);
  string::size_type c;
  while (cin >> r && r != 0) {
    cin >> c;
    string a[10], temp_str;
    int eli_num[10][10], temp_num(0);
    bool down_eli_flag[10][10];
    getline(cin, temp_str);
    for (int i = 0; i < r; ++i) getline(cin, a[i]);
    if (label_num) cout << endl;
    cout << "puzzle #" << ++label_num << ":" << endl
         << "Across" << endl;
    for (int i = 0; i < r; ++i)
      for (string::size_type j = 0; j < c; ++j) {
        down_eli_flag[i][j] = false;
        if (a[i][j] == '*') {
          continue;
        }
        bool eli_flag(false);
        if (j == 0 || a[i][j - 1] == '*') {
          eli_num[i][j] = ++temp_num;
          eli_flag = true;
          temp_str = a[i][j];
          for (string::size_type k = j + 1; k < c; ++k) 
            if (a[i][k] == '*') {
              break;
            } else {
              temp_str = temp_str + a[i][k];
            }
          cout << setw(3) << temp_num << "." << temp_str << endl;
          temp_str = "";
        }
        if (i == 0 || a[i - 1][j] == '*') {
          if (!eli_flag) eli_num[i][j] = ++temp_num;
          down_eli_flag[i][j] = true;
        }
      }
    cout << "Down" << endl;
    for (int i = 0; i < r; ++i)
      for (string::size_type j = 0; j < c; ++j) {
        if (down_eli_flag[i][j]) {
          temp_str = a[i][j];
          for (int k = i + 1; k < r; ++k)
            if (a[k][j] == '*') {
              break;
            } else {
              temp_str = temp_str + a[k][j];
            }
          cout << setw(3) << eli_num[i][j] << "." << temp_str << endl;
        }
      }
  }
  return 0;
}
    
            


    
