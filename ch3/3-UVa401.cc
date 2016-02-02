#include <iostream>
#include <string>
#include <cctype>
using std::cin;
using std::cout;
using std::endl;
using std::string;
const string a_str(" -- is not a palindrome."),
    b_str(" -- is a regular palindrome."),
    c_str(" -- is a mirrored string."),
    d_str(" -- is a mirrored palindrome."),
    mir_str("A   3  HIL JM O   2TUVWXY51SE Z  8 ");
char r(char ch) {
  if(isalpha(ch)) return mir_str[ch - 'A'];
  return mir_str[ch - '0' + 25];
}
int main() {
  string s;
  while (cin >> s) {
    string fan_s, mir_s;
    bool fan_flag(false), mir_flag(false);
    for (string::size_type i = s.size(); i > 0; --i) {
      fan_s += s[i-1];
      mir_s += r(s[i-1]);
    }
    if (s == fan_s) fan_flag = true;
    if (s == mir_s) mir_flag = true;
    if (!fan_flag && !mir_flag)
      cout << s + a_str << endl << endl;
    else if (fan_flag && !mir_flag)
      cout << s + b_str << endl << endl;
    else if (!fan_flag && mir_flag)
      cout << s + c_str << endl << endl;
    else
      cout << s + d_str << endl << endl;
  }
  return 0;
}
    
      
    
    
