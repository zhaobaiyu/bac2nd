#include <stdio.h>
int main() {
  int n;
  double s;
  scanf("%d", &n);
  s = n*95;
  if (s >= 300) s = s*0.85;
  printf("%.3lf\n", s);
  return 0;
}
