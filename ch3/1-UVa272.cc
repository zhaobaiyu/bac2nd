#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;
int main() {
  string input_line;
  bool quote_flag = false; 
  while (getline(cin, input_line)) {
    for (auto input_ch : input_line)
      if (input_ch == '\"' && quote_flag == 0) {
        cout << "``";
        quote_flag = 1;
      } else if (input_ch == '\"' && quote_flag == 1) {
        cout << "\'\'";
        quote_flag = 0;
      } else {
        cout << input_ch;
      }
    cout << endl;
  }
  return 0;
}
