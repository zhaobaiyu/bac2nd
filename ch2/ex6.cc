#include <stdio.h>
int main() {
  int temp[10];
  for (int i = 123; i <= 333; ++i) {
    bool f = 0;
    temp[1] = i/100;
    temp[2] = i/10%10;
    temp[3] = i%10;
    temp[4] = 2*i/100;
    temp[5] = 2*i/10%10;
    temp[6] = 2*i%10;
    temp[7] = 3*i/100;
    temp[8] = 3*i/10%10;
    temp[9] = 3*i%10;
    for (int j = 1; j <= 9; ++j) {
      if (temp[j] == 0) {
	f = 1;
	break;
      }
      temp[0] = temp[j];
      temp[j] = 10;
      if (temp[0] == temp[1] || temp[0] == temp[2] || temp[0] == temp[3]) {
	f = 1;
	break;
      }
      if (temp[0] == temp[4] || temp[0] == temp[5] || temp[0] == temp[6]) {
	f = 1;
	break;
      }
      if (temp[0] == temp[7] || temp[0] == temp[8] || temp[0] == temp[9]) {
	f = 1;
	break;
      }
    }
    if (f == 1) continue;
    printf("%d %d %d\n", i, i*2, i*3);
  }
  return 0;
}
