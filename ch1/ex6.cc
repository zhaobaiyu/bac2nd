#include <stdio.h>
int main() {
  int a, b, c;
  scanf("%d%d%d", &a, &b, &c);
  if (a + b <= c || a + c <= b || b + c <= a)
    printf("not a triangle\n");
  else if (a*a == b*b + c*c || b*b == a*a + c*c || c*c == a*a + b*b)
    printf("yes\n");
  else printf("no\n");
  return 0;
}
