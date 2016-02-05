#include <iostream>
using std::cin;
using std::cout;
using std::endl;
void swap(int &v1, int &v2) {
  int tmp = v2;
  v2 = v1;
  v1 = tmp;
}
int main() {
  int w[6], h[6];
  while (cin >> w[0]) {
    cin >> h[0];
    for (int i = 1; i < 6; ++i) cin >> w[i] >> h[i];
    for (int i = 0; i < 6; ++i) 
      if (w[i] > h[i])
        swap(w[i], h[i]);
    for (int i = 0; i < 6; ++i) 
      for(int j = i + 1; j < 6; ++j) 
        if (w[i] > w[j]) {
          swap(w[i], w[j]);
          swap(h[i], h[j]);
        }
        else if (w[i] == w[j] && h[i] > h[j]) {
          swap(h[i], h[j]);
        }
    bool psb_flag(true);
    for (int i = 0; i < 6; i = i + 2)
      if (w[i] != w[i+1] || h[i] != h[i+1]) {
        psb_flag = false;
        break;
      }
    if (!psb_flag) {
      cout << "IMPOSSIBLE" << endl;
      continue;
    }
    if (w[0] == w[2] && w[4] == h[0] && h[2] == h[4])
      cout << "POSSIBLE" << endl;
    else
      cout << "IMPOSSIBLE" << endl;
  }
  return 0;
}
