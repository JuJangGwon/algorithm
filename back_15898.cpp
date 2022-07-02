#include <iostream>
#include <memory.h>

using namespace std;

int gmam[5][5];
char gmam_char[5][5];
int us[10];
int used[10][4][4];
bool used_b[10][4][4];
pair<int,pair<int,int> >arr[3];
int inputs_numarray[10][4][4];
char inputs_chararray[10][4][4];
int inputs_num;
int max_result = 0;
int temp_array[4][4];
int temp_array_c[4][4];

int result_check()
{
  int red =0;
  int blue = 0;
  int green = 0;
  int yellow = 0;
  for (int i =0; i < 5; i++)
    {
      for (int j = 0; j < 5; j++)
        {
          if (gmam_char[i][j] == 'R')
          {
             red +=gmam[i][j];
          }
          else if (gmam_char[i][j] == 'B')
          {
             blue +=gmam[i][j];
          }
          else if (gmam_char[i][j] == 'G')
          {
             green +=gmam[i][j];
          }
          else if (gmam_char[i][j] == 'Y')
          {
             yellow +=gmam[i][j];
          }
        }
    }
    return red * 7 + blue * 5 + green * 3 + yellow * 2;
}

void rotate_array(int a,int b) // 회전 
{
  if (b == 1)
  {
    for(int i=0; i<4; i++)
      for(int j=0; j<4; j++)
        {
          temp_array[i][j] = inputs_numarray[a][4-j-1][i];
          temp_array_c[i][j] = inputs_chararray[a][4-j-1][i];
        }
  }
  else if (b == 2)
  {
      for(int i=0; i<4; i++)
      for(int j=0; j<4; j++)
        {
          temp_array[i][j] = inputs_numarray[a][4-j-1][4-i-1];
          temp_array_c[i][j] = inputs_chararray[a][4-j-1][4-i-1];
        }
  }
  else if (b == 3)
  {
      for(int i=0; i<4; i++)
      for(int j=0; j<4; j++)
        {
          temp_array[i][j] = inputs_numarray[a][j][4-i-1];
          temp_array_c[i][j] = inputs_chararray[a][j][4-i-1];
        }
  }
  else
  {
     for(int i=0; i<4; i++)
      for(int j=0; j<4; j++)
        {
          temp_array[i][j] = inputs_numarray[a][j][i];
          temp_array_c[i][j] = inputs_chararray[a][j][i];
        }
  }
}

void add_array(int a)
{
  int x = 0,y = 0;
  if (a == 1)
    x= 1;
  else if (a == 2)
    y = 1;
  else if (a == 3)
  {
    x = 1;
    y = 1;
  }
  for (int i = y; i < 4+y; i++)
  {
    for  (int j = x; j < 4+x; j++)
    {
        gmam[i][j] += temp_array[i-y][j-x];  
        if (gmam[i][j] >= 9)
            gmam[i][j] = 9;
        else if (gmam[i][j] < 0)
            gmam[i][j] = 0;
        gmam_char[i][j] = temp_array[i-y][j-x];
    }
  }
}

void add()
{
  memset(gmam,0,sizeof(gmam));
  memset(gmam_char,0,sizeof(gmam_char));
  for (int i = 0; i < 3; i++)
  {
      int a = arr[i].first;      // 어떤 배열 쓸껀지
      int b = arr[i].second.first;    // 각도
      int c = arr[i].second.second;      // 위치
      //
      rotate_array(a,b);
      add_array(c);
  }
}

void dfs(int a, int b, int angle, int pos)
{
  if (a == 3)
  {
      add();
      max_result = max(max_result,result_check());
      return ;
  }
  for (int i = 0; i < inputs_num; i++)
  {
    if (!us[i])
    {
      us[i] = true;
      for (int j = 0; j < 4; j++)
      {
        for (int k = 0;k < 4; k++)
        {
          if (!used_b[i][j][k])
          {
            used_b[i][j][k] = true;
            arr[a] = make_pair(i, make_pair(j,k));
            used_b[i][j][k] = false;
          }
        }
      }
      us[i] = false;
    }
  }
}

int main()
{
  cin >> inputs_num;
  for (int i = 0; i < inputs_num; i++)
  {
      for (int j = 0; j < 4; j++)
      {
          for (int k = 0; k <4; k++)
          {
                cin >> inputs_numarray[i][j][k];
          }
      }
     for (int j = 0; j < 4; j++)
      {
          for (int k = 0; k <4; k++)
          {
                cin >> inputs_chararray[i][j][k];
          }
      }
  }
  dfs(0,0,0,0);
  cout << max_result;
  return 0;
}

