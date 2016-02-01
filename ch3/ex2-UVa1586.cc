#include <iostream>
#include <string>
#include <cctype>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::fixed;
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    double flag, sum = 0;
    for (string::size_type j = 0; j < s.size(); ++j) {
      switch (s[j]) {
        case 'C': flag = 12.01; break;
        case 'H': flag = 1.008; break;
        case 'O': flag = 16.00; break;
        case 'N': flag = 14.01; break;
      }
      if (!isdigit(s[j+1])) {
        sum += flag;
      } else if (isdigit(s[j+1]) && !isdigit(s[j+2])) {
        sum += flag*(s[j+1] - 48);
        ++j;
      } else if (isdigit(s[j+1]) && isdigit(s[j+2])) {
        sum += flag*((s[j+1] - 48)*10 + s[j+2] - 48);
        j += 2;
      }
    }
    cout.precision(3);
    cout << fixed << sum <<endl;
  }
  return 0;
}
        
