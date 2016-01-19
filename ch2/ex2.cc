#include <stdio.h>
int main() {
  int kase = 0, ans[100], a, b, c;
  while (scanf("%d", &a) == 1) {
    ans[++kase] = 0;
    scanf("%d%d", &b, &c);
    for (int i = 10; i <= 100; ++i)
      if (i % 3 == a && i % 5 == b && i % 7 == c) {
	ans[kase] = i;
	break;
      }
  }
  for (int i = 1; i <= kase; ++i)
    if (ans[i] == 0)
      printf("Case %d: No answer\n", i);
    else
      printf("Case %d: %d\n", i, ans[i]);
  return 0;
}
