#include <stdio.h>
#include "math.h"

#define PI 3.141592

char map[101][101];

void YouAreHere()
{
    map[50][50] = '3';

}


int GetDay(int month, int day, int year)
{
  int sum = 0;
  int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  int i =1;
  while (i != month)
    sum += days[i++];
  sum += day-1; //당일은 제외시킴(-1)
  sum += (year-1) * 365;

  return sum;
}

void PrintMap()
{
  for (int i =0; i < 100; i++)
  {
    for (int j = 0; j < 100; j++)
    {
        printf("%c", map[i][j]);
    }
    printf("\n");
  }
}

int main()
{
  int year, month, day;
  int sumday;
  double moondegree;
  YouAreHere();
  printf("날짜를 입력하세요.\n");
  scanf("%d",&year);
  scanf("%d",&month);
  scanf("%d",&day);
  printf("%d년 %d월 %d일\n",year,month,day);

  sumday = GetDay(month,day,year);
 
  moondegree = sumday % 31 * 12;                               // 달 위치 각도로 변환(각도가 360니까 12로 맞춰줌)

  int moonx = 50 + 5 * cos(moondegree* ((double)3.14 / 180));
  int moony = 50 + 5 * sin (moondegree * ((double)3.14 / 180));

  //map[moony][moonx] = '2';    // 달 그리기

  PrintMap();

  return 0;
}