#include <iostream>
#include <string>
#include <cstring>
using std::cin;
using std::cout;
using std::endl;
using std::string;
void trans(string s, int *ant) {
  for (auto ch : s) ++ant[int(ch) - 65];
  for (int i = 0; i < 26; ++i)
    for (int j = i + 1; j < 26; ++j)
      if (ant[i] < ant[j]) {
        int temp = ant[i];
        ant[i] = ant[j];
        ant[j] = temp;
      }
}
int main() {
  string s1, s2;
  while (cin >> s1) {
    cin >> s2;
    int ant1[26], ant2[26];
    memset(ant1, 0, sizeof(ant1));
    memset(ant2, 0, sizeof(ant2));
    trans(s1, ant1);
    trans(s2, ant2);
    bool is_right(true);
    for (int i = 0; i < 26; ++i) 
      if (ant1[i] != ant2[i]) {
        is_right = false;
        break;
      }
    if (is_right)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
    
      
