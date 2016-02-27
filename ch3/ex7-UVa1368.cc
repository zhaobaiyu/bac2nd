#include <iostream>
#include <string>
#include <cstring>
using std::cin;
using std::cout;
using std::string;
using std::endl;
int main() {
  string acgt("ACGT");
  int sum;
  cin >> sum;
  for (int i = 0; i < sum; ++i) {
    int m, ch_sum[1000][4];
    string::size_type n;
    memset(ch_sum, 0, sizeof(ch_sum));
    cin >> m >> n;
    string temp_str;
    getline(cin, temp_str);
    for (int j = 0; j < m; ++j) {
      getline(cin, temp_str);
      for (string::size_type k = 0; k < n; ++k) 
        switch (temp_str[k]) {
          case 'A': ++ch_sum[k][0]; break;
          case 'C': ++ch_sum[k][1]; break;
          case 'G': ++ch_sum[k][2]; break;
          case 'T': ++ch_sum[k][3]; break;
        }
    }
    int hamming_sum(0);
    for (string::size_type j = 0; j < n; ++j) {
      int temp_ch_sum = ch_sum[j][0], temp_ans = 0;
      for (int k = 1; k < 4; ++k) 
        if (ch_sum[j][k] > temp_ch_sum) {
          temp_ch_sum = ch_sum[j][k];
          temp_ans = k;
        }
      cout << acgt[temp_ans];
      hamming_sum += m - ch_sum[j][temp_ans];
    }
    cout << endl << hamming_sum << endl;
  }
  return 0;
}
