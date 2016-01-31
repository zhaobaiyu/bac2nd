#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;
char rectify(char chtemp) {
  const string qwerty = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;\'ZXCVBNM,./";
  string::size_type i = 0;
  for (i = 0; i < qwerty.size(); ++i)
    if (qwerty[i] == chtemp) break;
  return qwerty[i - 1];
}
int main() {
  string s;
  while (getline(cin, s)) {
    for (auto ch : s)
      if (ch == ' ')
        cout << ch;
      else cout << rectify(ch);
    cout << endl;
  }
  return 0;
}
