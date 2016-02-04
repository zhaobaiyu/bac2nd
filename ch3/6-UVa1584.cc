#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    string min(s);
    for (string::size_type i = 1; i < s.size(); ++i) {
      string tmp = string(s, i, s.size() - i) + string (s, 0, i);
      if (tmp < min) min = tmp;
    }
    cout << min <<endl;
  }
  return 0;
}
      
