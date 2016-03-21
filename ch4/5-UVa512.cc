#include <stdio.h>
#include <string.h>
int r, c;
int a[60][60];
void ex() {
  int r1, c1, r2, c2;
  scanf("%d%d%d%d", &r1, &c1, &r2, &c2);
  int temp;
  temp = a[r1][c1];
  a[r1][c1] = a[r2][c2];
  a[r2][c2] = temp;
}
void dc() {
  int opn, o[15], temp;
  scanf("%d", &opn);  
  for (int k = 0; k < opn; ++k) {
    scanf("%d", &o[k]);
  }
  for (int i = 0; i < opn; ++i)
    for (int j = i + 1; j < opn; ++j)
      if (o[i] < o[j]) {
        temp = o[i];
        o[i] = o[j];
        o[j] = temp;
      }
  for (int k = 0; k < opn; ++k) {
    for (int j = o[k]; j <= c - 1; ++j) 
      for (int i = 1; i <= r; ++i) 
        a[i][j] = a[i][j+1];
    for (int i = 1; i <= r; ++i)
      a[i][c] = 0;
    --c;
  }
}
void dr() {
  int opn, o[15], temp;
  scanf("%d", &opn);
  for (int k = 0; k < opn; ++k) {
    scanf("%d", &o[k]);
  }
  for (int i = 0; i < opn; ++i)
    for (int j = i + 1; j < opn; ++j)
      if (o[i] < o[j]) {
        temp = o[i];
        o[i] = o[j];
        o[j] = temp;
      }
  for (int k = 0; k < opn; ++k) {
    for (int i = o[k]; i <= r - 1; ++i)
      for (int j = 1; j <= c; ++j)
        a[i][j] = a[i+1][j];
    for (int j = 1; j <= c; ++j)
      a[r][j] = 0;
    --r;
  }
}
void ic() {
  int opn, o[15], temp;
  scanf("%d", &opn);
  for (int k = 0; k < opn; ++k) {
    scanf("%d", &o[k]);
  }
  for (int i = 0; i < opn; ++i)
    for (int j = i + 1; j < opn; ++j)
      if (o[i] < o[j]) {
        temp = o[i];
        o[i] = o[j];
        o[j] = temp;
      }
  for (int k = 0; k < opn; ++k) {
    for (int j = c; j >= o[k]; --j)
      for (int i = 1; i <= r; ++i)
        a[i][j+1] = a[i][j];
    for (int i = 1; i <= r; ++i)
      a[i][o[k]] = 0;
    ++c;
  }
}
void ir() {
  int opn, o[15], temp;
  scanf("%d", &opn);
  for (int k = 0; k < opn; ++k) {
    scanf("%d", &o[k]);
  }
  for (int i = 0; i < opn; ++i)
    for (int j = i + 1; j < opn; ++j)
      if (o[i] < o[j]) {
        temp = o[i];
        o[i] = o[j];
        o[j] = temp;
      }
  for (int k = 0; k < opn; ++k) {
    for (int i = r; i >= o[k]; --i)
      for (int j = 1; j <= c; ++j)
        a[i+1][j] = a[i][j];
    for (int j = 1; j <= c; ++j)
      a[o[k]][j] = 0;
    ++r;
  }
}
void pt() {
  printf("%d %d\n", r, c);
  for (int i = 1; i <= r; ++i) {
    for (int j = 1; j <= c; ++j) {
      printf("%d ", a[i][j]);
    }
    printf("\n");
  }
}
int main() {
  int n, ord = 0;
  while (scanf("%d%d%d", &r, &c, &n) == 3 && r) {
    for (int i = 1; i <= r; ++i) 
      for (int j = 1; j <= c; ++j) 
        a[i][j] = i*100 + j;
    //    pt();
    char op[5];
    for (int i = 0; i < n; ++i) {
      scanf("%s", op);
      if (strcmp(op, "EX") == 0) ex();
      else if (strcmp(op, "DC") == 0) dc();
      else if (strcmp(op, "DR") == 0) dr();
      else if (strcmp(op, "IC") == 0) ic();
      else if (strcmp(op, "IR") == 0) ir();
      // pt();
    }
    if (ord > 0) printf("\n");
    printf("Spreadsheet #%d\n", ++ord);
    int m, rq, cq, find_flag;
    scanf("%d", &m);
    for (int k = 0; k < m; ++k) {
      scanf("%d%d", &rq, &cq);
      printf("Cell data in (%d,%d) ", rq, cq);
      find_flag = 0;
      for (int i = 1; i <= r; ++i) {
        for (int j = 1; j <= c; ++j) 
          if (a[i][j] == rq*100 + cq) {
            printf("moved to (%d,%d)\n", i, j);
            find_flag = 1;
            break;
          }
        if (find_flag) break;
      }
      if (!find_flag)
        printf("GONE\n");
    }
  }
  return 0;
}
