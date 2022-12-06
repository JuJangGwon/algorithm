#include <stdio.h>

int main()
{
  int n;

  scanf("%d" ,&n);
  for (int i = 1; i <= n;i++)
  {
      for (int j = 1; j <=n; j++)
      {
        if (i <= n/2)
        {
          if (j - 1 == n/2 - i)
           printf("-");
          else if (j == n/2 + i)
            printf("-");
          else 
          printf(" ");
        }
        else
        {
          if (j == i - (n/ 2))
          printf("-");
          if (j== n - i + (n/ 2))
          printf("-");
          else
            printf(" ");
        }
      }
      printf("\n");
  }
  return 0;
}