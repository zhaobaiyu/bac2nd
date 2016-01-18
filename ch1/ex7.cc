#include <stdio.h>
int main() {
  int n;
  scanf("%d", &n);
  if (n % 4000 == 0)
    printf("no\n");
  else if (n % 400 == 0)
    printf("yes\n");
  else if (n % 100 == 0)
    printf("no\n");
  else if (n % 4 == 0)
    printf("yes\n");
  return 0;
}
      
