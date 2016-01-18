#include <stdio.h>
#define INF 1000000000
int main() {
  /*
  int n, kase = 0;
  while (scanf("%d", &n) == 1 && n) {
    int x, min = INF, max = -INF, s = 0;
    for (int i = 0; i < n; ++i) {
      scanf("%d", &x);
      s += x;
      if (x < min) min = x;
      if (x > max) max = x;
    }
    if (kase) printf("\n");
    printf("Case %d: %d %d %.3f\n", ++kase, min, max, (double)s/n);
  }
  */
  
  int n, g = 0, kase = 0, a[100], b[100];
  double c[100];
  while (scanf("%d", &n) == 1 && n) {
    int s = 0, x;
    ++g;
    a[g] = INF;
    b[g] = -INF;
    for (int i = 0; i < n; ++i) {
      scanf("%d", &x);
      s += x;
      if (x < a[g]) a[g] = x;
      if (x > b[g]) b[g] = x;
      c[g] = (double)s/n;
    }
  }
  for (int i = 1; i <= g; ++i) {
    if (kase++) printf("\n");
    printf("Case %d: %d %d %.3f\n", i, a[i], b[i], c[i]);
  }
  return 0;
}
