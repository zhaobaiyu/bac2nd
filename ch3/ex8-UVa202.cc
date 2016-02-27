#include <iostream>
#include <string>
#include <cstring>
using std::cin;
using std::cout;
using std::endl;
using std::string;
int main() {
  int x, y, blank_line_flag(0);
  while (cin >> x) {
    cin >> y;
    int yushu_pos[3005], yushu = x%y, order_num(0);
    memset(yushu_pos, -1, sizeof(yushu_pos));
    yushu_pos[yushu] = order_num;
    string xiaoshu, xiaoshu1, xiaoshu2;
    if (blank_line_flag++) cout << endl;
    cout << x << '/' << y << " = " << x/y << '.';
    while (true) {
      if (yushu == 0) {
        xiaoshu1 = xiaoshu;
        xiaoshu2 = '0';
        break;
      }
      x = yushu*10;
      xiaoshu += char(x/y + 48);
      yushu = x%y;
      if (yushu_pos[yushu] == -1) {
        yushu_pos[yushu] = ++order_num;
      } else {
        xiaoshu1 = string(xiaoshu, 0, yushu_pos[yushu]);
        xiaoshu2 = string(xiaoshu, yushu_pos[yushu], order_num - yushu_pos[yushu] + 1);
        break;
      }
    }
    string::size_type xiaoshu2_size = xiaoshu2.size();
    /*
    if (xiaoshu1.size() > 50) {
      cout << string(xiaoshu1, 0, 50) << endl
           << "   " << xiaoshu2_size
           << " = number of digits in repeating cycle" << endl;
      continue;
    } else if (xiaoshu1.size() + xiaoshu2.size() > 50) {
      xiaoshu2 = string(xiaoshu2, 0, 50 - xiaoshu1.size()) + "...";
    }
     */
    if (xiaoshu2.size() > 50)
      xiaoshu2 = string(xiaoshu2, 0, 50) + "...";
    cout << xiaoshu1 << '(' << xiaoshu2 << ')' << endl
         << "   " << xiaoshu2_size
         << " = number of digits in repeating cycle" << endl;
  }
  cout << endl;  //There is a blank line after every input, not between two inputs!!!
  return 0;
}
