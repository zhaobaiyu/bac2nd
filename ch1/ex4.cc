#include <stdio.h>
#include <math.h>
int main() {
  int n;
  double s, c;
  scanf("%d", &n);
  s = sin(n*acos(-1.0)/180);
  c = cos(n*acos(-1.0)/180);
  printf("%lf %lf\n", s, c);
  return 0;
}
