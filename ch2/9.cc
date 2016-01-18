#include <stdio.h>
int main () {
  int x, n = 0, min, max, s = 0;
  while (scanf("%d", &x) == 1) {
    s += x;
    if (min > x) x = min;
    if (max < x) x = max;
    ++n;
  }
  printf("%d %d %.3f\n", min, max, (double)s/n);
  return 0;
}
