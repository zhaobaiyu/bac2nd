#include <stdio.h>
int main() {
  int kase = 0;
  double ans[100];
  int n, m;
  while (scanf("%d%d", &n, &m) == 2 && n && m) {
    ans[++kase] = 0;
    for (int i = n; i <= m; i++)
      ans[kase] += 1.0/i/i;
  }
  for (int i = 1; i <= kase; ++i)
    printf("Case %d: %.5f\n", i, ans[i]);
  return 0;
}
