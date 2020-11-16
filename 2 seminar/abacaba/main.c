
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void GenerateString (int n, char* str)
{
  int k = 0;
  for (int i = 1; i <= n; i++)
  {
    strncpy(&str[k + 1], str, sizeof(char) * k);
    str[k] = 'a' + i - 1;
    k = (1 << i) - 1;
  }
}
int main()
{
  int v, u;
  char* s;
  scanf("%d", &v);
  u = (1 << v) - 1;
  s = (char*)malloc(sizeof(char) * u);
  GenerateString (v, s);
  printf ("%s", s);
  free (s);
  return 0;
}

