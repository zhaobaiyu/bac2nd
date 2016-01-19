#include <stdio.h>
int main() {
  int a, b ,c, yu, kase = 0, ans[106][105], cc[100];
  while (scanf("%d%d%d", &a, &b, &c) == 3 && a && b && c) {
    ans[++kase][0] = a/b;
    cc[kase] = c;
    yu = a % b;
    for (int i = 1; i <= c + 1; ++i)
      if (yu == 0) {
	ans[kase][i] = 0;
	continue;
      }
      else {
	ans[kase][i] = yu*10/b;
	yu = yu*10%b;
      }
    //round
    if (ans[kase][c + 1] >= 5) {
      ++ans[kase][c];
      for (int i = c; i >= 1; --i)
	if (ans[kase][i] == 10) {
	  ans[kase][i] = 0;
	  ++ans[kase][i - 1];
	}
    }
  }
  for (int i = 1; i <= kase; ++i) {
    printf("Case %d: %d.", i, ans[i][0]);
    for (int j = 1; j <= cc[i]; ++j)
      printf("%d", ans[i][j]);
    printf("\n");
  }
  return 0;
}
